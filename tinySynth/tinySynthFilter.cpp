/*
==============================================================================
tinySynthFilter.cpp - Copyright (C) 2016 Aldo Ciaccini

Description:
tinySynthFilter implementations the  high order parametric filter and
resonant parametric equalizer used inside the tinySynth plugin.
Its architecture, reuses the filter code provided inside the vstSynth project 
developed by Gabriel Olochwoszcz in 2012 under the terms of the GNU Public Lic. v.2. 
The initial code has been extended adding the capabilities to modify the 
filter's frequency through LFO effects and ADSR modulation modifications.
Moreover, the class has been optimized in order to embedded inside a polyphonic Synthesizer.
==============================================================================
Copyright:
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
==============================================================================
*/

#include "tinySynthFilter.h"	

//==============================================================================
tinySynthFilter::tinySynthFilter()
{
	// LFO handler inzialization
	lfo_.Frequency = 0.0f;
	lfo_.Depth = 0.0f;
	lfo_.Destination = -1; // -1 to force the first initialization of lfo_ class variable
	lfo_.Wave = 0;


	// Initialize fixed design parameters
	G0 = 0.0001; // reference gain -120db
	G = 1.0f; // LF rev: fixed gain
	N = 3.0;
	phi = PI/6;
	s1 = sin(phi);

	// LF rev start: added intitializion code
	Wc = 0.025;
	W0 = 0;
	W1 = 0;
	W2 = Wc;
	dW = W2-W1;

	beta = 0.00288f;
	c0 = 1.0f;

	betaSq = beta*beta;
	c0Sq  = 0;

	Gr = 1.0f; // fixed gain
	dWr = 0.01f * G;

	c0r = cos(Wc); //resonator center freq cosine

	D0 = 0.5f;
	// second order coefficients
	b00 = b01 = b02 = 0.5f;
	a00 = a01 = a02 = 0.5f;

	D1 = 0.5f;
	// fourth order coefficients
	b10 = b11 = b12 = b13 = b14 = 0.5f;
	a10 = a11 = a12 = a13 = a14 = 0.5f;

	// resonator coefficients
	b20 = b21 = b22 = 0.5f;
	a20 = a21 = a22 = 0.5f;

	// Zeros internal states
	this->reset();	

	this->defineParameters(); 

	// resonator section coefficients
	betaR = sqrt((Gbr*Gbr - G0*G0)/(Gr*Gr - Gbr*Gbr))*tanf(dWr/2);

	filterType = 0;
	this->updateFilter();
	filterType = 1;
	this->updateFilter();
	filterType = 2;
	this->updateFilter();

	oldFrequency = Wc;
	EnvModDepth = 0.0f;
	// LF rev end: added intitializion code
}

//==============================================================================
tinySynthFilter::~tinySynthFilter()
{
}

//==============================================================================
// Set Frequency and Resonance parameters and update the filter
void tinySynthFilter::setCoefficients( float newFrequency, float newResonance)
{
	this->Wc = newFrequency;
	this->Gr = newResonance * G;	
	this->updateFilter(); // recalculate all coefficients
}

//==============================================================================
// Set filter type (0=LP,1=BP,2=HP) and update the filter
void tinySynthFilter::setType(int newType)
{
	this->filterType = newType; 
	this->updateFilter();
}
// LF rev: removed Set 2nd and 4th order gain

//==============================================================================
// Set cutoff frequency
void tinySynthFilter::setFrequency(float newFrequency)
{
	this->Wc = newFrequency;
	this->updateFilter();
}

//==============================================================================
// Set resonator gain above 2nd/4th order gain
void tinySynthFilter::setResonance(float newResonance)
{
	this->Gr = newResonance * G;
	this->updateFilter();
}

//==============================================================================
// Reset internal states after changes
void tinySynthFilter::reset()
{
	x01 = x02 = 0;
	y01 = y02 = 0;

	x11 = x12 = x13 = x14 = 0;
	y11 = y12 = y13 = y14 = 0;
	w11 = w12 = w13 = w14 = 0;

	x21 = x22 = 0;
	y21 = y22 = 0;
}

//==============================================================================
// Calculate g, g0, and epsilon
void tinySynthFilter::defineParameters() // LF rev: these values never change after inizialization
{
	// Filter gain > reference gain
	// Set cutoff gain to 6 dB below passband gain
	if (G >= G0)
	{
		Gb = G/2;
	}

	// Filter gain < reference gain
	// Set cutoff gain to 6 db below reference gain
	if (G < G0)
	{
		Gb = G0/2;
	}

	// Resonator reference gain is the passband gain
	G0r = G;

	// 6 dB below resonator peak
	Gbr = Gr/2;
	g = pow(G,1.0f/N);
	g0 = pow(G0,1.0f/N); 

	epsilon = sqrt((G*G - Gb*Gb)/(Gb*Gb - G0*G0));

	// squared values
	gSq = g*g;
	g0Sq = g0*g0;
}


//==============================================================================
// Calculate all coefficients
void tinySynthFilter::updateFilter()
// All resonator coefficients have "r" appended
{	
	// Set frequency parameters for each filter type
	switch (filterType) 
	{
		case 0: // lowpass filter
		{
			W0 = 0;
			W1 = 0;
			W2 = Wc;
			dW = W2 - W1;
			beta = pow(epsilon,-1.0f/N) * tanf(dW/2);
			betaSq = beta*beta;

			c0 = cos(W0);
			c0Sq = c0*c0;

			// Lowpass second order section
			D0 = beta + 1;
			b00 = (g*beta + g0)/D0;
			b01 = (g*beta - g0)/D0;
			b02 = 0;
			a01 = (beta - 1)/D0;
			a02 = 0;

			// Lowpass fourth order section
			D1 = betaSq + 2*s1*beta + 1;
			b10 = (gSq*betaSq + 2*g*g0*s1*beta + g0Sq)/D1;
			b11 = 2*(gSq*betaSq - g0Sq)/D1;
			b12 = (gSq*betaSq  -  2*g*g0*s1*beta + g0Sq)/D1;
			b13 = 0;
			b14 = 0;
			a11 = 2*(betaSq - 1)/D1;
			a12 = (betaSq - 2*s1*beta + 1)/D1;
			a13 = 0;
			a14 = 0;

			break;
		}

		
		case 1: // bandpass
		{
			// Approx two octave bandwidth
			if (Wc < 0.025)
			{
				Wc = 0.025;
			}
			W0 = Wc;
			W1 = Wc/2;
			float tanSq = tan(Wc/2)*tan(Wc/2);
			W2 = 2*atan(tanSq / tan(W1/2));
			dW = W2 - W1;

			beta = pow(epsilon,-1.0f/N) * tanf(dW/2);
			betaSq = beta*beta;

			c0 = cos(W0);
			c0Sq = c0*c0;

			// second order section coefficients
			D0 = beta + 1;
			b00 = (g0 + g*beta)/D0;
			b01 =  -2*g0*c0/D0;
			b02 = (g0 - g*beta)/D0;
			a01 =  -2*c0/D0;
			a02 = (1 - beta)/D0;

			// fourth order section coefficients
			D1 = betaSq + 2*s1*beta + 1;
			b10 = (gSq*betaSq + 2*g*g0*s1*beta + g0Sq)/D1;
			b11 =  -4*c0*(g0Sq + g*g0*s1*beta)/D1;
			b12 = 2*(g0Sq*(1 + 2*c0Sq) - gSq*betaSq)/D1;
			b13 =  -4*c0*(g0Sq - g*g0*s1*beta)/D1;
			b14 = (gSq*betaSq - 2*g*g0*s1*beta + g0Sq)/D1;
			a11 =  - 4*c0*(1 + s1*beta)/D1;
			a12 = 2*(1 + 2*c0Sq - betaSq)/D1;
			a13 =  -4*c0*(1 - s1*beta)/D1;
			a14 = (betaSq - 2*s1*beta + 1)/D1;

			break;
		}

			
		case 2: // highpass filter
		{
			W0 = PI;
			W1 = Wc;
			W2 = PI;
			dW = W2 - W1;

			beta = pow(epsilon,-1.0f/N) * tanf(dW/2);
			betaSq = beta*beta;

			c0 = cos(W0);
			c0Sq = c0*c0;

			// Highpass second order section
			D0 = beta + 1;
			b00 = (g*beta + g0)/D0;
			b01 = -(g*beta - g0)/D0;
			b02 = 0;
			a01 = -(beta - 1)/D0;
			a02 = 0;

			// Highpass fourth order section
			D1 = betaSq + 2*s1*beta + 1;
			b10 = (gSq*betaSq + 2*g*g0*s1*beta + g0Sq)/D1;
			b11 = -2*(gSq*betaSq - g0Sq)/D1;
			b12 = (gSq*betaSq  -  2*g*g0*s1*beta + g0Sq)/D1;
			b13 = 0;
			b14 = 0;
			a11 = -2*(betaSq - 1)/D1;
			a12 = (betaSq - 2*s1*beta + 1)/D1;
			a13 = 0;
			a14 = 0;

			break;
		}

		default:
			break;
	}

	// Resonator bandwidth
	// fixed ratio to gain to keep shape of resonator as gain changes
	dWr = 0.01 * G;

	
	// betaR = sqrt((Gbr*Gbr - G0*G0)/(Gr*Gr - Gbr*Gbr))*tanf(dWr/2); //LF rev: removed 
	
	c0r = cos(Wc); // LF rev: added

	b20 = (G0r + Gr*betaR)/(1 + betaR);
	b21 = -2*(G0r*c0r/(1 + betaR));
	b22 = (G0r - Gr*betaR)/(1 + betaR);
	a20 = 1;
	a21 = -2*c0r/(1 + betaR);
	a22 = (1 - betaR)/(1 + betaR);
}


//==============================================================================
// LF rev: added Set frequency modulation
void tinySynthFilter::setEnvModDepth(float modulation)
{
	this->EnvModDepth = modulation;	
}

//==============================================================================
// LF rev: added ADSR and LFO frequency modifications
// LF rev: removed buffer loop process in favor of a single sample process
float tinySynthFilter::singleSample(float input, float newFrequency, float newResonance, ADSR* envelope, LFO *lfo) noexcept
{
	//****** START <LFO handling> ******//
	float vibratoTick = 1.0f;
	if (lfo->Destination != 0  && lfo->Depth > 0.1f)
	{
		const float normDepth = lfo->Depth/10; // because the Depth parameter goes up to 10
		if(lfo_.Frequency != lfo->Frequency)
			modulateLfo.setVibratoRate(lfo->Frequency);
		if(lfo_.Depth != lfo->Depth)
			modulateLfo.setVibratoGain(normDepth); 
		if(lfo_.Wave != lfo->Wave)
			modulateLfo.setWaveform(lfo->Wave); // 0 = sine, 1 = Saw, 2 = Square

		//memories for switches above
		lfo_.Frequency = lfo->Frequency;
		lfo_.Depth = lfo->Depth;
		lfo_.Wave = lfo->Wave;
		lfo_.Destination = lfo->Destination;

		// vibratoTick assumes values between the range 0.0f and 1.0f acc
		vibratoTick = 0.5f*(1.0f-normDepth)+0.5f*(1.0f+modulateLfo.tick()); 
	}
	//****** END <LFO handling> ******//


	//****** START <ADSR handling> ******//
	if(envelope) // the pointer must never be zero
	{
		const float parChange = this->EnvModDepth; // range -1.0..+1.0
		float newFrequencyChange = newFrequency;

		if(parChange > 0.0f)
		{ newFrequencyChange = newFrequency*parChange*envelope->tick()+0.008f; }
		else if(parChange < 0.0f)	
		{ newFrequencyChange = newFrequency + newFrequency*parChange*envelope->tick()+0.008f; }

		if (lfo->Depth > 0.1f)
		{
			newFrequencyChange = newFrequencyChange*vibratoTick;
		}

		newFrequencyChange = (newFrequencyChange > 1.5f)? 1.5f : newFrequencyChange;
		newFrequencyChange = (newFrequencyChange < 0.008f)? 0.008f : newFrequencyChange;

		oldFrequency = 0.999f*oldFrequency + 0.001f*newFrequencyChange; // smoothing
		oldFrequency = (oldFrequency<1.0E-24f)? 1.0E-24f : oldFrequency; // float safety
		this->Wc = oldFrequency; Wc = (Wc<1.0E-24f)? 1.0E-24f : Wc; // float safety
		this->Gr = newResonance * G * 0.2f; // scaling for knob
		this->updateFilter();	
	}
	//****** END <ADSR handling> ******//


	// Get data 
	const float x00 = input+1.0E-24f;

	// second order section
	float y00 = b00 * x00
		+ b01 * x01
		+ b02 * x02
		- a01 * y01
		- a02 * y02;

	// Update internal states
	x02 = x01;
	x01 = x00;

	y02 = y01;
	y01 = y00;


	const float w10 = y00
		- a11 * w11
		- a12 * w12
		- a13 * w13
		- a14 * w14;

	float y10 = b10 * w10
		+ b11 * w11
		+ b12 * w12
		+ b13 * w13
		+ b14 * w14;

	// Update internal states
	w14 = w13;
	w13 = w12;
	w12 = w11;
	w11 = w10;

	// resonator section
	const float x20 = y10;

	float y20 = tanh(b20 * x20 // LF rev: become function of tanh
		+ b21 * x21
		+ b22 * x22
		- a21 * y21
		- a22 * y22);

	// Update internal states
	x22 = x21;
	x21 = x20;

	y22 = y21;
	y21 = y20;

	return y20-1.0E-24f;
}
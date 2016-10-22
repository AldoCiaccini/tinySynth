/*
==============================================================================
tinySynthLFO.h - header file for tinySynthLFO.cpp
Copyright (C) 2016 Aldo Ciaccini

Description:
tinySynthLFO implements a low frequency generator used to generate the
vibrato and tremolo effects inside the tinySynthOscillator class.
The LFO waveform type is based on the STK SineWave class and the internal
NaiveSaw and NaiveSquare classes.
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
STK LICENSE:

STK WWW site: http://ccrma.stanford.edu/software/stk/

The Synthesis ToolKit in C++ (STK)
Copyright (c) 1995-2011 Perry R. Cook and Gary P. Scavone

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

Any person wishing to distribute modifications to the Software is
asked to send the modifications to the original developer so that they
can be incorporated into the canonical version.  This is, however, not
a binding provision of this license.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
==============================================================================
*/


#ifndef tinySynthLFO_h
#define tinySynthLFO_h

#include "Generator.h"
#include "SineWave.h"
#include "Noise.h"
#include "OnePole.h"

namespace stk {

	/** \class tinySynthLFO
	 *  \brief This class implements the baseline LFO belonging to the tinySynth synthesizer 
	 *  \details tinySynthLFO implements a low frequency generator used to generate the
	 *  vibrato and tremolo effects inside the tinySynthOscillator class.\n
	 *  Three types of waveforms can be selected: 
	 * - Sine:  by using the STK SineWave class.  the output values are linear interpolated from a static sine "table"\n
	 * - Saw:  by using the internal NaiveSaw class 
	 * - Square: by using the internal NaiveSaw class 

	 */
	class tinySynthLFO : public Generator
	{
	public:
		tinySynthLFO( void ); /**< \brief class constructor. */ 
		~tinySynthLFO( void ); /**< \brief class deconstructor. */ 
		void reset( void ); /**< \brief reset internal state. */ 
		void setVibratoRate( StkFloat rate ); /**< \brief set the periodic rate or frequency in Hz. */ 
		void setVibratoGain( StkFloat gain ); /**< \brief set the periodic  gain. */ 
		void setWaveform( int wave );  /**< \brief set the waveform  type. */
		StkFloat lastOut( void ) const; /**< \brief return the last computed output value. */
		StkFloat tick( void ); /**< \brief compute and return one output sample. */
		StkFrames& tick( StkFrames& frames, unsigned int channel = 0 ); /**< \brief Fill a channel of the StkFrames object with computed outputs. */

	/** \enum Waves
	 *  \brief Three LFO modulation types are foreseen  
	 */
	enum Waves
	{
		sine_wave=0,
		saw_wave,
		square_wave
	};
		
	protected:
		/** \class NaiveSquare
		 *  \brief This class generates a saw waveform 
		 *  \details The class has been optimized for LFO aplication.\n
		 * The ouput values of square waveform are generated between -1.0f, 1.0f with a duty cyle of 50%\n
		 * and a minimum accepted sample rates of 32KS/s.
		 */

		class NaiveSquare
		{
		public:   
			NaiveSquare() 
			{
				samplePerCycle = 200.0f;
				iPhase = 0.0f;
			} /**< \brief class constructor. */ 

			void setFrequency( StkFloat frequency ) 
			{
				float sr = Stk::sampleRate();
				if (sr < 32000.0f) 
					sr = 32000.0f;
				if (frequency < 0.0001f) 
					frequency = 0.0001f; // safety
				samplePerCycle = Stk::sampleRate()/frequency;
			} /**< \brief set frequency of Square waveform (Hz). */ 

			StkFloat  tick() 
			{
				if((iPhase++) < samplePerCycle*0.5f)
					return 1.0f;
				else
				{
					if(iPhase >= samplePerCycle) 
						iPhase = 0.0f;
					return -1.0f;
				}
			} /**< \brief Compute and return one output sample  */ 

		protected:
			StkFloat iPhase;
			StkFloat samplePerCycle;
		};

		/** \class NaiveSaw
		 *  \brief This class generates a saw waveform. 
		 *  \details The class has been optimized for LFO aplication.\n
		 * The ouput values of saw waveform are generated between -1.0f, 1.0f with a minimum accepted sample rates of 32KS/s.
		 */
		class NaiveSaw
		{
		public:   
			NaiveSaw() 
			{
				samplePerCycle = 200.0f;
				iPhase = 0.0f;
			} /**< \brief class constructor. */ 
	
			void setFrequency( StkFloat frequency ) 
			{
				float sr = Stk::sampleRate();
				if (sr < 32000.0f) 
					sr = 32000.0f;
				if (frequency < 0.0001f) 
					frequency = 0.0001f; // safety
				samplePerCycle = Stk::sampleRate()/frequency;
				if (samplePerCycle < 0.00000001f) 
					samplePerCycle = 0.00000001f; // safety
				inc = 2.0f/samplePerCycle;
			} /**< \brief et frequency of Saw waveform (Hz). */ 
			
			StkFloat  tick() 
			{
				iPhase += inc;
				if (iPhase > 2.0f) 
					iPhase = 0.0f;
				return iPhase-1.0f;
			} /**< \brief Compute and return one output sample  */ 

		protected:
			StkFloat iPhase; 
			StkFloat inc;
			StkFloat samplePerCycle;
		};


	
		SineWave vibratoSine_;
		NaiveSaw vibratoSaw_;
		NaiveSquare vibratoSquare_;
		StkFloat vibratoGain_;
		int waveform_;

	};

	inline StkFloat tinySynthLFO :: tick( void ) 
	{
		// Compute periodic and random modulations.
		switch (waveform_)
		{
		case sine_wave:
			lastFrame_[0] = vibratoGain_ * vibratoSine_.tick();
			break;
		case saw_wave:
			lastFrame_[0] = vibratoGain_ * vibratoSaw_.tick();
			break;
		case square_wave:
			lastFrame_[0] = vibratoGain_ * vibratoSquare_.tick();
			break;
		}
		return lastFrame_[0];
	}

	inline StkFrames& tinySynthLFO :: tick( StkFrames& frames, unsigned int channel ) 
	{
		StkFloat *samples = &frames[channel];
		unsigned int hop = frames.channels();
		for ( unsigned int i=0; i<frames.frames(); i++, samples += hop )
			*samples = tinySynthLFO::tick();
		return frames;
	}

} // stk namespace

#endif

/*
==============================================================================
tinySynthLFO.cpp - Copyright (C) 2016 Aldo Ciaccini

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

#include "tinySynthLFO.h"

namespace stk {

// constructor class.
tinySynthLFO :: tinySynthLFO( void )
{
	// Init internal variables
	vibratoSine_.setFrequency( 6.0 );
	vibratoSaw_.setFrequency( 6.0 );
	vibratoSquare_.setFrequency( 6.0 );
	vibratoGain_ = 0.04;
	waveform_ = sine_wave;

	Stk::addSampleRateAlert( this );
}

// deconstructor class.
tinySynthLFO :: ~tinySynthLFO( void )
{  
	Stk::removeSampleRateAlert( this ); 
}


//reset internal state.
void tinySynthLFO::reset( void ) 
{ 
	lastFrame_[0] = 0.0; 
} 

// Set the periodic rate or frequency in Hz.
void tinySynthLFO::setVibratoRate( StkFloat rate )
{ 
	switch (waveform_)
	{ 
	case sine_wave:
		vibratoSine_.setFrequency( rate ); 
		break;
	case saw_wave:
		vibratoSaw_.setFrequency( rate ); 
		break;
	case square_wave:
		vibratoSquare_.setFrequency( rate ); 
		break;
	} 
}


// set the periodic  gain
void tinySynthLFO::setVibratoGain( StkFloat gain ) 
{ 
	vibratoGain_ = gain;
}

// set the waveform  type
void tinySynthLFO::setWaveform( int wave ) 
{ 
	waveform_ = wave;
}

// return the last computed output value.
StkFloat tinySynthLFO::lastOut( void ) const 
{ 
	return lastFrame_[0];
}

} // stk namespace

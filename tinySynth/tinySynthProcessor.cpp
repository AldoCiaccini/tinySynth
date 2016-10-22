/*
==============================================================================

This file was auto-generated!

It contains the basic startup code for a Juce application.

==============================================================================
*/

#include "tinySynthProcessor.h"
#include "tinySynthEditor.h"

//==============================================================================
tinySynthAudioProcessor::tinySynthAudioProcessor()
: delayBuffer(1,1)
{
	// Initialize tinySynthAudioProcessor internal parameters
	//****** START <Init oscillators internal parameters> ******//
	setParameterNotifyingHost(osc1WaveParam, 2.0f);
	setParameterNotifyingHost(osc2WaveParam, 2.0f);
	setParameterNotifyingHost(osc3WaveParam, 2.0f);

	setParameterNotifyingHost(osc1OctaveParam, 2.0f);
	setParameterNotifyingHost(osc2OctaveParam, 3.0f);
	setParameterNotifyingHost(osc3OctaveParam, 2.0f);

	setParameterNotifyingHost(osc1LevelParam, 0.5f);
	setParameterNotifyingHost(osc2LevelParam, 0.5f);
	setParameterNotifyingHost(osc3LevelParam, 0.0f);

	setParameterNotifyingHost(osc1LfoParam, 0.0f);
	setParameterNotifyingHost(osc2LfoParam, 0.0f);
	setParameterNotifyingHost(osc3LfoParam, 0.0f);

	setParameterNotifyingHost(osc1EnvParam, 0.0f);
	setParameterNotifyingHost(osc2EnvParam, 1.0f);
	setParameterNotifyingHost(osc3EnvParam, 0.0f);

	setParameterNotifyingHost(osc1OnParam, 1.0f);
	setParameterNotifyingHost(osc2OnParam, 1.0f);
	setParameterNotifyingHost(osc3OnParam, 1.0f);

	setParameterNotifyingHost(osc1SemiToneParam, 0.0f);
	setParameterNotifyingHost(osc2SemiToneParam, 0.0f);
	setParameterNotifyingHost(osc3SemiToneParam, 0.0f);
	//****** END <Init oscillators internal parameters> ******//


	//****** START <Init ADSR internal parameters> ******//
	setParameterNotifyingHost(adsr1AttackParam, 0.01f);
	setParameterNotifyingHost(adsr1DecayParam, 0.5f);
	setParameterNotifyingHost(adsr1SustainParam, 10.0f);
	setParameterNotifyingHost(adsr1ReleaseParam, 0.1f);

	setParameterNotifyingHost(adsr2AttackParam, 0.5f);
	setParameterNotifyingHost(adsr2DecayParam, 0.5f);
	setParameterNotifyingHost(adsr2SustainParam, 5.0f);
	setParameterNotifyingHost(adsr2ReleaseParam, 1.0f);

	setParameterNotifyingHost(adsr3AttackParam, 2.0f);
	setParameterNotifyingHost(adsr3DecayParam, 0.0f);
	setParameterNotifyingHost(adsr3SustainParam, 5.0f);
	setParameterNotifyingHost(adsr3ReleaseParam, 0.0f);
	//****** END <Init ADSR internal parameters> ******//

    //****** START <Init LFO internal parameters> ******//
	setParameterNotifyingHost(lfo1DestParam, 0.0f);
	setParameterNotifyingHost(lfo1WaveParam, 0.0f);
	setParameterNotifyingHost(lfo1FreqParam, 0.0f);
	setParameterNotifyingHost(lfo1DevParam, 0.0f);

	setParameterNotifyingHost(lfo2DestParam, 0.0f);
	setParameterNotifyingHost(lfo2WaveParam, 0.0f);
	setParameterNotifyingHost(lfo2FreqParam, 0.0f);
	setParameterNotifyingHost(lfo2DevParam, 0.0f);
	//****** END <Init LFO internal parameters> ******//

    //****** START <Init FILTER internal parameters> ******//
    setParameterNotifyingHost(filterSequenceParam, 1.0f); 

	setParameterNotifyingHost(filter1LfoParam, 0.0f); 
	setParameterNotifyingHost(filter1TypeParam, 3.0f);
	setParameterNotifyingHost(filter1CutoffParam, (float)(0.25 * PI));
	setParameterNotifyingHost(filter1ResonanceParam, 1.0f);
	setParameterNotifyingHost(filter1EnvModDepthParam, 0.0f);
	setParameterNotifyingHost(filter1EnvParam, 2.0f);

	setParameterNotifyingHost(filter2LfoParam, 0.0f); 
	setParameterNotifyingHost(filter2TypeParam, 3.0f);
	setParameterNotifyingHost(filter2CutoffParam, (float)(0.25 * PI));
	setParameterNotifyingHost(filter2ResonanceParam, 1.0f);
	setParameterNotifyingHost(filter2EnvModDepthParam, 0.0f);
	setParameterNotifyingHost(filter2EnvParam, 2.0f);
	//****** END <Init FILTER internal parameters> ******// 
	
    //****** START <Init DELAY internal parameters> ******//
	setParameterNotifyingHost(delayTimeParam, 0.0f);
	setParameterNotifyingHost(delayFeedbackParam, 0.0001f);
	setParameterNotifyingHost(delayGainParam, 0.0001f);
	setParameterNotifyingHost(delayOnParam, 0.0f);
    //****** END <Init DELAY internal parameters> ******//

	//****** START <Init REVERB internal parameters> ******//
	setParameterNotifyingHost(reverbDryWetParam, 0.5f);
	setParameterNotifyingHost(reverbSizeParam, 0.8f);
	setParameterNotifyingHost(reverbDampParam, 0.2f);
	setParameterNotifyingHost(reverbOnParam, 0.0f); 
    //****** END <Init REVERB internal parameters> ******//
    
    // Inizialize Drive parameter
	setParameterNotifyingHost(driveParam, 1.0f);
	
	// Inizialize Gain parameter
	setParameterNotifyingHost(outputGainParam, 0.25f); 

	// Inizialize number of voices parameter
	setParameterNotifyingHost(synthVoiceParam, 2.0f); 
	
	// Inizialize Noise parameter
	setParameterNotifyingHost(noiseParam, 0.0001f);

    //****** START <add sound and voices to the Synthesizer class> ******//
	tinySynth.allNotesOff(0,false);
	tinySynth.clearVoices();
	for (int numVoices = (getParameter(synthVoiceParam) + 1); --numVoices >= 0;)
	{
		// A reference to global parameters is passed to each
		// voice so that it can reference them locally. 
		tinySynth.addVoice (new tinySynthVoice(parameters));
	}
	tinySynth.addSound(new tinySynthSound());
	tinySynth.setNoteStealingEnabled(true); // to recyle voices
	UIUpdateFlag=true;
	//****** END <add voices and sound to the Synthesizer class> ******//
}

tinySynthAudioProcessor::~tinySynthAudioProcessor()
{
}

//==============================================================================
const String tinySynthAudioProcessor::getName() const
{
	return JucePlugin_Name;
}

//==============================================================================
int tinySynthAudioProcessor::getNumParameters()
{
	return totalNumParams;
}

//==============================================================================
float tinySynthAudioProcessor::getParameter (int index)
{
	return parameters[index];
}

//==============================================================================
void tinySynthAudioProcessor::setParameter (int index, float newValue)
{
	
	if(index == synthVoiceParam)
	{
		// reset voices and buffers to zero		
		tinySynth.allNotesOff(0,false);
		tinySynth.clearVoices();

		// add selected voices
		for (int numVoices = int(newValue+1.0f); --numVoices >= 0;) //menu index is zero for voices = 1 
		{
			// A reference to global parameters is passed to each
			// voice so that it can reference them locally. 
			tinySynth.addVoice (new tinySynthVoice(parameters));
		}
		tinySynth.setNoteStealingEnabled(true); // to recyle voices		
	}
	
	parameters[index] = newValue;
	UIUpdateFlag=true;
}

//==============================================================================
const String tinySynthAudioProcessor::getParameterName (int index)
{
	switch (index) 
	{
		// Oscillators
		case osc1WaveParam:		return "osc1Wave";
		case osc1OctaveParam:	return "osc1Octave";
		case osc1LevelParam:	return "osc1Level";
		case osc1LfoParam:		return "osc1Lfo";
		case osc1EnvParam:		return "osc1Env";
		case osc1SemiToneParam:		return "osc1SemiTone";

		case osc2WaveParam:		return "osc2Wave";
		case osc2OctaveParam:	return "osc2Octave";
		case osc2LevelParam:    return "osc2Level";
		case osc2LfoParam:		return "osc2Lfo";
		case osc2EnvParam:		return "osc2Env";
		case osc2SemiToneParam:		return "osc2SemiTone";

		case osc3WaveParam:     return "osc3Wave";
		case osc3OctaveParam:   return "osc3Octave";
		case osc3LevelParam:    return "osc3Level";
		case osc3LfoParam:		return "osc3Lfo";
		case osc3EnvParam:		return "osc3Env";
		case osc3SemiToneParam:		return "osc3SemiTone";

		// Envelopes
		case adsr1AttackParam:	return "adsr1Attack";
		case adsr1DecayParam:	return "adsr1Decay";
		case adsr1SustainParam:	return "adsr1Sustain";
		case adsr1ReleaseParam:	return "adsr1Release";

		case adsr2AttackParam:	return "adsr2Attack";
		case adsr2DecayParam:	return "adsr2Decay";
		case adsr2SustainParam:	return "adsr2Sustain";
		case adsr2ReleaseParam:	return "adsr2Release";

		case adsr3AttackParam:	return "adsr3Attack";
		case adsr3DecayParam:	return "adsr3Decay";
		case adsr3SustainParam:	return "adsr3Sustain";
		case adsr3ReleaseParam:	return "adsr3Release";

		// LFO
		case lfo1DestParam:		return "lfo1Dest";
		case lfo1WaveParam:		return "lfo1Wave";
		case lfo1FreqParam:		return "lfo1Freq";
		case lfo1DevParam:		return "lfo1Dev";

		case lfo2DestParam:     return "lfo2Dest";
		case lfo2WaveParam:     return "lfo2Wave";
		case lfo2FreqParam:     return "lfo2Freq";
		case lfo2DevParam:      return "lfo2Dev";

		// Filters 
		case filterSequenceParam:   return "filterSequence";
		case filter1LfoParam:       return "filter1Lfo";
		case filter1TypeParam:      return "filter1Type";
		case filter1CutoffParam:    return "filter1Cutoff";
		case filter1ResonanceParam: return "filter1Resonance";
		case filter1EnvModDepthParam:       return "filter1EnvModDepth";
		case filter1EnvParam:       return "filter1Env";

		case filter2LfoParam:       return "filter2Lfo";
		case filter2TypeParam:      return "filter2Type";
		case filter2CutoffParam:    return "filter2Cutoff";
		case filter2ResonanceParam: return "filter2Resonance";
		case filter2EnvModDepthParam:       return "filter2EnvModDepth";
		case filter2EnvParam:       return "filter2Env";

		// delay
		case delayTimeParam:        return "delayTime";
		case delayFeedbackParam:    return "delayFeedback";
		case delayGainParam:        return "delayGain";
		case delayOnParam:			return "delayOn";

		// reverb
		case reverbDryWetParam:     return "reverbDryWet";
		case reverbSizeParam:		return "reverbSize";
		case reverbDampParam:       return "reverbDamp";
		case reverbOnParam:			return "reverbOn";

		// output
		case noiseParam:            return "noiseGain";
		case driveParam:            return "drive";
		case outputGainParam:       return "outputGain";
	
		case synthVoiceParam:       return "synthVoice";

		default:                    break;
	}
	return String::empty;
}

//==============================================================================
const String tinySynthAudioProcessor::getParameterText (int index)
{
	return String (getParameter (index), 2);
}

//==============================================================================
const String tinySynthAudioProcessor::getInputChannelName (int channelIndex) const
{
	return String (channelIndex + 1);
}

//==============================================================================
const String tinySynthAudioProcessor::getOutputChannelName (int channelIndex) const
{
	return String (channelIndex + 1);
}

//==============================================================================
bool tinySynthAudioProcessor::isInputChannelStereoPair (int index) const
{
	return true;
}

//==============================================================================
bool tinySynthAudioProcessor::isOutputChannelStereoPair (int index) const
{
	return true;
}

//==============================================================================
bool tinySynthAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
	return true;
#else
	return false;
#endif
}

//==============================================================================
bool tinySynthAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
	return true;
#else
	return false;
#endif
}

//==============================================================================
bool tinySynthAudioProcessor::silenceInProducesSilenceOut() const
{
	return false;
}

//==============================================================================
double tinySynthAudioProcessor::getTailLengthSeconds() const
{
	return 0.0;
}


//==============================================================================
int tinySynthAudioProcessor::getNumPrograms()
{
	return 0;
}

//==============================================================================
int tinySynthAudioProcessor::getCurrentProgram()
{
	return 0;
}

//==============================================================================
void tinySynthAudioProcessor::setCurrentProgram (int index)
{
}

//==============================================================================
const String tinySynthAudioProcessor::getProgramName (int index)
{
	return String::empty;
}

//==============================================================================
void tinySynthAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================

void tinySynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
/*
The prepareToPlay() initializes the internal resources of the tinySynthAudioProcessor.
The sampleRate is the target sample rate, and will remain constant until playback stops.
The samplesPerBlock value is a strong hint about the maximum number of samples that will be provided in each block.
*/
	// Set sample rate for both tinySynth Synthesizer, reverb module and STK modules.
	tinySynth.setCurrentPlaybackSampleRate(sampleRate);
	Stk::setSampleRate(sampleRate);

	reverb.setSampleRate(sampleRate);


	//init reverb variables
	reverbSize = reverbDamp = reverbDryWet = 0.0f;

	// clear the delayBuffer used for the delay unit.
	delayBuffer.clear();
}

//==============================================================================
void tinySynthAudioProcessor::releaseResources()
{
	// When playback stops, you can use this as an opportunity to free up any
	// spare memory, etc.
}

//==============================================================================
void tinySynthAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
/* 
The processBlock() is called continuosly by the DAW every time there are new audio samples or MIDI messages to be processed.
The RAM for AudioSampleBuffer& buffer is allocated by DAW and its size could differs between two callbacks.
The buffer contains the sufficient space for all the channels that the plugin is using. 
Its maximum size is provided by DAW when it calls the prepareToPlay() method. 
The buffer will be filled with the plugin outputs. 
The midiMessages inform the plugin about the pressed notes.
The processBlock() is composed by three main blocks:
	1) VOICEs RENDERING: the rendering process is completely perfomed inside the tinySynth.renderNextBlock()
	2) SOUND RENDERING: the sound is processed inside the buffer loop in term of: Delay , Drive and Reverb
	3) GAIN RENDERING: the Gain is applied and the the buffer is copied on the second channel
*/

	// Get number of samples in the current buffer
	const int numSamples = buffer.getNumSamples();

//****** START < 1) VOICEs RENDERING> ******//
	/* 
	The buffer is filled summing the contribution of all voices.
	For each voice the audio output is generated by three indipendent Oscillators, and according to:\n
		- oscillator parameters: waveform type, frequency, octave and gain
		- LFO effects: vibrato and tremolo effects
		- ADSR modifications: attach, decay, release and sustain
		- Filters parameters: filtering and routing modifications
		- Noise level
	*/
	tinySynth.renderNextBlock(buffer, midiMessages, 0, numSamples);
//****** END < 1) VOICEs RENDERING> ******//


//****** START < 2) SOUND RENDERING> ******//
	//****** START <DELAY: handling of delayBuffer size> ******//
	bool bDelayFXisON = getParameter(delayOnParam) && getParameter(delayGainParam)> 0.01f;
	if(bDelayFXisON)
	{
		/* 
		Checks to see if delay size has changed since the last block. If it has,
		the delay buffer is resized and cleared (to prevent garbage in the output)
		The read and write pointers are also reset to their starting positions and
		the saved filter states are removed to reduce transients.
		delayTimeParam controlled by tinySynthEditor::delayTimeSlider
		*/
		if (delayBuffer.getNumSamples() != getParameter(delayTimeParam) + numSamples)
		{
			delayBuffer.setSize(1, getParameter(delayTimeParam) + numSamples);
			delayBuffer.clear();
			delayWritePtr =  delayBuffer.getSampleData(0) + (int) getParameter(delayTimeParam);
			delayReadPtr = delayBuffer.getSampleData(0);
		}
	}
	//****** END <<DELAY: handling of delayBuffer size> ******//

	//****** START <REVERB: handling of reverb parameters > ******//
	if(getParameter(reverbDampParam) != reverbDamp || getParameter (reverbSizeParam) != reverbSize || getParameter (reverbDryWetParam) != reverbDryWet)
	{
		// For performance improving the reverb class is updated only when necessary
		reverbDamp = getParameter(reverbDampParam);   reverbSize = getParameter (reverbSizeParam);    reverbDryWet = getParameter (reverbDryWetParam); 		
		

		Reverb::Parameters reverb_param;
		reverb_param.damping = 2.0f - 2.0f * reverbDamp;
		reverb_param.roomSize = reverbSize;
		reverb_param.wetLevel = 0.9f * reverbDryWet;
		reverb_param.dryLevel = 1.0f - 0.9f * reverbDryWet;
		reverb_param.width = 1.0f;
		reverb_param.freezeMode = 0;
		reverb.setParameters(reverb_param);

	}
	//****** END <REVERB: handling of reverb parameters > ******//

	//****** START <sound processing loop> ******//
	// Pointer to beginning of buffer
	float* bufferPtr = buffer.getSampleData(0, 0);
	for (int currentSample = 0; currentSample < numSamples; ++currentSample)
	{	
		//****** START <<apply DRIVE> ******/
		if(getParameter(driveParam) > 1.00001f)
		{
			*bufferPtr = 2.0f*tanhf(2.5f*getParameter(driveParam) * *bufferPtr)/(2.5f*getParameter(driveParam)); // driveParam is controlled by tinySynthEditor::driveSlider
		}
		//****** END <<apply DRIVE> ******/

		//****** START <<apply REVERB> ******//
		bool bReverbFXisON = getParameter(reverbOnParam); // // reverbOnParam is controlled by tinySynthEditor::reverbOnSW
		if(bReverbFXisON)
		{	
			reverb.processMono(bufferPtr, 1);
		}
		//****** END <<apply REVERB> ******//

		//****** START <<apply DELAY> ******//
		if(bDelayFXisON)
		{	
			const float input = *bufferPtr;
			*bufferPtr = input + input*getParameter(delayGainParam);

			// Add existing delay data into buffer
			*bufferPtr += getParameter(delayFeedbackParam) * *delayReadPtr; // delayFeedbackParam is controlled by tinySynthEditor::delayFBSlider

			// Save current output data into delay buffer
			*delayWritePtr = *bufferPtr;

			// Increment pointers
			delayWritePtr++;
			delayReadPtr++;

			// Circular buffer implementation: reset pointers to beginning of buffers when end is reached
			if (delayReadPtr > delayBuffer.getSampleData(0) + delayBuffer.getNumSamples())
			{
				delayReadPtr = delayBuffer.getSampleData(0);
			}

			if (delayWritePtr > delayBuffer.getSampleData(0) + delayBuffer.getNumSamples())
			{
				delayWritePtr = delayBuffer.getSampleData(0);
			}
		}
		//****** END <<apply DELAY> ******//
		
		bufferPtr++;// Increment pointer
	}
	//****** END <sound processing loop> ******//


//****** END < 2) SOUND RENDERING > ******//

//****** START < 3) GAIN  > ******//
	// Apply overall output gain to buffer before playback
	buffer.applyGain(pow(10, 0.05* getParameter(outputGainParam))); // outputGainParam is controlled by tinySynthEditor::outputGainSlider
	
	// All processing happens in only one channel for speed; the other channel is filled here.
	buffer.addFrom(1, 0, buffer, 0, 0, numSamples);

	//In case we have more outputs than inputs, we'll clear any output
	//channels that didn't contain input data, (because these aren't
	//guaranteed to be empty - they may contain garbage).
	for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
	{
		buffer.clear (i, 0, buffer.getNumSamples());
	}
//****** END < 3) GAIN  > ******//
}

//==============================================================================
bool tinySynthAudioProcessor::hasEditor() const
{
	return true; // (change this to false if you choose to not supply an editor)
}

//==============================================================================
AudioProcessorEditor* tinySynthAudioProcessor::createEditor()
{
	return new tinySynthAudioProcessorEditor (this);
}

//==============================================================================
void tinySynthAudioProcessor::getStateInformation (MemoryBlock& destData)
{
	/*
	The host will call this method when it wants to save the plugin's internal state.
	getStateInformation() stores all parameters[] in the memory block.
	All parameters[] are saved as a CVS string inside the XML element named "AllUserParam"
	*/

	for(int i = 0; i < totalNumParams; i++)
		parameters[i] = getParameter(i);
	XmlElement root("Root");
	XmlElement *el = root.createNewChildElement("AllUserParam");
	el->addTextElement(String(copyParametersIntoCSVString()));
	copyXmlToBinary(root, destData);
}


//==============================================================================
void tinySynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
	/*
	The host will call this method if it wants to restore the state of just the plugin's current program.
	setStateInformation() restores the parameters[] from the data memory block,
	whose contents will have been created by the getStateInformation() call and stored
	inside XML tag named "AllUserParam"
	*/
	XmlElement* pRoot = getXmlFromBinary(data, sizeInBytes);
	if (pRoot != NULL)
	{
		forEachXmlChildElement((*pRoot), pChild)
		{
			if (pChild->hasTagName("AllUserParam"))
			{
				String sFloatCSV = pChild->getAllSubText();
				setParametersFromCSVString (sFloatCSV);
			}
		}
		delete pRoot;
		UIUpdateFlag = true;
	}

}

//==============================================================================
String tinySynthAudioProcessor::copyParametersIntoCSVString()
{
	/*
	copyParametersIntoCSVString() copies the values of all parameters[] 
	inside a String formatted as a comma-separated value
	*/
	String result = "";
	for (int i = 0; i < (totalNumParams - 1); i++) 
		result << String(getParameter(i)) << ",";
	result << String(getParameter(totalNumParams - 1));
	return result;
}

//==============================================================================
int tinySynthAudioProcessor::setParametersFromCSVString (String sFloatCSV)
{
	/*
	setParametersFromCSVString() restores the values for all parameters[] 
	from a String formatted as a comma-separated value
	*/
	StringArray Tokenizer;
	Tokenizer.addTokens(sFloatCSV, ",", "");
	for(int i = 0; i < totalNumParams; i++) 
		setParameter (i, Tokenizer[i].getFloatValue());
	return (totalNumParams);
}

//==============================================================================
String tinySynthAudioProcessor::formatParametersIntoString()
{
	float * p =  parameters;
	char buffer[200];
	
	String result = "";
	
	sprintf(buffer,"OSC 1-> Wave:%0.2f, Octave:%0.2f, SemiTone: %0.2f, Level:%0.2f, LFO:%0.2f, ADSR:%0.2f, On:%0.2f\n",  
		p[osc1WaveParam], p[osc1OctaveParam], p[osc1SemiToneParam],  p[osc1LevelParam], p[osc1LfoParam], p[osc1EnvParam], p[osc1OnParam]);
	result << buffer;
	sprintf(buffer,"OSC 2-> Wave:%0.2f, Octave:%0.2f, SemiTone: %0.2f, Level:%0.2f, LFO:%0.2f, ADSR:%0.2f, On:%0.2f\n",  
		p[osc2WaveParam], p[osc2OctaveParam], p[osc2SemiToneParam], p[osc2LevelParam], p[osc2LfoParam], p[osc2EnvParam], p[osc2OnParam]);
	result << buffer;
	sprintf(buffer,"OSC 3-> Wave:%0.2f, Octave:%0.2f, SemiTone: %0.2f, Level:%0.2f, LFO:%0.2f, ADSR:%0.2f, On:%0.2f\n",  
		p[osc3WaveParam], p[osc3OctaveParam], p[osc3SemiToneParam], p[osc3LevelParam], p[osc3LfoParam], p[osc3EnvParam], p[osc3OnParam]);
	result << buffer;
	  	
	sprintf(buffer,"FIL  -> Sequence:%0.2f\n",  p[filterSequenceParam]);
	result << buffer;
	sprintf(buffer,"FIL 1-> Type:%0.2f, Freq:%0.2f, Res:%0.2f, Mod. Depth:%0.2f, ADSR:%0.2f, LFO:%0.2f\n",  
		p[filter1TypeParam], p[filter1CutoffParam], p[filter1ResonanceParam], p[filter1EnvModDepthParam], 
		p[filter1EnvParam], p[filter1LfoParam]);
	result << buffer;
    sprintf(buffer,"FIL 2-> Type:%0.2f, Freq:%0.2f, Res:%0.2f, Mod. Depth:%0.2f, ADSR:%0.2f, LFO:%0.2f\n",  
		p[filter2TypeParam], p[filter2CutoffParam], p[filter2ResonanceParam], p[filter2EnvModDepthParam], 
		p[filter2EnvParam], p[filter1LfoParam]);
	result << buffer;

	sprintf(buffer,"ENV 1-> A:%0.2f, D:%0.2f, S:%0.2f, R:%0.2f\n",  
		p[adsr1AttackParam], p[adsr1DecayParam], p[adsr1SustainParam], p[adsr1ReleaseParam]);
	result << buffer;
	sprintf(buffer,"ENV 2-> A:%0.2f, D:%0.2f, S:%0.2f, R:%0.2f\n",  
		p[adsr2AttackParam], p[adsr2DecayParam], p[adsr2SustainParam], p[adsr2ReleaseParam]);
	result << buffer;
	sprintf(buffer,"ENV 3-> A:%0.2f, D:%0.2f, S:%0.2f, R:%0.2f\n",  
		p[adsr3AttackParam], p[adsr3DecayParam], p[adsr3SustainParam], p[adsr3ReleaseParam]);
	result << buffer;

    sprintf(buffer,"LFO 1-> Dest:%0.2f, Wave:%0.2f, Freq:%0.2f, Depth:%0.2f\n",  
		p[lfo1DestParam], p[lfo1WaveParam], p[lfo1FreqParam], p[lfo1DevParam]);
	result << buffer;
	sprintf(buffer,"LFO 2-> Dest:%0.2f, Wave:%0.2f, Freq:%0.2f, Depth:%0.2f\n",  
		p[lfo2DestParam], p[lfo2WaveParam], p[lfo2FreqParam], p[lfo2DevParam]);
	result << buffer;

    sprintf(buffer,"DELAY-> Time:%0.2f, FB:%0.2f, Gain:%0.2f, On:%0.2f\n",  
		p[delayTimeParam], p[delayFeedbackParam], p[delayGainParam], p[delayOnParam]);
	result << buffer;
	
	sprintf(buffer,"REVERB-> DryWet:%0.2f, RoomSize:%0.2f, Damp:%0.2f, On:%0.2f\n",  
		p[reverbDryWetParam], p[reverbSizeParam], p[reverbDampParam], p[reverbOnParam]);
	result << buffer;

    sprintf(buffer,"OUPUT-> Noise:%0.2f, Drive:%0.2f, Gain:%0.2f\n",  
		p[noiseParam], p[driveParam], p[outputGainParam]);
	result << buffer;
        
	sprintf(buffer,"VOICE-> %0.2f\n",  p[synthVoiceParam]);
	result << buffer;

	return result;
}
//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new tinySynthAudioProcessor();
}

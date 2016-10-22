
/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef __PLUGINPROCESSOR_H_AEB64BCF__
#define __PLUGINPROCESSOR_H_AEB64BCF__

#include "tinySynth.h"

//==============================================================================
/** \class tinySynthAudioProcessor
 *  \brief this class handles in real-time the MIDI messages and generates the sound of VST instrument.\n 
 *  \details tinySynthAudioProcessor is the core class of tinySynth plug-in. It inherits form JUCE AudioProcessor class. \n
 * Its most notable methods are: \n
 * - prepareToPlay()\n
 * - processBlock()\n
 * - getParameter() and setParameter()\n <P>
 * The prepareToPlay() method initializes the audio resources when the plug-in is called from the first time by the DAW.\n
 * The processBlock() implements the sound of tinySynth plug-in. The DAW call continuosly the processBlock() 
 * passing a memory buffer and the MIDI messages generated from keyboard. The ProcessBlock() fills the memory 
 * buffer with the samples generated internally according to the DSP alghoritm.\n
 * The DAW plays the sound routing the stream of samples to the audio-board / speakers.\n
 * The getParameter() and setParameter() methods combined with the enum Parameters and the float array parameters[totalNumParams] 
 * provide a very reliable mechanism for storing parameters inside the AudioProcessor and synchronize their
 * representation and interaction inside the AudioProcessorEditor.
 */
 
class tinySynthAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    tinySynthAudioProcessor(); /**< \brief Class constructor*/
    ~tinySynthAudioProcessor(); /**< \brief Class deconstructor*/
    void prepareToPlay (double sampleRate, int samplesPerBlock); /**< \brief Called before playback starts, to let the plug-in prepare itself*/
    void releaseResources(); /**< \brief Called when playback stops, to let the plug-in deallocate its internal resources*/
	void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages); /**< \brief Called continuosly by the DAW every time there are new audio samples to be processed.*/
    float getParameter (int index); /**< \brief Returns the value inside parameters[index]*/
    void setParameter (int index, float newValue); /**< \brief Sets the newValue inside parameters[index]*/
    //==============================================================================
    AudioProcessorEditor* createEditor(); /**< \brief Creates the plugin's UI. */
    bool hasEditor() const;/**< \brief Return true if it can create an editor component. */
    const String getName() const;/**< \brief Returns the name of this processor. */
	int getNumParameters(); /**< \brief Returns the the number of parameters */
    const String getParameterName (int index); /**< \brief Returns the name of a particular parameter. */
    const String getParameterText (int index);  /**< \brief Returns the value of a parameter as a text string. */
    const String getInputChannelName (int channelIndex) const;/**< \brief Returns the names of all the available input channels on this device. */
    const String getOutputChannelName (int channelIndex) const;/**< \brief Returns the names of all the available output channels on this device. */
    bool isInputChannelStereoPair (int index) const;/**< \brief Returns true. */
    bool isOutputChannelStereoPair (int index) const;/**< \brief Returns true. */
    bool acceptsMidi() const; /**< \brief Returns true if the processor wants midi messages. */
    bool producesMidi() const;/**< \brief Returns true if the processor produces midi messages. */
	bool silenceInProducesSilenceOut() const;/**< \brief Returns true if a silent input always produces a silent output. */
    double getTailLengthSeconds() const;/**< \brief Returns the length of the filter's tail, in seconds. */
    int getNumPrograms();/**< \brief Returns the number of preset programs the filter supports. */
    int getCurrentProgram();/**< \brief Returns the number of the currently active program. */
    void setCurrentProgram (int index);/**< \brief Called by the host to change the current program. */
    const String getProgramName (int index);/**< \brief Must return the name of a given program. */
    void changeProgramName (int index, const String& newName);/**< \brief Called by the host to rename a program. */
    void getStateInformation (MemoryBlock& destData);/**< \brief The host will call this method when it wants to save the filter's internal state. */
    void setStateInformation (const void* data, int sizeInBytes);/**< \brief This must restore the filter's state from a block of data previously created using getStateInformation(). */
	//==============================================================================
 	bool NeedsUIUpdate(){return UIUpdateFlag;}; /**< \brief check if the UI must be updated */
	void RequestUIUpdate(){UIUpdateFlag=true;}; /**< \brief set a request for UI update */
	void ClearUIUpdateFlag(){UIUpdateFlag=false;}; /**< \brief clear pending request for UI update */
	String copyParametersIntoCSVString(); /**< \brief Copies all parameters[] values inside a comma-separated value string */
	int setParametersFromCSVString (String sFloatCSV); /**< \brief Restores all parameters[] values from a comma-separated value string */
	String formatParametersIntoString(); /**< \brief Prints parameters[] values inside a String for debug purposes*/
	//==============================================================================
	//Custom Methods, Params and Public Data 
	
	/** \enum Parameters
	*  \brief Parameters is an enumerative index used to get or set the float values of parameters[] array. \n
	* Each enumerative is associated with a correspondent UI object and its naming convention follows the rules:\n
	* - the intial part of the name for both enumerative and UI object is the same\n
	* - enumerative's name ends with "Param" \n
	* - UI name ends according to object type (i.e "Silder" for sliders, "Box" for boxes..)\n
	*/
	enum Parameters
    {
       
        // oscillators
		osc1WaveParam=0, osc1OctaveParam, osc1LevelParam, osc1LfoParam, osc1EnvParam, osc1OnParam, 
		osc2WaveParam, osc2OctaveParam, osc2LevelParam, osc2LfoParam, osc2EnvParam, osc2OnParam,
		osc3WaveParam, osc3OctaveParam, osc3LevelParam, osc3LfoParam, osc3EnvParam, osc3OnParam,

		// envelopes
        adsr1AttackParam, adsr1DecayParam, adsr1SustainParam, adsr1ReleaseParam,
        adsr2AttackParam, adsr2DecayParam, adsr2SustainParam, adsr2ReleaseParam,
		adsr3AttackParam, adsr3DecayParam, adsr3SustainParam, adsr3ReleaseParam,

        // LFOs
        lfo1DestParam, lfo1WaveParam, lfo1FreqParam, lfo1DevParam,

		lfo2DestParam, lfo2WaveParam, lfo2FreqParam, lfo2DevParam,
        
        // Filters 
        filter1TypeParam, filter1CutoffParam, filter1ResonanceParam, filter1EnvModDepthParam, filter1EnvParam,
		filter2TypeParam, filter2CutoffParam, filter2ResonanceParam, filter2EnvModDepthParam, filter2EnvParam,
       
        // delay
        delayTimeParam, delayFeedbackParam, delayGainParam, delayOnParam,
        
        // output
        noiseParam, driveParam,outputGainParam, 
		
		synthVoiceParam,
        
		// From here to be ordered by functionality
		
		//filter 
		filterSequenceParam, filter1LfoParam, filter2LfoParam,

		// reverb
		reverbDryWetParam, reverbSizeParam, reverbDampParam, reverbOnParam,

		//semitones
		osc1SemiToneParam, osc2SemiToneParam, osc3SemiToneParam,
        totalNumParams
    };

private: //Private Data, helper methods etc.
	
	/*
	The parameters[] array stores the values of the UI objects. 
	The values of UI objects are mantenied hooked with the ones in parameters[] by the tinySynthEditor (AudioProcessorEditor)
	The parameters values are used by tinySynthProcessor with the aim to controls its internal resources. 
	*/
	float parameters[totalNumParams];

	// Internal resources 
	Synthesiser tinySynth; // Synthetizer
	AudioSampleBuffer delayBuffer; 	float* delayWritePtr;   float* delayReadPtr; // Delay
	
	Reverb reverb; // Reverber by JUCE
	
	float gain;
	bool UIUpdateFlag;

	float reverbSize,reverbDamp, reverbDryWet;
	

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (tinySynthAudioProcessor);
};

#endif  // __PLUGINPROCESSOR_H_AEB64BCF__

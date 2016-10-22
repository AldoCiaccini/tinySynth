/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 4.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_F069AB87367C0D4C__
#define __JUCE_HEADER_F069AB87367C0D4C__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "tinySynthProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]

\class tinySynthAudioProcessorEditor
\brief tinySynthAudioProcessorEditor
\details tinySynthAudioProcessorEditor creates a graphical user interface for the plug-in.
This class inherits its  funcionalities from different public classes:
AudioProcessorEditor: Base class for the component that acts as the GUI for an AudioProcessor.
Timer: Makes repeated callbacks to the method timerCallBack() at a specified time interval (200ms).
SliderListener : A class for receiving callbacks from a Slider.
ComboBoxListener: A class for receiving callbacks from a ComboBox.
ButtonListener :A class for receiving callbacks from a ButtonListener
                                                                    //[/Comments]
*/
class tinySynthAudioProcessorEditor  : public AudioProcessorEditor,
                                       public Timer,
                                       public SliderListener,
                                       public ComboBoxListener,
                                       public ButtonListener
{
public:
    //==============================================================================
    tinySynthAudioProcessorEditor (tinySynthAudioProcessor* ownerFilter);
    ~tinySynthAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();  /**< for keeping the on-screen controls synchronized */
	tinySynthAudioProcessor* getProcessor() const {return static_cast <tinySynthAudioProcessor*> (getAudioProcessor());} /**< to access tinySynthAudioProcessor methods  */
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<GroupComponent> outputGroup;
    ScopedPointer<GroupComponent> lfoGroup5;
    ScopedPointer<GroupComponent> reverbGroup;
    ScopedPointer<GroupComponent> lfoGroup2;
    ScopedPointer<GroupComponent> lfoGroup3;
    ScopedPointer<GroupComponent> filterGroup;
    ScopedPointer<Slider> filter1EnvModDepthSlider;
    ScopedPointer<Slider> lfo1DevSlider;
    ScopedPointer<GroupComponent> oscGroup;
    ScopedPointer<Label> label21;
    ScopedPointer<Slider> adsr1SustainSlider;
    ScopedPointer<Slider> osc1lvlSlider;
    ScopedPointer<GroupComponent> delayGroup;
    ScopedPointer<Slider> delayFBSlider;
    ScopedPointer<Slider> delayGainSlider;
    ScopedPointer<Label> label8;
    ScopedPointer<Slider> adsr1DecaySlider;
    ScopedPointer<Slider> adsr1AttackSlider;
    ScopedPointer<Slider> delayTimeSlider;
    ScopedPointer<Label> label;
    ScopedPointer<Label> label2;
    ScopedPointer<Label> label3;
    ScopedPointer<Label> label4;
    ScopedPointer<Label> label5;
    ScopedPointer<Label> label6;
    ScopedPointer<Label> label7;
    ScopedPointer<Slider> noiseSlider;
    ScopedPointer<Slider> driveSlider;
    ScopedPointer<Slider> outputGainSlider;
    ScopedPointer<Label> label11;
    ScopedPointer<Label> label12;
    ScopedPointer<Label> label13;
    ScopedPointer<Slider> adsr1ReleaseSlider;
    ScopedPointer<ComboBox> osc3WaveBox;
    ScopedPointer<ComboBox> osc3OctaveBox;
    ScopedPointer<Label> label23;
    ScopedPointer<Label> label24;
    ScopedPointer<Label> label25;
    ScopedPointer<Label> label27;
    ScopedPointer<Label> label29;
    ScopedPointer<Slider> filter1FreqSlider;
    ScopedPointer<Label> label31;
    ScopedPointer<Label> label32;
    ScopedPointer<Label> label33;
    ScopedPointer<Slider> lfo1FreqSlider;
    ScopedPointer<ComboBox> lfo1WaveBox;
    ScopedPointer<ComboBox> lfo1DestBox;
    ScopedPointer<Label> label9;
    ScopedPointer<Slider> osc3lvlSlider;
    ScopedPointer<Slider> filter1ResSlider;
    ScopedPointer<ComboBox> filter1TypeBox;
    ScopedPointer<Label> label10;
    ScopedPointer<Label> label26;
    ScopedPointer<ComboBox> osc2WaveBox;
    ScopedPointer<ComboBox> osc2OctaveBox;
    ScopedPointer<Label> label14;
    ScopedPointer<Label> label15;
    ScopedPointer<Label> label16;
    ScopedPointer<Slider> osc2lvlSlider;
    ScopedPointer<Label> label17;
    ScopedPointer<ComboBox> osc1WaveBox;
    ScopedPointer<ComboBox> osc1OctaveBox;
    ScopedPointer<Label> label18;
    ScopedPointer<Label> label19;
    ScopedPointer<Label> label20;
    ScopedPointer<Slider> filter2EnvModDepthSlider;
    ScopedPointer<Slider> filter2FreqSlider;
    ScopedPointer<Label> label30;
    ScopedPointer<Label> label34;
    ScopedPointer<Label> label35;
    ScopedPointer<Slider> filter2ResSlider;
    ScopedPointer<ComboBox> filter2TypeBox;
    ScopedPointer<Label> label36;
    ScopedPointer<Slider> adsr2SustainSlider;
    ScopedPointer<Slider> adsr2DecaySlider;
    ScopedPointer<Slider> adsr2AttackSlider;
    ScopedPointer<Slider> adsr2ReleaseSlider;
    ScopedPointer<Slider> lfo2DevSlider;
    ScopedPointer<Label> label41;
    ScopedPointer<Label> label42;
    ScopedPointer<Label> label43;
    ScopedPointer<Slider> lfo2FreqSlider;
    ScopedPointer<ComboBox> lfo2WaveBox;
    ScopedPointer<ComboBox> lfo2DestBox;
    ScopedPointer<Label> label44;
    ScopedPointer<Slider> adsr3SustainSlider;
    ScopedPointer<Slider> adsr3DecaySlider;
    ScopedPointer<Slider> adsr3AttackSlider;
    ScopedPointer<Slider> adsr3ReleaseSlider;
    ScopedPointer<ComboBox> osc1LfoBox;
    ScopedPointer<Label> label49;
    ScopedPointer<ComboBox> osc1EnvBox;
    ScopedPointer<Label> label50;
    ScopedPointer<ComboBox> osc2LfoBox;
    ScopedPointer<Label> label51;
    ScopedPointer<ComboBox> osc2EnvBox;
    ScopedPointer<Label> label52;
    ScopedPointer<ComboBox> osc3LfoBox;
    ScopedPointer<Label> label53;
    ScopedPointer<ComboBox> osc3EnvBox;
    ScopedPointer<Label> label54;
    ScopedPointer<Label> label28;
    ScopedPointer<Label> label55;
    ScopedPointer<Label> label56;
    ScopedPointer<Label> label57;
    ScopedPointer<Label> label58;
    ScopedPointer<TextButton> saveTXT;
    ScopedPointer<TextButton> loadTXT;
    ScopedPointer<TextButton> checkP;
    ScopedPointer<TextEditor> presetName;
    ScopedPointer<ToggleButton> osc1On;
    ScopedPointer<ToggleButton> osc2On;
    ScopedPointer<ToggleButton> osc3On;
    ScopedPointer<ComboBox> synthVoiceBox;
    ScopedPointer<Label> label59;
    ScopedPointer<ToggleButton> delayOnSw;
    ScopedPointer<ComboBox> filter2EnvBox;
    ScopedPointer<Label> label60;
    ScopedPointer<ComboBox> filter1EnvBox;
    ScopedPointer<Label> label61;
    ScopedPointer<ComboBox> filter1LfoBox;
    ScopedPointer<Label> label62;
    ScopedPointer<ComboBox> filterSequenceBox;
    ScopedPointer<Label> label63;
    ScopedPointer<ComboBox> filter2LfoBox;
    ScopedPointer<Label> label64;
    ScopedPointer<Label> label65;
    ScopedPointer<Label> label66;
    ScopedPointer<Label> label37;
    ScopedPointer<Label> label38;
    ScopedPointer<Label> label39;
    ScopedPointer<Label> label40;
    ScopedPointer<Label> label45;
    ScopedPointer<Label> label46;
    ScopedPointer<Label> label47;
    ScopedPointer<Label> label48;
    ScopedPointer<Label> label67;
    ScopedPointer<Label> label68;
    ScopedPointer<Label> label22;
    ScopedPointer<Label> label69;
    ScopedPointer<Label> label70;
    ScopedPointer<Slider> reverbDryWetSlider;
    ScopedPointer<Label> label72;
    ScopedPointer<Slider> reverbSizeSlider;
    ScopedPointer<Label> label73;
    ScopedPointer<Slider> reverbDampSlider;
    ScopedPointer<Label> label74;
    ScopedPointer<ToggleButton> reverbOnSw;
    ScopedPointer<ComboBox> osc1SemiToneBox;
    ScopedPointer<ComboBox> osc2SemiToneBox;
    ScopedPointer<ComboBox> osc3SemiToneBox;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (tinySynthAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_F069AB87367C0D4C__

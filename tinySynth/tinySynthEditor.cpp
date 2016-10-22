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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "tinySynthEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
tinySynthAudioProcessorEditor::tinySynthAudioProcessorEditor (tinySynthAudioProcessor* ownerFilter)
    : AudioProcessorEditor (ownerFilter)
{
    //[Constructor_pre] You can add your own custom stuff here..
    // this allows to change the common style used by LookAndFeel of JUCE
	juce::LookAndFeel_V3* tinyLookAndFeel = new LookAndFeel_V3();
	tinyLookAndFeel->setColour(Label::outlineColourId, Colours::transparentBlack);
	tinyLookAndFeel->setColour(ToggleButton::textColourId, Colours::black);
	tinyLookAndFeel->setDefaultLookAndFeel(tinyLookAndFeel);
	this->setLookAndFeel(tinyLookAndFeel);
    //[/Constructor_pre]

    addAndMakeVisible (outputGroup = new GroupComponent ("new group",
                                                         String()));
    outputGroup->setColour (GroupComponent::outlineColourId, Colour (0xff8f5e22));
    outputGroup->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (lfoGroup5 = new GroupComponent ("new group",
                                                       String()));
    lfoGroup5->setTextLabelPosition (Justification::centredLeft);
    lfoGroup5->setColour (GroupComponent::outlineColourId, Colours::grey);
    lfoGroup5->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (reverbGroup = new GroupComponent ("new group",
                                                         String()));
    reverbGroup->setTextLabelPosition (Justification::centredLeft);
    reverbGroup->setColour (GroupComponent::outlineColourId, Colour (0xff397762));
    reverbGroup->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (lfoGroup2 = new GroupComponent ("new group",
                                                       String()));
    lfoGroup2->setTextLabelPosition (Justification::centredLeft);
    lfoGroup2->setColour (GroupComponent::outlineColourId, Colour (0xff591a94));
    lfoGroup2->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (lfoGroup3 = new GroupComponent ("new group",
                                                       String()));
    lfoGroup3->setTextLabelPosition (Justification::centredLeft);
    lfoGroup3->setColour (GroupComponent::outlineColourId, Colour (0xff8b8b00));
    lfoGroup3->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (filterGroup = new GroupComponent ("new group",
                                                         String()));
    filterGroup->setColour (GroupComponent::outlineColourId, Colour (0xff750000));
    filterGroup->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (filter1EnvModDepthSlider = new Slider ("new slider"));
    filter1EnvModDepthSlider->setRange (-1, 1, 0.01);
    filter1EnvModDepthSlider->setSliderStyle (Slider::Rotary);
    filter1EnvModDepthSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    filter1EnvModDepthSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffa7b5b5));
    filter1EnvModDepthSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff850000));
    filter1EnvModDepthSlider->setColour (Slider::textBoxTextColourId, Colour (0xffa7b5b5));
    filter1EnvModDepthSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    filter1EnvModDepthSlider->setColour (Slider::textBoxHighlightColourId, Colour (0x001111ee));
    filter1EnvModDepthSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    filter1EnvModDepthSlider->addListener (this);

    addAndMakeVisible (lfo1DevSlider = new Slider ("new slider"));
    lfo1DevSlider->setRange (0, 10, 0.1);
    lfo1DevSlider->setSliderStyle (Slider::Rotary);
    lfo1DevSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    lfo1DevSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff74c615));
    lfo1DevSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff591a94));
    lfo1DevSlider->setColour (Slider::textBoxTextColourId, Colour (0xff74c615));
    lfo1DevSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    lfo1DevSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    lfo1DevSlider->addListener (this);

    addAndMakeVisible (oscGroup = new GroupComponent ("new group",
                                                      String()));
    oscGroup->setColour (GroupComponent::outlineColourId, Colour (0xff00005c));
    oscGroup->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (label21 = new Label ("new label",
                                            TRANS("OSCILLATOR 1")));
    label21->setFont (Font (15.00f, Font::bold));
    label21->setJustificationType (Justification::centredLeft);
    label21->setEditable (false, false, false);
    label21->setColour (Label::textColourId, Colours::white);
    label21->setColour (TextEditor::textColourId, Colours::black);
    label21->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (adsr1SustainSlider = new Slider ("new slider"));
    adsr1SustainSlider->setRange (0.01, 10, 0.01);
    adsr1SustainSlider->setSliderStyle (Slider::Rotary);
    adsr1SustainSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    adsr1SustainSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff158ec6));
    adsr1SustainSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff8b8b00));
    adsr1SustainSlider->setColour (Slider::textBoxTextColourId, Colour (0xff158ec6));
    adsr1SustainSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    adsr1SustainSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    adsr1SustainSlider->addListener (this);

    addAndMakeVisible (osc1lvlSlider = new Slider ("new slider"));
    osc1lvlSlider->setRange (-100, 0, 0.5);
    osc1lvlSlider->setSliderStyle (Slider::Rotary);
    osc1lvlSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    osc1lvlSlider->setColour (Slider::backgroundColourId, Colour (0x00000000));
    osc1lvlSlider->setColour (Slider::trackColourId, Colour (0x7fffffff));
    osc1lvlSlider->setColour (Slider::rotarySliderFillColourId, Colours::white);
    osc1lvlSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff0000b9));
    osc1lvlSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    osc1lvlSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    osc1lvlSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    osc1lvlSlider->addListener (this);

    addAndMakeVisible (delayGroup = new GroupComponent ("new group",
                                                        String()));
    delayGroup->setColour (GroupComponent::outlineColourId, Colour (0xff9a9a9a));
    delayGroup->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (delayFBSlider = new Slider ("new slider"));
    delayFBSlider->setRange (-40, 0, 0.5);
    delayFBSlider->setSliderStyle (Slider::Rotary);
    delayFBSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    delayFBSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff865cad));
    delayFBSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xffb4772a));
    delayFBSlider->setColour (Slider::textBoxTextColourId, Colour (0xff865cad));
    delayFBSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00faf7f7));
    delayFBSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    delayFBSlider->addListener (this);

    addAndMakeVisible (delayGainSlider = new Slider ("new slider"));
    delayGainSlider->setRange (-40, 0, 0.5);
    delayGainSlider->setSliderStyle (Slider::Rotary);
    delayGainSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    delayGainSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff865cad));
    delayGainSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xffb4772a));
    delayGainSlider->setColour (Slider::textBoxTextColourId, Colour (0xff865cad));
    delayGainSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    delayGainSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    delayGainSlider->addListener (this);

    addAndMakeVisible (label8 = new Label ("new label",
                                           TRANS("Mode")));
    label8->setFont (Font (15.00f, Font::plain));
    label8->setJustificationType (Justification::centredLeft);
    label8->setEditable (false, false, false);
    label8->setColour (Label::backgroundColourId, Colour (0x00b70101));
    label8->setColour (Label::textColourId, Colour (0xff74c615));
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (adsr1DecaySlider = new Slider ("new slider"));
    adsr1DecaySlider->setRange (0.001, 10, 0.001);
    adsr1DecaySlider->setSliderStyle (Slider::Rotary);
    adsr1DecaySlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    adsr1DecaySlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff158ec6));
    adsr1DecaySlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff8b8b00));
    adsr1DecaySlider->setColour (Slider::textBoxTextColourId, Colour (0xff158ec6));
    adsr1DecaySlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    adsr1DecaySlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    adsr1DecaySlider->addListener (this);

    addAndMakeVisible (adsr1AttackSlider = new Slider ("new slider"));
    adsr1AttackSlider->setRange (0.001, 10, 0.001);
    adsr1AttackSlider->setSliderStyle (Slider::Rotary);
    adsr1AttackSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    adsr1AttackSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff158ec6));
    adsr1AttackSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff8b8b00));
    adsr1AttackSlider->setColour (Slider::textBoxTextColourId, Colour (0xff158ec6));
    adsr1AttackSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    adsr1AttackSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    adsr1AttackSlider->addListener (this);

    addAndMakeVisible (delayTimeSlider = new Slider ("new slider"));
    delayTimeSlider->setRange (0, 1, 0.001);
    delayTimeSlider->setSliderStyle (Slider::Rotary);
    delayTimeSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    delayTimeSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff865cad));
    delayTimeSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xffb4772a));
    delayTimeSlider->setColour (Slider::textBoxTextColourId, Colour (0xff865cad));
    delayTimeSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    delayTimeSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    delayTimeSlider->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Attack\n"
                                          "(sec)")));
    label->setFont (Font (13.00f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colour (0xff158ec6));
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Sustain\n"
                                           "(..)")));
    label2->setFont (Font (13.00f, Font::plain));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (Label::textColourId, Colour (0xff158ec6));
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("Decay\n"
                                           "(sec)")));
    label3->setFont (Font (13.00f, Font::plain));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (Label::textColourId, Colour (0xff158ec6));
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("Release\n"
                                           "(sec)")));
    label4->setFont (Font (13.00f, Font::plain));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (Label::textColourId, Colour (0xff158ec6));
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label5 = new Label ("new label",
                                           TRANS("Feedback")));
    label5->setFont (Font (13.00f, Font::plain));
    label5->setJustificationType (Justification::centred);
    label5->setEditable (false, false, false);
    label5->setColour (Label::textColourId, Colour (0xff865cad));
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label6 = new Label ("new label",
                                           TRANS("Gain (dB)")));
    label6->setFont (Font (13.00f, Font::plain));
    label6->setJustificationType (Justification::centred);
    label6->setEditable (false, false, false);
    label6->setColour (Label::textColourId, Colour (0xff865cad));
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label7 = new Label ("new label",
                                           TRANS("Time (sec)")));
    label7->setFont (Font (13.00f, Font::plain));
    label7->setJustificationType (Justification::centred);
    label7->setEditable (false, false, false);
    label7->setColour (Label::textColourId, Colour (0xff865cad));
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (noiseSlider = new Slider ("new slider"));
    noiseSlider->setRange (-40, 0, 0.5);
    noiseSlider->setSliderStyle (Slider::Rotary);
    noiseSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    noiseSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffc61515));
    noiseSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff51a88a));
    noiseSlider->setColour (Slider::textBoxTextColourId, Colour (0xffc61515));
    noiseSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    noiseSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    noiseSlider->addListener (this);

    addAndMakeVisible (driveSlider = new Slider ("new slider"));
    driveSlider->setRange (1, 10, 0.05);
    driveSlider->setSliderStyle (Slider::Rotary);
    driveSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    driveSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffc61515));
    driveSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff51a88a));
    driveSlider->setColour (Slider::textBoxTextColourId, Colour (0xffc61515));
    driveSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00c61515));
    driveSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00c61515));
    driveSlider->addListener (this);

    addAndMakeVisible (outputGainSlider = new Slider ("new slider"));
    outputGainSlider->setRange (-20, 20, 0.5);
    outputGainSlider->setSliderStyle (Slider::Rotary);
    outputGainSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    outputGainSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffc61515));
    outputGainSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff51a88a));
    outputGainSlider->setColour (Slider::textBoxTextColourId, Colour (0xffc61515));
    outputGainSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    outputGainSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    outputGainSlider->addListener (this);

    addAndMakeVisible (label11 = new Label ("new label",
                                            TRANS("Gain (dB)")));
    label11->setFont (Font (13.00f, Font::plain));
    label11->setJustificationType (Justification::centred);
    label11->setEditable (false, false, false);
    label11->setColour (Label::textColourId, Colour (0xffc61515));
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label12 = new Label ("new label",
                                            TRANS("Drive")));
    label12->setFont (Font (13.00f, Font::plain));
    label12->setJustificationType (Justification::centred);
    label12->setEditable (false, false, false);
    label12->setColour (Label::textColourId, Colour (0xffc61515));
    label12->setColour (TextEditor::textColourId, Colours::black);
    label12->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label13 = new Label ("new label",
                                            TRANS("Noise (dB)")));
    label13->setFont (Font (13.00f, Font::plain));
    label13->setJustificationType (Justification::centred);
    label13->setEditable (false, false, false);
    label13->setColour (Label::textColourId, Colour (0xffc61515));
    label13->setColour (TextEditor::textColourId, Colours::black);
    label13->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (adsr1ReleaseSlider = new Slider ("new slider"));
    adsr1ReleaseSlider->setRange (0.001, 10, 0.001);
    adsr1ReleaseSlider->setSliderStyle (Slider::Rotary);
    adsr1ReleaseSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    adsr1ReleaseSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff158ec6));
    adsr1ReleaseSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff8b8b00));
    adsr1ReleaseSlider->setColour (Slider::textBoxTextColourId, Colour (0xff158ec6));
    adsr1ReleaseSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    adsr1ReleaseSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    adsr1ReleaseSlider->addListener (this);

    addAndMakeVisible (osc3WaveBox = new ComboBox ("new combo box"));
    osc3WaveBox->setEditableText (false);
    osc3WaveBox->setJustificationType (Justification::centredLeft);
    osc3WaveBox->setTextWhenNothingSelected (String());
    osc3WaveBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    osc3WaveBox->addItem (TRANS("Sine"), 1);
    osc3WaveBox->addItem (TRANS("Saw"), 2);
    osc3WaveBox->addItem (TRANS("Square"), 3);
    osc3WaveBox->addListener (this);

    addAndMakeVisible (osc3OctaveBox = new ComboBox ("new combo box"));
    osc3OctaveBox->setEditableText (false);
    osc3OctaveBox->setJustificationType (Justification::centredLeft);
    osc3OctaveBox->setTextWhenNothingSelected (String());
    osc3OctaveBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    osc3OctaveBox->addItem (TRANS("-2"), 1);
    osc3OctaveBox->addItem (TRANS("-1"), 2);
    osc3OctaveBox->addItem (TRANS("0"), 3);
    osc3OctaveBox->addItem (TRANS("+1"), 4);
    osc3OctaveBox->addItem (TRANS("+2"), 5);
    osc3OctaveBox->addListener (this);

    addAndMakeVisible (label23 = new Label ("new label",
                                            TRANS("Octave")));
    label23->setFont (Font (15.00f, Font::plain));
    label23->setJustificationType (Justification::centredLeft);
    label23->setEditable (false, false, false);
    label23->setColour (Label::textColourId, Colours::white);
    label23->setColour (TextEditor::textColourId, Colours::black);
    label23->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label24 = new Label ("new label",
                                            TRANS("Wave")));
    label24->setFont (Font (15.00f, Font::plain));
    label24->setJustificationType (Justification::centredLeft);
    label24->setEditable (false, false, false);
    label24->setColour (Label::backgroundColourId, Colour (0x00000000));
    label24->setColour (Label::textColourId, Colours::white);
    label24->setColour (TextEditor::textColourId, Colours::black);
    label24->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label25 = new Label ("new label",
                                            TRANS("Level\n"
                                            "(dB)")));
    label25->setFont (Font (13.00f, Font::plain));
    label25->setJustificationType (Justification::centred);
    label25->setEditable (false, false, false);
    label25->setColour (Label::textColourId, Colours::white);
    label25->setColour (TextEditor::textColourId, Colours::black);
    label25->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label27 = new Label ("new label",
                                            TRANS("Frequency\n"
                                            "(Hz)")));
    label27->setFont (Font (13.00f, Font::plain));
    label27->setJustificationType (Justification::centred);
    label27->setEditable (false, false, false);
    label27->setColour (Label::textColourId, Colour (0xff74c615));
    label27->setColour (TextEditor::textColourId, Colours::black);
    label27->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label29 = new Label ("new label",
                                            TRANS("Depth")));
    label29->setFont (Font (13.00f, Font::plain));
    label29->setJustificationType (Justification::centred);
    label29->setEditable (false, false, false);
    label29->setColour (Label::textColourId, Colour (0xff74c615));
    label29->setColour (TextEditor::textColourId, Colours::black);
    label29->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (filter1FreqSlider = new Slider ("new slider"));
    filter1FreqSlider->setRange (50, 11205, 5);
    filter1FreqSlider->setSliderStyle (Slider::Rotary);
    filter1FreqSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    filter1FreqSlider->setColour (Slider::backgroundColourId, Colour (0x00000000));
    filter1FreqSlider->setColour (Slider::trackColourId, Colour (0x7fffffff));
    filter1FreqSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffa7b5b5));
    filter1FreqSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff850000));
    filter1FreqSlider->setColour (Slider::textBoxTextColourId, Colour (0xffa7b5b5));
    filter1FreqSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    filter1FreqSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    filter1FreqSlider->addListener (this);

    addAndMakeVisible (label31 = new Label ("new label",
                                            TRANS("Resonance")));
    label31->setFont (Font (13.00f, Font::plain));
    label31->setJustificationType (Justification::centred);
    label31->setEditable (false, false, false);
    label31->setColour (Label::textColourId, Colour (0xffa7b5b5));
    label31->setColour (TextEditor::textColourId, Colours::black);
    label31->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label32 = new Label ("new label",
                                            TRANS("Frequency\n"
                                            "(Hz)")));
    label32->setFont (Font (13.00f, Font::plain));
    label32->setJustificationType (Justification::centred);
    label32->setEditable (false, false, false);
    label32->setColour (Label::textColourId, Colour (0xffa7b5b5));
    label32->setColour (TextEditor::textColourId, Colours::black);
    label32->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label33 = new Label ("new label",
                                            TRANS("ADSR Mod. \n"
                                            "Depth")));
    label33->setFont (Font (13.00f, Font::plain));
    label33->setJustificationType (Justification::centred);
    label33->setEditable (false, false, false);
    label33->setColour (Label::textColourId, Colour (0xffa7b5b5));
    label33->setColour (TextEditor::textColourId, Colours::black);
    label33->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (lfo1FreqSlider = new Slider ("new slider"));
    lfo1FreqSlider->setRange (0, 30, 0.1);
    lfo1FreqSlider->setSliderStyle (Slider::Rotary);
    lfo1FreqSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    lfo1FreqSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff74c615));
    lfo1FreqSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff591a94));
    lfo1FreqSlider->setColour (Slider::textBoxTextColourId, Colour (0xff74c615));
    lfo1FreqSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    lfo1FreqSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    lfo1FreqSlider->addListener (this);

    addAndMakeVisible (lfo1WaveBox = new ComboBox ("new combo box"));
    lfo1WaveBox->setEditableText (false);
    lfo1WaveBox->setJustificationType (Justification::centredLeft);
    lfo1WaveBox->setTextWhenNothingSelected (String());
    lfo1WaveBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    lfo1WaveBox->addItem (TRANS("Sine"), 1);
    lfo1WaveBox->addItem (TRANS("Saw"), 2);
    lfo1WaveBox->addItem (TRANS("Square"), 3);
    lfo1WaveBox->addListener (this);

    addAndMakeVisible (lfo1DestBox = new ComboBox ("new combo box"));
    lfo1DestBox->setTooltip (TRANS("LFO Vibrato can be applied to a sigle Oscillator just selecting VIbrato in LFO box of oscillator"));
    lfo1DestBox->setEditableText (false);
    lfo1DestBox->setJustificationType (Justification::centredLeft);
    lfo1DestBox->setTextWhenNothingSelected (String());
    lfo1DestBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    lfo1DestBox->addItem (TRANS("Off"), 1);
    lfo1DestBox->addItem (TRANS("Vibrato"), 2);
    lfo1DestBox->addItem (TRANS("Tremolo"), 3);
    lfo1DestBox->addListener (this);

    addAndMakeVisible (label9 = new Label ("new label",
                                           TRANS("Wave")));
    label9->setFont (Font (15.00f, Font::plain));
    label9->setJustificationType (Justification::centredLeft);
    label9->setEditable (false, false, false);
    label9->setColour (Label::textColourId, Colour (0xff74c615));
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (osc3lvlSlider = new Slider ("new slider"));
    osc3lvlSlider->setRange (-100, 0, 0.5);
    osc3lvlSlider->setSliderStyle (Slider::Rotary);
    osc3lvlSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    osc3lvlSlider->setColour (Slider::rotarySliderFillColourId, Colours::white);
    osc3lvlSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff0000c1));
    osc3lvlSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    osc3lvlSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    osc3lvlSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808000));
    osc3lvlSlider->addListener (this);

    addAndMakeVisible (filter1ResSlider = new Slider ("new slider"));
    filter1ResSlider->setRange (0, 40, 1);
    filter1ResSlider->setSliderStyle (Slider::Rotary);
    filter1ResSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    filter1ResSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffa7b5b5));
    filter1ResSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff850000));
    filter1ResSlider->setColour (Slider::textBoxTextColourId, Colour (0xffa7b5b5));
    filter1ResSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    filter1ResSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    filter1ResSlider->addListener (this);

    addAndMakeVisible (filter1TypeBox = new ComboBox ("new combo box"));
    filter1TypeBox->setEditableText (false);
    filter1TypeBox->setJustificationType (Justification::centredLeft);
    filter1TypeBox->setTextWhenNothingSelected (String());
    filter1TypeBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    filter1TypeBox->addItem (TRANS("Low Pass"), 1);
    filter1TypeBox->addItem (TRANS("Band Pass"), 2);
    filter1TypeBox->addItem (TRANS("High Pass"), 3);
    filter1TypeBox->addItem (TRANS("Off"), 4);
    filter1TypeBox->addListener (this);

    addAndMakeVisible (label10 = new Label ("new label",
                                            TRANS("Type")));
    label10->setFont (Font (15.00f, Font::plain));
    label10->setJustificationType (Justification::centredLeft);
    label10->setEditable (false, false, false);
    label10->setColour (Label::textColourId, Colour (0xffa7b5b5));
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label26 = new Label ("new label",
                                            TRANS("OSCILLATOR 3")));
    label26->setFont (Font (15.00f, Font::bold));
    label26->setJustificationType (Justification::centredLeft);
    label26->setEditable (false, false, false);
    label26->setColour (Label::textColourId, Colours::white);
    label26->setColour (TextEditor::textColourId, Colours::black);
    label26->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (osc2WaveBox = new ComboBox ("new combo box"));
    osc2WaveBox->setEditableText (false);
    osc2WaveBox->setJustificationType (Justification::centredLeft);
    osc2WaveBox->setTextWhenNothingSelected (String());
    osc2WaveBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    osc2WaveBox->addItem (TRANS("Sine"), 1);
    osc2WaveBox->addItem (TRANS("Saw"), 2);
    osc2WaveBox->addItem (TRANS("Square"), 3);
    osc2WaveBox->addListener (this);

    addAndMakeVisible (osc2OctaveBox = new ComboBox ("new combo box"));
    osc2OctaveBox->setEditableText (false);
    osc2OctaveBox->setJustificationType (Justification::centredLeft);
    osc2OctaveBox->setTextWhenNothingSelected (String());
    osc2OctaveBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    osc2OctaveBox->addItem (TRANS("-2"), 1);
    osc2OctaveBox->addItem (TRANS("-1"), 2);
    osc2OctaveBox->addItem (TRANS("0"), 3);
    osc2OctaveBox->addItem (TRANS("+1"), 4);
    osc2OctaveBox->addItem (TRANS("+2"), 5);
    osc2OctaveBox->addListener (this);

    addAndMakeVisible (label14 = new Label ("new label",
                                            TRANS("Octave")));
    label14->setFont (Font (15.00f, Font::plain));
    label14->setJustificationType (Justification::centredLeft);
    label14->setEditable (false, false, false);
    label14->setColour (Label::textColourId, Colours::white);
    label14->setColour (TextEditor::textColourId, Colours::black);
    label14->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label15 = new Label ("new label",
                                            TRANS("Wave")));
    label15->setFont (Font (15.00f, Font::plain));
    label15->setJustificationType (Justification::centredLeft);
    label15->setEditable (false, false, false);
    label15->setColour (Label::textColourId, Colours::white);
    label15->setColour (TextEditor::textColourId, Colours::black);
    label15->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label16 = new Label ("new label",
                                            TRANS("Level \n"
                                            "(dB)")));
    label16->setFont (Font (13.00f, Font::plain));
    label16->setJustificationType (Justification::centred);
    label16->setEditable (false, false, false);
    label16->setColour (Label::textColourId, Colours::white);
    label16->setColour (TextEditor::textColourId, Colours::black);
    label16->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (osc2lvlSlider = new Slider ("new slider"));
    osc2lvlSlider->setRange (-100, 0, 0.5);
    osc2lvlSlider->setSliderStyle (Slider::Rotary);
    osc2lvlSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    osc2lvlSlider->setColour (Slider::rotarySliderFillColourId, Colours::white);
    osc2lvlSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff0000b9));
    osc2lvlSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    osc2lvlSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    osc2lvlSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    osc2lvlSlider->addListener (this);

    addAndMakeVisible (label17 = new Label ("new label",
                                            TRANS("OSCILLATOR 2")));
    label17->setFont (Font (15.00f, Font::bold));
    label17->setJustificationType (Justification::centredLeft);
    label17->setEditable (false, false, false);
    label17->setColour (Label::textColourId, Colours::white);
    label17->setColour (TextEditor::textColourId, Colours::black);
    label17->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (osc1WaveBox = new ComboBox ("new combo box"));
    osc1WaveBox->setTooltip (TRANS("waveform selector"));
    osc1WaveBox->setEditableText (false);
    osc1WaveBox->setJustificationType (Justification::centredLeft);
    osc1WaveBox->setTextWhenNothingSelected (String());
    osc1WaveBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    osc1WaveBox->addItem (TRANS("Sine"), 1);
    osc1WaveBox->addItem (TRANS("Saw"), 2);
    osc1WaveBox->addItem (TRANS("Square"), 3);
    osc1WaveBox->addListener (this);

    addAndMakeVisible (osc1OctaveBox = new ComboBox ("new combo box"));
    osc1OctaveBox->setEditableText (false);
    osc1OctaveBox->setJustificationType (Justification::centredLeft);
    osc1OctaveBox->setTextWhenNothingSelected (String());
    osc1OctaveBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    osc1OctaveBox->addItem (TRANS("-2"), 1);
    osc1OctaveBox->addItem (TRANS("-1"), 2);
    osc1OctaveBox->addItem (TRANS("0"), 3);
    osc1OctaveBox->addItem (TRANS("+1"), 4);
    osc1OctaveBox->addItem (TRANS("+2"), 5);
    osc1OctaveBox->addListener (this);

    addAndMakeVisible (label18 = new Label ("new label",
                                            TRANS("Octave")));
    label18->setFont (Font (15.00f, Font::plain));
    label18->setJustificationType (Justification::centredLeft);
    label18->setEditable (false, false, false);
    label18->setColour (Label::textColourId, Colours::white);
    label18->setColour (TextEditor::textColourId, Colours::black);
    label18->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label19 = new Label ("new label",
                                            TRANS("Wave")));
    label19->setFont (Font (15.00f, Font::plain));
    label19->setJustificationType (Justification::centredLeft);
    label19->setEditable (false, false, false);
    label19->setColour (Label::textColourId, Colours::white);
    label19->setColour (TextEditor::textColourId, Colours::black);
    label19->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label20 = new Label ("new label",
                                            TRANS("Level \n"
                                            "(dB)")));
    label20->setFont (Font (13.00f, Font::plain));
    label20->setJustificationType (Justification::centred);
    label20->setEditable (false, false, false);
    label20->setColour (Label::textColourId, Colours::white);
    label20->setColour (TextEditor::textColourId, Colours::black);
    label20->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (filter2EnvModDepthSlider = new Slider ("new slider"));
    filter2EnvModDepthSlider->setTooltip (TRANS("ADSR level of modulation of  frequency filetr"));
    filter2EnvModDepthSlider->setRange (-1, 1, 0.01);
    filter2EnvModDepthSlider->setSliderStyle (Slider::Rotary);
    filter2EnvModDepthSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    filter2EnvModDepthSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff909090));
    filter2EnvModDepthSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff860000));
    filter2EnvModDepthSlider->setColour (Slider::textBoxTextColourId, Colour (0xffa7b5b5));
    filter2EnvModDepthSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    filter2EnvModDepthSlider->setColour (Slider::textBoxHighlightColourId, Colour (0x001111ee));
    filter2EnvModDepthSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    filter2EnvModDepthSlider->addListener (this);

    addAndMakeVisible (filter2FreqSlider = new Slider ("new slider"));
    filter2FreqSlider->setRange (50, 11205, 5);
    filter2FreqSlider->setSliderStyle (Slider::Rotary);
    filter2FreqSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 12);
    filter2FreqSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffa7b5b5));
    filter2FreqSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff860000));
    filter2FreqSlider->setColour (Slider::textBoxTextColourId, Colour (0xffa7b5b5));
    filter2FreqSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    filter2FreqSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    filter2FreqSlider->addListener (this);

    addAndMakeVisible (label30 = new Label ("new label",
                                            TRANS("Resonance")));
    label30->setFont (Font (13.00f, Font::plain));
    label30->setJustificationType (Justification::centred);
    label30->setEditable (false, false, false);
    label30->setColour (Label::textColourId, Colour (0xffa7b5b5));
    label30->setColour (TextEditor::textColourId, Colours::black);
    label30->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label34 = new Label ("new label",
                                            TRANS("Frequency\n"
                                            "(Hz)")));
    label34->setFont (Font (13.00f, Font::plain));
    label34->setJustificationType (Justification::centred);
    label34->setEditable (false, false, false);
    label34->setColour (Label::textColourId, Colour (0xffa7b5b5));
    label34->setColour (TextEditor::textColourId, Colours::black);
    label34->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label35 = new Label ("new label",
                                            TRANS("ADSR Mod. \n"
                                            "Depth")));
    label35->setFont (Font (13.00f, Font::plain));
    label35->setJustificationType (Justification::centred);
    label35->setEditable (false, false, false);
    label35->setColour (Label::textColourId, Colour (0xffa7b5b5));
    label35->setColour (TextEditor::textColourId, Colours::black);
    label35->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (filter2ResSlider = new Slider ("new slider"));
    filter2ResSlider->setRange (0, 40, 1);
    filter2ResSlider->setSliderStyle (Slider::Rotary);
    filter2ResSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    filter2ResSlider->setColour (Slider::trackColourId, Colour (0xffa7b5b5));
    filter2ResSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffa7b5b5));
    filter2ResSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff860000));
    filter2ResSlider->setColour (Slider::textBoxTextColourId, Colour (0xffa7b5b5));
    filter2ResSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    filter2ResSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    filter2ResSlider->addListener (this);

    addAndMakeVisible (filter2TypeBox = new ComboBox ("new combo box"));
    filter2TypeBox->setEditableText (false);
    filter2TypeBox->setJustificationType (Justification::centredLeft);
    filter2TypeBox->setTextWhenNothingSelected (String());
    filter2TypeBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    filter2TypeBox->addItem (TRANS("Low Pass"), 1);
    filter2TypeBox->addItem (TRANS("Band Pass"), 2);
    filter2TypeBox->addItem (TRANS("High Pass"), 3);
    filter2TypeBox->addItem (TRANS("Off"), 4);
    filter2TypeBox->addListener (this);

    addAndMakeVisible (label36 = new Label ("new label",
                                            TRANS("Type")));
    label36->setFont (Font (15.00f, Font::plain));
    label36->setJustificationType (Justification::centredLeft);
    label36->setEditable (false, false, false);
    label36->setColour (Label::textColourId, Colour (0xffa7b5b5));
    label36->setColour (TextEditor::textColourId, Colours::black);
    label36->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (adsr2SustainSlider = new Slider ("new slider"));
    adsr2SustainSlider->setRange (0.01, 10, 0.01);
    adsr2SustainSlider->setSliderStyle (Slider::Rotary);
    adsr2SustainSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    adsr2SustainSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff158ec6));
    adsr2SustainSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff8b8b00));
    adsr2SustainSlider->setColour (Slider::textBoxTextColourId, Colour (0xff158ec6));
    adsr2SustainSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    adsr2SustainSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    adsr2SustainSlider->addListener (this);

    addAndMakeVisible (adsr2DecaySlider = new Slider ("new slider"));
    adsr2DecaySlider->setRange (0.001, 10, 0.001);
    adsr2DecaySlider->setSliderStyle (Slider::Rotary);
    adsr2DecaySlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    adsr2DecaySlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff158ec6));
    adsr2DecaySlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff8b8b00));
    adsr2DecaySlider->setColour (Slider::textBoxTextColourId, Colour (0xff158ec6));
    adsr2DecaySlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    adsr2DecaySlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    adsr2DecaySlider->addListener (this);

    addAndMakeVisible (adsr2AttackSlider = new Slider ("new slider"));
    adsr2AttackSlider->setRange (0.001, 10, 0.001);
    adsr2AttackSlider->setSliderStyle (Slider::Rotary);
    adsr2AttackSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    adsr2AttackSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff158ec6));
    adsr2AttackSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff8b8b00));
    adsr2AttackSlider->setColour (Slider::textBoxTextColourId, Colour (0xff158ec6));
    adsr2AttackSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    adsr2AttackSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    adsr2AttackSlider->addListener (this);

    addAndMakeVisible (adsr2ReleaseSlider = new Slider ("new slider"));
    adsr2ReleaseSlider->setRange (0.001, 10, 0.001);
    adsr2ReleaseSlider->setSliderStyle (Slider::Rotary);
    adsr2ReleaseSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    adsr2ReleaseSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff26799f));
    adsr2ReleaseSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff8b8b00));
    adsr2ReleaseSlider->setColour (Slider::textBoxTextColourId, Colour (0xff158ec6));
    adsr2ReleaseSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    adsr2ReleaseSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    adsr2ReleaseSlider->addListener (this);

    addAndMakeVisible (lfo2DevSlider = new Slider ("new slider"));
    lfo2DevSlider->setRange (0, 10, 0.1);
    lfo2DevSlider->setSliderStyle (Slider::Rotary);
    lfo2DevSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    lfo2DevSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff74c615));
    lfo2DevSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff591a94));
    lfo2DevSlider->setColour (Slider::textBoxTextColourId, Colour (0xff74c615));
    lfo2DevSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    lfo2DevSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    lfo2DevSlider->addListener (this);

    addAndMakeVisible (label41 = new Label ("new label",
                                            TRANS("Mode")));
    label41->setFont (Font (15.00f, Font::plain));
    label41->setJustificationType (Justification::centredLeft);
    label41->setEditable (false, false, false);
    label41->setColour (Label::backgroundColourId, Colour (0x00b70101));
    label41->setColour (Label::textColourId, Colour (0xff74c615));
    label41->setColour (TextEditor::textColourId, Colours::black);
    label41->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label42 = new Label ("new label",
                                            TRANS("Frequency\n"
                                            "(Hz)")));
    label42->setFont (Font (13.00f, Font::plain));
    label42->setJustificationType (Justification::centred);
    label42->setEditable (false, false, false);
    label42->setColour (Label::textColourId, Colour (0xff74c615));
    label42->setColour (TextEditor::textColourId, Colours::black);
    label42->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label43 = new Label ("new label",
                                            TRANS("Depth")));
    label43->setFont (Font (13.00f, Font::plain));
    label43->setJustificationType (Justification::centred);
    label43->setEditable (false, false, false);
    label43->setColour (Label::textColourId, Colour (0xff74c615));
    label43->setColour (TextEditor::textColourId, Colours::black);
    label43->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (lfo2FreqSlider = new Slider ("new slider"));
    lfo2FreqSlider->setRange (0, 30, 0.1);
    lfo2FreqSlider->setSliderStyle (Slider::Rotary);
    lfo2FreqSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    lfo2FreqSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff74c615));
    lfo2FreqSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff591a94));
    lfo2FreqSlider->setColour (Slider::textBoxTextColourId, Colour (0xff74c615));
    lfo2FreqSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    lfo2FreqSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    lfo2FreqSlider->addListener (this);

    addAndMakeVisible (lfo2WaveBox = new ComboBox ("new combo box"));
    lfo2WaveBox->setEditableText (false);
    lfo2WaveBox->setJustificationType (Justification::centredLeft);
    lfo2WaveBox->setTextWhenNothingSelected (String());
    lfo2WaveBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    lfo2WaveBox->addItem (TRANS("Sine"), 1);
    lfo2WaveBox->addItem (TRANS("Saw"), 2);
    lfo2WaveBox->addItem (TRANS("Square"), 3);
    lfo2WaveBox->addListener (this);

    addAndMakeVisible (lfo2DestBox = new ComboBox ("new combo box"));
    lfo2DestBox->setEditableText (false);
    lfo2DestBox->setJustificationType (Justification::centredLeft);
    lfo2DestBox->setTextWhenNothingSelected (String());
    lfo2DestBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    lfo2DestBox->addItem (TRANS("Off"), 1);
    lfo2DestBox->addItem (TRANS("Vibrato"), 2);
    lfo2DestBox->addItem (TRANS("Tremolo"), 3);
    lfo2DestBox->addListener (this);

    addAndMakeVisible (label44 = new Label ("new label",
                                            TRANS("Wave")));
    label44->setFont (Font (15.00f, Font::plain));
    label44->setJustificationType (Justification::centredLeft);
    label44->setEditable (false, false, false);
    label44->setColour (Label::textColourId, Colour (0xff74c615));
    label44->setColour (TextEditor::textColourId, Colours::black);
    label44->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (adsr3SustainSlider = new Slider ("new slider"));
    adsr3SustainSlider->setRange (0.01, 10, 0.01);
    adsr3SustainSlider->setSliderStyle (Slider::Rotary);
    adsr3SustainSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    adsr3SustainSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff158ec6));
    adsr3SustainSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff8b8b00));
    adsr3SustainSlider->setColour (Slider::textBoxTextColourId, Colour (0xff158ec6));
    adsr3SustainSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    adsr3SustainSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    adsr3SustainSlider->addListener (this);

    addAndMakeVisible (adsr3DecaySlider = new Slider ("new slider"));
    adsr3DecaySlider->setRange (0.001, 10, 0.001);
    adsr3DecaySlider->setSliderStyle (Slider::Rotary);
    adsr3DecaySlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    adsr3DecaySlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff158ec6));
    adsr3DecaySlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff8b8b00));
    adsr3DecaySlider->setColour (Slider::textBoxTextColourId, Colour (0xff158ec6));
    adsr3DecaySlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    adsr3DecaySlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    adsr3DecaySlider->addListener (this);

    addAndMakeVisible (adsr3AttackSlider = new Slider ("new slider"));
    adsr3AttackSlider->setRange (0.001, 10, 0.001);
    adsr3AttackSlider->setSliderStyle (Slider::Rotary);
    adsr3AttackSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    adsr3AttackSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff158ec6));
    adsr3AttackSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff8b8b00));
    adsr3AttackSlider->setColour (Slider::textBoxTextColourId, Colour (0xff158ec6));
    adsr3AttackSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    adsr3AttackSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    adsr3AttackSlider->addListener (this);

    addAndMakeVisible (adsr3ReleaseSlider = new Slider ("new slider"));
    adsr3ReleaseSlider->setRange (0.001, 10, 0.001);
    adsr3ReleaseSlider->setSliderStyle (Slider::Rotary);
    adsr3ReleaseSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    adsr3ReleaseSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xff158ec6));
    adsr3ReleaseSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff8b8b00));
    adsr3ReleaseSlider->setColour (Slider::textBoxTextColourId, Colour (0xff158ec6));
    adsr3ReleaseSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    adsr3ReleaseSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    adsr3ReleaseSlider->addListener (this);

    addAndMakeVisible (osc1LfoBox = new ComboBox ("new combo box"));
    osc1LfoBox->setTooltip (TRANS("LFO selector."));
    osc1LfoBox->setEditableText (false);
    osc1LfoBox->setJustificationType (Justification::centredLeft);
    osc1LfoBox->setTextWhenNothingSelected (String());
    osc1LfoBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    osc1LfoBox->addItem (TRANS("Off"), 1);
    osc1LfoBox->addItem (TRANS("1"), 2);
    osc1LfoBox->addItem (TRANS("2"), 3);
    osc1LfoBox->addListener (this);

    addAndMakeVisible (label49 = new Label ("new label",
                                            TRANS("LFO")));
    label49->setFont (Font (13.00f, Font::plain));
    label49->setJustificationType (Justification::centredLeft);
    label49->setEditable (false, false, false);
    label49->setColour (Label::textColourId, Colours::white);
    label49->setColour (TextEditor::textColourId, Colours::black);
    label49->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (osc1EnvBox = new ComboBox ("new combo box"));
    osc1EnvBox->setEditableText (false);
    osc1EnvBox->setJustificationType (Justification::centredLeft);
    osc1EnvBox->setTextWhenNothingSelected (String());
    osc1EnvBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    osc1EnvBox->addItem (TRANS("1"), 1);
    osc1EnvBox->addItem (TRANS("2"), 2);
    osc1EnvBox->addItem (TRANS("3"), 3);
    osc1EnvBox->addListener (this);

    addAndMakeVisible (label50 = new Label ("new label",
                                            TRANS("ADSR")));
    label50->setFont (Font (13.00f, Font::plain));
    label50->setJustificationType (Justification::centredLeft);
    label50->setEditable (false, false, false);
    label50->setColour (Label::textColourId, Colours::white);
    label50->setColour (TextEditor::textColourId, Colours::black);
    label50->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (osc2LfoBox = new ComboBox ("new combo box"));
    osc2LfoBox->setEditableText (false);
    osc2LfoBox->setJustificationType (Justification::centredLeft);
    osc2LfoBox->setTextWhenNothingSelected (String());
    osc2LfoBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    osc2LfoBox->addItem (TRANS("Off"), 1);
    osc2LfoBox->addItem (TRANS("1"), 2);
    osc2LfoBox->addItem (TRANS("2"), 3);
    osc2LfoBox->addListener (this);

    addAndMakeVisible (label51 = new Label ("new label",
                                            TRANS("LFO")));
    label51->setFont (Font (13.00f, Font::plain));
    label51->setJustificationType (Justification::centredLeft);
    label51->setEditable (false, false, false);
    label51->setColour (Label::textColourId, Colours::white);
    label51->setColour (TextEditor::textColourId, Colours::black);
    label51->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (osc2EnvBox = new ComboBox ("new combo box"));
    osc2EnvBox->setEditableText (false);
    osc2EnvBox->setJustificationType (Justification::centredLeft);
    osc2EnvBox->setTextWhenNothingSelected (String());
    osc2EnvBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    osc2EnvBox->addItem (TRANS("1"), 1);
    osc2EnvBox->addItem (TRANS("2"), 2);
    osc2EnvBox->addItem (TRANS("3"), 3);
    osc2EnvBox->addListener (this);

    addAndMakeVisible (label52 = new Label ("new label",
                                            TRANS("ADSR")));
    label52->setFont (Font (13.00f, Font::plain));
    label52->setJustificationType (Justification::centredLeft);
    label52->setEditable (false, false, false);
    label52->setColour (Label::textColourId, Colours::white);
    label52->setColour (TextEditor::textColourId, Colours::black);
    label52->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (osc3LfoBox = new ComboBox ("new combo box"));
    osc3LfoBox->setEditableText (false);
    osc3LfoBox->setJustificationType (Justification::centredLeft);
    osc3LfoBox->setTextWhenNothingSelected (String());
    osc3LfoBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    osc3LfoBox->addItem (TRANS("Off"), 1);
    osc3LfoBox->addItem (TRANS("1"), 2);
    osc3LfoBox->addItem (TRANS("2"), 3);
    osc3LfoBox->addListener (this);

    addAndMakeVisible (label53 = new Label ("new label",
                                            TRANS("LFO")));
    label53->setFont (Font (13.00f, Font::plain));
    label53->setJustificationType (Justification::centredLeft);
    label53->setEditable (false, false, false);
    label53->setColour (Label::textColourId, Colours::white);
    label53->setColour (TextEditor::textColourId, Colours::black);
    label53->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (osc3EnvBox = new ComboBox ("new combo box"));
    osc3EnvBox->setEditableText (false);
    osc3EnvBox->setJustificationType (Justification::centredLeft);
    osc3EnvBox->setTextWhenNothingSelected (String());
    osc3EnvBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    osc3EnvBox->addItem (TRANS("1"), 1);
    osc3EnvBox->addItem (TRANS("2"), 2);
    osc3EnvBox->addItem (TRANS("3"), 3);
    osc3EnvBox->addListener (this);

    addAndMakeVisible (label54 = new Label ("new label",
                                            TRANS("ADSR")));
    label54->setFont (Font (13.00f, Font::plain));
    label54->setJustificationType (Justification::centredLeft);
    label54->setEditable (false, false, false);
    label54->setColour (Label::textColourId, Colours::white);
    label54->setColour (TextEditor::textColourId, Colours::black);
    label54->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label28 = new Label ("new label",
                                            TRANS("FILTER 2")));
    label28->setFont (Font (15.00f, Font::bold));
    label28->setJustificationType (Justification::centredLeft);
    label28->setEditable (false, false, false);
    label28->setColour (Label::textColourId, Colour (0xff747272));
    label28->setColour (Label::outlineColourId, Colour (0x00000000));
    label28->setColour (TextEditor::textColourId, Colours::black);
    label28->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label55 = new Label ("new label",
                                            TRANS("FILTER 1")));
    label55->setFont (Font (15.00f, Font::bold));
    label55->setJustificationType (Justification::centredLeft);
    label55->setEditable (false, false, false);
    label55->setColour (Label::textColourId, Colour (0xff747272));
    label55->setColour (TextEditor::textColourId, Colours::black);
    label55->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label56 = new Label ("new label",
                                            TRANS("ADSR 1")));
    label56->setFont (Font (15.00f, Font::bold));
    label56->setJustificationType (Justification::bottomLeft);
    label56->setEditable (false, false, false);
    label56->setColour (Label::textColourId, Colour (0xff158ec6));
    label56->setColour (TextEditor::textColourId, Colours::black);
    label56->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label57 = new Label ("new label",
                                            TRANS("ADSR 2")));
    label57->setFont (Font (15.00f, Font::bold));
    label57->setJustificationType (Justification::bottomLeft);
    label57->setEditable (false, false, false);
    label57->setColour (Label::textColourId, Colour (0xff158ec6));
    label57->setColour (TextEditor::textColourId, Colours::black);
    label57->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label58 = new Label ("new label",
                                            TRANS("ADSR 3")));
    label58->setFont (Font (15.00f, Font::bold));
    label58->setJustificationType (Justification::bottomLeft);
    label58->setEditable (false, false, false);
    label58->setColour (Label::textColourId, Colour (0xff158ec6));
    label58->setColour (TextEditor::textColourId, Colours::black);
    label58->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (saveTXT = new TextButton ("saveTXT"));
    saveTXT->setButtonText (TRANS("save to file"));
    saveTXT->addListener (this);
    saveTXT->setColour (TextButton::buttonOnColourId, Colour (0xffa7b5ff));

    addAndMakeVisible (loadTXT = new TextButton ("loadTXT"));
    loadTXT->setButtonText (TRANS("load from file"));
    loadTXT->addListener (this);
    loadTXT->setColour (TextButton::buttonColourId, Colour (0xffbbbbff));
    loadTXT->setColour (TextButton::buttonOnColourId, Colour (0xffa7b5b5));

    addAndMakeVisible (checkP = new TextButton ("checkP"));
    checkP->setButtonText (TRANS("check param"));
    checkP->addListener (this);
    checkP->setColour (TextButton::buttonOnColourId, Colour (0xffa7b5ff));

    addAndMakeVisible (presetName = new TextEditor ("presetName"));
    presetName->setMultiLine (false);
    presetName->setReturnKeyStartsNewLine (false);
    presetName->setReadOnly (true);
    presetName->setScrollbarsShown (true);
    presetName->setCaretVisible (false);
    presetName->setPopupMenuEnabled (true);
    presetName->setText (String());

    addAndMakeVisible (osc1On = new ToggleButton ("new toggle button"));
    osc1On->setButtonText (TRANS("On"));
    osc1On->setConnectedEdges (Button::ConnectedOnLeft);
    osc1On->addListener (this);
    osc1On->setToggleState (true, dontSendNotification);
    osc1On->setColour (ToggleButton::textColourId, Colours::azure);

    addAndMakeVisible (osc2On = new ToggleButton ("new toggle button"));
    osc2On->setButtonText (TRANS("On"));
    osc2On->setConnectedEdges (Button::ConnectedOnLeft);
    osc2On->addListener (this);
    osc2On->setToggleState (true, dontSendNotification);
    osc2On->setColour (ToggleButton::textColourId, Colours::azure);

    addAndMakeVisible (osc3On = new ToggleButton ("new toggle button"));
    osc3On->setButtonText (TRANS("On"));
    osc3On->setConnectedEdges (Button::ConnectedOnLeft);
    osc3On->addListener (this);
    osc3On->setToggleState (true, dontSendNotification);
    osc3On->setColour (ToggleButton::textColourId, Colours::azure);

    addAndMakeVisible (synthVoiceBox = new ComboBox ("new combo box"));
    synthVoiceBox->setEditableText (false);
    synthVoiceBox->setJustificationType (Justification::centredLeft);
    synthVoiceBox->setTextWhenNothingSelected (String());
    synthVoiceBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    synthVoiceBox->addItem (TRANS("1"), 1);
    synthVoiceBox->addItem (TRANS("2"), 2);
    synthVoiceBox->addItem (TRANS("3"), 3);
    synthVoiceBox->addItem (TRANS("4"), 4);
    synthVoiceBox->addItem (TRANS("5"), 5);
    synthVoiceBox->addItem (TRANS("6"), 6);
    synthVoiceBox->addItem (TRANS("7"), 7);
    synthVoiceBox->addItem (TRANS("8"), 8);
    synthVoiceBox->addListener (this);

    addAndMakeVisible (label59 = new Label ("new label",
                                            TRANS("Voice No")));
    label59->setFont (Font (13.00f, Font::plain));
    label59->setJustificationType (Justification::centredLeft);
    label59->setEditable (false, false, false);
    label59->setColour (Label::textColourId, Colours::white);
    label59->setColour (TextEditor::textColourId, Colours::black);
    label59->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (delayOnSw = new ToggleButton ("new toggle button"));
    delayOnSw->setButtonText (TRANS("On"));
    delayOnSw->setConnectedEdges (Button::ConnectedOnLeft);
    delayOnSw->addListener (this);
    delayOnSw->setToggleState (true, dontSendNotification);
    delayOnSw->setColour (ToggleButton::textColourId, Colours::azure);

    addAndMakeVisible (filter2EnvBox = new ComboBox ("new combo box"));
    filter2EnvBox->setTooltip (TRANS("select the ADSR number used for the Filter modulation depth"));
    filter2EnvBox->setEditableText (false);
    filter2EnvBox->setJustificationType (Justification::centredLeft);
    filter2EnvBox->setTextWhenNothingSelected (String());
    filter2EnvBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    filter2EnvBox->addItem (TRANS("1"), 1);
    filter2EnvBox->addItem (TRANS("2"), 2);
    filter2EnvBox->addItem (TRANS("3"), 3);
    filter2EnvBox->addListener (this);

    addAndMakeVisible (label60 = new Label ("new label",
                                            TRANS("ADSR")));
    label60->setFont (Font (13.00f, Font::plain));
    label60->setJustificationType (Justification::centredLeft);
    label60->setEditable (false, false, false);
    label60->setColour (Label::textColourId, Colour (0xffa7b5b5));
    label60->setColour (TextEditor::textColourId, Colours::black);
    label60->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (filter1EnvBox = new ComboBox ("new combo box"));
    filter1EnvBox->setTooltip (TRANS("select the ADSR number used for the Filter modulation depth"));
    filter1EnvBox->setEditableText (false);
    filter1EnvBox->setJustificationType (Justification::centredLeft);
    filter1EnvBox->setTextWhenNothingSelected (String());
    filter1EnvBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    filter1EnvBox->addItem (TRANS("1"), 1);
    filter1EnvBox->addItem (TRANS("2"), 2);
    filter1EnvBox->addItem (TRANS("3"), 3);
    filter1EnvBox->addListener (this);

    addAndMakeVisible (label61 = new Label ("new label",
                                            TRANS("ADSR")));
    label61->setFont (Font (13.00f, Font::plain));
    label61->setJustificationType (Justification::centredLeft);
    label61->setEditable (false, false, false);
    label61->setColour (Label::textColourId, Colour (0xffa7b5b5));
    label61->setColour (TextEditor::textColourId, Colours::black);
    label61->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (filter1LfoBox = new ComboBox ("new combo box"));
    filter1LfoBox->setTooltip (TRANS("LFO selector."));
    filter1LfoBox->setEditableText (false);
    filter1LfoBox->setJustificationType (Justification::centredLeft);
    filter1LfoBox->setTextWhenNothingSelected (String());
    filter1LfoBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    filter1LfoBox->addItem (TRANS("Off"), 1);
    filter1LfoBox->addItem (TRANS("1"), 2);
    filter1LfoBox->addItem (TRANS("2"), 3);
    filter1LfoBox->addListener (this);

    addAndMakeVisible (label62 = new Label ("new label",
                                            TRANS("LFO")));
    label62->setFont (Font (13.00f, Font::plain));
    label62->setJustificationType (Justification::centredLeft);
    label62->setEditable (false, false, false);
    label62->setColour (Label::textColourId, Colour (0xffa7b5b5));
    label62->setColour (TextEditor::textColourId, Colours::black);
    label62->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (filterSequenceBox = new ComboBox ("new combo box"));
    filterSequenceBox->setTooltip (TRANS("LFO selector."));
    filterSequenceBox->setEditableText (false);
    filterSequenceBox->setJustificationType (Justification::centredLeft);
    filterSequenceBox->setTextWhenNothingSelected (String());
    filterSequenceBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    filterSequenceBox->addItem (TRANS("Parallel"), 1);
    filterSequenceBox->addItem (TRANS("1->2"), 2);
    filterSequenceBox->addItem (TRANS("2->1"), 3);
    filterSequenceBox->addListener (this);

    addAndMakeVisible (label63 = new Label ("new label",
                                            TRANS("Seq.")));
    label63->setFont (Font (15.00f, Font::plain));
    label63->setJustificationType (Justification::centredLeft);
    label63->setEditable (false, false, false);
    label63->setColour (Label::textColourId, Colour (0xffa7b5b5));
    label63->setColour (TextEditor::textColourId, Colours::black);
    label63->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (filter2LfoBox = new ComboBox ("new combo box"));
    filter2LfoBox->setTooltip (TRANS("LFO selector."));
    filter2LfoBox->setEditableText (false);
    filter2LfoBox->setJustificationType (Justification::centredLeft);
    filter2LfoBox->setTextWhenNothingSelected (String());
    filter2LfoBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    filter2LfoBox->addItem (TRANS("Off"), 1);
    filter2LfoBox->addItem (TRANS("1"), 2);
    filter2LfoBox->addItem (TRANS("2"), 3);
    filter2LfoBox->addListener (this);

    addAndMakeVisible (label64 = new Label ("new label",
                                            TRANS("LFO")));
    label64->setFont (Font (13.00f, Font::plain));
    label64->setJustificationType (Justification::centredLeft);
    label64->setEditable (false, false, false);
    label64->setColour (Label::textColourId, Colour (0xffa7b5b5));
    label64->setColour (TextEditor::textColourId, Colours::black);
    label64->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label65 = new Label ("new label",
                                            TRANS("LFO 1")));
    label65->setFont (Font (15.00f, Font::bold));
    label65->setJustificationType (Justification::bottomLeft);
    label65->setEditable (false, false, false);
    label65->setColour (Label::textColourId, Colour (0xff74c615));
    label65->setColour (TextEditor::textColourId, Colours::black);
    label65->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label66 = new Label ("new label",
                                            TRANS("LFO 2")));
    label66->setFont (Font (15.00f, Font::bold));
    label66->setJustificationType (Justification::bottomLeft);
    label66->setEditable (false, false, false);
    label66->setColour (Label::textColourId, Colour (0xff74c615));
    label66->setColour (TextEditor::textColourId, Colours::black);
    label66->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label37 = new Label ("new label",
                                            TRANS("Attack\n"
                                            "(sec)")));
    label37->setFont (Font (13.00f, Font::plain));
    label37->setJustificationType (Justification::centred);
    label37->setEditable (false, false, false);
    label37->setColour (Label::textColourId, Colour (0xff158ec6));
    label37->setColour (TextEditor::textColourId, Colours::black);
    label37->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label38 = new Label ("new label",
                                            TRANS("Sustain\n"
                                            "(..)")));
    label38->setFont (Font (13.00f, Font::plain));
    label38->setJustificationType (Justification::centred);
    label38->setEditable (false, false, false);
    label38->setColour (Label::textColourId, Colour (0xff158ec6));
    label38->setColour (TextEditor::textColourId, Colours::black);
    label38->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label39 = new Label ("new label",
                                            TRANS("Decay\n"
                                            "(sec)")));
    label39->setFont (Font (13.00f, Font::plain));
    label39->setJustificationType (Justification::centred);
    label39->setEditable (false, false, false);
    label39->setColour (Label::textColourId, Colour (0xff158ec6));
    label39->setColour (TextEditor::textColourId, Colours::black);
    label39->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label40 = new Label ("new label",
                                            TRANS("Release\n"
                                            "(sec)")));
    label40->setFont (Font (13.00f, Font::plain));
    label40->setJustificationType (Justification::centred);
    label40->setEditable (false, false, false);
    label40->setColour (Label::textColourId, Colour (0xff158ec6));
    label40->setColour (TextEditor::textColourId, Colours::black);
    label40->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label45 = new Label ("new label",
                                            TRANS("Attack\n"
                                            "(sec)")));
    label45->setFont (Font (13.00f, Font::plain));
    label45->setJustificationType (Justification::centred);
    label45->setEditable (false, false, false);
    label45->setColour (Label::textColourId, Colour (0xff158ec6));
    label45->setColour (TextEditor::textColourId, Colours::black);
    label45->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label46 = new Label ("new label",
                                            TRANS("Sustain\n"
                                            "(..)")));
    label46->setFont (Font (13.00f, Font::plain));
    label46->setJustificationType (Justification::centred);
    label46->setEditable (false, false, false);
    label46->setColour (Label::textColourId, Colour (0xff158ec6));
    label46->setColour (TextEditor::textColourId, Colours::black);
    label46->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label47 = new Label ("new label",
                                            TRANS("Decay\n"
                                            "(sec)")));
    label47->setFont (Font (13.00f, Font::plain));
    label47->setJustificationType (Justification::centred);
    label47->setEditable (false, false, false);
    label47->setColour (Label::textColourId, Colour (0xff158ec6));
    label47->setColour (TextEditor::textColourId, Colours::black);
    label47->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label48 = new Label ("new label",
                                            TRANS("Release\n"
                                            "(sec)")));
    label48->setFont (Font (13.00f, Font::plain));
    label48->setJustificationType (Justification::centred);
    label48->setEditable (false, false, false);
    label48->setColour (Label::textColourId, Colour (0xff158ec6));
    label48->setColour (TextEditor::textColourId, Colours::black);
    label48->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label67 = new Label ("new label",
                                            TRANS("Current Preset")));
    label67->setFont (Font (13.00f, Font::plain));
    label67->setJustificationType (Justification::centredLeft);
    label67->setEditable (false, false, false);
    label67->setColour (Label::textColourId, Colours::white);
    label67->setColour (TextEditor::textColourId, Colours::black);
    label67->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label68 = new Label ("new label",
                                            TRANS("REVERB")));
    label68->setFont (Font (15.00f, Font::bold));
    label68->setJustificationType (Justification::bottomLeft);
    label68->setEditable (false, false, false);
    label68->setColour (Label::textColourId, Colour (0xffc1b115));
    label68->setColour (TextEditor::textColourId, Colours::black);
    label68->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label22 = new Label ("new label",
                                            TRANS("DELAY")));
    label22->setFont (Font (15.00f, Font::bold));
    label22->setJustificationType (Justification::bottomLeft);
    label22->setEditable (false, false, false);
    label22->setColour (Label::textColourId, Colour (0xff865cad));
    label22->setColour (TextEditor::textColourId, Colours::black);
    label22->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label69 = new Label ("new label",
                                            TRANS("OUTPUT")));
    label69->setFont (Font (15.00f, Font::bold));
    label69->setJustificationType (Justification::bottomLeft);
    label69->setEditable (false, false, false);
    label69->setColour (Label::textColourId, Colours::crimson);
    label69->setColour (TextEditor::textColourId, Colours::black);
    label69->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label70 = new Label ("new label",
                                            TRANS("tinySynth 1.2.5")));
    label70->setFont (Font (15.00f, Font::bold));
    label70->setJustificationType (Justification::topRight);
    label70->setEditable (false, false, false);
    label70->setColour (Label::textColourId, Colours::white);
    label70->setColour (TextEditor::textColourId, Colours::black);
    label70->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (reverbDryWetSlider = new Slider ("new slider"));
    reverbDryWetSlider->setRange (0, 1, 0.01);
    reverbDryWetSlider->setSliderStyle (Slider::Rotary);
    reverbDryWetSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    reverbDryWetSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffc1b115));
    reverbDryWetSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xffd2d2d2));
    reverbDryWetSlider->setColour (Slider::textBoxTextColourId, Colour (0xffc1b115));
    reverbDryWetSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00faf7f7));
    reverbDryWetSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    reverbDryWetSlider->addListener (this);

    addAndMakeVisible (label72 = new Label ("new label",
                                            TRANS("Dry/Wet")));
    label72->setFont (Font (13.00f, Font::plain));
    label72->setJustificationType (Justification::centred);
    label72->setEditable (false, false, false);
    label72->setColour (Label::textColourId, Colour (0xffc1b115));
    label72->setColour (TextEditor::textColourId, Colours::black);
    label72->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (reverbSizeSlider = new Slider ("new slider"));
    reverbSizeSlider->setRange (0, 1, 0.01);
    reverbSizeSlider->setSliderStyle (Slider::Rotary);
    reverbSizeSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    reverbSizeSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffc1b115));
    reverbSizeSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xffd2d2d2));
    reverbSizeSlider->setColour (Slider::textBoxTextColourId, Colour (0xffc1b115));
    reverbSizeSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00faf7f7));
    reverbSizeSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    reverbSizeSlider->addListener (this);

    addAndMakeVisible (label73 = new Label ("new label",
                                            TRANS("Size")));
    label73->setFont (Font (13.00f, Font::plain));
    label73->setJustificationType (Justification::centred);
    label73->setEditable (false, false, false);
    label73->setColour (Label::textColourId, Colour (0xffc1b115));
    label73->setColour (TextEditor::textColourId, Colours::black);
    label73->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (reverbDampSlider = new Slider ("new slider"));
    reverbDampSlider->setRange (0, 1, 0.01);
    reverbDampSlider->setSliderStyle (Slider::Rotary);
    reverbDampSlider->setTextBoxStyle (Slider::TextBoxAbove, true, 80, 10);
    reverbDampSlider->setColour (Slider::rotarySliderFillColourId, Colour (0xffc1b115));
    reverbDampSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xffd2d2d2));
    reverbDampSlider->setColour (Slider::textBoxTextColourId, Colour (0xffc1b115));
    reverbDampSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00faf7f7));
    reverbDampSlider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    reverbDampSlider->addListener (this);

    addAndMakeVisible (label74 = new Label ("new label",
                                            TRANS("Damp")));
    label74->setFont (Font (13.00f, Font::plain));
    label74->setJustificationType (Justification::centred);
    label74->setEditable (false, false, false);
    label74->setColour (Label::textColourId, Colour (0xffc1b115));
    label74->setColour (TextEditor::textColourId, Colours::black);
    label74->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (reverbOnSw = new ToggleButton ("new toggle button"));
    reverbOnSw->setButtonText (TRANS("On"));
    reverbOnSw->setConnectedEdges (Button::ConnectedOnLeft);
    reverbOnSw->addListener (this);
    reverbOnSw->setToggleState (true, dontSendNotification);
    reverbOnSw->setColour (ToggleButton::textColourId, Colours::azure);

    addAndMakeVisible (osc1SemiToneBox = new ComboBox ("new combo box"));
    osc1SemiToneBox->setEditableText (false);
    osc1SemiToneBox->setJustificationType (Justification::centredLeft);
    osc1SemiToneBox->setTextWhenNothingSelected (String());
    osc1SemiToneBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    osc1SemiToneBox->addItem (TRANS("0"), 1);
    osc1SemiToneBox->addItem (TRANS("1"), 2);
    osc1SemiToneBox->addItem (TRANS("2"), 3);
    osc1SemiToneBox->addItem (TRANS("3"), 4);
    osc1SemiToneBox->addItem (TRANS("4"), 5);
    osc1SemiToneBox->addItem (TRANS("5"), 6);
    osc1SemiToneBox->addItem (TRANS("6"), 7);
    osc1SemiToneBox->addItem (TRANS("7"), 8);
    osc1SemiToneBox->addItem (TRANS("8"), 9);
    osc1SemiToneBox->addItem (TRANS("9"), 10);
    osc1SemiToneBox->addItem (TRANS("10"), 11);
    osc1SemiToneBox->addItem (TRANS("11"), 12);
    osc1SemiToneBox->addListener (this);

    addAndMakeVisible (osc2SemiToneBox = new ComboBox ("new combo box"));
    osc2SemiToneBox->setEditableText (false);
    osc2SemiToneBox->setJustificationType (Justification::centredLeft);
    osc2SemiToneBox->setTextWhenNothingSelected (String());
    osc2SemiToneBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    osc2SemiToneBox->addItem (TRANS("0"), 1);
    osc2SemiToneBox->addItem (TRANS("1"), 2);
    osc2SemiToneBox->addItem (TRANS("2"), 3);
    osc2SemiToneBox->addItem (TRANS("3"), 4);
    osc2SemiToneBox->addItem (TRANS("4"), 5);
    osc2SemiToneBox->addItem (TRANS("5"), 6);
    osc2SemiToneBox->addItem (TRANS("6"), 7);
    osc2SemiToneBox->addItem (TRANS("7"), 8);
    osc2SemiToneBox->addItem (TRANS("8"), 9);
    osc2SemiToneBox->addItem (TRANS("9"), 10);
    osc2SemiToneBox->addItem (TRANS("10"), 11);
    osc2SemiToneBox->addItem (TRANS("11"), 12);
    osc2SemiToneBox->addListener (this);

    addAndMakeVisible (osc3SemiToneBox = new ComboBox ("new combo box"));
    osc3SemiToneBox->setEditableText (false);
    osc3SemiToneBox->setJustificationType (Justification::centredLeft);
    osc3SemiToneBox->setTextWhenNothingSelected (String());
    osc3SemiToneBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    osc3SemiToneBox->addItem (TRANS("0"), 1);
    osc3SemiToneBox->addItem (TRANS("1"), 2);
    osc3SemiToneBox->addItem (TRANS("2"), 3);
    osc3SemiToneBox->addItem (TRANS("3"), 4);
    osc3SemiToneBox->addItem (TRANS("4"), 5);
    osc3SemiToneBox->addItem (TRANS("5"), 6);
    osc3SemiToneBox->addItem (TRANS("6"), 7);
    osc3SemiToneBox->addItem (TRANS("7"), 8);
    osc3SemiToneBox->addItem (TRANS("8"), 9);
    osc3SemiToneBox->addItem (TRANS("9"), 10);
    osc3SemiToneBox->addItem (TRANS("10"), 11);
    osc3SemiToneBox->addItem (TRANS("11"), 12);
    osc3SemiToneBox->addListener (this);


    //[UserPreSize]
	saveTXT->setColour (Label::textColourId, Colours::white);
	loadTXT->setColour (Label::textColourId, Colours::white);
	osc1On->changeWidthToFitText();
	osc2On->changeWidthToFitText();
	osc3On->changeWidthToFitText();

	// the position of the knob in the middle  is the one between brackets
	// it grows in an unlinear way inside its range of values
	filter1FreqSlider->setSkewFactorFromMidPoint (500);
	filter2FreqSlider->setSkewFactorFromMidPoint (500);

	lfo1FreqSlider->setSkewFactorFromMidPoint (5);
 	lfo2FreqSlider->setSkewFactorFromMidPoint (5);

	osc1lvlSlider->setSkewFactorFromMidPoint (-6);
 	osc2lvlSlider->setSkewFactorFromMidPoint (-6);
 	osc3lvlSlider->setSkewFactorFromMidPoint (-6);

	adsr1AttackSlider->setSkewFactorFromMidPoint (1);
	adsr1DecaySlider->setSkewFactorFromMidPoint (1);
	adsr1ReleaseSlider->setSkewFactorFromMidPoint (1);
	adsr1SustainSlider->setSkewFactorFromMidPoint (1);

	adsr2AttackSlider->setSkewFactorFromMidPoint (1);
	adsr2DecaySlider->setSkewFactorFromMidPoint (1);
	adsr2ReleaseSlider->setSkewFactorFromMidPoint (1);
	adsr2SustainSlider->setSkewFactorFromMidPoint (1);

	adsr3AttackSlider->setSkewFactorFromMidPoint (1);
	adsr3DecaySlider->setSkewFactorFromMidPoint (1);
	adsr3ReleaseSlider->setSkewFactorFromMidPoint (1);
	adsr3SustainSlider->setSkewFactorFromMidPoint (1);
    //[/UserPreSize]

    setSize (898, 665);


    //[Constructor] You can add your own custom stuff here..
	// set the flag UIUpdateFlag=True and the internal timer to 200 msec.
	// see timerCallback ()  for details about the GUI synchronization WRT the internal parameters.
	getProcessor()->RequestUIUpdate();
	startTimer(200);
    //[/Constructor]
}

tinySynthAudioProcessorEditor::~tinySynthAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    outputGroup = nullptr;
    lfoGroup5 = nullptr;
    reverbGroup = nullptr;
    lfoGroup2 = nullptr;
    lfoGroup3 = nullptr;
    filterGroup = nullptr;
    filter1EnvModDepthSlider = nullptr;
    lfo1DevSlider = nullptr;
    oscGroup = nullptr;
    label21 = nullptr;
    adsr1SustainSlider = nullptr;
    osc1lvlSlider = nullptr;
    delayGroup = nullptr;
    delayFBSlider = nullptr;
    delayGainSlider = nullptr;
    label8 = nullptr;
    adsr1DecaySlider = nullptr;
    adsr1AttackSlider = nullptr;
    delayTimeSlider = nullptr;
    label = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    label4 = nullptr;
    label5 = nullptr;
    label6 = nullptr;
    label7 = nullptr;
    noiseSlider = nullptr;
    driveSlider = nullptr;
    outputGainSlider = nullptr;
    label11 = nullptr;
    label12 = nullptr;
    label13 = nullptr;
    adsr1ReleaseSlider = nullptr;
    osc3WaveBox = nullptr;
    osc3OctaveBox = nullptr;
    label23 = nullptr;
    label24 = nullptr;
    label25 = nullptr;
    label27 = nullptr;
    label29 = nullptr;
    filter1FreqSlider = nullptr;
    label31 = nullptr;
    label32 = nullptr;
    label33 = nullptr;
    lfo1FreqSlider = nullptr;
    lfo1WaveBox = nullptr;
    lfo1DestBox = nullptr;
    label9 = nullptr;
    osc3lvlSlider = nullptr;
    filter1ResSlider = nullptr;
    filter1TypeBox = nullptr;
    label10 = nullptr;
    label26 = nullptr;
    osc2WaveBox = nullptr;
    osc2OctaveBox = nullptr;
    label14 = nullptr;
    label15 = nullptr;
    label16 = nullptr;
    osc2lvlSlider = nullptr;
    label17 = nullptr;
    osc1WaveBox = nullptr;
    osc1OctaveBox = nullptr;
    label18 = nullptr;
    label19 = nullptr;
    label20 = nullptr;
    filter2EnvModDepthSlider = nullptr;
    filter2FreqSlider = nullptr;
    label30 = nullptr;
    label34 = nullptr;
    label35 = nullptr;
    filter2ResSlider = nullptr;
    filter2TypeBox = nullptr;
    label36 = nullptr;
    adsr2SustainSlider = nullptr;
    adsr2DecaySlider = nullptr;
    adsr2AttackSlider = nullptr;
    adsr2ReleaseSlider = nullptr;
    lfo2DevSlider = nullptr;
    label41 = nullptr;
    label42 = nullptr;
    label43 = nullptr;
    lfo2FreqSlider = nullptr;
    lfo2WaveBox = nullptr;
    lfo2DestBox = nullptr;
    label44 = nullptr;
    adsr3SustainSlider = nullptr;
    adsr3DecaySlider = nullptr;
    adsr3AttackSlider = nullptr;
    adsr3ReleaseSlider = nullptr;
    osc1LfoBox = nullptr;
    label49 = nullptr;
    osc1EnvBox = nullptr;
    label50 = nullptr;
    osc2LfoBox = nullptr;
    label51 = nullptr;
    osc2EnvBox = nullptr;
    label52 = nullptr;
    osc3LfoBox = nullptr;
    label53 = nullptr;
    osc3EnvBox = nullptr;
    label54 = nullptr;
    label28 = nullptr;
    label55 = nullptr;
    label56 = nullptr;
    label57 = nullptr;
    label58 = nullptr;
    saveTXT = nullptr;
    loadTXT = nullptr;
    checkP = nullptr;
    presetName = nullptr;
    osc1On = nullptr;
    osc2On = nullptr;
    osc3On = nullptr;
    synthVoiceBox = nullptr;
    label59 = nullptr;
    delayOnSw = nullptr;
    filter2EnvBox = nullptr;
    label60 = nullptr;
    filter1EnvBox = nullptr;
    label61 = nullptr;
    filter1LfoBox = nullptr;
    label62 = nullptr;
    filterSequenceBox = nullptr;
    label63 = nullptr;
    filter2LfoBox = nullptr;
    label64 = nullptr;
    label65 = nullptr;
    label66 = nullptr;
    label37 = nullptr;
    label38 = nullptr;
    label39 = nullptr;
    label40 = nullptr;
    label45 = nullptr;
    label46 = nullptr;
    label47 = nullptr;
    label48 = nullptr;
    label67 = nullptr;
    label68 = nullptr;
    label22 = nullptr;
    label69 = nullptr;
    label70 = nullptr;
    reverbDryWetSlider = nullptr;
    label72 = nullptr;
    reverbSizeSlider = nullptr;
    label73 = nullptr;
    reverbDampSlider = nullptr;
    label74 = nullptr;
    reverbOnSw = nullptr;
    osc1SemiToneBox = nullptr;
    osc2SemiToneBox = nullptr;
    osc3SemiToneBox = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void tinySynthAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff131a26));

    g.setColour (Colours::black);
    g.fillRoundedRectangle (729.0f, 8.0f, 80.0f, 320.0f, 1.000f);

    g.setColour (Colour (0xff0a0808));
    g.fillRoundedRectangle (4.0f, 10.0f, 238.0f, 154.0f, 1.000f);

    g.setColour (Colour (0xff6a716c));
    g.drawRoundedRectangle (4.0f, 10.0f, 238.0f, 154.0f, 1.000f, 1.000f);

    g.setColour (Colours::black);
    g.fillRoundedRectangle (367.0f, 470.0f, 358.0f, 137.0f, 1.000f);

    g.setColour (Colour (0xff6c6a73));
    g.drawRoundedRectangle (367.0f, 470.0f, 358.0f, 137.0f, 1.000f, 1.000f);

    g.setColour (Colours::black);
    g.fillRoundedRectangle (367.0f, 169.0f, 358.0f, 155.0f, 1.000f);

    g.setColour (Colour (0xff717d79));
    g.drawRoundedRectangle (367.0f, 169.0f, 358.0f, 155.0f, 1.000f, 1.000f);

    g.setColour (Colours::black);
    g.fillRoundedRectangle (816.0f, 8.0f, 80.0f, 320.0f, 1.000f);

    g.setColour (Colours::black);
    g.fillRoundedRectangle (4.0f, 169.0f, 361.0f, 155.0f, 1.000f);

    g.setColour (Colour (0xff7b7575));
    g.drawRoundedRectangle (4.0f, 169.0f, 361.0f, 155.0f, 1.000f, 1.000f);

    g.setColour (Colours::black);
    g.fillRoundedRectangle (4.0f, 470.0f, 361.0f, 137.0f, 1.000f);

    g.setColour (Colour (0xff7d8078));
    g.drawRoundedRectangle (4.0f, 470.0f, 361.0f, 137.0f, 1.000f, 1.000f);

    g.setColour (Colour (0xff0a0808));
    g.fillRoundedRectangle (244.0f, 10.0f, 238.0f, 154.0f, 1.000f);

    g.setColour (Colour (0xff7c8087));
    g.drawRoundedRectangle (244.0f, 10.0f, 238.0f, 154.0f, 1.000f, 1.000f);

    g.setColour (Colour (0xff0a0808));
    g.fillRoundedRectangle (484.0f, 10.0f, 240.0f, 154.0f, 1.000f);

    g.setColour (Colour (0xff7e7e79));
    g.drawRoundedRectangle (484.0f, 10.0f, 240.0f, 154.0f, 1.000f, 1.000f);

    g.setColour (Colours::black);
    g.fillRoundedRectangle (4.0f, 328.0f, 238.0f, 137.0f, 1.000f);

    g.setColour (Colour (0xff75787d));
    g.drawRoundedRectangle (4.0f, 328.0f, 238.0f, 137.0f, 1.000f, 1.000f);

    g.setColour (Colours::black);
    g.fillRoundedRectangle (244.0f, 328.0f, 238.0f, 137.0f, 1.000f);

    g.setColour (Colour (0xff7a7474));
    g.drawRoundedRectangle (244.0f, 328.0f, 238.0f, 137.0f, 1.000f, 1.000f);

    g.setColour (Colours::black);
    g.fillRoundedRectangle (484.0f, 328.0f, 240.0f, 137.0f, 1.000f);

    g.setColour (Colour (0xff757276));
    g.drawRoundedRectangle (484.0f, 328.0f, 240.0f, 137.0f, 1.000f, 1.000f);

    g.setColour (Colours::black);
    g.fillRect (728, 328, 168, 280);

    g.setColour (Colours::black);
    g.fillRect (0, 608, 896, 56);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void tinySynthAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    outputGroup->setBounds (810, 0, 88, 328);
    lfoGroup5->setBounds (0, 601, 898, 63);
    reverbGroup->setBounds (725, 319, 172, 291);
    lfoGroup2->setBounds (0, 460, 728, 150);
    lfoGroup3->setBounds (0, 319, 728, 150);
    filterGroup->setBounds (0, 160, 728, 168);
    filter1EnvModDepthSlider->setBounds (298, 208, 50, 65);
    lfo1DevSlider->setBounds (220, 502, 50, 65);
    oscGroup->setBounds (0, 0, 728, 168);
    label21->setBounds (2, 8, 113, 20);
    adsr1SustainSlider->setBounds (124, 359, 50, 65);
    osc1lvlSlider->setBounds (168, 47, 50, 65);
    delayGroup->setBounds (725, 0, 88, 328);
    delayFBSlider->setBounds (824, 248, 50, 65);
    delayGainSlider->setBounds (824, 152, 50, 65);
    label8->setBounds (2, 502, 80, 20);
    adsr1DecaySlider->setBounds (69, 359, 50, 65);
    adsr1AttackSlider->setBounds (14, 359, 50, 65);
    delayTimeSlider->setBounds (824, 60, 50, 65);
    label->setBounds (-6, 418, 88, 25);
    label2->setBounds (104, 418, 88, 25);
    label3->setBounds (48, 418, 88, 25);
    label4->setBounds (161, 418, 88, 25);
    label5->setBounds (808, 304, 88, 20);
    label6->setBounds (808, 208, 88, 20);
    label7->setBounds (808, 116, 88, 20);
    noiseSlider->setBounds (781, 340, 50, 65);
    driveSlider->setBounds (781, 432, 50, 65);
    outputGainSlider->setBounds (781, 528, 50, 65);
    label11->setBounds (766, 581, 88, 20);
    label12->setBounds (764, 488, 88, 20);
    label13->setBounds (764, 396, 88, 20);
    adsr1ReleaseSlider->setBounds (179, 359, 50, 65);
    osc3WaveBox->setBounds (537, 48, 90, 20);
    osc3OctaveBox->setBounds (537, 73, 43, 20);
    label23->setBounds (485, 73, 80, 20);
    label24->setBounds (485, 48, 80, 20);
    label25->setBounds (643, 104, 78, 29);
    label27->setBounds (136, 575, 88, 31);
    label29->setBounds (200, 575, 88, 20);
    filter1FreqSlider->setBounds (155, 208, 50, 65);
    label31->setBounds (200, 264, 88, 20);
    label32->setBounds (136, 260, 88, 40);
    label33->setBounds (280, 260, 88, 40);
    lfo1FreqSlider->setBounds (155, 502, 50, 65);
    lfo1WaveBox->setBounds (50, 527, 90, 20);
    lfo1DestBox->setBounds (50, 502, 90, 20);
    label9->setBounds (2, 527, 80, 20);
    osc3lvlSlider->setBounds (658, 46, 50, 65);
    filter1ResSlider->setBounds (220, 208, 50, 65);
    filter1TypeBox->setBounds (50, 206, 90, 20);
    label10->setBounds (2, 204, 88, 24);
    label26->setBounds (485, 8, 111, 20);
    osc2WaveBox->setBounds (296, 48, 90, 20);
    osc2OctaveBox->setBounds (296, 73, 43, 20);
    label14->setBounds (245, 73, 80, 20);
    label15->setBounds (245, 48, 80, 20);
    label16->setBounds (403, 104, 77, 29);
    osc2lvlSlider->setBounds (417, 46, 50, 65);
    label17->setBounds (245, 6, 111, 22);
    osc1WaveBox->setBounds (52, 48, 90, 20);
    osc1OctaveBox->setBounds (52, 73, 43, 20);
    label18->setBounds (2, 73, 80, 20);
    label19->setBounds (2, 48, 80, 20);
    label20->setBounds (152, 105, 80, 29);
    filter2EnvModDepthSlider->setBounds (670, 204, 50, 65);
    filter2FreqSlider->setBounds (525, 203, 50, 65);
    label30->setBounds (577, 259, 88, 20);
    label34->setBounds (506, 259, 88, 33);
    label35->setBounds (647, 259, 88, 35);
    filter2ResSlider->setBounds (596, 203, 50, 65);
    filter2TypeBox->setBounds (421, 206, 90, 20);
    label36->setBounds (366, 204, 88, 24);
    adsr2SustainSlider->setBounds (366, 359, 50, 65);
    adsr2DecaySlider->setBounds (311, 359, 50, 65);
    adsr2AttackSlider->setBounds (256, 359, 50, 65);
    adsr2ReleaseSlider->setBounds (421, 359, 50, 65);
    lfo2DevSlider->setBounds (596, 503, 50, 65);
    label41->setBounds (368, 502, 80, 20);
    label42->setBounds (506, 576, 88, 30);
    label43->setBounds (577, 576, 88, 20);
    lfo2FreqSlider->setBounds (525, 503, 50, 65);
    lfo2WaveBox->setBounds (421, 527, 90, 20);
    lfo2DestBox->setBounds (421, 502, 90, 20);
    label44->setBounds (368, 527, 80, 20);
    adsr3SustainSlider->setBounds (612, 359, 50, 65);
    adsr3DecaySlider->setBounds (557, 359, 50, 65);
    adsr3AttackSlider->setBounds (502, 359, 50, 65);
    adsr3ReleaseSlider->setBounds (667, 359, 50, 65);
    osc1LfoBox->setBounds (97, 98, 45, 20);
    label49->setBounds (46, 98, 52, 20);
    osc1EnvBox->setBounds (97, 123, 45, 20);
    label50->setBounds (46, 123, 60, 20);
    osc2LfoBox->setBounds (340, 98, 45, 20);
    label51->setBounds (290, 98, 49, 20);
    osc2EnvBox->setBounds (340, 123, 45, 20);
    label52->setBounds (290, 123, 49, 20);
    osc3LfoBox->setBounds (582, 98, 45, 20);
    label53->setBounds (531, 98, 37, 20);
    osc3EnvBox->setBounds (582, 123, 45, 20);
    label54->setBounds (531, 123, 45, 20);
    label28->setBounds (366, 169, 84, 20);
    label55->setBounds (3, 169, 75, 20);
    label56->setBounds (3, 328, 68, 20);
    label57->setBounds (248, 328, 72, 20);
    label58->setBounds (489, 328, 78, 20);
    saveTXT->setBounds (232, 638, 88, 20);
    loadTXT->setBounds (232, 616, 88, 20);
    checkP->setBounds (792, 638, 88, 20);
    presetName->setBounds (75, 637, 150, 20);
    osc1On->setBounds (172, 8, 42, 24);
    osc2On->setBounds (419, 8, 42, 24);
    osc3On->setBounds (659, 7, 42, 24);
    synthVoiceBox->setBounds (16, 637, 45, 20);
    label59->setBounds (10, 614, 88, 20);
    delayOnSw->setBounds (824, 27, 42, 24);
    filter2EnvBox->setBounds (466, 256, 45, 20);
    label60->setBounds (415, 256, 56, 20);
    filter1EnvBox->setBounds (95, 256, 45, 20);
    label61->setBounds (43, 256, 45, 20);
    filter1LfoBox->setBounds (95, 231, 45, 20);
    label62->setBounds (45, 231, 43, 20);
    filterSequenceBox->setBounds (421, 281, 90, 20);
    label63->setBounds (366, 281, 64, 20);
    filter2LfoBox->setBounds (466, 231, 45, 20);
    label64->setBounds (415, 231, 41, 20);
    label65->setBounds (3, 469, 68, 20);
    label66->setBounds (368, 469, 68, 20);
    label37->setBounds (236, 418, 88, 25);
    label38->setBounds (346, 418, 88, 25);
    label39->setBounds (290, 418, 88, 25);
    label40->setBounds (403, 418, 88, 25);
    label45->setBounds (481, 417, 88, 25);
    label46->setBounds (591, 417, 88, 25);
    label47->setBounds (535, 417, 88, 25);
    label48->setBounds (648, 417, 88, 25);
    label67->setBounds (69, 614, 88, 20);
    label68->setBounds (728, 8, 78, 20);
    label22->setBounds (816, 8, 78, 20);
    label69->setBounds (728, 328, 78, 20);
    label70->setBounds (731, 613, 166, 20);
    reverbDryWetSlider->setBounds (743, 58, 50, 65);
    label72->setBounds (725, 117, 88, 20);
    reverbSizeSlider->setBounds (742, 148, 50, 65);
    label73->setBounds (723, 209, 88, 20);
    reverbDampSlider->setBounds (742, 250, 50, 65);
    label74->setBounds (722, 306, 88, 20);
    reverbOnSw->setBounds (744, 27, 42, 24);
    osc1SemiToneBox->setBounds (97, 73, 45, 20);
    osc2SemiToneBox->setBounds (340, 73, 45, 20);
    osc3SemiToneBox->setBounds (582, 73, 45, 20);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void tinySynthAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
	// sliderValueChanged management method is called every time the user changes the value of a slider
	// the code  associated  for each slider is the one reported inside the if / else if sections
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == filter1EnvModDepthSlider)
    {
        //[UserSliderCode_filter1EnvModDepthSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::filter1EnvModDepthParam, (float) filter1EnvModDepthSlider->getValue());
        //[/UserSliderCode_filter1EnvModDepthSlider]
    }
    else if (sliderThatWasMoved == lfo1DevSlider)
    {
        //[UserSliderCode_lfo1DevSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::lfo1DevParam, (float) lfo1DevSlider->getValue());
        //[/UserSliderCode_lfo1DevSlider]
    }
    else if (sliderThatWasMoved == adsr1SustainSlider)
    {
        //[UserSliderCode_adsr1SustainSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::adsr1SustainParam, (float) adsr1SustainSlider->getValue());
        //[/UserSliderCode_adsr1SustainSlider]
    }
    else if (sliderThatWasMoved == osc1lvlSlider)
    {
        //[UserSliderCode_osc1lvlSlider] -- add your slider handling code here..
		float _osc1LevelParam = (float) pow(10, 0.05 * osc1lvlSlider->getValue());
		if (_osc1LevelParam < 0.00002f ) { _osc1LevelParam = 0.0f; }
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::osc1LevelParam, _osc1LevelParam);
        //[/UserSliderCode_osc1lvlSlider]
    }
    else if (sliderThatWasMoved == delayFBSlider)
    {
        //[UserSliderCode_delayFBSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::delayFeedbackParam, (float) pow(10, 0.05 * delayFBSlider->getValue()));
        //[/UserSliderCode_delayFBSlider]
    }
    else if (sliderThatWasMoved == delayGainSlider)
    {
        //[UserSliderCode_delayGainSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::delayGainParam, (float) pow(10, 0.05 * delayGainSlider->getValue()));
        //[/UserSliderCode_delayGainSlider]
    }
    else if (sliderThatWasMoved == adsr1DecaySlider)
    {
        //[UserSliderCode_adsr1DecaySlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::adsr1DecayParam, (float) adsr1DecaySlider->getValue());
        //[/UserSliderCode_adsr1DecaySlider]
    }
    else if (sliderThatWasMoved == adsr1AttackSlider)
    {
        //[UserSliderCode_adsr1AttackSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::adsr1AttackParam, (float) adsr1AttackSlider->getValue());
        //[/UserSliderCode_adsr1AttackSlider]
    }
    else if (sliderThatWasMoved == delayTimeSlider)
    {
        //[UserSliderCode_delayTimeSlider] -- add your slider handling code here..
		double sampleRate = getProcessor()->getSampleRate();
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::delayTimeParam, (float) floor(sampleRate * (float) delayTimeSlider->getValue()));
        //[/UserSliderCode_delayTimeSlider]
    }
    else if (sliderThatWasMoved == noiseSlider)
    {
        //[UserSliderCode_noiseSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::noiseParam, (float) pow(10, 0.05 * noiseSlider->getValue()));
        //[/UserSliderCode_noiseSlider]
    }
    else if (sliderThatWasMoved == driveSlider)
    {
        //[UserSliderCode_driveSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::driveParam, (float) driveSlider->getValue());
        //[/UserSliderCode_driveSlider]
    }
    else if (sliderThatWasMoved == outputGainSlider)
    {
        //[UserSliderCode_outputGainSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::outputGainParam, (float) pow(10, 0.05 * outputGainSlider->getValue()));
        //[/UserSliderCode_outputGainSlider]
    }
    else if (sliderThatWasMoved == adsr1ReleaseSlider)
    {
        //[UserSliderCode_adsr1ReleaseSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::adsr1ReleaseParam, (float) adsr1ReleaseSlider->getValue());
        //[/UserSliderCode_adsr1ReleaseSlider]
    }
    else if (sliderThatWasMoved == filter1FreqSlider)
    {
        //[UserSliderCode_filter1FreqSlider] -- add your slider handling code here..
		double sampleRate = getProcessor()->getSampleRate();
        // Convert from Hz to rads/sample
        float radsPerSample = 2 * (float) PI * (float) filter1FreqSlider->getValue()/sampleRate;
        getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::filter1CutoffParam, radsPerSample);
        //[/UserSliderCode_filter1FreqSlider]
    }
    else if (sliderThatWasMoved == lfo1FreqSlider)
    {
        //[UserSliderCode_lfo1FreqSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::lfo1FreqParam, (float) lfo1FreqSlider->getValue());
        //[/UserSliderCode_lfo1FreqSlider]
    }
    else if (sliderThatWasMoved == osc3lvlSlider)
    {
        //[UserSliderCode_osc3lvlSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::osc3LevelParam, (float) pow(10, 0.05 * osc3lvlSlider->getValue()));
        //[/UserSliderCode_osc3lvlSlider]
    }
    else if (sliderThatWasMoved == filter1ResSlider)
    {
        //[UserSliderCode_filter1ResSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::filter1ResonanceParam, (float) pow(10, 0.05 * filter1ResSlider->getValue()));
        //[/UserSliderCode_filter1ResSlider]
    }
    else if (sliderThatWasMoved == osc2lvlSlider)
    {
        //[UserSliderCode_osc2lvlSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::osc2LevelParam, (float) pow(10, 0.05 * osc2lvlSlider->getValue()));
        //[/UserSliderCode_osc2lvlSlider]
    }
    else if (sliderThatWasMoved == filter2EnvModDepthSlider)
    {
        //[UserSliderCode_filter2EnvModDepthSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::filter2EnvModDepthParam, (float) filter2EnvModDepthSlider->getValue());
        //[/UserSliderCode_filter2EnvModDepthSlider]
    }
    else if (sliderThatWasMoved == filter2FreqSlider)
    {
        //[UserSliderCode_filter2FreqSlider] -- add your slider handling code here..
		float sampleRate = getProcessor()->getSampleRate();
        // Convert from Hz to rads/sample
        float radsPerSample = 2 * PI * (float) filter2FreqSlider->getValue()/sampleRate;
        getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::filter2CutoffParam, radsPerSample);
        //[/UserSliderCode_filter2FreqSlider]
    }
    else if (sliderThatWasMoved == filter2ResSlider)
    {
        //[UserSliderCode_filter2ResSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::filter2ResonanceParam, (float) pow(10, 0.05 * filter2ResSlider->getValue()));
        //[/UserSliderCode_filter2ResSlider]
    }
    else if (sliderThatWasMoved == adsr2SustainSlider)
    {
        //[UserSliderCode_adsr2SustainSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::adsr2SustainParam, (float) adsr2SustainSlider->getValue());
        //[/UserSliderCode_adsr2SustainSlider]
    }
    else if (sliderThatWasMoved == adsr2DecaySlider)
    {
        //[UserSliderCode_adsr2DecaySlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::adsr2DecayParam, (float) adsr2DecaySlider->getValue());
        //[/UserSliderCode_adsr2DecaySlider]
    }
    else if (sliderThatWasMoved == adsr2AttackSlider)
    {
        //[UserSliderCode_adsr2AttackSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::adsr2AttackParam, (float) adsr2AttackSlider->getValue());
        //[/UserSliderCode_adsr2AttackSlider]
    }
    else if (sliderThatWasMoved == adsr2ReleaseSlider)
    {
        //[UserSliderCode_adsr2ReleaseSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::adsr2ReleaseParam, (float) adsr2ReleaseSlider->getValue());
        //[/UserSliderCode_adsr2ReleaseSlider]
    }
    else if (sliderThatWasMoved == lfo2DevSlider)
    {
        //[UserSliderCode_lfo2DevSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::lfo2DevParam, (float) lfo2DevSlider->getValue());
        //[/UserSliderCode_lfo2DevSlider]
    }
    else if (sliderThatWasMoved == lfo2FreqSlider)
    {
        //[UserSliderCode_lfo2FreqSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::lfo2FreqParam, (float) lfo2FreqSlider->getValue());
        //[/UserSliderCode_lfo2FreqSlider]
    }
    else if (sliderThatWasMoved == adsr3SustainSlider)
    {
        //[UserSliderCode_adsr3SustainSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::adsr3SustainParam, (float) adsr3SustainSlider->getValue());
        //[/UserSliderCode_adsr3SustainSlider]
    }
    else if (sliderThatWasMoved == adsr3DecaySlider)
    {
        //[UserSliderCode_adsr3DecaySlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::adsr3DecayParam, (float) adsr3DecaySlider->getValue());
        //[/UserSliderCode_adsr3DecaySlider]
    }
    else if (sliderThatWasMoved == adsr3AttackSlider)
    {
        //[UserSliderCode_adsr3AttackSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::adsr3AttackParam, (float) adsr3AttackSlider->getValue());
        //[/UserSliderCode_adsr3AttackSlider]
    }
    else if (sliderThatWasMoved == adsr3ReleaseSlider)
    {
        //[UserSliderCode_adsr3ReleaseSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::adsr3ReleaseParam, (float) adsr3ReleaseSlider->getValue());
        //[/UserSliderCode_adsr3ReleaseSlider]
    }
    else if (sliderThatWasMoved == reverbDryWetSlider)
    {
        //[UserSliderCode_reverbDryWetSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::reverbDryWetParam, (float) reverbDryWetSlider->getValue());
        //[/UserSliderCode_reverbDryWetSlider]
    }
    else if (sliderThatWasMoved == reverbSizeSlider)
    {
        //[UserSliderCode_reverbSizeSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::reverbSizeParam, (float) reverbSizeSlider->getValue());
        //[/UserSliderCode_reverbSizeSlider]
    }
    else if (sliderThatWasMoved == reverbDampSlider)
    {
        //[UserSliderCode_reverbDampSlider] -- add your slider handling code here..
		getProcessor()->setParameterNotifyingHost (tinySynthAudioProcessor::reverbDampParam, (float) reverbDampSlider->getValue());
        //[/UserSliderCode_reverbDampSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void tinySynthAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    // comboBoxChanged management method is called every time the user changes the value of a combobox
	// the code  associated  to each combobox is the one reported inside the if / else if sections
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == osc3WaveBox)
    {
        //[UserComboBoxCode_osc3WaveBox] -- add your combo box handling code here..
        getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::osc3WaveParam, (float) osc3WaveBox->getSelectedItemIndex());
        //[/UserComboBoxCode_osc3WaveBox]
    }
    else if (comboBoxThatHasChanged == osc3OctaveBox)
    {
        //[UserComboBoxCode_osc3OctaveBox] -- add your combo box handling code here..
        getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::osc3OctaveParam, (float) osc3OctaveBox->getSelectedItemIndex());
        //[/UserComboBoxCode_osc3OctaveBox]
    }
    else if (comboBoxThatHasChanged == lfo1WaveBox)
    {
        //[UserComboBoxCode_lfo1WaveBox] -- add your combo box handling code here..
		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::lfo1WaveParam, (float) lfo1WaveBox->getSelectedItemIndex());
        //[/UserComboBoxCode_lfo1WaveBox]
    }
    else if (comboBoxThatHasChanged == lfo1DestBox)
    {
        //[UserComboBoxCode_lfo1DestBox] -- add your combo box handling code here..
		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::lfo1DestParam, (float) lfo1DestBox->getSelectedItemIndex());
        //[/UserComboBoxCode_lfo1DestBox]
    }
    else if (comboBoxThatHasChanged == filter1TypeBox)
    {
        //[UserComboBoxCode_filter1TypeBox] -- add your combo box handling code here..
		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::filter1TypeParam, (float) filter1TypeBox->getSelectedItemIndex());
        //[/UserComboBoxCode_filter1TypeBox]
    }
    else if (comboBoxThatHasChanged == osc2WaveBox)
    {
        //[UserComboBoxCode_osc2WaveBox] -- add your combo box handling code here..
        getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::osc2WaveParam, (float) osc2WaveBox->getSelectedItemIndex());
        //[/UserComboBoxCode_osc2WaveBox]
    }
    else if (comboBoxThatHasChanged == osc2OctaveBox)
    {
        //[UserComboBoxCode_osc2OctaveBox] -- add your combo box handling code here..
        getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::osc2OctaveParam, (float) osc2OctaveBox->getSelectedItemIndex());
        //[/UserComboBoxCode_osc2OctaveBox]
    }
    else if (comboBoxThatHasChanged == osc1WaveBox)
    {
        //[UserComboBoxCode_osc1WaveBox] -- add your combo box handling code here..
		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::osc1WaveParam, (float) osc1WaveBox->getSelectedItemIndex());
        //[/UserComboBoxCode_osc1WaveBox]
    }
    else if (comboBoxThatHasChanged == osc1OctaveBox)
    {
        //[UserComboBoxCode_osc1OctaveBox] -- add your combo box handling code here..
        getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::osc1OctaveParam, (float) osc1OctaveBox->getSelectedItemIndex());
        //[/UserComboBoxCode_osc1OctaveBox]
    }
    else if (comboBoxThatHasChanged == filter2TypeBox)
    {
        //[UserComboBoxCode_filter2TypeBox] -- add your combo box handling code here..
		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::filter2TypeParam, (float) filter2TypeBox->getSelectedItemIndex());
        //[/UserComboBoxCode_filter2TypeBox]
    }
    else if (comboBoxThatHasChanged == lfo2WaveBox)
    {
        //[UserComboBoxCode_lfo2WaveBox] -- add your combo box handling code here..
		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::lfo2WaveParam, (float) lfo2WaveBox->getSelectedItemIndex());
        //[/UserComboBoxCode_lfo2WaveBox]
    }
    else if (comboBoxThatHasChanged == lfo2DestBox)
    {
        //[UserComboBoxCode_lfo2DestBox] -- add your combo box handling code here..
		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::lfo2DestParam, (float) lfo2DestBox->getSelectedItemIndex());
        //[/UserComboBoxCode_lfo2DestBox]
    }
    else if (comboBoxThatHasChanged == osc1LfoBox)
    {
        //[UserComboBoxCode_osc1LfoBox] -- add your combo box handling code here..
		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::osc1LfoParam, (float) osc1LfoBox->getSelectedItemIndex());
        //[/UserComboBoxCode_osc1LfoBox]
    }
    else if (comboBoxThatHasChanged == osc1EnvBox)
    {
        //[UserComboBoxCode_osc1EnvBox] -- add your combo box handling code here..
		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::osc1EnvParam, (float) osc1EnvBox->getSelectedItemIndex());
        //[/UserComboBoxCode_osc1EnvBox]
    }
    else if (comboBoxThatHasChanged == osc2LfoBox)
    {
        //[UserComboBoxCode_osc2LfoBox] -- add your combo box handling code here..
		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::osc2LfoParam, (float) osc2LfoBox->getSelectedItemIndex());
        //[/UserComboBoxCode_osc2LfoBox]
    }
    else if (comboBoxThatHasChanged == osc2EnvBox)
    {
        //[UserComboBoxCode_osc2EnvBox] -- add your combo box handling code here..
		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::osc2EnvParam, (float) osc2EnvBox->getSelectedItemIndex());
        //[/UserComboBoxCode_osc2EnvBox]
    }
    else if (comboBoxThatHasChanged == osc3LfoBox)
    {
        //[UserComboBoxCode_osc3LfoBox] -- add your combo box handling code here..
		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::osc3LfoParam, (float) osc3LfoBox->getSelectedItemIndex());
        //[/UserComboBoxCode_osc3LfoBox]
    }
    else if (comboBoxThatHasChanged == osc3EnvBox)
    {
        //[UserComboBoxCode_osc3EnvBox] -- add your combo box handling code here..
		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::osc3EnvParam, (float) osc3EnvBox->getSelectedItemIndex());
        //[/UserComboBoxCode_osc3EnvBox]
    }
    else if (comboBoxThatHasChanged == synthVoiceBox)
    {
        //[UserComboBoxCode_synthVoiceBox] -- add your combo box handling code here..
		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::synthVoiceParam, (float) synthVoiceBox->getSelectedItemIndex());
        //[/UserComboBoxCode_synthVoiceBox]
    }
    else if (comboBoxThatHasChanged == filter2EnvBox)
    {
        //[UserComboBoxCode_filter2EnvBox] -- add your combo box handling code here..
       	getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::filter2EnvParam, (float) filter2EnvBox->getSelectedItemIndex());
        //[/UserComboBoxCode_filter2EnvBox]
    }
    else if (comboBoxThatHasChanged == filter1EnvBox)
    {
        //[UserComboBoxCode_filter1EnvBox] -- add your combo box handling code here..
         getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::filter1EnvParam, (float) filter1EnvBox->getSelectedItemIndex());
        //[/UserComboBoxCode_filter1EnvBox]
    }
    else if (comboBoxThatHasChanged == filter1LfoBox)
    {
        //[UserComboBoxCode_filter1LfoBox] -- add your combo box handling code here..
        getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::filter1LfoParam, (float) filter1LfoBox->getSelectedItemIndex());
        //[/UserComboBoxCode_filter1LfoBox]
    }
    else if (comboBoxThatHasChanged == filterSequenceBox)
    {
        //[UserComboBoxCode_filterSequenceBox] -- add your combo box handling code here..
        getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::filterSequenceParam, (float) filterSequenceBox->getSelectedItemIndex());
        //[/UserComboBoxCode_filterSequenceBox]
    }
    else if (comboBoxThatHasChanged == filter2LfoBox)
    {
        //[UserComboBoxCode_filter2LfoBox] -- add your combo box handling code here..
        getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::filter2LfoParam, (float) filter2LfoBox->getSelectedItemIndex());
        //[/UserComboBoxCode_filter2LfoBox]
    }
    else if (comboBoxThatHasChanged == osc1SemiToneBox)
    {
        //[UserComboBoxCode_osc1SemiToneBox] -- add your combo box handling code here..
        getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::osc1SemiToneParam, (float) osc1SemiToneBox->getSelectedItemIndex());
        //[/UserComboBoxCode_osc1SemiToneBox]
    }
    else if (comboBoxThatHasChanged == osc2SemiToneBox)
    {
        //[UserComboBoxCode_osc2SemiToneBox] -- add your combo box handling code here..
		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::osc2SemiToneParam, (float) osc2SemiToneBox->getSelectedItemIndex());
        //[/UserComboBoxCode_osc2SemiToneBox]
    }
    else if (comboBoxThatHasChanged == osc3SemiToneBox)
    {
        //[UserComboBoxCode_osc3SemiToneBox] -- add your combo box handling code here..
        getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::osc3SemiToneParam, (float) osc3SemiToneBox->getSelectedItemIndex());
        //[/UserComboBoxCode_osc3SemiToneBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void tinySynthAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    // buttonClicked management method is called every time the user changes the value of a button
	// the code  associated  to each button is the one reported inside the if / else if sections
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == saveTXT)
    {
        //[UserButtonCode_saveTXT] -- add your button handler code here..
		// this code allows to save a preset in  a specific folder
		FileChooser ChooseFile("Save parameters values to file: ",File::getSpecialLocation(File::userHomeDirectory),"*.txt");
		if(ChooseFile.browseForFileToSave(true))
		{
			File fileName2=ChooseFile.getResult().withFileExtension("txt");//make sure you end with desired extension
			presetName->setText(fileName2.getFileName(), true);
			fileName2.create();
			fileName2.replaceWithText(getProcessor()->copyParametersIntoCSVString());
		}
        //[/UserButtonCode_saveTXT]
    }
    else if (buttonThatWasClicked == loadTXT)
    {
        //[UserButtonCode_loadTXT] -- add your button handler code here..
		// this code allows to load already saved preset from a specific folder
		FileChooser chooser ("Load parameters values from  file",File::nonexistent, "*.txt");
		if (chooser.browseForFileToOpen())
		{
			File file (chooser.getResult());
			presetName->setText(file.getFileName(), true);
			getProcessor()->setParametersFromCSVString(file.loadFileAsString());
			getProcessor()->RequestUIUpdate();
		}

        //[/UserButtonCode_loadTXT]
    }
    else if (buttonThatWasClicked == checkP)
    {
        //[UserButtonCode_checkP] -- add your button handler code here..
		// this code is used for debug purposes, it allows to display  the current values of internal  parameters
		AlertWindow::showMessageBox(AlertWindow::InfoIcon,"Current Memory Parameters:",getProcessor()->formatParametersIntoString());
        //[/UserButtonCode_checkP]
    }
    else if (buttonThatWasClicked == osc1On)
    {
        //[UserButtonCode_osc1On] -- add your button handler code here..
		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::osc1OnParam, (float) osc1On->getToggleState());
        //[/UserButtonCode_osc1On]
    }
    else if (buttonThatWasClicked == osc2On)
    {
        //[UserButtonCode_osc2On] -- add your button handler code here..
		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::osc2OnParam, (float) osc2On->getToggleState());
        //[/UserButtonCode_osc2On]
    }
    else if (buttonThatWasClicked == osc3On)
    {
        //[UserButtonCode_osc3On] -- add your button handler code here..
		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::osc3OnParam, (float) osc3On->getToggleState());
        //[/UserButtonCode_osc3On]
    }
    else if (buttonThatWasClicked == delayOnSw)
    {
        //[UserButtonCode_delayOnSw] -- add your button handler code here..
  		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::delayOnParam, (float) delayOnSw->getToggleState());
        //[/UserButtonCode_delayOnSw]
    }
    else if (buttonThatWasClicked == reverbOnSw)
    {
        //[UserButtonCode_reverbOnSw] -- add your button handler code here..
		getProcessor()->setParameterNotifyingHost(tinySynthAudioProcessor::reverbOnParam, (float) reverbOnSw->getToggleState());
        //[/UserButtonCode_reverbOnSw]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void tinySynthAudioProcessorEditor::timerCallback()
{
	// timerCallback() keeps the on-screen controls synchronized with the values inside the internal parameter array.
	// this method is in called every 200 msec
	// its mainly used when the user select a new preset configuration file

	tinySynthAudioProcessor* ourProcessor = getProcessor();
	if (ourProcessor->NeedsUIUpdate())
	{
		//****** START <oscillators controls synchronization> ******//
		osc1WaveBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::osc1WaveParam), dontSendNotification);
		osc2WaveBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::osc2WaveParam), dontSendNotification);
		osc3WaveBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::osc3WaveParam), dontSendNotification);

		osc1OctaveBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::osc1OctaveParam), dontSendNotification);
		osc2OctaveBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::osc2OctaveParam), dontSendNotification);
		osc3OctaveBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::osc3OctaveParam), dontSendNotification);

		osc1SemiToneBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::osc1SemiToneParam), dontSendNotification);
		osc2SemiToneBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::osc2SemiToneParam), dontSendNotification);
		osc3SemiToneBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::osc3SemiToneParam), dontSendNotification);

		osc1lvlSlider->setValue(20 * log10(ourProcessor->getParameter(tinySynthAudioProcessor::osc1LevelParam)), dontSendNotification);
		osc2lvlSlider->setValue(20 * log10(ourProcessor->getParameter(tinySynthAudioProcessor::osc2LevelParam)), dontSendNotification);
		osc3lvlSlider->setValue(20 * log10(ourProcessor->getParameter(tinySynthAudioProcessor::osc3LevelParam)), dontSendNotification);

		osc1LfoBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::osc1LfoParam), dontSendNotification);
		osc2LfoBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::osc2LfoParam), dontSendNotification);
		osc3LfoBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::osc3LfoParam), dontSendNotification);

		osc1EnvBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::osc1EnvParam), dontSendNotification);
		osc2EnvBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::osc2EnvParam), dontSendNotification);
		osc3EnvBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::osc3EnvParam), dontSendNotification);

		osc1On->setToggleState((bool) ourProcessor->getParameter(tinySynthAudioProcessor::osc1OnParam), dontSendNotification);
		osc2On->setToggleState((bool) ourProcessor->getParameter(tinySynthAudioProcessor::osc2OnParam), dontSendNotification);
		osc3On->setToggleState((bool) ourProcessor->getParameter(tinySynthAudioProcessor::osc3OnParam), dontSendNotification);
		//****** END <oscillators controls synchronization> ******//


		//****** START <ADSR controls synchronization> ******//
		adsr1AttackSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::adsr1AttackParam), dontSendNotification);
		adsr1DecaySlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::adsr1DecayParam), dontSendNotification);
		adsr1SustainSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::adsr1SustainParam), dontSendNotification);
		adsr1ReleaseSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::adsr1ReleaseParam), dontSendNotification);

		adsr2AttackSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::adsr2AttackParam), dontSendNotification);
		adsr2DecaySlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::adsr2DecayParam), dontSendNotification);
		adsr2SustainSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::adsr2SustainParam), dontSendNotification);
		adsr2ReleaseSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::adsr2ReleaseParam), dontSendNotification);

		adsr3AttackSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::adsr3AttackParam), dontSendNotification);
		adsr3DecaySlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::adsr3DecayParam), dontSendNotification);
		adsr3SustainSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::adsr3SustainParam), dontSendNotification);
		adsr3ReleaseSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::adsr3ReleaseParam), dontSendNotification);
		//****** END <ADSR controls synchronization> ******//

		//****** START <LFO controls synchronization> ******//
		lfo1DestBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::lfo1DestParam), dontSendNotification);
		lfo1WaveBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::lfo1WaveParam), dontSendNotification);
		lfo1FreqSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::lfo1FreqParam), dontSendNotification);
		lfo1DevSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::lfo1DevParam), dontSendNotification);

		lfo2DestBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::lfo2DestParam), dontSendNotification);
		lfo2WaveBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::lfo2WaveParam), dontSendNotification);
		lfo2FreqSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::lfo2FreqParam), dontSendNotification);
		lfo2DevSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::lfo2DevParam), dontSendNotification);
		//****** END <LFO controls synchronization> ******//

		//****** START <Filters controls synchronization> ******//
		double sampleRate = getProcessor()->getSampleRate();
		filterSequenceBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::filterSequenceParam), dontSendNotification);

		filter1LfoBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::filter1LfoParam), dontSendNotification);
		filter1FreqSlider->setValue(sampleRate / (2 * PI) * ourProcessor->getParameter(tinySynthAudioProcessor::filter1CutoffParam), dontSendNotification);
		filter1TypeBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::filter1TypeParam), dontSendNotification);
		filter1ResSlider->setValue(20 * log10(ourProcessor->getParameter(tinySynthAudioProcessor::filter1ResonanceParam)), dontSendNotification);
		filter1EnvModDepthSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::filter1EnvModDepthParam), dontSendNotification);
		filter1EnvBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::filter1EnvParam), dontSendNotification);

		filter2LfoBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::filter2LfoParam), dontSendNotification);
		filter2FreqSlider->setValue(sampleRate / (2 * PI) * ourProcessor->getParameter(tinySynthAudioProcessor::filter2CutoffParam), dontSendNotification);
		filter2TypeBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::filter2TypeParam), dontSendNotification);
		filter2ResSlider->setValue(20 * log10(ourProcessor->getParameter(tinySynthAudioProcessor::filter2ResonanceParam)), dontSendNotification);
		filter2EnvModDepthSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::filter2EnvModDepthParam), dontSendNotification);
		filter2EnvBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::filter2EnvParam), dontSendNotification);
		//****** END <Filters controls synchronization> ******//

		//****** START <Delay controls synchronization> ******//
		delayTimeSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::delayTimeParam)/sampleRate, dontSendNotification);
		delayFBSlider->setValue(20 * log10(ourProcessor->getParameter(tinySynthAudioProcessor::delayFeedbackParam)), dontSendNotification);
		delayGainSlider->setValue(20 * log10(ourProcessor->getParameter(tinySynthAudioProcessor::delayGainParam)), dontSendNotification);
		delayOnSw->setToggleState((bool) ourProcessor->getParameter(tinySynthAudioProcessor::delayOnParam), dontSendNotification);
		//****** END <Delay controls synchronization> ******//

		//****** START <Reverb controls synchronization> ******//
		reverbDryWetSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::reverbDryWetParam), dontSendNotification);
		reverbSizeSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::reverbSizeParam), dontSendNotification);
		reverbDampSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::reverbDampParam), dontSendNotification);
		reverbOnSw->setToggleState((bool) ourProcessor->getParameter(tinySynthAudioProcessor::reverbOnParam), dontSendNotification);
		//****** END <Reverb controls synchronization> ******//

		// Noise control synchronization
		noiseSlider->setValue(20 * log10(ourProcessor->getParameter(tinySynthAudioProcessor::noiseParam)), dontSendNotification);

		// Drive control synchronization
		driveSlider->setValue(ourProcessor->getParameter(tinySynthAudioProcessor::driveParam), dontSendNotification);

		// Gain control synchronization
		outputGainSlider->setValue(20 * log10(ourProcessor->getParameter(tinySynthAudioProcessor::outputGainParam)), dontSendNotification);

		// Number of Voices control synchronization
		synthVoiceBox->setSelectedItemIndex ((int) ourProcessor->getParameter(tinySynthAudioProcessor::synthVoiceParam), dontSendNotification);
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="tinySynthAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="tinySynthAudioProcessor* ownerFilter" variableInitialisers="AudioProcessorEditor (ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="898" initialHeight="665">
  <BACKGROUND backgroundColour="ff131a26">
    <ROUNDRECT pos="729 8 80 320" cornerSize="1" fill="solid: ff000000" hasStroke="0"/>
    <ROUNDRECT pos="4 10 238 154" cornerSize="1" fill="solid: ff0a0808" hasStroke="1"
               stroke="1, mitered, butt" strokeColour="solid: ff6a716c"/>
    <ROUNDRECT pos="367 470 358 137" cornerSize="1" fill="solid: ff000000" hasStroke="1"
               stroke="1, mitered, butt" strokeColour="solid: ff6c6a73"/>
    <ROUNDRECT pos="367 169 358 155" cornerSize="1" fill="solid: ff000000" hasStroke="1"
               stroke="1, mitered, butt" strokeColour="solid: ff717d79"/>
    <ROUNDRECT pos="816 8 80 320" cornerSize="1" fill="solid: ff000000" hasStroke="0"/>
    <ROUNDRECT pos="4 169 361 155" cornerSize="1" fill="solid: ff000000" hasStroke="1"
               stroke="1, mitered, butt" strokeColour="solid: ff7b7575"/>
    <ROUNDRECT pos="4 470 361 137" cornerSize="1" fill="solid: ff000000" hasStroke="1"
               stroke="1, mitered, butt" strokeColour="solid: ff7d8078"/>
    <ROUNDRECT pos="244 10 238 154" cornerSize="1" fill="solid: ff0a0808" hasStroke="1"
               stroke="1, mitered, butt" strokeColour="solid: ff7c8087"/>
    <ROUNDRECT pos="484 10 240 154" cornerSize="1" fill="solid: ff0a0808" hasStroke="1"
               stroke="1, mitered, butt" strokeColour="solid: ff7e7e79"/>
    <ROUNDRECT pos="4 328 238 137" cornerSize="1" fill="solid: ff000000" hasStroke="1"
               stroke="1, mitered, butt" strokeColour="solid: ff75787d"/>
    <ROUNDRECT pos="244 328 238 137" cornerSize="1" fill="solid: ff000000" hasStroke="1"
               stroke="1, mitered, butt" strokeColour="solid: ff7a7474"/>
    <ROUNDRECT pos="484 328 240 137" cornerSize="1" fill="solid: ff000000" hasStroke="1"
               stroke="1, mitered, butt" strokeColour="solid: ff757276"/>
    <RECT pos="728 328 168 280" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="0 608 896 56" fill="solid: ff000000" hasStroke="0"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" id="32ee0e26eb09be5a" memberName="outputGroup"
                  virtualName="" explicitFocusOrder="0" pos="810 0 88 328" outlinecol="ff8f5e22"
                  textcol="ffffffff" title=""/>
  <GROUPCOMPONENT name="new group" id="ab42c4a4e9ef07c7" memberName="lfoGroup5"
                  virtualName="" explicitFocusOrder="0" pos="0 601 898 63" outlinecol="ff808080"
                  textcol="ffffffff" title="" textpos="33"/>
  <GROUPCOMPONENT name="new group" id="43f58707c856a928" memberName="reverbGroup"
                  virtualName="" explicitFocusOrder="0" pos="725 319 172 291" outlinecol="ff397762"
                  textcol="ffffffff" title="" textpos="33"/>
  <GROUPCOMPONENT name="new group" id="d1c2501b2706f9a3" memberName="lfoGroup2"
                  virtualName="" explicitFocusOrder="0" pos="0 460 728 150" outlinecol="ff591a94"
                  textcol="ffffffff" title="" textpos="33"/>
  <GROUPCOMPONENT name="new group" id="3592cbef918be9a1" memberName="lfoGroup3"
                  virtualName="" explicitFocusOrder="0" pos="0 319 728 150" outlinecol="ff8b8b00"
                  textcol="ffffffff" title="" textpos="33"/>
  <GROUPCOMPONENT name="new group" id="ea3069c632e89929" memberName="filterGroup"
                  virtualName="" explicitFocusOrder="0" pos="0 160 728 168" outlinecol="ff750000"
                  textcol="ffffffff" title=""/>
  <SLIDER name="new slider" id="ec58c63b4ccff8af" memberName="filter1EnvModDepthSlider"
          virtualName="" explicitFocusOrder="0" pos="298 208 50 65" rotarysliderfill="ffa7b5b5"
          rotaryslideroutline="ff850000" textboxtext="ffa7b5b5" textboxbkgd="ffffff"
          textboxhighlight="1111ee" textboxoutline="808080" min="-1" max="1"
          int="0.01" style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="10" skewFactor="1"/>
  <SLIDER name="new slider" id="9b2e1431fcd2f805" memberName="lfo1DevSlider"
          virtualName="" explicitFocusOrder="0" pos="220 502 50 65" rotarysliderfill="ff74c615"
          rotaryslideroutline="ff591a94" textboxtext="ff74c615" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.10000000000000001"
          style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="10" skewFactor="1"/>
  <GROUPCOMPONENT name="new group" id="65a0feb597479c50" memberName="oscGroup"
                  virtualName="" explicitFocusOrder="0" pos="0 0 728 168" outlinecol="ff00005c"
                  textcol="ffffffff" title=""/>
  <LABEL name="new label" id="55fd3e4f75cff325" memberName="label21" virtualName=""
         explicitFocusOrder="0" pos="2 8 113 20" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="OSCILLATOR 1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <SLIDER name="new slider" id="8f89739b8fee464b" memberName="adsr1SustainSlider"
          virtualName="" explicitFocusOrder="0" pos="124 359 50 65" rotarysliderfill="ff158ec6"
          rotaryslideroutline="ff8b8b00" textboxtext="ff158ec6" textboxbkgd="ffffff"
          textboxoutline="808080" min="0.01" max="10" int="0.01" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <SLIDER name="new slider" id="fd2273ee05f26609" memberName="osc1lvlSlider"
          virtualName="" explicitFocusOrder="0" pos="168 47 50 65" bkgcol="0"
          trackcol="7fffffff" rotarysliderfill="ffffffff" rotaryslideroutline="ff0000b9"
          textboxtext="ffffffff" textboxbkgd="ffffff" textboxoutline="808080"
          min="-100" max="0" int="0.5" style="Rotary" textBoxPos="TextBoxAbove"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="10" skewFactor="1"/>
  <GROUPCOMPONENT name="new group" id="1ff1c17feeb8ec2a" memberName="delayGroup"
                  virtualName="" explicitFocusOrder="0" pos="725 0 88 328" outlinecol="ff9a9a9a"
                  textcol="ffffffff" title=""/>
  <SLIDER name="new slider" id="a75d50ad64e53127" memberName="delayFBSlider"
          virtualName="" explicitFocusOrder="0" pos="824 248 50 65" rotarysliderfill="ff865cad"
          rotaryslideroutline="ffb4772a" textboxtext="ff865cad" textboxbkgd="faf7f7"
          textboxoutline="808080" min="-40" max="0" int="0.5" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <SLIDER name="new slider" id="2b67fbd26d4a51e1" memberName="delayGainSlider"
          virtualName="" explicitFocusOrder="0" pos="824 152 50 65" rotarysliderfill="ff865cad"
          rotaryslideroutline="ffb4772a" textboxtext="ff865cad" textboxbkgd="ffffff"
          textboxoutline="808080" min="-40" max="0" int="0.5" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <LABEL name="new label" id="ee0c7e762e5270f5" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="2 502 80 20" bkgCol="b70101" textCol="ff74c615"
         edTextCol="ff000000" edBkgCol="0" labelText="Mode" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="f5aabb99a95e5062" memberName="adsr1DecaySlider"
          virtualName="" explicitFocusOrder="0" pos="69 359 50 65" rotarysliderfill="ff158ec6"
          rotaryslideroutline="ff8b8b00" textboxtext="ff158ec6" textboxbkgd="ffffff"
          textboxoutline="808080" min="0.001" max="10" int="0.001" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <SLIDER name="new slider" id="95bb1bdea3cb3d24" memberName="adsr1AttackSlider"
          virtualName="" explicitFocusOrder="0" pos="14 359 50 65" rotarysliderfill="ff158ec6"
          rotaryslideroutline="ff8b8b00" textboxtext="ff158ec6" textboxbkgd="ffffff"
          textboxoutline="808080" min="0.001" max="10" int="0.001" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <SLIDER name="new slider" id="d31354e1003f6da9" memberName="delayTimeSlider"
          virtualName="" explicitFocusOrder="0" pos="824 60 50 65" rotarysliderfill="ff865cad"
          rotaryslideroutline="ffb4772a" textboxtext="ff865cad" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="1" int="0.001" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <LABEL name="new label" id="501a157c94ed15a8" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="-6 418 88 25" textCol="ff158ec6"
         edTextCol="ff000000" edBkgCol="0" labelText="Attack&#10;(sec)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="220b9859b66f7f8d" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="104 418 88 25" textCol="ff158ec6"
         edTextCol="ff000000" edBkgCol="0" labelText="Sustain&#10;(..)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="dfcf9cca27e240f5" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="48 418 88 25" textCol="ff158ec6"
         edTextCol="ff000000" edBkgCol="0" labelText="Decay&#10;(sec)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="bb0184db111ca28" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="161 418 88 25" textCol="ff158ec6"
         edTextCol="ff000000" edBkgCol="0" labelText="Release&#10;(sec)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="c5b8dd30e3f72c57" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="808 304 88 20" textCol="ff865cad"
         edTextCol="ff000000" edBkgCol="0" labelText="Feedback" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="33f990a20ca36ef7" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="808 208 88 20" textCol="ff865cad"
         edTextCol="ff000000" edBkgCol="0" labelText="Gain (dB)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="efd42dad964489a3" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="808 116 88 20" textCol="ff865cad"
         edTextCol="ff000000" edBkgCol="0" labelText="Time (sec)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="50603b8782394472" memberName="noiseSlider"
          virtualName="" explicitFocusOrder="0" pos="781 340 50 65" rotarysliderfill="ffc61515"
          rotaryslideroutline="ff51a88a" textboxtext="ffc61515" textboxbkgd="ffffff"
          textboxoutline="808080" min="-40" max="0" int="0.5" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <SLIDER name="new slider" id="bad6de7cc47b0108" memberName="driveSlider"
          virtualName="" explicitFocusOrder="0" pos="781 432 50 65" rotarysliderfill="ffc61515"
          rotaryslideroutline="ff51a88a" textboxtext="ffc61515" textboxbkgd="c61515"
          textboxoutline="c61515" min="1" max="10" int="0.050000000000000003"
          style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="10" skewFactor="1"/>
  <SLIDER name="new slider" id="74d03ea84f25ef02" memberName="outputGainSlider"
          virtualName="" explicitFocusOrder="0" pos="781 528 50 65" rotarysliderfill="ffc61515"
          rotaryslideroutline="ff51a88a" textboxtext="ffc61515" textboxbkgd="ffffff"
          textboxoutline="808080" min="-20" max="20" int="0.5" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <LABEL name="new label" id="6f104a8e37375aa0" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="766 581 88 20" textCol="ffc61515"
         edTextCol="ff000000" edBkgCol="0" labelText="Gain (dB)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="49c1ace250c4f8ee" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="764 488 88 20" textCol="ffc61515"
         edTextCol="ff000000" edBkgCol="0" labelText="Drive" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="6b139137b8b0fd39" memberName="label13" virtualName=""
         explicitFocusOrder="0" pos="764 396 88 20" textCol="ffc61515"
         edTextCol="ff000000" edBkgCol="0" labelText="Noise (dB)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="9dabcece093dca00" memberName="adsr1ReleaseSlider"
          virtualName="" explicitFocusOrder="0" pos="179 359 50 65" rotarysliderfill="ff158ec6"
          rotaryslideroutline="ff8b8b00" textboxtext="ff158ec6" textboxbkgd="ffffff"
          textboxoutline="808080" min="0.001" max="10" int="0.001" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <COMBOBOX name="new combo box" id="c37948d0c3bd9c5b" memberName="osc3WaveBox"
            virtualName="" explicitFocusOrder="0" pos="537 48 90 20" editable="0"
            layout="33" items="Sine&#10;Saw&#10;Square" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="4ae71ef44644cda7" memberName="osc3OctaveBox"
            virtualName="" explicitFocusOrder="0" pos="537 73 43 20" editable="0"
            layout="33" items="-2&#10;-1&#10;0&#10;+1&#10;+2" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="912baf86a1a0ad06" memberName="label23" virtualName=""
         explicitFocusOrder="0" pos="485 73 80 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Octave" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="332fa9d8aa556539" memberName="label24" virtualName=""
         explicitFocusOrder="0" pos="485 48 80 20" bkgCol="0" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Wave" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="9824114c301fcea0" memberName="label25" virtualName=""
         explicitFocusOrder="0" pos="643 104 78 29" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Level&#10;(dB)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="43d19f5393ba8ba0" memberName="label27" virtualName=""
         explicitFocusOrder="0" pos="136 575 88 31" textCol="ff74c615"
         edTextCol="ff000000" edBkgCol="0" labelText="Frequency&#10;(Hz)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="200d41631cc9ffa5" memberName="label29" virtualName=""
         explicitFocusOrder="0" pos="200 575 88 20" textCol="ff74c615"
         edTextCol="ff000000" edBkgCol="0" labelText="Depth" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="c6e3b536dabbe181" memberName="filter1FreqSlider"
          virtualName="" explicitFocusOrder="0" pos="155 208 50 65" bkgcol="0"
          trackcol="7fffffff" rotarysliderfill="ffa7b5b5" rotaryslideroutline="ff850000"
          textboxtext="ffa7b5b5" textboxbkgd="ffffff" textboxoutline="808080"
          min="50" max="11205" int="5" style="Rotary" textBoxPos="TextBoxAbove"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="10" skewFactor="1"/>
  <LABEL name="new label" id="dfbe4933e3b8ec07" memberName="label31" virtualName=""
         explicitFocusOrder="0" pos="200 264 88 20" textCol="ffa7b5b5"
         edTextCol="ff000000" edBkgCol="0" labelText="Resonance" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="ac6f6b11384ff2b" memberName="label32" virtualName=""
         explicitFocusOrder="0" pos="136 260 88 40" textCol="ffa7b5b5"
         edTextCol="ff000000" edBkgCol="0" labelText="Frequency&#10;(Hz)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="a0b29c1bc98035a1" memberName="label33" virtualName=""
         explicitFocusOrder="0" pos="280 260 88 40" textCol="ffa7b5b5"
         edTextCol="ff000000" edBkgCol="0" labelText="ADSR Mod. &#10;Depth"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="c40e18508b0c7437" memberName="lfo1FreqSlider"
          virtualName="" explicitFocusOrder="0" pos="155 502 50 65" rotarysliderfill="ff74c615"
          rotaryslideroutline="ff591a94" textboxtext="ff74c615" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="30" int="0.10000000000000001"
          style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="10" skewFactor="1"/>
  <COMBOBOX name="new combo box" id="9ef0d8a2b2849ba7" memberName="lfo1WaveBox"
            virtualName="" explicitFocusOrder="0" pos="50 527 90 20" editable="0"
            layout="33" items="Sine&#10;Saw&#10;Square" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="8eb3a72193ed6930" memberName="lfo1DestBox"
            virtualName="" explicitFocusOrder="0" pos="50 502 90 20" tooltip="LFO Vibrato can be applied to a sigle Oscillator just selecting VIbrato in LFO box of oscillator"
            editable="0" layout="33" items="Off&#10;Vibrato&#10;Tremolo"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="4995cb78101163ca" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="2 527 80 20" textCol="ff74c615" edTextCol="ff000000"
         edBkgCol="0" labelText="Wave" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="4c6a01a02cb62be7" memberName="osc3lvlSlider"
          virtualName="" explicitFocusOrder="0" pos="658 46 50 65" rotarysliderfill="ffffffff"
          rotaryslideroutline="ff0000c1" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808000" min="-100" max="0" int="0.5" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <SLIDER name="new slider" id="5809b2c616366c36" memberName="filter1ResSlider"
          virtualName="" explicitFocusOrder="0" pos="220 208 50 65" rotarysliderfill="ffa7b5b5"
          rotaryslideroutline="ff850000" textboxtext="ffa7b5b5" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="40" int="1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <COMBOBOX name="new combo box" id="a6246f5792d2062f" memberName="filter1TypeBox"
            virtualName="" explicitFocusOrder="0" pos="50 206 90 20" editable="0"
            layout="33" items="Low Pass&#10;Band Pass&#10;High Pass&#10;Off"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="3c636708a43de103" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="2 204 88 24" textCol="ffa7b5b5" edTextCol="ff000000"
         edBkgCol="0" labelText="Type" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="8eb30b7b5e9d77bd" memberName="label26" virtualName=""
         explicitFocusOrder="0" pos="485 8 111 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="OSCILLATOR 3" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="5c54f1a8a395239b" memberName="osc2WaveBox"
            virtualName="" explicitFocusOrder="0" pos="296 48 90 20" editable="0"
            layout="33" items="Sine&#10;Saw&#10;Square" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="2fc2e28ae0fde6a3" memberName="osc2OctaveBox"
            virtualName="" explicitFocusOrder="0" pos="296 73 43 20" editable="0"
            layout="33" items="-2&#10;-1&#10;0&#10;+1&#10;+2" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="b5a440e9f025ebd2" memberName="label14" virtualName=""
         explicitFocusOrder="0" pos="245 73 80 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Octave" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="35e567332bb5c0d5" memberName="label15" virtualName=""
         explicitFocusOrder="0" pos="245 48 80 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Wave" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="f452e44f60e3b2ec" memberName="label16" virtualName=""
         explicitFocusOrder="0" pos="403 104 77 29" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Level &#10;(dB)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="e7671b1dcd8ad512" memberName="osc2lvlSlider"
          virtualName="" explicitFocusOrder="0" pos="417 46 50 65" rotarysliderfill="ffffffff"
          rotaryslideroutline="ff0000b9" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="808080" min="-100" max="0" int="0.5" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <LABEL name="new label" id="1b877b32ef164692" memberName="label17" virtualName=""
         explicitFocusOrder="0" pos="245 6 111 22" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="OSCILLATOR 2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="f77e2df6e32fe9bb" memberName="osc1WaveBox"
            virtualName="" explicitFocusOrder="0" pos="52 48 90 20" tooltip="waveform selector"
            editable="0" layout="33" items="Sine&#10;Saw&#10;Square" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="8160e144bbe9cd9c" memberName="osc1OctaveBox"
            virtualName="" explicitFocusOrder="0" pos="52 73 43 20" editable="0"
            layout="33" items="-2&#10;-1&#10;0&#10;+1&#10;+2" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="356b6b7cf57e370a" memberName="label18" virtualName=""
         explicitFocusOrder="0" pos="2 73 80 20" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="Octave" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="532eb7a22ea08ac9" memberName="label19" virtualName=""
         explicitFocusOrder="0" pos="2 48 80 20" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="Wave" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="99c889db831c4574" memberName="label20" virtualName=""
         explicitFocusOrder="0" pos="152 105 80 29" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Level &#10;(dB)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="3943130ceee8d2c8" memberName="filter2EnvModDepthSlider"
          virtualName="" explicitFocusOrder="0" pos="670 204 50 65" tooltip="ADSR level of modulation of  frequency filetr"
          rotarysliderfill="ff909090" rotaryslideroutline="ff860000" textboxtext="ffa7b5b5"
          textboxbkgd="ffffff" textboxhighlight="1111ee" textboxoutline="808080"
          min="-1" max="1" int="0.01" style="Rotary" textBoxPos="TextBoxAbove"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="10" skewFactor="1"/>
  <SLIDER name="new slider" id="7e9018994c96dc7a" memberName="filter2FreqSlider"
          virtualName="" explicitFocusOrder="0" pos="525 203 50 65" rotarysliderfill="ffa7b5b5"
          rotaryslideroutline="ff860000" textboxtext="ffa7b5b5" textboxbkgd="ffffff"
          textboxoutline="808080" min="50" max="11205" int="5" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="12" skewFactor="1"/>
  <LABEL name="new label" id="ea0ad4e2b9758002" memberName="label30" virtualName=""
         explicitFocusOrder="0" pos="577 259 88 20" textCol="ffa7b5b5"
         edTextCol="ff000000" edBkgCol="0" labelText="Resonance" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="ecd3ce42afa0f3bf" memberName="label34" virtualName=""
         explicitFocusOrder="0" pos="506 259 88 33" textCol="ffa7b5b5"
         edTextCol="ff000000" edBkgCol="0" labelText="Frequency&#10;(Hz)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="d33e523095421f0b" memberName="label35" virtualName=""
         explicitFocusOrder="0" pos="647 259 88 35" textCol="ffa7b5b5"
         edTextCol="ff000000" edBkgCol="0" labelText="ADSR Mod. &#10;Depth"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="78c00b78e651e330" memberName="filter2ResSlider"
          virtualName="" explicitFocusOrder="0" pos="596 203 50 65" trackcol="ffa7b5b5"
          rotarysliderfill="ffa7b5b5" rotaryslideroutline="ff860000" textboxtext="ffa7b5b5"
          textboxbkgd="ffffff" textboxoutline="808080" min="0" max="40"
          int="1" style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="10" skewFactor="1"/>
  <COMBOBOX name="new combo box" id="6b1fa6d935a776c1" memberName="filter2TypeBox"
            virtualName="" explicitFocusOrder="0" pos="421 206 90 20" editable="0"
            layout="33" items="Low Pass&#10;Band Pass&#10;High Pass&#10;Off"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="31f0a45b25e96805" memberName="label36" virtualName=""
         explicitFocusOrder="0" pos="366 204 88 24" textCol="ffa7b5b5"
         edTextCol="ff000000" edBkgCol="0" labelText="Type" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="b511f06214f2f5f" memberName="adsr2SustainSlider"
          virtualName="" explicitFocusOrder="0" pos="366 359 50 65" rotarysliderfill="ff158ec6"
          rotaryslideroutline="ff8b8b00" textboxtext="ff158ec6" textboxbkgd="ffffff"
          textboxoutline="808080" min="0.01" max="10" int="0.01" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <SLIDER name="new slider" id="7ec11cb8ac30e0f1" memberName="adsr2DecaySlider"
          virtualName="" explicitFocusOrder="0" pos="311 359 50 65" rotarysliderfill="ff158ec6"
          rotaryslideroutline="ff8b8b00" textboxtext="ff158ec6" textboxbkgd="ffffff"
          textboxoutline="808080" min="0.001" max="10" int="0.001" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <SLIDER name="new slider" id="9f8f8f91f920536d" memberName="adsr2AttackSlider"
          virtualName="" explicitFocusOrder="0" pos="256 359 50 65" rotarysliderfill="ff158ec6"
          rotaryslideroutline="ff8b8b00" textboxtext="ff158ec6" textboxbkgd="ffffff"
          textboxoutline="808080" min="0.001" max="10" int="0.001" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <SLIDER name="new slider" id="1a56ecc76d8dff99" memberName="adsr2ReleaseSlider"
          virtualName="" explicitFocusOrder="0" pos="421 359 50 65" rotarysliderfill="ff26799f"
          rotaryslideroutline="ff8b8b00" textboxtext="ff158ec6" textboxbkgd="ffffff"
          textboxoutline="808080" min="0.001" max="10" int="0.001" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <SLIDER name="new slider" id="e6c8f76b55efc061" memberName="lfo2DevSlider"
          virtualName="" explicitFocusOrder="0" pos="596 503 50 65" rotarysliderfill="ff74c615"
          rotaryslideroutline="ff591a94" textboxtext="ff74c615" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="10" int="0.10000000000000001"
          style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="10" skewFactor="1"/>
  <LABEL name="new label" id="4e5b3a6ae67f27fd" memberName="label41" virtualName=""
         explicitFocusOrder="0" pos="368 502 80 20" bkgCol="b70101" textCol="ff74c615"
         edTextCol="ff000000" edBkgCol="0" labelText="Mode" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="776eca80a1bc0e39" memberName="label42" virtualName=""
         explicitFocusOrder="0" pos="506 576 88 30" textCol="ff74c615"
         edTextCol="ff000000" edBkgCol="0" labelText="Frequency&#10;(Hz)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="4db77c4cdcc06340" memberName="label43" virtualName=""
         explicitFocusOrder="0" pos="577 576 88 20" textCol="ff74c615"
         edTextCol="ff000000" edBkgCol="0" labelText="Depth" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="4559f4ce1b49d54a" memberName="lfo2FreqSlider"
          virtualName="" explicitFocusOrder="0" pos="525 503 50 65" rotarysliderfill="ff74c615"
          rotaryslideroutline="ff591a94" textboxtext="ff74c615" textboxbkgd="ffffff"
          textboxoutline="808080" min="0" max="30" int="0.10000000000000001"
          style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="10" skewFactor="1"/>
  <COMBOBOX name="new combo box" id="6af782e4a6f8ef54" memberName="lfo2WaveBox"
            virtualName="" explicitFocusOrder="0" pos="421 527 90 20" editable="0"
            layout="33" items="Sine&#10;Saw&#10;Square" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="c9f56082cde3fde9" memberName="lfo2DestBox"
            virtualName="" explicitFocusOrder="0" pos="421 502 90 20" editable="0"
            layout="33" items="Off&#10;Vibrato&#10;Tremolo" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="ab0e8f2742a2daee" memberName="label44" virtualName=""
         explicitFocusOrder="0" pos="368 527 80 20" textCol="ff74c615"
         edTextCol="ff000000" edBkgCol="0" labelText="Wave" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="3e1f72a4378a03b1" memberName="adsr3SustainSlider"
          virtualName="" explicitFocusOrder="0" pos="612 359 50 65" rotarysliderfill="ff158ec6"
          rotaryslideroutline="ff8b8b00" textboxtext="ff158ec6" textboxbkgd="ffffff"
          textboxoutline="808080" min="0.01" max="10" int="0.01" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <SLIDER name="new slider" id="e92b9cb2473ea675" memberName="adsr3DecaySlider"
          virtualName="" explicitFocusOrder="0" pos="557 359 50 65" rotarysliderfill="ff158ec6"
          rotaryslideroutline="ff8b8b00" textboxtext="ff158ec6" textboxbkgd="ffffff"
          textboxoutline="808080" min="0.001" max="10" int="0.001" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <SLIDER name="new slider" id="6dae261da4c2c7c0" memberName="adsr3AttackSlider"
          virtualName="" explicitFocusOrder="0" pos="502 359 50 65" rotarysliderfill="ff158ec6"
          rotaryslideroutline="ff8b8b00" textboxtext="ff158ec6" textboxbkgd="ffffff"
          textboxoutline="808080" min="0.001" max="10" int="0.001" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <SLIDER name="new slider" id="1ad4027593719a72" memberName="adsr3ReleaseSlider"
          virtualName="" explicitFocusOrder="0" pos="667 359 50 65" rotarysliderfill="ff158ec6"
          rotaryslideroutline="ff8b8b00" textboxtext="ff158ec6" textboxbkgd="ffffff"
          textboxoutline="808080" min="0.001" max="10" int="0.001" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <COMBOBOX name="new combo box" id="e2e93e3992a3b191" memberName="osc1LfoBox"
            virtualName="" explicitFocusOrder="0" pos="97 98 45 20" tooltip="LFO selector."
            editable="0" layout="33" items="Off&#10;1&#10;2" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="1c2c2582972b022b" memberName="label49" virtualName=""
         explicitFocusOrder="0" pos="46 98 52 20" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="LFO" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13"
         bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="7332d130d687a99c" memberName="osc1EnvBox"
            virtualName="" explicitFocusOrder="0" pos="97 123 45 20" editable="0"
            layout="33" items="1&#10;2&#10;3" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="2dd4e8d6212e03a3" memberName="label50" virtualName=""
         explicitFocusOrder="0" pos="46 123 60 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="ADSR" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="f53b13d638c316e3" memberName="osc2LfoBox"
            virtualName="" explicitFocusOrder="0" pos="340 98 45 20" editable="0"
            layout="33" items="Off&#10;1&#10;2" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="98c3be4eec8fa596" memberName="label51" virtualName=""
         explicitFocusOrder="0" pos="290 98 49 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="LFO" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="a44379a1dcff0b68" memberName="osc2EnvBox"
            virtualName="" explicitFocusOrder="0" pos="340 123 45 20" editable="0"
            layout="33" items="1&#10;2&#10;3" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="37c8e9114735d873" memberName="label52" virtualName=""
         explicitFocusOrder="0" pos="290 123 49 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="ADSR" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="6cc8adcf78d6aa34" memberName="osc3LfoBox"
            virtualName="" explicitFocusOrder="0" pos="582 98 45 20" editable="0"
            layout="33" items="Off&#10;1&#10;2" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="72603d8a65d6e170" memberName="label53" virtualName=""
         explicitFocusOrder="0" pos="531 98 37 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="LFO" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="b743175866f892a1" memberName="osc3EnvBox"
            virtualName="" explicitFocusOrder="0" pos="582 123 45 20" editable="0"
            layout="33" items="1&#10;2&#10;3" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="99bbe8439fc1d08b" memberName="label54" virtualName=""
         explicitFocusOrder="0" pos="531 123 45 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="ADSR" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="8b6c99a10836b3bd" memberName="label28" virtualName=""
         explicitFocusOrder="0" pos="366 169 84 20" textCol="ff747272"
         outlineCol="0" edTextCol="ff000000" edBkgCol="0" labelText="FILTER 2"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="1" italic="0" justification="33"/>
  <LABEL name="new label" id="bb59f4e95ae878f0" memberName="label55" virtualName=""
         explicitFocusOrder="0" pos="3 169 75 20" textCol="ff747272" edTextCol="ff000000"
         edBkgCol="0" labelText="FILTER 1" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="1" italic="0" justification="33"/>
  <LABEL name="new label" id="ee499e3d30a3260f" memberName="label56" virtualName=""
         explicitFocusOrder="0" pos="3 328 68 20" textCol="ff158ec6" edTextCol="ff000000"
         edBkgCol="0" labelText="ADSR 1" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="1" italic="0" justification="17"/>
  <LABEL name="new label" id="9b9411cf53810263" memberName="label57" virtualName=""
         explicitFocusOrder="0" pos="248 328 72 20" textCol="ff158ec6"
         edTextCol="ff000000" edBkgCol="0" labelText="ADSR 2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="17"/>
  <LABEL name="new label" id="ecd9b6a85a149cc8" memberName="label58" virtualName=""
         explicitFocusOrder="0" pos="489 328 78 20" textCol="ff158ec6"
         edTextCol="ff000000" edBkgCol="0" labelText="ADSR 3" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="17"/>
  <TEXTBUTTON name="saveTXT" id="15b6431704424935" memberName="saveTXT" virtualName=""
              explicitFocusOrder="0" pos="232 638 88 20" bgColOn="ffa7b5ff"
              buttonText="save to file" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="loadTXT" id="198833022b36ec2" memberName="loadTXT" virtualName=""
              explicitFocusOrder="0" pos="232 616 88 20" bgColOff="ffbbbbff"
              bgColOn="ffa7b5b5" buttonText="load from file" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="checkP" id="257439489fc2872a" memberName="checkP" virtualName=""
              explicitFocusOrder="0" pos="792 638 88 20" bgColOn="ffa7b5ff"
              buttonText="check param" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTEDITOR name="presetName" id="397970316212f775" memberName="presetName"
              virtualName="" explicitFocusOrder="0" pos="75 637 150 20" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="1"
              caret="0" popupmenu="1"/>
  <TOGGLEBUTTON name="new toggle button" id="d57e86b8eee85d7f" memberName="osc1On"
                virtualName="" explicitFocusOrder="0" pos="172 8 42 24" txtcol="fff0ffff"
                buttonText="On" connectedEdges="1" needsCallback="1" radioGroupId="0"
                state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="e8eaaa9b6df87248" memberName="osc2On"
                virtualName="" explicitFocusOrder="0" pos="419 8 42 24" txtcol="fff0ffff"
                buttonText="On" connectedEdges="1" needsCallback="1" radioGroupId="0"
                state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="41e8bf7303f528a3" memberName="osc3On"
                virtualName="" explicitFocusOrder="0" pos="659 7 42 24" txtcol="fff0ffff"
                buttonText="On" connectedEdges="1" needsCallback="1" radioGroupId="0"
                state="1"/>
  <COMBOBOX name="new combo box" id="db3154e094f749df" memberName="synthVoiceBox"
            virtualName="" explicitFocusOrder="0" pos="16 637 45 20" editable="0"
            layout="33" items="1&#10;2&#10;3&#10;4&#10;5&#10;6&#10;7&#10;8"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="8559710f42df77a2" memberName="label59" virtualName=""
         explicitFocusOrder="0" pos="10 614 88 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Voice No" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="4a05dd94e6a85828" memberName="delayOnSw"
                virtualName="" explicitFocusOrder="0" pos="824 27 42 24" txtcol="fff0ffff"
                buttonText="On" connectedEdges="1" needsCallback="1" radioGroupId="0"
                state="1"/>
  <COMBOBOX name="new combo box" id="a76fe9d26c227459" memberName="filter2EnvBox"
            virtualName="" explicitFocusOrder="0" pos="466 256 45 20" tooltip="select the ADSR number used for the Filter modulation depth"
            editable="0" layout="33" items="1&#10;2&#10;3" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="5b4577dabe696c35" memberName="label60" virtualName=""
         explicitFocusOrder="0" pos="415 256 56 20" textCol="ffa7b5b5"
         edTextCol="ff000000" edBkgCol="0" labelText="ADSR" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="80b25bce37191d7b" memberName="filter1EnvBox"
            virtualName="" explicitFocusOrder="0" pos="95 256 45 20" tooltip="select the ADSR number used for the Filter modulation depth"
            editable="0" layout="33" items="1&#10;2&#10;3" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="ed35f27ca3f5017c" memberName="label61" virtualName=""
         explicitFocusOrder="0" pos="43 256 45 20" textCol="ffa7b5b5"
         edTextCol="ff000000" edBkgCol="0" labelText="ADSR" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="425d3a5f4589973f" memberName="filter1LfoBox"
            virtualName="" explicitFocusOrder="0" pos="95 231 45 20" tooltip="LFO selector."
            editable="0" layout="33" items="Off&#10;1&#10;2" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="613902566c93d17b" memberName="label62" virtualName=""
         explicitFocusOrder="0" pos="45 231 43 20" textCol="ffa7b5b5"
         edTextCol="ff000000" edBkgCol="0" labelText="LFO" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="ebdf1a447a20f57c" memberName="filterSequenceBox"
            virtualName="" explicitFocusOrder="0" pos="421 281 90 20" tooltip="LFO selector."
            editable="0" layout="33" items="Parallel&#10;1-&gt;2&#10;2-&gt;1"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="59fb99ef94c3a098" memberName="label63" virtualName=""
         explicitFocusOrder="0" pos="366 281 64 20" textCol="ffa7b5b5"
         edTextCol="ff000000" edBkgCol="0" labelText="Seq." editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="5355e77fa802f922" memberName="filter2LfoBox"
            virtualName="" explicitFocusOrder="0" pos="466 231 45 20" tooltip="LFO selector."
            editable="0" layout="33" items="Off&#10;1&#10;2" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="862c5063aff52967" memberName="label64" virtualName=""
         explicitFocusOrder="0" pos="415 231 41 20" textCol="ffa7b5b5"
         edTextCol="ff000000" edBkgCol="0" labelText="LFO" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="d64e1230d16a29ab" memberName="label65" virtualName=""
         explicitFocusOrder="0" pos="3 469 68 20" textCol="ff74c615" edTextCol="ff000000"
         edBkgCol="0" labelText="LFO 1" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="1" italic="0" justification="17"/>
  <LABEL name="new label" id="4f0e42ca0bc99b61" memberName="label66" virtualName=""
         explicitFocusOrder="0" pos="368 469 68 20" textCol="ff74c615"
         edTextCol="ff000000" edBkgCol="0" labelText="LFO 2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="17"/>
  <LABEL name="new label" id="f5768622d861d27" memberName="label37" virtualName=""
         explicitFocusOrder="0" pos="236 418 88 25" textCol="ff158ec6"
         edTextCol="ff000000" edBkgCol="0" labelText="Attack&#10;(sec)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="d13291f190cd80e2" memberName="label38" virtualName=""
         explicitFocusOrder="0" pos="346 418 88 25" textCol="ff158ec6"
         edTextCol="ff000000" edBkgCol="0" labelText="Sustain&#10;(..)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="d15119e87c0c52f8" memberName="label39" virtualName=""
         explicitFocusOrder="0" pos="290 418 88 25" textCol="ff158ec6"
         edTextCol="ff000000" edBkgCol="0" labelText="Decay&#10;(sec)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="d8c77577dd3eeaf0" memberName="label40" virtualName=""
         explicitFocusOrder="0" pos="403 418 88 25" textCol="ff158ec6"
         edTextCol="ff000000" edBkgCol="0" labelText="Release&#10;(sec)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="e08eef329df55577" memberName="label45" virtualName=""
         explicitFocusOrder="0" pos="481 417 88 25" textCol="ff158ec6"
         edTextCol="ff000000" edBkgCol="0" labelText="Attack&#10;(sec)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="8baa6f5cc6d13ce8" memberName="label46" virtualName=""
         explicitFocusOrder="0" pos="591 417 88 25" textCol="ff158ec6"
         edTextCol="ff000000" edBkgCol="0" labelText="Sustain&#10;(..)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="adb4b3615e815820" memberName="label47" virtualName=""
         explicitFocusOrder="0" pos="535 417 88 25" textCol="ff158ec6"
         edTextCol="ff000000" edBkgCol="0" labelText="Decay&#10;(sec)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="4c5559a982172572" memberName="label48" virtualName=""
         explicitFocusOrder="0" pos="648 417 88 25" textCol="ff158ec6"
         edTextCol="ff000000" edBkgCol="0" labelText="Release&#10;(sec)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="ce38724cc57bdb27" memberName="label67" virtualName=""
         explicitFocusOrder="0" pos="69 614 88 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Current Preset"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="13" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="dc414f7b844ba0f6" memberName="label68" virtualName=""
         explicitFocusOrder="0" pos="728 8 78 20" textCol="ffc1b115" edTextCol="ff000000"
         edBkgCol="0" labelText="REVERB" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="1" italic="0" justification="17"/>
  <LABEL name="new label" id="85d77118f73c1faf" memberName="label22" virtualName=""
         explicitFocusOrder="0" pos="816 8 78 20" textCol="ff865cad" edTextCol="ff000000"
         edBkgCol="0" labelText="DELAY" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="1" italic="0" justification="17"/>
  <LABEL name="new label" id="55491df961f606ea" memberName="label69" virtualName=""
         explicitFocusOrder="0" pos="728 328 78 20" textCol="ffdc143c"
         edTextCol="ff000000" edBkgCol="0" labelText="OUTPUT" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="1" italic="0" justification="17"/>
  <LABEL name="new label" id="4d58df7b15913839" memberName="label70" virtualName=""
         explicitFocusOrder="0" pos="731 613 166 20" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="tinySynth 1.2.5"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="1" italic="0" justification="10"/>
  <SLIDER name="new slider" id="9c1ac188894c26f6" memberName="reverbDryWetSlider"
          virtualName="" explicitFocusOrder="0" pos="743 58 50 65" rotarysliderfill="ffc1b115"
          rotaryslideroutline="ffd2d2d2" textboxtext="ffc1b115" textboxbkgd="faf7f7"
          textboxoutline="808080" min="0" max="1" int="0.01" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <LABEL name="new label" id="94756583e5b8f32f" memberName="label72" virtualName=""
         explicitFocusOrder="0" pos="725 117 88 20" textCol="ffc1b115"
         edTextCol="ff000000" edBkgCol="0" labelText="Dry/Wet" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="46eea964fe9f9a25" memberName="reverbSizeSlider"
          virtualName="" explicitFocusOrder="0" pos="742 148 50 65" rotarysliderfill="ffc1b115"
          rotaryslideroutline="ffd2d2d2" textboxtext="ffc1b115" textboxbkgd="faf7f7"
          textboxoutline="808080" min="0" max="1" int="0.01" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <LABEL name="new label" id="ee84d9d95b312cbc" memberName="label73" virtualName=""
         explicitFocusOrder="0" pos="723 209 88 20" textCol="ffc1b115"
         edTextCol="ff000000" edBkgCol="0" labelText="Size" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="236ec608851b1f61" memberName="reverbDampSlider"
          virtualName="" explicitFocusOrder="0" pos="742 250 50 65" rotarysliderfill="ffc1b115"
          rotaryslideroutline="ffd2d2d2" textboxtext="ffc1b115" textboxbkgd="faf7f7"
          textboxoutline="808080" min="0" max="1" int="0.01" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="10" skewFactor="1"/>
  <LABEL name="new label" id="a7d244fade45eda7" memberName="label74" virtualName=""
         explicitFocusOrder="0" pos="722 306 88 20" textCol="ffc1b115"
         edTextCol="ff000000" edBkgCol="0" labelText="Damp" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="13" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="new toggle button" id="24932d377aa1e313" memberName="reverbOnSw"
                virtualName="" explicitFocusOrder="0" pos="744 27 42 24" txtcol="fff0ffff"
                buttonText="On" connectedEdges="1" needsCallback="1" radioGroupId="0"
                state="1"/>
  <COMBOBOX name="new combo box" id="6d778f3cd9e060fe" memberName="osc1SemiToneBox"
            virtualName="" explicitFocusOrder="0" pos="97 73 45 20" editable="0"
            layout="33" items="0&#10;1&#10;2&#10;3&#10;4&#10;5&#10;6&#10;7&#10;8&#10;9&#10;10&#10;11"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="5c2a1aa989eccea1" memberName="osc2SemiToneBox"
            virtualName="" explicitFocusOrder="0" pos="340 73 45 20" editable="0"
            layout="33" items="0&#10;1&#10;2&#10;3&#10;4&#10;5&#10;6&#10;7&#10;8&#10;9&#10;10&#10;11"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="e871fa89d8717b26" memberName="osc3SemiToneBox"
            virtualName="" explicitFocusOrder="0" pos="582 73 45 20" editable="0"
            layout="33" items="0&#10;1&#10;2&#10;3&#10;4&#10;5&#10;6&#10;7&#10;8&#10;9&#10;10&#10;11"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

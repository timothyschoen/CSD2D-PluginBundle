/*
   ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

   ==============================================================================
 */

#pragma once

#include <JuceHeader.h>
#include "SliderClass.h"

//==============================================================================
/**
 */
class NewProjectAudioProcessorEditor : public AudioProcessorEditor
{
public:
NewProjectAudioProcessorEditor (NewProjectAudioProcessor&);
~NewProjectAudioProcessorEditor();

//==============================================================================
void paint (Graphics&) override;
void resized() override;


TextButton qualityToggle[3];

TextButton channelToggle[3];

ImageButton bypassButton;

int channel = 0;


enum RadioButtonIds
{
        Quality = 1234,
        Channel = 5678
};
// This reference is provided as a quick way for your editor to
// access the processor object that created it.
NewProjectAudioProcessor& processor;

//#IF defined(BinaryData::font_otf)
//static Font customFont (Font (Typeface::createSystemTypefaceFor (BinaryData::font_otf, BinaryData::font_otfSize)));
//#ELSE

//#ENDIF

private:


SliderClass sliders;

void updateToggleState(NewProjectAudioProcessor &process, Button* button, int idx);



JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NewProjectAudioProcessorEditor)
};

//
//  SliderClass.hpp
//  VOX Wah
//
//  Created by Timothy Schoen on 01/05/2020.
//  Copyright © 2020 TS. All rights reserved.

#pragma once

#include <stdio.h>
#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
 */
class SliderClass : public Slider::Listener
{
public:


Slider sliders[16];

SliderClass ();
~SliderClass();



int sliderwidth = 200;

void makeSliders (AudioProcessorEditor &process, NewProjectAudioProcessor &processor);
void resized(AudioProcessorEditor &process);

void draw(Graphics &g, AudioProcessorEditor &process);
void sliderValueChanged (Slider* slider) override;

NewProjectAudioProcessor* p;
    
Font customFont;
    
private:



};

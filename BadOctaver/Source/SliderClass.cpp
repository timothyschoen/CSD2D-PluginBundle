// this file was auto-generated
// I don't generate any comments yet but it's on my todo list!


#include "SliderClass.h"

SliderClass::SliderClass () {
};
SliderClass::~SliderClass() {
};


void SliderClass::makeSliders(AudioProcessorEditor &process, NewProjectAudioProcessor &processor)
{
        p = &processor;
        sliders[0].setSliderStyle (Slider::LinearVertical);
        sliders[0].setRange(0.0, 1.0, 0.000001);
        sliders[0].setValue(0.2);
        sliders[1].setSliderStyle (Slider::LinearVertical);
        sliders[1].setRange(0.0, 1.0, 0.000001);
        sliders[1].setValue(0.8);
        sliders[2].setSliderStyle (Slider::LinearVertical);
        sliders[2].setRange(0.0, 1.0, 0.000001);
        sliders[2].setValue(0.8);
        for (int i = 0; i < 3; i++) {
                sliders[i].setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
                sliders[i].setPopupDisplayEnabled (false, false, &process);
                sliders[i].addListener (this);
                process.addAndMakeVisible(sliders[i]);
        }
        process.getLookAndFeel().setColour (Slider::thumbColourId, Colour::fromString("FF214aff"));
        process.getLookAndFeel().setColour (Slider::backgroundColourId, Colours::grey);
        process.getLookAndFeel().setColour (Slider::trackColourId, Colours::dimgrey);
        process.getLookAndFeel().setColour (TextButton::buttonColourId, Colours::white);
        process.getLookAndFeel().setColour (TextButton::buttonOnColourId, Colours::lightgrey);
        process.getLookAndFeel().setColour (TextButton::textColourOffId, Colours::darkgrey);
        process.getLookAndFeel().setColour (TextButton::textColourOnId, Colours::darkgrey);
        customFont = (Font (Typeface::createSystemTypefaceFor (BinaryData::font_otf, BinaryData::font_otfSize)));
        customFont.setHeight (45);
}


void SliderClass::resized(AudioProcessorEditor &process)
{
        sliders[0].setBounds (230, 10, 30, sliderwidth);
        sliders[1].setBounds (313.3333333333333, 10, 30, sliderwidth);
        sliders[2].setBounds (396.66666666666663, 10, 30, sliderwidth);
}


void SliderClass::draw(Graphics &g, AudioProcessorEditor &process)
{
        g.drawFittedText ("Gain", 220, 215, 50, 20, Justification::centred, 1);
        g.drawFittedText ("Volume", 303.3333333333333, 215, 50, 20, Justification::centred, 1);
        g.drawFittedText ("Dry/Wet", 386.66666666666663, 215, 50, 20, Justification::centred, 1);
        g.setColour (Colour::fromString("FF214aff"));
        g.fillRect (process.getWidth()-75, 0, 75, process.getHeight());
        g.setFont (customFont);
        g.drawSingleLineText ("BadOctaver ", 25, 75);
        g.setFont (Font(Font::getDefaultSansSerifFontName(), 12, 0));
}


void SliderClass::sliderValueChanged (Slider* slider)
{
        for (int i = 0; i < 4; i++) {
                if (slider == &sliders[i]) {
                        p->patchL.setSlider(i, sliders[i].getValue());
                        p->patchR.setSlider(i, sliders[i].getValue());
                        break;
                }
        }
}

#include "SliderClass.h"

SliderClass::SliderClass () {};
SliderClass::~SliderClass() {};


void SliderClass::makeSliders(AudioProcessorEditor &process, NewProjectAudioProcessor &processor)
{
  p = &processor;
  sliders[1].setSliderStyle (Slider::LinearVertical);
  sliders[1].setRange(0.0, 1.0, 0.000001);
  sliders[1].setValue(0.2);
  sliders[1].setTextValueSuffix (" Mod Depth");
  sliders[2].setSliderStyle (Slider::LinearVertical);
  sliders[2].setRange(0.0, 1.0, 0.000001);
  sliders[2].setValue(0.2);
  sliders[2].setTextValueSuffix (" Mod Rate");
  sliders[3].setSliderStyle (Slider::LinearVertical);
  sliders[3].setRange(0.0, 1.0, 0.000001);
  sliders[3].setValue(0.2);
  sliders[3].setTextValueSuffix (" Feedback");
  sliders[0].setSliderStyle (Slider::LinearVertical);
  sliders[0].setRange(0.0, 1.0, 0.000001);
  sliders[0].setValue(0.2);
  sliders[4].setSliderStyle (Slider::LinearVertical);
  sliders[4].setRange(0.0, 1.0, 0.000001);
  sliders[4].setValue(0.8);
  sliders[5].setSliderStyle (Slider::LinearVertical);
  sliders[5].setRange(0.0, 1.0, 0.000001);
  sliders[5].setValue(0.8);
  for (int i = 0; i < 6; i++) {
  sliders[i].setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
  sliders[i].setPopupDisplayEnabled (false, false, &process);
  sliders[i].addListener (this);
  process.addAndMakeVisible(sliders[i]);
  }
  process.getLookAndFeel().setColour (Slider::thumbColourId, Colour::fromString("FF8dff45"));
  process.getLookAndFeel().setColour (Slider::backgroundColourId, Colours::grey);
  process.getLookAndFeel().setColour (Slider::trackColourId, Colours::dimgrey);
  process.getLookAndFeel().setColour (TextButton::buttonColourId, Colours::white);
  process.getLookAndFeel().setColour (TextButton::buttonOnColourId, Colours::lightgrey);
  process.getLookAndFeel().setColour (TextButton::textColourOffId, Colours::darkgrey);
  process.getLookAndFeel().setColour (TextButton::textColourOnId, Colours::darkgrey);
  customFont = (Font (Typeface::createSystemTypefaceFor (BinaryData::font_ttf, BinaryData::font_ttfSize)));
  customFont.setHeight (50);
  }


void SliderClass::resized(AudioProcessorEditor &process)
{
  sliders[0].setBounds (230, 10, 30, sliderwidth);
  sliders[1].setBounds (281.6666666666667, 10, 30, sliderwidth);
  sliders[2].setBounds (333.33333333333337, 10, 30, sliderwidth);
  sliders[3].setBounds (385.00000000000006, 10, 30, sliderwidth);
  sliders[4].setBounds (436.66666666666674, 10, 30, sliderwidth);
  sliders[5].setBounds (488.3333333333334, 10, 30, sliderwidth);
  }


void SliderClass::draw(Graphics &g, AudioProcessorEditor &process)
{
   g.drawFittedText ("Gain", 220, 215, 50, 20, Justification::centred, 1);
   g.drawFittedText ("Mod Depth", 271.6666666666667, 215, 50, 20, Justification::centred, 1);
   g.drawFittedText ("Mod Rate", 323.33333333333337, 215, 50, 20, Justification::centred, 1);
   g.drawFittedText ("Feedback", 375.00000000000006, 215, 50, 20, Justification::centred, 1);
   g.drawFittedText ("Volume", 426.66666666666674, 215, 50, 20, Justification::centred, 1);
   g.drawFittedText ("Dry/Wet", 478.3333333333334, 215, 50, 20, Justification::centred, 1);
  g.setColour (Colour::fromString("FF8dff45"));
  g.fillRect (process.getWidth()-75, 0, 75, process.getHeight());
  g.setFont (customFont);
  g.drawSingleLineText ("ChorusDelay ", 25, 75);
  g.setFont (Font(Font::getDefaultSansSerifFontName(), 12, 0));
  }


void SliderClass::sliderValueChanged (Slider* slider)
{
  for (int i = 0; i < 7; i++) {
  if (slider == &sliders[i]) {
    p->patchL.setSlider(i, sliders[i].getValue());
    p->patchR.setSlider(i, sliders[i].getValue());
    break;
    }
  }
}

#include "SliderClass.h"

SliderClass::SliderClass () {};
SliderClass::~SliderClass() {};


void SliderClass::makeSliders(AudioProcessorEditor &process, NewProjectAudioProcessor &processor)
{
  p = &processor;
  sliders[1].setSliderStyle (Slider::LinearVertical);
  sliders[1].setRange(0.0, 1.0, 0.000001);
  sliders[1].setValue(0.2);
  sliders[1].setTextValueSuffix (" Slider");
  sliders[0].setSliderStyle (Slider::LinearVertical);
  sliders[0].setRange(0.0, 1.0, 0.000001);
  sliders[0].setValue(0.2);
  sliders[2].setSliderStyle (Slider::LinearVertical);
  sliders[2].setRange(0.0, 1.0, 0.000001);
  sliders[2].setValue(0.8);
  sliders[3].setSliderStyle (Slider::LinearVertical);
  sliders[3].setRange(0.0, 1.0, 0.000001);
  sliders[3].setValue(0.8);
  for (int i = 0; i < 4; i++) {
  sliders[i].setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
  sliders[i].setPopupDisplayEnabled (false, false, &process);
  sliders[i].addListener (this);
  process.addAndMakeVisible(sliders[i]);
  }
  process.getLookAndFeel().setColour (Slider::thumbColourId, Colour::fromString("FFff8051"));
  process.getLookAndFeel().setColour (Slider::backgroundColourId, Colours::grey);
  process.getLookAndFeel().setColour (Slider::trackColourId, Colours::dimgrey);
  process.getLookAndFeel().setColour (TextButton::buttonColourId, Colours::white);
  process.getLookAndFeel().setColour (TextButton::buttonOnColourId, Colours::lightgrey);
  process.getLookAndFeel().setColour (TextButton::textColourOffId, Colours::darkgrey);
  process.getLookAndFeel().setColour (TextButton::textColourOnId, Colours::darkgrey);
  customFont = (Font (Typeface::createSystemTypefaceFor (BinaryData::font_ttf, BinaryData::font_ttfSize)));
  customFont.setHeight (65);
  }


void SliderClass::resized(AudioProcessorEditor &process)
{
  sliders[0].setBounds (230, 10, 30, sliderwidth);
  sliders[1].setBounds (292.5, 10, 30, sliderwidth);
  sliders[2].setBounds (355, 10, 30, sliderwidth);
  sliders[3].setBounds (417.5, 10, 30, sliderwidth);
  }


void SliderClass::draw(Graphics &g, AudioProcessorEditor &process)
{
   g.drawFittedText ("Gain", 220, 215, 50, 20, Justification::centred, 1);
   g.drawFittedText ("Slider", 282.5, 215, 50, 20, Justification::centred, 1);
   g.drawFittedText ("Volume", 345, 215, 50, 20, Justification::centred, 1);
   g.drawFittedText ("Dry/Wet", 407.5, 215, 50, 20, Justification::centred, 1);
  g.setColour (Colour::fromString("FFff8051"));
  g.fillRect (process.getWidth()-75, 0, 75, process.getHeight());
  g.setFont (customFont);
  g.drawSingleLineText ("Fuzzface ", 25, 75);
  g.setFont (Font(Font::getDefaultSansSerifFontName(), 12, 0));
  }


void SliderClass::sliderValueChanged (Slider* slider)
{
  for (int i = 0; i < 5; i++) {
  if (slider == &sliders[i]) {
    p->patchL.setSlider(i, sliders[i].getValue());
    p->patchR.setSlider(i, sliders[i].getValue());
    break;
    }
  }
}

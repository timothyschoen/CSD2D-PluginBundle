/*
   ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

   ==============================================================================
 */

#pragma once

#include <JuceHeader.h>
#include "ScopeComponent.h"
#include "patch.h"

//==============================================================================
/**
 */
class NewProjectAudioProcessor : public AudioProcessor
{
public:
//==============================================================================
NewProjectAudioProcessor();
~NewProjectAudioProcessor();


AudioOscilloscope oscilloscope;

Patch patchL;
Patch patchR;

int channel = 0;

void setChannel(int chan);

void processLeft(int outputChannels, int numsamps, float** outBuffer, const float** inBuffer);

void processRight(int outputChannels, int numsamps, float** outBuffer, const float** inBuffer);

void processStereo(int outputChannels, int numsamps, float** outBuffer, const float** inBuffer);

void processBypass(int outputChannels, int numsamps, float** outBuffer, const float** inBuffer);

void (NewProjectAudioProcessor::*channelGenerators[4])(int outputChannels, int numsamps, float** outBuffer, const float** inBuffer) = {&NewProjectAudioProcessor::processLeft, &NewProjectAudioProcessor::processRight, &NewProjectAudioProcessor::processStereo, &NewProjectAudioProcessor::processBypass};


//==============================================================================
void prepareToPlay (double sampleRate, int samplesPerBlock) override;
void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

//==============================================================================
AudioProcessorEditor* createEditor() override;
bool hasEditor() const override;

//==============================================================================
const String getName() const override;

bool acceptsMidi() const override;
bool producesMidi() const override;
bool isMidiEffect() const override;
double getTailLengthSeconds() const override;

//==============================================================================
int getNumPrograms() override;
int getCurrentProgram() override;
void setCurrentProgram (int index) override;
const String getProgramName (int index) override;
void changeProgramName (int index, const String& newName) override;

//==============================================================================
void getStateInformation (MemoryBlock& destData) override;
void setStateInformation (const void* data, int sizeInBytes) override;

private:
JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NewProjectAudioProcessor)
};

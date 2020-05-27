/*
   ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

   ==============================================================================
 */

#include "PluginProcessor.h"
#include "PluginEditor.h"



//==============================================================================
NewProjectAudioProcessor::NewProjectAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
        : AudioProcessor (BusesProperties()
                     #if !JucePlugin_IsMidiEffect
                      #if !JucePlugin_IsSynth
                          .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                          .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                          )

#endif

{
}

NewProjectAudioProcessor::~NewProjectAudioProcessor()
{
}

//==============================================================================
const String NewProjectAudioProcessor::getName() const
{
        return JucePlugin_Name;
}

bool NewProjectAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
        return true;
   #else
        return false;
   #endif
}

bool NewProjectAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
        return true;
   #else
        return false;
   #endif
}

bool NewProjectAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
        return true;
   #else
        return false;
   #endif
}

double NewProjectAudioProcessor::getTailLengthSeconds() const
{
        return 0.0;
}

int NewProjectAudioProcessor::getNumPrograms()
{
        return 1; // NB: some hosts don't cope very well if you tell them there are 0 programs,
                  // so this should be at least 1, even if you're not really implementing programs.
}

int NewProjectAudioProcessor::getCurrentProgram()
{
        return 0;
}

void NewProjectAudioProcessor::setCurrentProgram (int index)
{
}

const String NewProjectAudioProcessor::getProgramName (int index)
{
        return {};
}

void NewProjectAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================


//==============================================================================
void NewProjectAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
        // Initialize the same patch twice for stereo processing
        patchL.init();
        patchR.init();

}

void NewProjectAudioProcessor::releaseResources()
{
        // Delete recources
        patchL.destroy();
        patchR.destroy();
        // When playback stops, you can use this as an opportunity to free up any
        // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool NewProjectAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
        ignoreUnused (layouts);
        return true;
  #else
        // This is the place where you check if the layout is supported.
        // In this template code we only support mono or stereo.
        if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
            && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
                return false;

        // This checks if the input layout matches the output layout
   #if !JucePlugin_IsSynth
        if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
                return false;
   #endif

        return true;
  #endif
}
#endif

void NewProjectAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
        ScopedNoDenormals noDenormals;
        auto totalNumInputChannels  = getTotalNumInputChannels();
        auto totalNumOutputChannels = getTotalNumOutputChannels();

        // In case we have more outputs than inputs, this code clears any output
        // channels that didn't contain input data, (because these aren't
        // guaranteed to be empty - they may contain garbage).
        // This is here to avoid people getting screaming feedback
        // when they first compile a plugin, but obviously you don't need to keep
        // this code if your algorithm always overwrites all the output channels.
        for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
                buffer.clear (i, 0, buffer.getNumSamples());

        const float* inBuffer[totalNumInputChannels];
        float* outBuffer[totalNumOutputChannels];

        for (int i = 0; i < totalNumInputChannels; ++i)
                inBuffer[i] = buffer.getReadPointer (i);

        for (int i = 0; i < totalNumOutputChannels; ++i)
                outBuffer[i] = buffer.getWritePointer (i);

        // Get the sample!!
        // I made an array of functions to easily switch between left, right or stereo input
        (this->*channelGenerators[channel])(totalNumOutputChannels, buffer.getNumSamples(), outBuffer, inBuffer);


}

// Process audio for left side
void NewProjectAudioProcessor::processLeft(int outputChannels, int numsamps, float** outBuffer, const float** inBuffer) {

        for (int i=0; i<numsamps; ++i)
        {
                float sample = patchL.inout(inBuffer[0][i]);

                for (int j=0; j<outputChannels; ++j)
                {
                        outBuffer[j][i] = sample;
                }
                oscilloscope.addSample(sample*60);

        }
}
// Process audio for right side
void NewProjectAudioProcessor::processRight(int outputChannels, int numsamps, float** outBuffer, const float** inBuffer) {
        for (int i=0; i<numsamps; ++i)
        {
                float sample = patchR.inout(inBuffer[1][i]);
                for (int j=0; j<outputChannels; ++j)
                {
                        outBuffer[j][i] = sample;
                }
                oscilloscope.addSample(sample*60);

        }

}

// Process stereo audio
void NewProjectAudioProcessor::processStereo(int outputChannels, int numsamps, float** outBuffer, const float** inBuffer) {
        for (int i=0; i<numsamps; ++i)
        {
                double sample[2] = {patchL.inout(inBuffer[0][i]), patchR.inout(inBuffer[1][i])};
                for (int j=0; j<outputChannels; ++j)
                {
                        outBuffer[j][i] = sample[j];
                }
                oscilloscope.addSample(sample[0]*60);

        }

}

// Bypass audio -> I should later implement shutdownAudio and setNumChannels for this!!!!
void NewProjectAudioProcessor::processBypass(int outputChannels, int numsamps, float** outBuffer, const float** inBuffer) {
        for (int i=0; i<numsamps; ++i)
        {
                for (int j=0; j<outputChannels; ++j)
                {
                        outBuffer[j][i] = 0;
                }
        }

}

void NewProjectAudioProcessor::setChannel(int chan) {
        channel = chan;
}



//==============================================================================
bool NewProjectAudioProcessor::hasEditor() const
{
        return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* NewProjectAudioProcessor::createEditor()
{
        return new NewProjectAudioProcessorEditor (*this);
}

//==============================================================================
void NewProjectAudioProcessor::getStateInformation (MemoryBlock& destData)
{
        // You should use this method to store your parameters in the memory block.
        // You could do that either as raw data, or use the XML or ValueTree classes
        // as intermediaries to make it easy to save and load complex data.
}

void NewProjectAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
        // You should use this method to restore your parameters from this memory block,
        // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
        return new NewProjectAudioProcessor();
}

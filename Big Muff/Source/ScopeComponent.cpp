/*
   ==============================================================================

   This file is part of the dRowAudio JUCE module
   Copyright 2004-13 by dRowAudio.

   ------------------------------------------------------------------------------

   dRowAudio is provided under the terms of The MIT License (MIT):

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.

   ==============================================================================
 */

// This is a oscilloscope object I found online

#include "ScopeComponent.h"

AudioOscilloscope::AudioOscilloscope() :
        bufferSizeMask (1023),
        currentMax (-1.0f),
        currentMin (1.0f),
        bufferPos (0),
        lastBufferPos (0),
        bufferSize (1024), // Needs to be a power of 2 and larger than the width of your scope!
        numSamplesIn (0),
        bufferLastMax (-1.0f),
        bufferLastMin (1.0f),
        verticalZoomFactor (1.5f),
        horizontalZoomFactor (0.05f),
        backgroundColour (Colours::white),
        traceColour (Colours::green)
{
        circularBufferMax.calloc (bufferSize);
        circularBufferMin.calloc (bufferSize);
        clear();

        setOpaque (true);
        resized(); //Initialises the image
        startTimerHz (100);
}

//==============================================================================

// Add a whole block of samples
void AudioOscilloscope::processBlock (const float* inputChannelData,
                                      int numSamples)
{
        if (inputChannelData != nullptr)
                for (int i = 0; i < numSamples; ++i)
                        addSample (inputChannelData [i]);
}

void AudioOscilloscope::clear()
{
        zeromem (circularBufferMax, sizeof (float) * size_t (bufferSize));
        zeromem (circularBufferMin, sizeof (float) * size_t (bufferSize));
}

//==============================================================================
void AudioOscilloscope::resized()
{
        Image oldImage (waveformImage);
        waveformImage = Image (Image::RGB,
                               jmax (1, getWidth()), jmax (1, getHeight()),
                               true);
        waveformImage.clear(waveformImage.getBounds(), Colours::black);

        if (oldImage.isValid())
                waveformImage = oldImage.rescaled (waveformImage.getWidth(), waveformImage.getHeight());
}

void AudioOscilloscope::paint (Graphics& g)
{
        g.drawImageAt (waveformImage, 0, 0);
}

//draw!
void AudioOscilloscope::timerCallback()
{
        const int width = getWidth();
        const float halfHeight = getHeight() * 0.5f;

        const int numPixelsToDraw = bufferPos - lastBufferPos;
        const int newSectionStart = width - numPixelsToDraw;

        // shuffle image along
        waveformImage.moveImageSection (0, 0,
                                        numPixelsToDraw, 0,
                                        newSectionStart, waveformImage.getHeight());

        // draw new section
        Graphics g (waveformImage);

        g.setColour (backgroundColour);
        g.fillRect (newSectionStart, 0, 200*100, waveformImage.getHeight());
        g.setColour (traceColour);

        const int bp = bufferPos + bufferSize;

        for (int x = width; --x >= newSectionStart;)
        {
                const int samplesAgo = width - x;

                float max = circularBufferMax [(bp - samplesAgo) &bufferSizeMask];
                float min = circularBufferMin [(bp - samplesAgo) &bufferSizeMask];

                if (min > bufferLastMax)
                        min = bufferLastMax;
                if (max < bufferLastMin)
                        max = bufferLastMin;

                bufferLastMax = max;
                bufferLastMin = min;

                g.drawLine ((float) x, halfHeight + (halfHeight * verticalZoomFactor * max),
                            (float) x, halfHeight + (halfHeight * verticalZoomFactor * min));
        }

        lastBufferPos = bufferPos;

        repaint();
}

// Add a single sample to the oscilloscope
void AudioOscilloscope::addSample (const float sample)
{
        if (sample > currentMax)
                currentMax = sample;
        if (sample < currentMin)
                currentMin = sample;

        const int samplesToAverage = 1 + (int) (127.0 * horizontalZoomFactor);

        if (++numSamplesIn > samplesToAverage)
        {
                bufferPos = bufferPos & bufferSizeMask;
                circularBufferMax [bufferPos] = currentMax;
                circularBufferMin [bufferPos] = currentMin;
                bufferPos++;

                numSamplesIn = 0;
                currentMin = 1.0e6f;
                currentMax = -currentMin;
        }
}

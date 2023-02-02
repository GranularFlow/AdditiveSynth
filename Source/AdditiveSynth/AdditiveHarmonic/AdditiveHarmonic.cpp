/*
  ==============================================================================

    AdditiveHarmonic.cpp
    Created: 1 Feb 2023 11:01:49pm
    Author:  honza

  ==============================================================================
*/

#include "AdditiveHarmonic.h"

AdditiveHarmonic::AdditiveHarmonic(int sampleRateIn)
{
    sampleRate = sampleRateIn;
    addAndMakeVisible(harmonicSettings);
    startTimer(1);
}

AdditiveHarmonic::~AdditiveHarmonic()
{
    stopTimer();

}

void AdditiveHarmonic::paint(Graphics& g)
{
}

void AdditiveHarmonic::resized()
{
    harmonicSettings.setBounds(getLocalBounds()
        .withTrimmedTop((getHeight() / 2) * (1.01))
        .withTrimmedLeft(getWidth() * 0.01)
        .withTrimmedRight(getWidth() * 0.01)
        .withTrimmedBottom(getWidth() * 0.01)
    );

}

void AdditiveHarmonic::timerCallback()
{
}

void AdditiveHarmonic::fillNextBuffer(AudioBuffer<float>& bufferToFill)
{
    float* leftChannel = bufferToFill.getWritePointer(0);
    float* rightChannel = bufferToFill.getWritePointer(1);

    for (int i = 0; i < bufferToFill.getNumSamples(); i++)
    {
        leftChannel[i] = sinf(2 * std::atanf(1.f) * 4 * (float)i / totalSamples);
        rightChannel[i] = leftChannel[i];
        currentSample++;
    }
}

void AdditiveHarmonic::changeTimer(float)
{
}

void AdditiveHarmonic::setSampleRate(int sampleRateIn)
{
    sampleRate = sampleRateIn;
}

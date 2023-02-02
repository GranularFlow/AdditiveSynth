/*
  ==============================================================================

    AdditiveHarmonic.h
    Created: 1 Feb 2023 11:01:49pm
    Author:  honza

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "AdditiveHarmonicSettings/AdditiveHarmonicSettings.h"
class AdditiveHarmonic : public Component, public Timer
{
public:
    // Class
	AdditiveHarmonic(int);
	~AdditiveHarmonic() override;
    //GUI
    void paint(Graphics& g) override;
    void resized() override;
    // Listeners
    void timerCallback() override;
    // Tools
    void fillNextBuffer(AudioBuffer<float>&);
    void changeTimer(float);
    void setSampleRate(int);


private:
    // Settings
    int totalSamples = 100;	
    int currentSample = 0;
    int sampleRate;
    AdditiveHarmonicSettings harmonicSettings;
};

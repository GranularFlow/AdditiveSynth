/*
  ==============================================================================

    AdditiveVisualiser.h
    Created: 1 Feb 2023 11:15:23pm
    Author:  honza

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "../../Constants.h"

class AdditiveVisualiser : public Component
{
public:
    // Class
	AdditiveVisualiser();
	~AdditiveVisualiser();
    // GUI
    void paint(Graphics&) override;
    // Setters
    void setWaveForm(AudioBuffer<float>&);

private:
    Array<float> waveForm;
    bool waveformSet = false;
};

/*
  ==============================================================================

    AdditiveHarmonicsSettings.h
    Created: 1 Feb 2023 10:20:17pm
    Author:  honza

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "../../../Constants.h"
#include "../../../Utils/Utils.h"
#include "../../../CustomSetting/RadioBox.h"
#include "../../../CustomSetting/Knob.h"
#include "../../../CustomSetting/Separator.h"

class AdditiveHarmonicSettings : public Component
{
public:

    // Class
	AdditiveHarmonicSettings();
	~AdditiveHarmonicSettings();
    // GUI
    void initGui();
    void paint(Graphics& graphics) override;
    void resized() override;
    // Tools
    // Getters
    float getPhase();
    float getFreq();
    float getVolume();
    float getPan(int8);

private:
    // GUI
    Colour guiColour;
    OwnedArray<Separator> separators;
    // Play style
    // Harmonics
    Knob phaseKnob{ "PHASE", L_AQUA, 0, 100, 1, 50 }; // %
    Knob freqKnob{ "FREQUENCY", L_ORANGE, 0, 100, 1, 50 }; // %
    // Master
    Knob volumeKnob{ "VOLUME", C_SUNFLOWER, 0, 100, 1, 50 }; // %
    Knob panKnob{ "PAN", C_BILLS, 0, 100, 1, 50 }; // %
};
/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Utils/Constants.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class GranularFlowAdditiveAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    GranularFlowAdditiveAudioProcessorEditor (GranularFlowAdditiveAudioProcessor&);
    ~GranularFlowAdditiveAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;


private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    GranularFlowAdditiveAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GranularFlowAdditiveAudioProcessorEditor)
};

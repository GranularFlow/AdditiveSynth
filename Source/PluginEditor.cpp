/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GranularFlowAdditiveAudioProcessorEditor::GranularFlowAdditiveAudioProcessorEditor (GranularFlowAdditiveAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible(audioProcessor.additiveSynth);
    setSize (W_WIDTH, W_HEIGHT);
}

GranularFlowAdditiveAudioProcessorEditor::~GranularFlowAdditiveAudioProcessorEditor()
{
}

//==============================================================================
void GranularFlowAdditiveAudioProcessorEditor::paint (juce::Graphics& g)
{
}

void GranularFlowAdditiveAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    audioProcessor.additiveSynth.setBounds(getLocalBounds());
}

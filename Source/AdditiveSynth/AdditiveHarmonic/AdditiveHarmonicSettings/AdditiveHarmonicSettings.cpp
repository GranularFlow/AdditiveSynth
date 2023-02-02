/*
  ==============================================================================

    AdditiveHarmonicsSettings.cpp
    Created: 1 Feb 2023 10:20:17pm
    Author:  honza

  ==============================================================================
*/

#include "AdditiveHarmonicSettings.h"

AdditiveHarmonicSettings::AdditiveHarmonicSettings()
{
    initGui();

}

AdditiveHarmonicSettings::~AdditiveHarmonicSettings()
{
}

void AdditiveHarmonicSettings::initGui()
{
    // GUI
    for (int8 i = 0; i < 3; i++)
    {
        separators.add(new Separator());
        addAndMakeVisible(separators.getLast());
    }

    // Settings
    addAndMakeVisible(phaseKnob);
    addAndMakeVisible(freqKnob);

    // Master
    addAndMakeVisible(volumeKnob);
    addAndMakeVisible(panKnob);
}

void AdditiveHarmonicSettings::paint(Graphics& g)
{
    g.setColour(L_GRAY);
    g.fillRoundedRectangle(getLocalBounds().toFloat(), 30);

}

void AdditiveHarmonicSettings::resized()
{
    int sectionWidth = (getWidth() * 0.9) / 3;
    int sectionHeight = getHeight();

    FlexBox fb{
            FlexBox::Direction::row,
            FlexBox::Wrap::noWrap,
            FlexBox::AlignContent::center,
            FlexBox::AlignItems::flexStart,
            FlexBox::JustifyContent::spaceAround
    };
    // First column    
    FlexBox tmpFB = fb;
    tmpFB.flexWrap = FlexBox::Wrap::wrap;
    tmpFB.alignItems = FlexBox::AlignItems::center;
    tmpFB.justifyContent = FlexBox::JustifyContent::center;
    // Second column
    FlexBox tmpFB2 = tmpFB;
    tmpFB2.flexDirection = FlexBox::Direction::column;


    // Second column
    int tmp_height = sectionHeight;
    int tmp_width = sectionWidth / 2;
    tmpFB.items.add(FlexItem(phaseKnob).withOrder(1).withMinWidth(tmp_width).withMinHeight(tmp_height));
    tmpFB.items.add(FlexItem(freqKnob).withOrder(2).withMinWidth(tmp_width).withMinHeight(tmp_height));
    //tmpFB2.items.add(FlexItem(cursorPositionKnob).withOrder(5).withMinWidth(tmp_width).withMinHeight(tmp_height));
    // Add column to final flex box  
    fb.items.add(FlexItem(tmpFB2).withOrder(3).withMinWidth(sectionWidth).withHeight(sectionHeight));

    // Third column
    tmp_height = sectionHeight / 2;
    tmp_width = 100;
    tmpFB2.items.add(FlexItem(volumeKnob).withOrder(1).withMinWidth(tmp_width).withHeight(tmp_height));
    tmpFB2.items.add(FlexItem(panKnob).withOrder(2).withMinWidth(tmp_width).withHeight(tmp_height));
    // Add column to final flex box
    fb.items.add(FlexItem(tmpFB2).withOrder(5).withMinWidth(sectionWidth).withHeight(sectionHeight));


    // White lines
    for (int8 i = 0; i < 3; i++)
    {
        fb.items.add(FlexItem(*separators[i]).withMinWidth(1).withHeight(sectionHeight).withOrder((i + 1) * 2));
    }

    fb.performLayout(getLocalBounds());

}

float AdditiveHarmonicSettings::getPhase()
{
    return phaseKnob.getValue();
}

float AdditiveHarmonicSettings::getFreq()
{
    return freqKnob.getValue();
}

float AdditiveHarmonicSettings::getVolume()
{
    return (float)volumeKnob.getValue() / 100;
}

float AdditiveHarmonicSettings::getPan(int8 channel)
{
    return  1 - abs(channel - ((float)panKnob.getValue() / 100));
}

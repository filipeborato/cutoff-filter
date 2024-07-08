/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "CutOffPlugin/PluginProcessor.h"
#include "CutOffPlugin/PluginEditor.h"

//==============================================================================
LPHPFilterAudioProcessorEditor::LPHPFilterAudioProcessorEditor (LPHPFilterAudioProcessor& p, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    constexpr auto HEIGHT = 380;
    constexpr auto WIDTH = 340;

    addAndMakeVisible(cutoffFrequencySlider);
    cutoffFrequencySlider.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    cutoffFrequencyAttachment.reset(
        new juce::AudioProcessorValueTreeState::SliderAttachment(
            vts, "cutoff_frequency", cutoffFrequencySlider));

    addAndMakeVisible(cutoffFrequencyLabel);
    cutoffFrequencyLabel.setText("Cutoff Frequency", juce::dontSendNotification);

    addAndMakeVisible(highpassButton);
    highpassAttachment.reset(
        new juce::AudioProcessorValueTreeState::ButtonAttachment(
            vts, "highpass", highpassButton));

    addAndMakeVisible(highpassButtonLabel);
    highpassButtonLabel.setText("Highpass", juce::dontSendNotification);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(WIDTH, HEIGHT);
}

LPHPFilterAudioProcessorEditor::~LPHPFilterAudioProcessorEditor()
{
}

//==============================================================================
void LPHPFilterAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

    g.setColour(juce::Colours::whitesmoke);
    g.setFont(15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
    cutoffFrequencySlider.setBounds({ 15, 80, 250, 250 });
    //cutoffFrequencySlider.setRotaryParameters(0, (float)2*3.14, true);
    cutoffFrequencyLabel.setBounds({ cutoffFrequencySlider.getX() + 110, cutoffFrequencySlider.getY() - 50,
        200, 50 });
    highpassButton.setBounds({ cutoffFrequencySlider.getX(),
        cutoffFrequencySlider.getY() + cutoffFrequencySlider.getHeight() -5, 30, 50 });
    highpassButtonLabel.setBounds({ cutoffFrequencySlider.getX() + highpassButton.getWidth() + 15, highpassButton.getY(),
        cutoffFrequencySlider.getWidth() - highpassButton.getWidth(),
        highpassButton.getHeight() });
}

void LPHPFilterAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
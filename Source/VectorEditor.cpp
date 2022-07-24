#include "PluginProcessor.h"
#include "VectorEditor.h"

VectorAudioProcessorEditor::VectorAudioProcessorEditor(ResizableAppAudioProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    addAndMakeVisible(slider);

    setResizable(true, true);
    setSize(400, 300);
}

VectorAudioProcessorEditor::~VectorAudioProcessorEditor()
{
}

void VectorAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.setGradientFill(ColourGradient{ Colours::darkgrey, getLocalBounds().toFloat().getCentre(), Colours::darkgrey.darker(0.7f), {}, true });
    g.fillRect(getLocalBounds());
}

void VectorAudioProcessorEditor::resized()
{
    const auto dimensions = jmin(proportionOfWidth(0.25f), proportionOfHeight(0.25f));
    slider.setBounds(getLocalBounds().withSizeKeepingCentre(dimensions, dimensions));
}

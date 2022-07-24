#include "PluginProcessor.h"
#include "RasterEditor.h"

RasterAudioProcessorEditor::RasterAudioProcessorEditor (ResizableAppAudioProcessor& p) :
    AudioProcessorEditor(p), audioProcessor (p)
{
    addAndMakeVisible(slider);

    setResizable(true, true);
    setSize(1200, 800);
}

RasterAudioProcessorEditor::~RasterAudioProcessorEditor()
{
}

void RasterAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.drawImage(ImageCache::getFromMemory(BinaryData::Background_png, BinaryData::Background_pngSize), getLocalBounds().toFloat());
}

void RasterAudioProcessorEditor::resized()
{
    slider.setBounds(631, 393, 233, 233);
}
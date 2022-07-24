#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Components/VectorKnob.h"

class VectorAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    VectorAudioProcessorEditor(ResizableAppAudioProcessor&);
    ~VectorAudioProcessorEditor() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    ResizableAppAudioProcessor& audioProcessor;

    VectorKnob slider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VectorAudioProcessorEditor)
};

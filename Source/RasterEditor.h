#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Components/RasterKnob.h"

class RasterAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    RasterAudioProcessorEditor (ResizableAppAudioProcessor&);
    ~RasterAudioProcessorEditor() override;
    
    void paint (Graphics&) override;
    void resized() override;

private:
    ResizableAppAudioProcessor& audioProcessor;
    RasterKnob slider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RasterAudioProcessorEditor)
};
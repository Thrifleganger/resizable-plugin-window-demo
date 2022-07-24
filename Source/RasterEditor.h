#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Components/RasterKnob.h"

class RasterComponent  : public Component
{
public:
    RasterComponent (ResizableAppAudioProcessor&);
    ~RasterComponent() override;
    
    void paint (Graphics&) override;
    void resized() override;

private:
    ResizableAppAudioProcessor& audioProcessor;
    RasterKnob slider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RasterComponent)
};

// Root Wrapper

class WrappedRasterAudioProcessorEditor : public AudioProcessorEditor
{
public:
    WrappedRasterAudioProcessorEditor(ResizableAppAudioProcessor&);
    void resized() override;

private:
    static constexpr int originalWidth{ 1200 };
    static constexpr int originalHeight{ 800 };

    RasterComponent rasterComponent;
    ApplicationProperties applicationProperties;
};

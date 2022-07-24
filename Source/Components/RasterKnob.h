#pragma once

#include <JuceHeader.h>

class RasterKnob : public Slider
{
public:
    RasterKnob() : Slider(SliderStyle::RotaryHorizontalVerticalDrag, TextEntryBoxPosition::NoTextBox)
    {
        setMouseCursor(MouseCursor::PointingHandCursor);
        setLookAndFeel(&mainSliderLookAndFeel);
    }

    ~RasterKnob()
    {
        setLookAndFeel(nullptr);
    }

private:
    class RasterKnobLookAndFeel : public LookAndFeel_V4
    {
    public:
        RasterKnobLookAndFeel()
        {
            image = ImageCache::getFromMemory(BinaryData::RasterKnob_png, BinaryData::RasterKnob_pngSize);
        }

        void drawRotarySlider(
            Graphics& g, 
            int x, 
            int y, 
            int width, 
            int height, 
            float sliderPosProportional,
            float /*rotaryStartAngle*/, 
            float /*rotaryEndAngle*/, 
            Slider& /*slider*/) override
        {
            const auto frames = 90;
            const auto frameId = static_cast<int>(ceil(sliderPosProportional * (static_cast<float>(frames) - 1.0f)));

            g.drawImage(image,
                x,
                y,
                width,
                height,
                (frameId % 9) * width,
                (frameId / 9) * height,
                width,
                height);
        }

    private:
        Image image;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RasterKnobLookAndFeel)
    } mainSliderLookAndFeel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RasterKnob)
};

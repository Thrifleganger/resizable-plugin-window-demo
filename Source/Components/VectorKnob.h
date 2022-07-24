#pragma once

#include <JuceHeader.h>

class VectorKnob : public Slider
{
public:
	VectorKnob() : Slider(SliderStyle::RotaryHorizontalVerticalDrag, NoTextBox)
	{
		setMouseCursor(MouseCursor::PointingHandCursor);
		setLookAndFeel(&lookAndFeel);
	}

	~VectorKnob()
	{
		setLookAndFeel(nullptr);
	}

private:

	class VectorKnobLookAndFeel : public LookAndFeel_V4
	{
	public:
		void drawRotarySlider(
			Graphics& g, 
			int x, 
			int y, 
			int width, 
			int height, 
			float sliderPosProportional, 
			float rotaryStartAngle, 
			float rotaryEndAngle, 
			Slider& slider) override
		{
			if (const auto svg = XmlDocument::parse(BinaryData::VectorKnob_svg))
			{
				const auto drawable = Drawable::createFromSVG(*svg);
				drawable->setTransformToFit(Rectangle<int>(x, y, width, height).toFloat(), RectanglePlacement::centred);

				const float angle = rotaryStartAngle + sliderPosProportional * (rotaryEndAngle - rotaryStartAngle);
				drawable->draw(g, 1.f, AffineTransform::rotation(angle, width / 2.f, height / 2.f));
			}
		}
	} lookAndFeel;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VectorKnob)
};

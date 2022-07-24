#include "PluginProcessor.h"
#include "RasterEditor.h"

RasterComponent::RasterComponent (ResizableAppAudioProcessor& p) : audioProcessor (p)
{
    addAndMakeVisible(slider);
}

RasterComponent::~RasterComponent()
{
}

void RasterComponent::paint (juce::Graphics& g)
{
    g.drawImage(ImageCache::getFromMemory(BinaryData::Background_png, BinaryData::Background_pngSize), getLocalBounds().toFloat());
}

void RasterComponent::resized()
{
    slider.setBounds(631, 393, 233, 233);
}


// Wrapper implementation

WrappedRasterAudioProcessorEditor::WrappedRasterAudioProcessorEditor(ResizableAppAudioProcessor& p) :
    AudioProcessorEditor(p),
    rasterComponent(p)
{
    addAndMakeVisible(rasterComponent);

    PropertiesFile::Options options;
    options.applicationName = ProjectInfo::projectName;
    options.commonToAllUsers = true;
    options.filenameSuffix = "settings";
    options.osxLibrarySubFolder = "Application Support";
    applicationProperties.setStorageParameters(options);

    if (auto* constrainer = getConstrainer())
    {
        constrainer->setFixedAspectRatio(static_cast<double> (originalWidth) / static_cast<double> (originalHeight));
        constrainer->setSizeLimits(originalWidth / 4, originalHeight / 4,
            originalWidth, originalHeight);
    }

    auto sizeRatio{ 1.0 };
    if (auto* properties = applicationProperties.getCommonSettings(true))
    {
        sizeRatio = properties->getDoubleValue("sizeRatio", 1.0);
    }

    setResizable(true, true);
    setSize(static_cast<int> (originalWidth * sizeRatio), 
        static_cast<int> (originalHeight * sizeRatio));
}

void WrappedRasterAudioProcessorEditor::resized()
{
    const auto scaleFactor = static_cast<float> (getWidth()) / originalWidth;
    if (auto* properties = applicationProperties.getCommonSettings(true))
    {
        properties->setValue("sizeRatio", scaleFactor);
    }

    rasterComponent.setTransform(AffineTransform::scale(scaleFactor));
    rasterComponent.setBounds(0, 0, originalWidth, originalHeight);
}

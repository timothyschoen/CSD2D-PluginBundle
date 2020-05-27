// Class for static UI elements

#include "PluginEditor.h"


//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
        : AudioProcessorEditor (&p), processor (p)
{
        // Make sure that before the constructor has finished, you've set the
        // editor's size to whatever you need it to be.
        setSize (550, 270);
        sliders.makeSliders(*this, processor);

        Image normalButton = ImageCache::getFromMemory (BinaryData::offswitch_png, BinaryData::offswitch_pngSize);
        Image overButton = ImageCache::getFromMemory (BinaryData::clickedswitch_png, BinaryData::clickedswitch_pngSize);
        Image downButton = ImageCache::getFromMemory (BinaryData::onswitch_png, BinaryData::onswitch_pngSize);
        bypassButton.setImages (false, false, true, normalButton, 1.0f, {}, overButton, 1.0f, {}, downButton, 1.0f, {});

        bypassButton.setClickingTogglesState (true);
        bypassButton.setToggleState(true, dontSendNotification);
        bypassButton.onClick = [this, &p] {
                                       updateToggleState (p, &channelToggle[0], 6);
                               };

        addAndMakeVisible(bypassButton);





        for(int i = 0; i < 3; i++) {
                qualityToggle[i].setClickingTogglesState (true);
                channelToggle[i].setClickingTogglesState (true);

                addAndMakeVisible (qualityToggle[i]);
                addAndMakeVisible (channelToggle[i]);
        }


        qualityToggle[0].setRadioGroupId(Quality);
        qualityToggle[1].setRadioGroupId(Quality);
        qualityToggle[2].setRadioGroupId(Quality);

        qualityToggle[1].setToggleState(true, dontSendNotification);

        channelToggle[0].setRadioGroupId(Channel);
        channelToggle[1].setRadioGroupId(Channel);
        channelToggle[2].setRadioGroupId(Channel);

        channelToggle[0].setToggleState(true, dontSendNotification);

        channelToggle[0].onClick = [this, &p] {
                                           updateToggleState (p, &channelToggle[0], 0);
                                   };
        channelToggle[1].onClick = [this, &p] {
                                           updateToggleState (p, &channelToggle[1], 2);
                                   };
        channelToggle[2].onClick = [this, &p] {
                                           updateToggleState (p, &channelToggle[2], 1);
                                   };

        int edges[4] = {2, 3, 1};

        for (int i = 0; i < 3; i++) {
                qualityToggle[i].setConnectedEdges(edges[i]);
                channelToggle[i].setConnectedEdges(edges[i]);
        }

        qualityToggle[0].setButtonText("L");
        qualityToggle[1].setButtonText ("M");
        qualityToggle[2].setButtonText ("H");

        channelToggle[0].setButtonText("L");
        channelToggle[1].setButtonText ("ST");
        channelToggle[2].setButtonText ("R");

        processor.oscilloscope.setTraceColour(getLookAndFeel().findColour(Slider::thumbColourId));

        addAndMakeVisible(processor.oscilloscope);



}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}


//==============================================================================
void NewProjectAudioProcessorEditor::paint (Graphics& g)
{

        g.fillAll (Colours::white);


        sliders.draw(g, *this);

        g.setColour (Colours::white);
        g.drawFittedText ("Input\nChannel", getWidth()-70, 50, 70, 100, Justification::centred, 1);
        g.drawFittedText ("Quality", getWidth()-70, 120, 70, 70, Justification::centred, 1);

        Image logo = ImageCache::getFromMemory (BinaryData::logo_png, BinaryData::logo_pngSize);
        g.drawImageAt(logo, getWidth()-65, getHeight()-60);

        g.setColour (Colours::grey);

        Line<float> lineSidebar (Point<float> (getWidth()-75, 0),
                                 Point<float> (getWidth()-75, 500));

        g.drawLine (lineSidebar, 1.0f);

        Line<float> lineLogoV (Point<float> (20, 100),
                               Point<float> (200, 100));

        g.drawLine (lineLogoV, 1.0f);

        Line<float> lineLogoH (Point<float> (210, 20),
                               Point<float> (210, getHeight()-20));

        g.drawLine (lineLogoH, 1.0f);

        g.setColour (Colours::darkgrey);




        //processor.oscilloscope.paint(g);



}


void NewProjectAudioProcessorEditor::resized()
{

        channelToggle[0].setBounds (getWidth()-67, 120, 21, 21);
        channelToggle[1].setBounds (getWidth()-47, 120, 21, 21);
        channelToggle[2].setBounds (getWidth()-27, 120, 21, 21);

        qualityToggle[0].setBounds (getWidth()-67, 170, 21, 21);
        qualityToggle[1].setBounds (getWidth()-47, 170, 21, 21);
        qualityToggle[2].setBounds (getWidth()-27, 170, 21, 21);
        sliders.resized(*this);

        processor.oscilloscope.setBounds (20, 120, 180, 100);

        bypassButton.setBounds (getWidth()-53, 20, 32, 32);



}

void NewProjectAudioProcessorEditor::updateToggleState (NewProjectAudioProcessor &processor, Button* button, int idx)
{
        printf("%d", idx);
        if(idx < 3) {
                processor.setChannel(idx);
                channel = idx;
        }
        else if (idx < 6) {
                processor.patchL.setIterations((idx-2)*5);
                processor.patchR.setIterations((idx-2)*5);
        }
        else {
                if (!bypassButton.getToggleState()) {
                        processor.setChannel(3);
                }
                else {
                        processor.setChannel(channel);
                }

        }
}

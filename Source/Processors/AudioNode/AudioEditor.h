/*
    ------------------------------------------------------------------

    This file is part of the Open Ephys GUI
    Copyright (C) 2014 Open Ephys

    ------------------------------------------------------------------

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#ifndef __AUDIOEDITOR_H_9D6F1FC3__
#define __AUDIOEDITOR_H_9D6F1FC3__


#include "../../../JuceLibraryCode/JuceHeader.h"
#include "AudioNode.h"
#include <stdio.h>

class AudioNode;
class AudioComponent;

/**
	Toggles audio output on and off.

	@see AudioNode, AudioEditor

*/

class MuteButton : public ImageButton
{
public:
    MuteButton();
    ~MuteButton();
};

/**
	Used to show and hide the AudioConfigurationWindow.

	@see AudioNode, AudioEditor

*/

class AudioWindowButton : public Button
{
public:
    AudioWindowButton();
    ~AudioWindowButton();
    void paintButton(Graphics& g, bool isMouseOver, bool isButtonDown);
    void setText(String);
private:
    Font font;
    String textString;
};

/**
	Allows the user to access audio output settings.

	@see AudioNode, AudioEditor

*/

class AudioConfigurationWindow : public DocumentWindow,
    public AccessClass
{
public:
    AudioConfigurationWindow(AudioDeviceManager& adm, AudioWindowButton* b);
    ~AudioConfigurationWindow();

    void paint(Graphics& g);
    void resized();

private:

    void closeButtonPressed();

    AudioWindowButton* controlButton;

};

/**
	Holds the interface for editing audio output parameters.

	@see AudioNode

*/

class AudioEditor : public AudioProcessorEditor,
    public Button::Listener,
    public Slider::Listener,
    public AccessClass

{
public:
    AudioEditor(AudioNode* owner);
    ~AudioEditor();

    void paint(Graphics& g);

    bool keyPressed(const KeyPress& key);

    void resized();

    void updateBufferSizeText();

    void enable();
    void disable();

    void saveStateToXml(XmlElement* xml);
    void loadStateFromXml(XmlElement* xml);

private:

    void buttonClicked(Button* button);
    void sliderValueChanged(Slider* slider);

    float lastValue;

    bool isEnabled;

    MuteButton* muteButton;
    AudioWindowButton* audioWindowButton;
    AudioConfigurationWindow* acw;

    Slider* volumeSlider;
    Slider* noiseGateSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioEditor);

};



#endif  // __AUDIOEDITOR_H_9D6F1FC3__

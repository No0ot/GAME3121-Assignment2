#pragma once
#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include "OgreTrays.h"
#include <iostream>
#include <list>
#include "InputSubject.h"

using namespace Ogre;
using namespace OgreBites;

class InputManager : public InputListener
{
	//KeyboardEvent*

public:
	InputManager();
	~InputManager();

	bool keyPressed(const KeyboardEvent& evt);
	bool keyReleased(const KeyboardEvent& evt);

	InputSubject* GetInputSubject(Keycode, EventType);

private:
	std::list<InputSubject*> mKeyDownSubjects;
	std::list<InputSubject*> mKeyUpSubjects;

};


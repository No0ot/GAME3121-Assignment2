#pragma once
#include <list>
#include <iostream>
#include <string>
#include "OgreTrays.h"

using namespace Ogre;
using namespace OgreBites;
class InputObserver;


class InputSubject
{
public:
	InputSubject(Keycode evt, EventType evttype);
	~InputSubject();

	void Attach(InputObserver* observer);
	void Detach(InputObserver* observer);
	void Notify(Keycode, EventType);
	Keycode mKeyboardEvent;
	EventType mEventType;
private:
	std::list<InputObserver*> mObservers;
};


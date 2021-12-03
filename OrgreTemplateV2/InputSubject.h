#pragma once
#include <list>
#include <iostream>
#include <string>
#include "OgreTrays.h"

using namespace Ogre;
using namespace OgreBites;
class InputObserver;
/// <summary>
/// Subject class for the input manager that uses an observer pattern.
/// </summary>
class InputSubject
{
public:
	InputSubject(Keycode evt, EventType evttype);
	~InputSubject();
	/// <summary>
	/// Attaches an observer to this subject to open it up to notifys.
	/// </summary>
	/// <param name="observer"></param>
	void Attach(InputObserver* observer);
	/// <summary>
	/// Removes an observer from the list
	/// </summary>
	/// <param name="observer"></param>
	void Detach(InputObserver* observer);
	/// <summary>
	/// Calls an update on all the observers in the list.
	/// </summary>
	/// <param name=""></param>
	/// <param name=""></param>
	void Notify(Keycode, EventType);
	Keycode mKeyboardEvent;/**< the SDLK keycode or key that this subject represents.*/
	EventType mEventType;/**< The event tied to this subject whether its keyUP or keyDown.*/
private:
	std::list<InputObserver*> mObservers; /**< List of observers attached to this subject.*/
};


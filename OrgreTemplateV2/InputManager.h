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
/// <summary>
/// Manager class to manage the observer pattern used for the inputs.Its derived from the Ogre InputListener to catch inputs.
/// </summary>
class InputManager : public InputListener
{
public:
	InputManager();
	~InputManager();
	/// <summary>
	/// Ogre::InputListener keyPressed function for catching keypressed events.
	/// </summary>
	/// <param name="evt"></param>
	/// <returns></returns>
	bool keyPressed(const KeyboardEvent& evt);
	/// <summary>
	/// Ogre::InputListener keyReleasedfunction for catching key up events.
	/// </summary>
	/// <param name="evt"></param>
	/// <returns></returns>
	bool keyReleased(const KeyboardEvent& evt);
	/// <summary>
	/// Populates the keydown subjects list with possible keydown events.
	/// </summary>
	void PopulateKeyDownList();
	/// <summary>
	/// Populates the keyup subjects list with possible keyup events.
	/// </summary>
	void PopulateKeyUpList();
	/// <summary>
	/// Returns a subject object from one of the lists depending on the passed in keycode and eventtype.
	/// </summary>
	/// <param name=""></param>
	/// <param name=""></param>
	/// <returns></returns>
	InputSubject* GetInputSubject(Keycode, EventType);

private:
	std::list<InputSubject*> mKeyDownSubjects; /**< List of keydown subjects.*/
	std::list<InputSubject*> mKeyUpSubjects; /**< List of keyup subjects.*/

};


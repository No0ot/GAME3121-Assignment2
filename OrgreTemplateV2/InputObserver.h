#pragma once
#include "InputSubject.h"
#include <list>

/// <summary>
/// An observer base class that attaches itself to a subject so that it recieves notices.
/// </summary>
class InputObserver
{
public:
	InputObserver();
	~InputObserver();
	/// <summary>
	/// Attaches itself to an input subject so that it recieves notices from the subject.
	/// </summary>
	/// <param name="subject"></param>
	void AttachToSubject(InputSubject& subject);
	/// <summary>
	/// Non-virtual update function that calls the virtual one.
	/// </summary>
	/// <param name=""></param>
	/// <param name=""></param>
	void Update(Keycode, EventType);
	/// <summary>
	/// Virtual function that gets called when the observer recieves a notice from the subject.
	/// </summary>
	/// <param name=""></param>
	/// <param name=""></param>
	virtual void ObserverUpdate(Keycode,EventType) = 0;

private:

};


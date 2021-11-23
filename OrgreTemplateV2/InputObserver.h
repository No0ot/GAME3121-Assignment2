#pragma once
#include "InputSubject.h"
#include <list>

class InputObserver
{
public:
	InputObserver();
	~InputObserver();

	void RemoveMeFromTheList();
	void AttachToSubject(InputSubject& mSubject);
	void Update(Keycode, EventType);
	virtual void ObserverUpdate(Keycode,EventType) = 0;


private:
	//std::list<InputSubject&> mSubject;
};


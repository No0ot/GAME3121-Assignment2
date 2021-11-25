#pragma once
#include "InputSubject.h"
#include <list>

class InputObserver
{
public:
	InputObserver();
	~InputObserver();

	void AttachToSubject(InputSubject& subject);
	void Update(Keycode, EventType);
	virtual void ObserverUpdate(Keycode,EventType) = 0;


private:
};


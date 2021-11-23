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
	void Update();
	virtual void ObserverUpdate() = 0;


private:
	//std::list<InputSubject&> mSubject;
};


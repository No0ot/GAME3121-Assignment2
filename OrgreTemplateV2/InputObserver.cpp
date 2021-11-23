#include "InputObserver.h"

InputObserver::InputObserver()
{

}

InputObserver::~InputObserver()
{
}

void InputObserver::RemoveMeFromTheList()
{
}

void InputObserver::AttachToSubject(InputSubject& mSubject)
{
	mSubject.Attach(this);
}

void InputObserver::Update(Keycode keycode, EventType evttype)
{
	ObserverUpdate(keycode, evttype);
}

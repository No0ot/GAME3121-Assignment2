#include "InputObserver.h"

InputObserver::InputObserver()
{

}

InputObserver::~InputObserver()
{
}

void InputObserver::AttachToSubject(InputSubject& subject)
{
	subject.Attach(this);
}

void InputObserver::Update(Keycode keycode, EventType evttype)
{
	ObserverUpdate(keycode, evttype);
}

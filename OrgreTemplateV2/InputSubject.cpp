#include "InputSubject.h"
#include "InputObserver.h"

InputSubject::InputSubject(Keycode evt, EventType evttype) : mKeyboardEvent(evt), mEventType(evttype)
{

}

InputSubject::~InputSubject()
{
}

void InputSubject::Attach(InputObserver* observer)
{
	mObservers.push_back(observer);
}

void InputSubject::Detach(InputObserver* observer)
{
	mObservers.remove(observer);
}

void InputSubject::Notify(Keycode keycode, EventType evttype)
{
	std::list<InputObserver*>::iterator iterator = mObservers.begin();
	while (iterator != mObservers.end())
	{
		(*iterator)->Update(keycode, evttype);
		++iterator;
	}
}

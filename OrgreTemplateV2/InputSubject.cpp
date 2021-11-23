#include "InputSubject.h"
#include "InputObserver.h"

InputSubject::InputSubject()
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

void InputSubject::Notify()
{
	std::list<InputObserver*>::iterator iterator = mObservers.begin();
	while (iterator != mObservers.end())
	{
		(*iterator)->Update();
		++iterator;
	}
}

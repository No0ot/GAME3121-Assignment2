#pragma once
#include <list>
#include <iostream>
#include <string>

using namespace Ogre;
using namespace OgreBites;
class InputObserver;

enum KeyDown
{
	A,
	S,
	D,
	W,
	SPACE,
};

enum KeyUp
{
	A,
	S,
	D,
	W,
	SPACE,
};

class InputSubject
{
public:
	InputSubject();
	~InputSubject();

	void Attach(InputObserver* observer);
	void Detach(InputObserver* observer);
	void Notify();
private:
	std::list<InputObserver*> mObservers;
	KeyboardEvent* evt;
};


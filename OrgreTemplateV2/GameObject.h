#pragma once
#include "InputObserver.h"
#include <iostream>

class Game;

class GameObject : public InputObserver
{
public:
	GameObject(Game* gameInstance);
	~GameObject();

	//Example of how the Observer Input works
	//void ObserverUpdate(Keycode, EventType) override;

	virtual void ObserverUpdate(Keycode, EventType) = 0;
protected:
	Game* mGameReference;
};


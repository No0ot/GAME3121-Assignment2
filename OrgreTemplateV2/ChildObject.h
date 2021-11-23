#pragma once
#include "GameObject.h"
class ChildObject : public GameObject
{
public:
	ChildObject(Game* gameInstance);
	~ChildObject();

	void ObserverUpdate(Keycode, EventType) override;
};


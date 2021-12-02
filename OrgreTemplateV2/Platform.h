#pragma once
#include "GameObject.h"
#include "PhysicsObject.h"

class Platform : public GameObject, public PhysicsObject
{
public:
	Platform(Game* gameInstance, SceneManager* scnmngr, std::string name);
	~Platform();

	void ObserverUpdate(Keycode, EventType) override;
	void Update() override;
};

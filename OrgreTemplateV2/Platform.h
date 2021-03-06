#pragma once
#include "GameObject.h"
#include "PhysicsObject.h"

/// <summary>
/// GameObject class for the platforms that player jumps on, is also a PhysicsObject.
/// </summary>
class Platform : public GameObject, public PhysicsObject
{
public:
	Platform(Game* gameInstance, SceneManager* scnmngr, std::string name);
	~Platform();

	void ObserverUpdate(Keycode, EventType) override;

	void Update() override;
};

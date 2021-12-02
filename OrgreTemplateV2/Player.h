#pragma once
#include "GameObject.h"
#include "PhysicsObject.h"

class Player : public GameObject, public PhysicsObject
{
public:
	Player(Game* gameInstance, SceneManager* scnmngr, std::string name);
	~Player();

	void ObserverUpdate(Keycode, EventType) override;
	void Update() override;

private:
	bool moveDown;
	bool moveUp;
	bool moveLeft;
	bool moveRight;
	float speed_;
	float jump_force_;
};

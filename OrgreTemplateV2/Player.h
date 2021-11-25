#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(Game* gameInstance, SceneManager* scnmngr, std::string name);
	~Player();

	void ObserverUpdate(Keycode, EventType) override;
	void Update() override;
private:
	bool moveDown;
	bool moveUp;
};


#pragma once
#include "GameObject.h"
#include "PhysicsObject.h"

/// <summary>
/// GameObject class for the player character, is also a PhysicsObject.
/// </summary>
class Player : public GameObject, public PhysicsObject
{
public:
	Player(Game* gameInstance, SceneManager* scnmngr, std::string name);
	~Player();

	void ObserverUpdate(Keycode, EventType) override;
	void Update() override;

	/// <summary>
	/// Sets velocity with the jump force value.
	/// </summary>
	void DoJump();

private:
	bool moveDown; /**< Flag to check for move down input.*/
	bool moveUp; /**< Flag to check for move up input.*/
	bool moveLeft; /**< Flag to check for move left input.*/
	bool moveRight; /**< Flag to check for move right input.*/
	float speed_; /**< Movement speed value, for left/right movement.*/
	float jump_force_; /**< Jump value, for jump movement.*/
	float fall_multiplier_; /**< Modifier value so player falls faster.*/
};

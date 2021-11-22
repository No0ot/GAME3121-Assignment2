#pragma once
#include "PhysicsObject.h"
#include "Mesh.h"

/// <summary>
/// Class inheriting from PhysicsObject to implement the paddle functionality
/// </summary>
class Paddle : public PhysicsObject
{
private:

public:
	Paddle();
	~Paddle();
	/// <summary>
	/// Bool used for moving paddle left.
	/// </summary>
	bool moveLeft;
	/// <summary>
	/// Bool used for moving paddle right.
	/// </summary>
	bool moveRight;
	/// <summary>
	/// Function to be called every frame.Handles physics movement.
	/// </summary>
	void update(const Ogre::FrameEvent& evt) override;
	/// <summary>
	/// Ensures the paddle does not leave the bounds of the screen.
	/// </summary>
	void CheckBounds();
	/// <summary>
	/// Sets the velocity to be moved left.
	/// </summary>
	void MoveLeft();
	/// <summary>
	/// Sets the velocity to be moved right.
	/// </summary>
	void MoveRight();
};


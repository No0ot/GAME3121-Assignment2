#pragma once
#include "PhysicsObject.h"

/// <summary>
/// Class inheriting from PhysicsObject to implement the ball functionality
/// </summary>
class Ball : public PhysicsObject
{
private:
	PhysicsObject* paddleReference; /**< Pointer Reference to the Paddle object for collision.*/
	bool inPlay; /**< bool used to determine if ball is in play or not.*/
	int lives = 5; /**< Int for game lives*/
	int score; /**< int for game score*/
public:
	Ball(PhysicsObject* ref);
	~Ball();
	/// <summary>
	/// Function to be called every frame.Handles physics movement
	/// </summary>
	void update(const Ogre::FrameEvent& evt) override;
	/// <summary>
	/// Ensures the ball to stay within the bounds of the screen
	/// </summary>
	void CheckBounds();
	/// <summary>
	/// Checks collision against the paddle using the paddleReference
	/// </summary>
	void checkCollision();
	/// <summary>
	/// Reflects the velocity based upon surface when colliding
	/// </summary>
	/// <param name="reflectX">Used to see if ball needs to be reflected on X axis(true) or Y axis(false)</param>
	void ReflectVelocity(bool reflectX);
	/// <summary>
	/// Sets the reference to the paddle object
	/// </summary>
	/// <param name="ref"> Passed in object from scene</param>
	void setPaddleReference(PhysicsObject* ref);
	/// <summary>
	/// Resets the ball when a life is to be lost
	/// </summary>
	void ResetBall();
	/// <summary>
	/// Starts the ball movement to begin the game
	/// </summary>
	void BeginPlay();
	/// <summary>
	/// Returns lives
	/// </summary>
	int GetLives();
	/// <summary>
	/// Returns score
	/// </summary>
	int GetScore();
};


#include "Ball.h"
#include <iostream>

Ball::Ball(PhysicsObject* ref)
{
	SetMoveSpeed(0.0f);
	SetVelocity(Ogre::Vector3(1.0f, 1.0f, 0.0f));
	paddleReference = ref;
	inPlay = false;
}

Ball::~Ball()
{
}

void Ball::update(const Ogre::FrameEvent& evt)
{
	getNode()->translate((GetVelocity() * GetMoveSpeed()) * evt.timeSinceLastFrame);
	//SetVelocity(GetVelocity() * 0.95f);

	CheckBounds();
	checkCollision();
	//std::cout << GetMoveSpeed() << std::endl;
}

void Ball::CheckBounds()
{
	
	//Left side
	if (getNode()->getPosition().x < -26.0f)
	{
		ReflectVelocity(true);
	}
	//Right side
	if (getNode()->getPosition().x > 26.0f)
	{
		ReflectVelocity(true);
	}
	//Top side
	if (getNode()->getPosition().y > 21.0f)
	{
		ReflectVelocity(false);
	}
	//Bottom side
	if (getNode()->getPosition().y < -21.0f)
	{
		ResetBall();
		lives--;
	}
}

void Ball::checkCollision()
{
	//Collides with Top
	if (paddleReference->getNode()->getPosition().x - (paddleReference->getNode()->getScale().x / 2) < getNode()->getPosition().x &&
		paddleReference->getNode()->getPosition().x + (paddleReference->getNode()->getScale().x / 2) > getNode()->getPosition().x &&
		getNode()->getPosition().y < paddleReference->getNode()->getPosition().y + (paddleReference->getNode()->getScale().y))
	{
		//std::cout << "COLLISION TOP" << std::endl;
		score++;
		ReflectVelocity(false);
	}

	//Collide with Right
	//else if (paddleReference->getNode()->getPosition().y - (paddleReference->getNode()->getScale().y / 2) < getNode()->getPosition().y &&
	//	paddleReference->getNode()->getPosition().y + (paddleReference->getNode()->getScale().y / 2) > getNode()->getPosition().y &&
	//	getNode()->getPosition().x < paddleReference->getNode()->getPosition().x + (paddleReference->getNode()->getScale().x / 2))
	//{
	//	//std::cout << "COLLISION RIGHT" << std::endl;
	//	ReflectVelocity(false);
	//}
	//
	//else if //Collide with Left
	//	(paddleReference->getNode()->getPosition().y - (paddleReference->getNode()->getScale().y / 2) < getNode()->getPosition().y &&
	//	paddleReference->getNode()->getPosition().y + (paddleReference->getNode()->getScale().y /2) > getNode()->getPosition().y &&
	//	getNode()->getPosition().x < paddleReference->getNode()->getPosition().x - (paddleReference->getNode()->getScale().x / 2))
	//{
	//	//std::cout << "COLLISION LEFT" << std::endl;
	//	ReflectVelocity(false);
	//}

}

void Ball::ReflectVelocity(bool reflectX)
{
	if (reflectX)
	{
		SetVelocity(Ogre::Vector3(GetVelocity().x * -1, GetVelocity().y, GetVelocity().z));
		SetMoveSpeed(GetMoveSpeed() + 0.5f);
	}
	else
	{
		SetVelocity(Ogre::Vector3(GetVelocity().x, GetVelocity().y * -1, GetVelocity().z));
		SetMoveSpeed(GetMoveSpeed() + 0.5f);
	}

	//std::cout << GetMesh()->getBoundingRadius() << std::endl;
}

void Ball::setPaddleReference(PhysicsObject* ref)
{
	paddleReference = ref;
}

void Ball::ResetBall()
{
	SetMoveSpeed(0.0f);
	getNode()->setPosition(0, 15, 250);
	inPlay = false;
}

void Ball::BeginPlay()
{
	if (!inPlay)
	{
		SetMoveSpeed(20.0f);
		inPlay = true;
	}
}

int Ball::GetLives()
{
	return lives;
}

int Ball::GetScore()
{
	return score;
}

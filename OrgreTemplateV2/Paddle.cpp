#include "Paddle.h"
#include <iostream>

Paddle::Paddle()
{
	SetMoveSpeed(50.0f);
}

Paddle::~Paddle()
{
}

void Paddle::update(const Ogre::FrameEvent& evt)
{
	if (moveLeft)
		MoveLeft();
	else if (moveRight)
		MoveRight();

	getNode()->translate((GetVelocity() * GetMoveSpeed()) * evt.timeSinceLastFrame);
	SetVelocity(GetVelocity() * 0.95f);

	CheckBounds();
	//std::cout << getNode()->getPosition().x - getNode()->getScale().x / 2  << std::endl;
}

void Paddle::CheckBounds()
{
	if (getNode()->getPosition().x < -21.0f)
	{
		getNode()->setPosition(Ogre::Vector3(-21.0f, getNode()->getPosition().y, getNode()->getPosition().z));
	}
	if (getNode()->getPosition().x > 21.0f)
	{
		getNode()->setPosition(Ogre::Vector3(21.0f, getNode()->getPosition().y, getNode()->getPosition().z));
	}
}

void Paddle::MoveLeft()
{
	SetVelocity(Ogre::Vector3(-1, 0, 0));

}

void Paddle::MoveRight()
{
	SetVelocity(Ogre::Vector3(1, 0, 0));
}

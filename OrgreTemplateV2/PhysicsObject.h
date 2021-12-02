#pragma once
#include "Ogre.h"
#include <iostream>

class PhysicsObject
{
private:
	Ogre::SceneNode* node_;
	Ogre::ManualObject* mesh_;

protected:
	Ogre::Vector3 velocity_;
	float mass_;
	float gravity_ = 0.0098f;

	void PhysicsUpdate();

public:
	PhysicsObject();
	PhysicsObject(Ogre::SceneNode* node);
	~PhysicsObject();

	Ogre::Vector3 GetVelocity();
	void SetVelocity(Ogre::Vector3 value);
	void SetVelocity(float x, float y, float z);
};

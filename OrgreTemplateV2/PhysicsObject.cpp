#include "PhysicsObject.h"

PhysicsObject::PhysicsObject()
{
	
}

PhysicsObject::PhysicsObject(Ogre::SceneNode* node)
{
	node_ = node;
}

PhysicsObject::~PhysicsObject()
{
}

Ogre::Vector3 PhysicsObject::GetVelocity()
{
	return velocity_;
}

void PhysicsObject::SetVelocity(Ogre::Vector3 value)
{
	velocity_ = value;
}

void PhysicsObject::SetVelocity(float x, float y, float z)
{
	velocity_.x = x;
	velocity_.y = y;
	velocity_.z = z;
}

void PhysicsObject::PhysicsUpdate()
{
	node_->translate(velocity_);
	velocity_.y -= gravity_;
}


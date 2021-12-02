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
	bool is_static_ = false;
	bool is_grounded_ = false;

	virtual void PhysicsUpdate();

public:
	PhysicsObject();
	PhysicsObject(Ogre::SceneNode* node);
	~PhysicsObject();

	Ogre::Vector3 GetVelocity() const;
	void SetVelocity(const Ogre::Vector3& value);
	void SetVelocity(const float& x, const float& y, const float& z);
	bool IsStatic() const;
	void SetStatic(const bool& value);
	bool IsGrounded() const;
	void SetGrounded(const bool& value);
};

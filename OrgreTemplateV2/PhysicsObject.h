#pragma once
#include "Ogre.h"
#include <iostream>

class PhysicsObject
{
public:
	enum RigidbodyType
	{
		kDynamic,
		kKinematic,
		kStatic
	};

private:
	Ogre::SceneNode* node_;
	Ogre::ManualObject* mesh_;

protected:
	Ogre::Vector3 velocity_;
	float mass_;
	float gravity_ = 0.0098f;
	PhysicsObject::RigidbodyType rb_type_;
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
	void SetRigidbodyType(const PhysicsObject::RigidbodyType& value);
	bool IsGrounded() const;
	void SetGrounded(const bool& value);
};

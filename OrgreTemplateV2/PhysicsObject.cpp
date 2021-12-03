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

Ogre::Vector3 PhysicsObject::GetVelocity() const
{
	return velocity_;
}

void PhysicsObject::SetVelocity(const Ogre::Vector3& value)
{
	velocity_ = value;
}

void PhysicsObject::SetVelocity(const float& x, const float& y, const float& z)
{
	velocity_.x = x;
	velocity_.y = y;
	velocity_.z = z;
}

bool PhysicsObject::IsStatic() const
{
	return (rb_type_ == PhysicsObject::RigidbodyType::kStatic ? true : false);
}

void PhysicsObject::SetRigidbodyType(const PhysicsObject::RigidbodyType& value)
{
	rb_type_ = (PhysicsObject::RigidbodyType)value;
}

bool PhysicsObject::IsGrounded() const
{
	return is_grounded_;
}

void PhysicsObject::SetGrounded(const bool& value)
{
	is_grounded_ = value;
	if (is_grounded_)
	{
		velocity_.y = 0;
	}
}

void PhysicsObject::PhysicsUpdate()
{
	if (rb_type_ != kStatic)
	{
		node_->translate(velocity_);
		if (rb_type_ != kKinematic)
		{
			if (!is_grounded_)
			{
				if (velocity_.y >= 0)
				{
					velocity_.y -= gravity_;
				}
				else
				{
					velocity_.y -= gravity_ * 1.75f;
				}
			}
		}
	}
}


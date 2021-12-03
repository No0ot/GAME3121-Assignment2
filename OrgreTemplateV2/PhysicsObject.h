#pragma once
#include "Ogre.h"
#include <iostream>

/// <summary>
/// Object type for physics calculation.
/// </summary>
class PhysicsObject
{
public:
	/// <summary>
	/// enum for the type of Rigidbody. Dynamic is affected by gravity, Kinematic has to be moved manually, Static cannot be moved
	/// </summary>
	enum RigidbodyType
	{
		kDynamic,
		kKinematic,
		kStatic
	};

private:
	Ogre::SceneNode* node_; /**< The reference to the scene node.*/
	Ogre::ManualObject* mesh_; /**< The reference to the mesh, in case we want to deform it.*/

protected:
	Ogre::Vector3 velocity_; /**< Velocity value.*/
	float mass_; /**< Mass value.*/
	float gravity_ = 0.0098f; /**< Gravity value.*/
	PhysicsObject::RigidbodyType rb_type_; /**< Rigidbody type.*/
	bool is_grounded_ = false; /**< Flag to check if object is grounded, to stop gravity moving it down.*/

	/// <summary>
	/// Update function for physics that can be overridden.
	/// </summary>
	/// <param name="node"></param>
	virtual void PhysicsUpdate(); 

public:
	PhysicsObject();
	PhysicsObject(Ogre::SceneNode* node);
	~PhysicsObject();

	/// <summary>
	/// Accessor for velocity. 
	/// </summary>
	Ogre::Vector3 GetVelocity() const;
	/// <summary>
	/// Mutator for velocity, using Vector3.
	/// </summary>
	void SetVelocity(const Ogre::Vector3& value);
	/// <summary>
	/// Mutator for velocity, using 3 float values.
	/// </summary>
	void SetVelocity(const float& x, const float& y, const float& z);
	/// <summary>
	/// Check if PhysicsObject is of type Static.
	/// </summary>
	bool IsStatic() const;
	/// <summary>
	/// Mutator for rigidbody type.
	/// </summary>
	void SetRigidbodyType(const PhysicsObject::RigidbodyType& value);
	/// <summary>
	/// Check if PhysicsObject is on the ground.
	/// </summary>
	bool IsGrounded() const;
	/// <summary>
	/// Mutator for grounded status.
	/// </summary>
	void SetGrounded(const bool& value);
};

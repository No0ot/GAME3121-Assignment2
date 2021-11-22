#include "PhysicsObject.h"

PhysicsObject::PhysicsObject()
{
	
}
/// <summary>
/// Returns a reference to the attached SceneNode
/// </summary>
/// <returns> Returns node member</returns>
Ogre::SceneNode* PhysicsObject::getNode()
{
	return node;
}
/// <summary>
/// Sets the reference to a SceneNode
/// </summary>
/// <param name="newnode"> Reference to the SceneNode to be attached</param>
void PhysicsObject::setNode(Ogre::SceneNode* newnode)
{
	node = newnode;
}
/// <summary>
/// Returns a reference to the attached Manual object(mesh)
/// </summary>
/// <returns> Returns mesh member </returns>
Ogre::ManualObject* PhysicsObject::GetMesh()
{
	return mesh;
}
/// <summary>
/// Sets the reference to a ManualObject(mesh)
/// </summary>
/// <param name="newmesh"> Reference to the ManualObject to be attached</param>
void PhysicsObject::SetMesh(Ogre::ManualObject* newmesh)
{
	mesh = newmesh;
}
/// <summary>
/// Sets the movespeed of the object
/// </summary>
/// <param name="newmovespeed"> Takes in float to assign to moveSpeed</param>
void PhysicsObject::SetMoveSpeed(float newmovespeed)
{
	moveSpeed = newmovespeed;
}
/// <summary>
/// Gets the Move Speed
/// </summary>
/// <returns>Returns moveSpeed</returns>
float PhysicsObject::GetMoveSpeed()
{
	return moveSpeed;
}
/// <summary>
/// Sets the velocity
/// </summary>
/// <param name="newvelocity"> Takes in Ogre::Vector3 and assigns it to velocity </param>
void PhysicsObject::SetVelocity(Ogre::Vector3 newvelocity)
{
	velocity = newvelocity;
}
/// <summary>
/// Gets the velocity
/// </summary>
/// <returns> Returns velocity</returns>
Ogre::Vector3 PhysicsObject::GetVelocity()
{
	return velocity;
}

PhysicsObject::~PhysicsObject()
{

}

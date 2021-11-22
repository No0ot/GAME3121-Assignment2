#pragma once
#include "Ogre.h"

using namespace Ogre;

/// <summary>
/// Base class used to implement objects to be affected by physics
/// </summary>
class PhysicsObject
{
private:
	Ogre::SceneNode* node; /**< Pointer Reference to the SceneNode.*/
    Ogre::ManualObject* mesh; /**< Pointer Reference to the manual object to be used as the mesh.*/

    float moveSpeed; /**< float for the movespeed of the object*/
    Ogre::Vector3 velocity; /**< vector for the velocity of the object*/
public:
    PhysicsObject();
    ~PhysicsObject();
    /// <summary>
    /// virtual update function to be inherited
    /// </summary>
    virtual void update(const Ogre::FrameEvent& evt) = 0; 
    /// <summary>
    /// Returns a reference to the attached SceneNode
    /// </summary>
    Ogre::SceneNode* getNode();
    /// <summary>
    /// Sets the reference to a SceneNode
    /// </summary>
    void setNode(Ogre::SceneNode* newnode);
    /// <summary>
    /// Returns a reference to the attached Manual object(mesh)
    /// </summary>
    Ogre::ManualObject* GetMesh();
    /// <summary>
    /// Sets the reference to a ManualObject(mesh)
    /// </summary>
    void SetMesh(Ogre::ManualObject* newmesh);
    /// <summary>
    /// Sets the movespeed of the object
    /// </summary>
    void SetMoveSpeed(float newmovespeed);
    /// <summary>
    /// Gets the Move Speed
    /// </summary>
    float GetMoveSpeed();
    /// <summary>
    /// Sets the velocity
    /// </summary>
    void SetVelocity(Ogre::Vector3 newvelocity);
    /// <summary>
    /// Gets the velocity
    /// </summary>
    Ogre::Vector3 GetVelocity();
};




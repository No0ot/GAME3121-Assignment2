#pragma once
#include "Ogre.h"
/// class containing static functions to build manual Objects to be used as meshes
/// 
/// 
class MyMesh
{
private:

public:
	/// <summary>
	/// Creates a cube Mesh
	/// </summary>
	static Ogre::ManualObject* createCubeMesh(Ogre::String name, Ogre::String matName, Ogre::Vector3 clr);
	/// <summary>
	/// Creates a sphere Mesh
	/// </summary>
	static Ogre::ManualObject* createSphereMesh(Ogre::String name, Ogre::String matName, const float r, Ogre::Vector3 clr);
};


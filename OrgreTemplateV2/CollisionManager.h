#pragma once
#include "GameObject.h"
// Core Libraries
#include "Ogre.h"
#include <iostream>

/// <summary>
/// Collision Manager using static method to check where objects collide.
/// </summary>
class CollisionManager 
{
public:
	/// <summary>
	/// enum for where object1 collides with the other one
	/// </summary>
	enum CollisionType
	{
		kNull,
		kTop,
		kBottom,
		kLeft,
		kRight
	};

	/// <summary>
	/// Checks collision between 2 GameObjects using their WorldAABB
	/// </summary>
	/// <param name="object1"></param>
	/// <param name="object2"></param>
	/// <returns>Returns where object1 collides with the other one</returns>
	static CollisionType AABBCheck(GameObject* object1, GameObject* object2);

	/// <summary>
	/// Checks collision between a GameObject using its WorldAABB and camera
	/// </summary>
	/// <param name="object1"></param>
	/// <param name="object2"></param>
	/// <returns>Returns where object1 collides with the other one</returns>
	static CollisionType CameraBoundCheck(GameObject* object1, Camera* cam);

private:
	CollisionManager();
	~CollisionManager();
};

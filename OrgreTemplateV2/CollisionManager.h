#pragma once
#include "GameObject.h"
// Core Libraries
#include "Ogre.h"
#include <iostream>

/// <summary>
/// 
/// </summary>
class CollisionManager 
{
public:
	enum CollisionType
	{
		kNull,
		kTop,
		kBottom,
		kLeft,
		kRight
	};

	static CollisionType AABBCheck(GameObject* object1, GameObject* object2);

	static CollisionType CameraBoundCheck(GameObject* object1, Camera* cam);

private:
	CollisionManager();
	~CollisionManager();
};

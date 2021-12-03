#include "CollisionManager.h"

CollisionManager::CollisionType CollisionManager::AABBCheck(GameObject * object1, GameObject * object2)
{
    if (object1->GetNode()->_getWorldAABB().intersects(object2->GetNode()->_getWorldAABB()))
    {
        float dist = object1->GetNode()->_getWorldAABB().getCorner(Ogre::AxisAlignedBox::CornerEnum::FAR_LEFT_BOTTOM).y -
            object2->GetNode()->_getWorldAABB().getCorner(Ogre::AxisAlignedBox::CornerEnum::FAR_LEFT_TOP).y;
        if (dist < 1.65f && dist > -1.65f)
        {
            return kBottom; //result related to object1
        }
        dist = object1->GetNode()->_getWorldAABB().getCorner(Ogre::AxisAlignedBox::CornerEnum::FAR_LEFT_TOP).y -
            object2->GetNode()->_getWorldAABB().getCorner(Ogre::AxisAlignedBox::CornerEnum::FAR_LEFT_BOTTOM).y;
        if (dist < 1.65f && dist > -1.65f)
        {
            return kTop;
        }
        dist = object1->GetNode()->_getWorldAABB().getCorner(Ogre::AxisAlignedBox::CornerEnum::FAR_LEFT_BOTTOM).y -
            object2->GetNode()->_getWorldAABB().getCorner(Ogre::AxisAlignedBox::CornerEnum::FAR_RIGHT_BOTTOM).y;
        if (dist < 1.65f && dist > -1.65f)
        {
            return kLeft;
        }
        dist = object1->GetNode()->_getWorldAABB().getCorner(Ogre::AxisAlignedBox::CornerEnum::FAR_RIGHT_BOTTOM).y -
            object2->GetNode()->_getWorldAABB().getCorner(Ogre::AxisAlignedBox::CornerEnum::FAR_LEFT_BOTTOM).y;
        if (dist < 1.65f && dist > -1.65f)
        {
            return kRight;
        }
    }
	return kNull;
}

CollisionManager::CollisionType CollisionManager::CameraBoundCheck(GameObject* object1, Camera* cam)
{
    Ogre::Vector3 object1_screen_pos = cam->getProjectionMatrix() * cam->getViewMatrix() *
        object1->GetNode()->_getWorldAABB().getCenter();
    if (object1_screen_pos.y <= -1)
    {
        return kBottom;
    }
    if (object1_screen_pos.y >= 1)
    {
        return kTop;
    }
    if (object1_screen_pos.x <= -1)
    {
        return kLeft;
    }
    if (object1_screen_pos.x >= 1)
    {
        return kRight;
    }
    return kNull;
}

CollisionManager::CollisionManager()
= default;

CollisionManager::~CollisionManager()
= default;

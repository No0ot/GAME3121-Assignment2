#include "GameObject.h"
#include "Game.h"

GameObject::GameObject(Game* ref, SceneManager* scnmngr, std::string name) : mGameReference(ref)
{
	node = scnmngr->getRootSceneNode()->createChildSceneNode(name);
}

GameObject::~GameObject()
{
}

Ogre::SceneNode* GameObject::getNode()
{
	return node;
}
/// <summary>
/// Sets the reference to a SceneNode
/// </summary>
/// <param name="newnode"> Reference to the SceneNode to be attached</param>
void GameObject::setNode(Ogre::SceneNode* newnode)
{
	node = newnode;
}
/// <summary>
/// Returns a reference to the attached Manual object(mesh)
/// </summary>
/// <returns> Returns mesh member </returns>
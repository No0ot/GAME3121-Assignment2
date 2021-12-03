#pragma once
#include "InputObserver.h"
#include "Mesh.h"
#include <iostream>

class Game;
/// <summary>
/// Base GameObject class. Inherits from InputObserver so that any object can respond to Inputs.
/// </summary>
class GameObject : public InputObserver
{
public:
	GameObject(Game* gameInstance, SceneManager* scnmngr, std::string name);
	~GameObject();

	/// <summary>
	/// Virtual Update Function for game loop to call during its update.
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// Returns the pointer to the attached Node.
	/// </summary>
	/// <returns></returns>
	Ogre::SceneNode* GetNode();
	/// <summary>
	/// Sets the node in case you need to switch the node of an object.
	/// </summary>
	/// <param name="newnode"></param>
	void SetNode(Ogre::SceneNode* newnode);
	/// <summary>
	/// Virtual function that gets called when the InputObserver base class gets notified by a subject.
	/// </summary>
	/// <param name=""></param>
	/// <param name=""></param>
	virtual void ObserverUpdate(Keycode, EventType) = 0;

protected:
	Game* mGameReference; /**< Pointer reference to the Game instance.*/
	Ogre::SceneNode* node; /**< Pointer to the sceneNode.*/
	Ogre::ManualObject* mesh; /**< Pointer to the Mesh object attached to the node.*/
};

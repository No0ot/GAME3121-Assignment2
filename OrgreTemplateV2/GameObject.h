#pragma once
#include "InputObserver.h"
#include "Mesh.h"
#include <iostream>

class Game;

class GameObject : public InputObserver
{
public:
	GameObject(Game* gameInstance, SceneManager* scnmngr, std::string name);
	~GameObject();

	virtual void Update(const Ogre::FrameEvent& evt) = 0;

	Ogre::SceneNode* getNode();
	void setNode(Ogre::SceneNode* newnode);

	virtual void ObserverUpdate(Keycode, EventType) = 0;
protected:
	Game* mGameReference;
	Ogre::SceneNode* node;
	Ogre::ManualObject* mesh;
};


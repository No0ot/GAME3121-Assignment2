#include "Platform.h"
#include "Game.h"

Platform::Platform(Game* gameInstance, SceneManager* scnmngr, std::string name) : GameObject(gameInstance,scnmngr, name ), PhysicsObject(node)
{
	Ogre::ManualObject* cubeMesh = MyMesh::createCubeMesh("Platform", "FlatVertexColour", Ogre::Vector3(0.0, 0.0f, 1.0f));
	node->attachObject(cubeMesh);
	node->showBoundingBox(true);
	node->setScale(7.0f, 1.0f, 1.0f);
	node->setPosition(0, 0, 0);

	SetRigidbodyType(PhysicsObject::RigidbodyType::kKinematic);
	//SetVelocity(0,-0.2f,0);
}

Platform::~Platform()
{
}

void Platform::ObserverUpdate(Keycode keycode, EventType eventtype)
{
}

void Platform::Update()
{
	//PhysicsUpdate();
}
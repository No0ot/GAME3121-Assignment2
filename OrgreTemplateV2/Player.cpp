#include "Player.h"
#include "Game.h"

Player::Player(Game* gameInstance, SceneManager* scnmngr, std::string name) : GameObject(gameInstance,scnmngr, name )
{
	InputSubject* temp = mGameReference->mInputManager->GetInputSubject(SDLK_SPACE, EventType::KEYDOWN);
	AttachToSubject(*temp);
	temp = mGameReference->mInputManager->GetInputSubject(SDLK_SPACE, EventType::KEYUP);
	AttachToSubject(*temp);
	temp = mGameReference->mInputManager->GetInputSubject(SDLK_DOWN, EventType::KEYDOWN);
	AttachToSubject(*temp);
	temp = mGameReference->mInputManager->GetInputSubject('s', EventType::KEYDOWN);
	AttachToSubject(*temp);
	temp = mGameReference->mInputManager->GetInputSubject('s', EventType::KEYUP);
	AttachToSubject(*temp);
	temp = mGameReference->mInputManager->GetInputSubject('w', EventType::KEYDOWN);
	AttachToSubject(*temp);
	temp = mGameReference->mInputManager->GetInputSubject('w', EventType::KEYUP);
	AttachToSubject(*temp);

	Ogre::ManualObject* cubeMesh = MyMesh::createSphereMesh("Sphere", "FlatVertexColour", 1.0f, Ogre::Vector3(1.0, 0.0f, 0.0f));
	node->attachObject(cubeMesh);
	node->showBoundingBox(true);
	node->setScale(2.0, 4.0, 2.0);
	node->setPosition(0, 15, 0);
	moveDown = false;
}

Player::~Player()
{
}

// handles Input events
void Player::ObserverUpdate(Keycode keycode, EventType eventtype)
{
	if (keycode == SDLK_SPACE && eventtype == EventType::KEYDOWN)
		std::cout << "SOMETHING HAPPENS DOWN" << std::endl;
	if (keycode == SDLK_SPACE && eventtype == EventType::KEYUP)
		std::cout << "SOMETHING HAPPENS UP" << std::endl;
	if (keycode == SDLK_DOWN && eventtype == EventType::KEYDOWN)
		std::cout << "SOMETHING DOWNWNWNWNDWN" << std::endl;


	if (keycode == 's' && eventtype == EventType::KEYDOWN)
		moveDown = true;
	if (keycode == 's' && eventtype == EventType::KEYUP)
		moveDown = false;
	if (keycode == 'w' && eventtype == EventType::KEYDOWN)
		moveUp = true;
	if (keycode == 'w' && eventtype == EventType::KEYUP)
		moveUp = false;
}

// actual game update
void Player::Update()
{
	if (moveDown)
		node->translate(Ogre::Vector3(0.0f,-1.0f,0.0f));
	if (moveUp)
		node->translate(Ogre::Vector3(0.0f, 1.0f, 0.0f));
}

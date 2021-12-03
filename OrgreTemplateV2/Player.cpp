#include "Player.h"
#include "Game.h"
#include "SoundManager.h"

Player::Player(Game* gameInstance, SceneManager* scnmngr, std::string name) : GameObject(gameInstance,scnmngr, name ), PhysicsObject(node)
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
	temp = mGameReference->mInputManager->GetInputSubject('a', EventType::KEYDOWN);
	AttachToSubject(*temp);
	temp = mGameReference->mInputManager->GetInputSubject('a', EventType::KEYUP);
	AttachToSubject(*temp);
	temp = mGameReference->mInputManager->GetInputSubject('d', EventType::KEYDOWN);
	AttachToSubject(*temp);
	temp = mGameReference->mInputManager->GetInputSubject('d', EventType::KEYUP);
	AttachToSubject(*temp);

	TheSoundManager::Instance()->load("Jump.wav", "Jump", sound_type::SOUND_SFX);

	Ogre::ManualObject* cubeMesh = MyMesh::createSphereMesh("Sphere", "FlatVertexColour", 1.0f, Ogre::Vector3(1.0, 0.0f, 0.0f));
	node->attachObject(cubeMesh);
	node->showBoundingBox(true);
	node->setScale(1.0, 2.0, 1.0);
	node->setPosition(0, 15, 0);
	moveDown = false;

	speed_ = 0.4f;
	jump_force_ = 0.575f;
	fall_multiplier_ = 1.25f;

	SetRigidbodyType(PhysicsObject::RigidbodyType::kDynamic);
}

Player::~Player()
{
}

// handles Input events
void Player::ObserverUpdate(Keycode keycode, EventType eventtype)
{

	if ((keycode == 's' || keycode == SDLK_DOWN) && eventtype == EventType::KEYDOWN)
		moveDown = true;
	if ((keycode == 's' || keycode == SDLK_DOWN) && eventtype == EventType::KEYUP)
		moveDown = false;
	if ((keycode == 'w' || keycode == SDLK_UP || keycode == SDLK_SPACE) && eventtype == EventType::KEYDOWN)
	{
		moveUp = true;
	}
	if ((keycode == 'w' || keycode == SDLK_UP || keycode == SDLK_SPACE) && eventtype == EventType::KEYUP)
		moveUp = false;
	if ((keycode == 'a' || keycode == SDLK_LEFT ) && eventtype == EventType::KEYDOWN)
		moveLeft = true;
	if ((keycode == 'a' || keycode == SDLK_LEFT) && eventtype == EventType::KEYUP)
		moveLeft = false;
	if ((keycode == 'd' || keycode == SDLK_RIGHT ) && eventtype == EventType::KEYDOWN)
		moveRight = true;
	if ((keycode == 'd' || keycode == SDLK_RIGHT) && eventtype == EventType::KEYUP)
		moveRight = false;
}

// actual game update
void Player::Update()
{
	if (moveLeft)
	{
		SetVelocity(Ogre::Vector3(-speed_, GetVelocity().y, GetVelocity().z));
	}
	else if (moveRight)
	{
		SetVelocity(Ogre::Vector3(speed_, GetVelocity().y, GetVelocity().z));
	}
	else
	{
		SetVelocity(Ogre::Vector3(0.0f, GetVelocity().y, GetVelocity().z));
	}

	PhysicsUpdate();
}

void Player::DoJump() 
{
	SetVelocity(Ogre::Vector3(GetVelocity().x, jump_force_, GetVelocity().z));
	TheSoundManager::Instance()->playSound("Jump", 0, 64);
}
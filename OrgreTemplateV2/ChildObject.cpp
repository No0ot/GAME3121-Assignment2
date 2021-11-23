#include "ChildObject.h"
#include "Game.h"

ChildObject::ChildObject(Game* gameInstance) : GameObject(gameInstance)
{
	InputSubject* temp = mGameReference->mInputManager->GetInputSubject(SDLK_SPACE, EventType::KEYDOWN);
	AttachToSubject(*temp);
	temp = mGameReference->mInputManager->GetInputSubject(SDLK_SPACE, EventType::KEYUP);
	AttachToSubject(*temp);
	temp = mGameReference->mInputManager->GetInputSubject(SDLK_DOWN, EventType::KEYDOWN);
	AttachToSubject(*temp);
}

ChildObject::~ChildObject()
{
}

void ChildObject::ObserverUpdate(Keycode keycode, EventType eventtype)
{
	if (keycode == SDLK_SPACE && eventtype == EventType::KEYDOWN)
		std::cout << "SOMETHING HAPPENS DOWN" << std::endl;
	if (keycode == SDLK_SPACE && eventtype == EventType::KEYUP)
		std::cout << "SOMETHING HAPPENS UP" << std::endl;
	if (keycode == SDLK_DOWN && eventtype == EventType::KEYDOWN)
		std::cout << "SOMETHING DOWNWNWNWNDWN" << std::endl;
}

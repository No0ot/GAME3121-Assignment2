#include "GameObject.h"
//#include "Game.h"

GameObject::GameObject(Game* ref) : mGameReference(ref)
{

}

GameObject::~GameObject()
{
}

//Example of how the Observer Input works
//void GameObject::ObserverUpdate(Keycode keycode, EventType eventtype)
//{
//	if(keycode == SDLK_SPACE && eventtype == EventType::KEYDOWN)
//		std::cout << "SOMETHING HAPPENS DOWN" << std::endl;
//	if (keycode == SDLK_SPACE && eventtype == EventType::KEYUP)
//		std::cout << "SOMETHING HAPPENS UP" << std::endl;
//	if (keycode == SDLK_DOWN && eventtype == EventType::KEYDOWN)
//		std::cout << "SOMETHING DOWNWNWNWNDWN" << std::endl;
//
//}

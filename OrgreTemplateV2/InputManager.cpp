#include "InputManager.h"

InputManager::InputManager()
{
    mSpaceDownSubject = new InputSubject();
}

InputManager::~InputManager()
{
}

bool InputManager::keyPressed(const KeyboardEvent& evt)
{
    switch (evt.keysym.sym)
    {
    case SDLK_ESCAPE:
        std::cout << "escape";
        break;
    case 'a':
        std::cout << "a";
        //getRoot()->queueEndRendering();
        break;
    case SDLK_SPACE:
        mSpaceDownSubject->Notify();
        break;
    default:
        break;
    }
    return true;
}

bool InputManager::keyReleased(const KeyboardEvent& evt)
{
    switch (evt.keysym.sym)
    {
    default:
        break;
    }
    return true;
}

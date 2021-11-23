#include "InputManager.h"

InputManager::InputManager()
{
    mKeyDownSubjects.push_back(new InputSubject(SDLK_SPACE, EventType::KEYDOWN));


    mKeyDownSubjects.push_back(new InputSubject(SDLK_DOWN, EventType::KEYDOWN));


    mKeyUpSubjects.push_back(new InputSubject(SDLK_SPACE, EventType::KEYUP));
}

InputManager::~InputManager()
{
}

bool InputManager::keyPressed(const KeyboardEvent& evt)
{
    std::list<InputSubject*>::iterator iterator = mKeyDownSubjects.begin();
    while (iterator != mKeyDownSubjects.end())
    {
        if ((*iterator)->mKeyboardEvent == evt.keysym.sym)
        {
            (*iterator)->Notify(evt.keysym.sym, (OgreBites::EventType)evt.type);
        }
        ++iterator;
    }
    return true;
}

bool InputManager::keyReleased(const KeyboardEvent& evt)
{
    std::list<InputSubject*>::iterator iterator = mKeyUpSubjects.begin();
    while (iterator != mKeyUpSubjects.end())
    {
        if ((*iterator)->mKeyboardEvent == evt.keysym.sym)
        {
            (*iterator)->Notify(evt.keysym.sym, (OgreBites::EventType)evt.type);
        }
        ++iterator;
    }
    return true;
}

InputSubject* InputManager::GetInputSubject(Keycode keycode, EventType evtype)
{
    std::list<InputSubject*>::iterator iterator;

    switch (evtype)
    {
    case EventType::KEYDOWN:
        iterator = mKeyDownSubjects.begin();
        while (iterator != mKeyDownSubjects.end())
        {
            if ((*iterator)->mKeyboardEvent == keycode)
            {
                return *iterator;
            }
            ++iterator;
        }
        break;
    case EventType::KEYUP:
        iterator = mKeyUpSubjects.begin();
        while (iterator != mKeyUpSubjects.end())
        {
            if ((*iterator)->mKeyboardEvent == keycode)
            {
                return *iterator;
            }
            ++iterator;
        }
        break;
    default:
        return nullptr;
    }
    //return nullptr;
}

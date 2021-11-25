#include "InputManager.h"

InputManager::InputManager()
{
    PopulateKeyDownList();
    PopulateKeyUpList();
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

void InputManager::PopulateKeyDownList()
{
    mKeyDownSubjects.push_back(new InputSubject(SDLK_ESCAPE, EventType::KEYDOWN));
    mKeyDownSubjects.push_back(new InputSubject(SDLK_SPACE, EventType::KEYDOWN));
    mKeyDownSubjects.push_back(new InputSubject(SDLK_UP, EventType::KEYDOWN));
    mKeyDownSubjects.push_back(new InputSubject(SDLK_DOWN, EventType::KEYDOWN));
    mKeyDownSubjects.push_back(new InputSubject(SDLK_LEFT, EventType::KEYDOWN));
    mKeyDownSubjects.push_back(new InputSubject(SDLK_RIGHT, EventType::KEYDOWN));
    mKeyDownSubjects.push_back(new InputSubject('w', EventType::KEYDOWN));
    mKeyDownSubjects.push_back(new InputSubject('s', EventType::KEYDOWN));
    mKeyDownSubjects.push_back(new InputSubject('a', EventType::KEYDOWN));
    mKeyDownSubjects.push_back(new InputSubject('d', EventType::KEYDOWN));

}

void InputManager::PopulateKeyUpList()
{
    mKeyUpSubjects.push_back(new InputSubject(SDLK_SPACE, EventType::KEYUP));
    mKeyUpSubjects.push_back(new InputSubject(SDLK_UP, EventType::KEYUP));
    mKeyUpSubjects.push_back(new InputSubject(SDLK_DOWN, EventType::KEYUP));
    mKeyUpSubjects.push_back(new InputSubject(SDLK_LEFT, EventType::KEYUP));
    mKeyUpSubjects.push_back(new InputSubject(SDLK_RIGHT, EventType::KEYUP));
    mKeyUpSubjects.push_back(new InputSubject('w', EventType::KEYUP));
    mKeyUpSubjects.push_back(new InputSubject('s', EventType::KEYUP));
    mKeyUpSubjects.push_back(new InputSubject('a', EventType::KEYUP));
    mKeyUpSubjects.push_back(new InputSubject('d', EventType::KEYUP));
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

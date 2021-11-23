#pragma once
#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include "OgreTrays.h"
#include "InputManager.h"
#include <iostream>

using namespace Ogre;
using namespace OgreBites;
/// <summary>
/// Game class used to build the application and set-up the game world
/// </summary>
class Game 
    : public ApplicationContext
 //   , public InputListener
{
private:
    SceneManager* scnMgr;
    Root* root;

    InputManager* mInputManager;

    TrayManager* mTrayMgr;
    TrayListener myTrayListener;
    Label* mInfoLabel;
    Label* mFpsLabel;
    Label* mFps;
    String fpsnum;

    Label* mScoreLabel;
    Label* mScore;
    String scorenum;

    Label* mTpuLabel;
    Label* mTpu;
    String Tpunum;

    Label* mLivesLabel;
    Label* mLives;
    String livesnum;

public:
    Game();
    ~Game();

    /// <summary>
    /// Main Setup Function
    /// </summary>
    void setup();
    /// <summary>
    /// Input detection function for keydown
    /// </summary>
    bool keyPressed(const KeyboardEvent& evt);
    /// <summary>
   /// Input detection for Keyup
   /// </summary>
    bool keyReleased(const KeyboardEvent& evt);
    /// <summary>
    /// Calls the other functions that create the main objects in the game
    /// </summary>
    void CreateScene();
    /// <summary>
    /// Creates the game world camera and binds it to a scenenode
    /// </summary>
    void CreateCamera();
    /// <summary>
    /// Creates the custom observer class framelistener
    /// </summary>
    void CreateFrameListener();
    /// <summary>
    /// Creates the Background Plane
    /// </summary>
    void CreateBackground();
    /// <summary>
    /// Creates all the lights needed for the scene
    /// </summary>
    void CreateLights();
    /// <summary>
    /// Creates the custom meshes and objects used within the scene
    /// </summary>
    void CreatePhysicsObjects();
    /// <summary>
    /// Creates the traymanager and the different labels present within the scene
    /// </summary>
    void CreateUI();
    /// <summary>
    /// A function to update the UI
    /// </summary>
    /// <param name="evt"></param>
    void UpdateUI(const Ogre::FrameEvent& evt);
};


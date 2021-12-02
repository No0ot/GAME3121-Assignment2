/*! Game class used to build the application and set-up the game world */
#include "Game.h"

/// Custom FrameListener. 
/// Keeps references to physics objects to call their update functions. 
/// Also keeps a reference to the game instance to call the update on the UI
class PhysicsFrameListener : public Ogre::FrameListener
{
private:
    Game* gameInstance;

public:
    PhysicsFrameListener( Game* gameinstanceref )
    {
        gameInstance = gameinstanceref;
    }

    bool frameStarted(const Ogre::FrameEvent& evt)
    {
        
        return true;
    }

    bool frameEnded(const Ogre::FrameEvent& evt)
    {
        
        return true;
    }

    bool frameRenderingQueued(const Ogre::FrameEvent& evt)
    {
        gameInstance->UpdateUI(evt);
        return true;
    }
};

/// Game class Constructor
/// 
/// 
Game::Game()
    : ApplicationContext("GAME3121 - Assignment 2")
{
    _keepRunning = true;
}
Game::~Game()
{
}

/// Main setup function
/// calls the super setup function as well as gets references to the root and SceneManager
/// 
void Game::setup()
{
    // do not forget to call the base first
    ApplicationContext::setup();
    mInputManager = new InputManager();
    addInputListener(mInputManager);
    InputSubject* temp = mInputManager->GetInputSubject(SDLK_ESCAPE, EventType::KEYDOWN);

    this->AttachToSubject(*temp);
    temp = mInputManager->GetInputSubject(SDLK_SPACE, EventType::KEYDOWN);
    this->AttachToSubject(*temp);
    sndMngr = new SoundManager();

    // get a pointer to the already created root
    root = getRoot();
    scnMgr = root->createSceneManager();

    // register our scene with the RTSS
    RTShader::ShaderGenerator* shadergen = RTShader::ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(scnMgr);

    playerObject = new Player(this, this->scnMgr, "Player");
    gameObjects.push_back(playerObject);

    for (int i = 0; i < 2; i++)
    {
        Platform* temp = new Platform(this, this->scnMgr, "Platform_" + i);
        platformObjects.push_back(temp);
        gameObjects.push_back(temp);
    }
    platformObjects[0]->GetNode()->translate(0, 0.0f, 0);
    platformObjects[1]->GetNode()->translate(10.0f, 10.0f, 0);

    CreateScene();
    CreateCamera();
    CreateFrameListener();
}
/// Input detection function for keydown
/// Handles input detection for keyboard buttons pressed down
/// Basic Controls for the game
//bool Game::keyPressed(const KeyboardEvent& evt)
//{
//
//   
//}
///// Input detection for Keyup
///// used to smooth movement of the paddle object
///// 
//bool Game::keyReleased(const KeyboardEvent& evt)
//{
//   
//}
/// Create Scene Function
/// Calls the other functions that create the main objects in the game
///
void Game::CreateScene()
{
    CreateLights();
    CreateBackground();
    CreatePhysicsObjects();
    CreateUI();
    //sndMngr->PlayMusic();
}

/// Create Camera Function:
/// Creates the game world camera and binds it to a scenenode
///
void Game::CreateCamera()
{
    SceneNode* camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    cam_ = scnMgr->createCamera("myCam");
    cam_->setNearClipDistance(5);
    cam_->setAutoAspectRatio(true);
    camNode->attachObject(cam_);
    camNode->setPosition(0, 0, 50);

    getRenderWindow()->addViewport(cam_);
}

/// Creates the custom observer class framelistener :
/// Creates the custom PhysicsFrameListener while passing in a vector of all the physics objects along with a refrence to the game instance
///
void Game::CreateFrameListener()
{
    Ogre::FrameListener* FrameListener = new PhysicsFrameListener(this);
    root->addFrameListener(FrameListener);
}

/// Creates the Background Plane
/// creates a plane for the background and binds a texture to the material
/// 
void Game::CreateBackground()
{
    //The first thing we'll do is create an abstract Plane object. This is not the mesh, it is more of a blueprint.
    Plane plane(Vector3::UNIT_Z, 0);
    //Now we'll ask the MeshManager to create us a mesh using our Plane blueprint. The MeshManager is already keeping track of the resources we loaded when initializing our application. On top of this, it can create new meshes for us.
    MeshManager::getSingleton().createPlane(
        "ground", RGN_DEFAULT,
        plane,
        100, 100, 20, 20,
        true,
        1, 5, 5,
        Vector3::UNIT_Y);

    //Now we will create a new Entity using this mesh.
    //We want to tell our SceneManager not to cast shadows from our ground Entity. It would just be a waste. Don't get confused, this means the ground won't cast a shadow, it doesn't mean we can't cast shadows on to the ground.
    Entity* groundEntity = scnMgr->createEntity("ground");
    scnMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
    groundEntity->setCastShadows(false);

    //And finally we need to give our ground a material.
    groundEntity->setMaterialName("Examples/Rockwall");
}

/// Create Lights Function :
/// Creates all the lights needed for the scene
/// 
void Game::CreateLights()
{
    scnMgr->setAmbientLight(ColourValue(0.5, 0.5, 0.5));

    Light* light = scnMgr->createLight("MainLight");
    SceneNode* mainlightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    mainlightNode->attachObject(light);

    mainlightNode->setPosition(-80, 80, 50);
    Light* light1 = scnMgr->createLight("Light1");
    light1->setType(Ogre::Light::LT_POINT);
    // Set Light Color
    light1->setDiffuseColour(1.0f, 1.0f, 1.0f);
    // Set Light Reflective Color
    light1->setSpecularColour(1.0f, 0.0f, 0.0f);
    // Set Light (Range, Brightness, Fade Speed, Rapid Fade Speed)
    light1->setAttenuation(10, 0.5, 0.045, 0.0);
    Entity* lightEnt = scnMgr->createEntity("LightEntity", "sphere.mesh");
    SceneNode* lightNode = scnMgr->createSceneNode("LightNode");
    lightNode->attachObject(lightEnt);
    lightNode->attachObject(light1);
    lightNode->setScale(0.01f, 0.01f, 0.01f);
}

/// Create Physics Objects function:
/// Creates the custom meshes and objects used within the scene
///
void Game::CreatePhysicsObjects()
{

}

/// Creates the UI:
/// Creates the traymanager and the different labels present within the scene
///
void Game::CreateUI()
{
    mTrayMgr = new OgreBites::TrayManager("InterfaceName", getRenderWindow());
    //you must add this in order to add a tray
    scnMgr->addRenderQueueListener(mOverlaySystem);

    //Once you have your tray manager, make sure you relay input events to it.
    addInputListener(mTrayMgr);

    mInfoLabel = mTrayMgr->createLabel(TL_TOP, "TInfo", "Pong Game", 300);

    mFpsLabel = mTrayMgr->createLabel(TL_TOPRIGHT, "FPS", "FPS:", 150);
    mFps = mTrayMgr->createLabel(TL_TOPRIGHT, "fps", "60", 150);

    mScoreLabel = mTrayMgr->createLabel(TL_TOPLEFT, "Score", "Score:", 150);
    mScore = mTrayMgr->createLabel(TL_TOPLEFT, "score", scorenum, 150);

    mTpuLabel = mTrayMgr->createLabel(TL_TOPRIGHT, "Time/Update", "Time/Update:", 150);
    mTpu = mTrayMgr->createLabel(TL_TOPRIGHT, "tpu", "0", 150);

    mLivesLabel = mTrayMgr->createLabel(TL_TOPLEFT, "Lives", "Lives:", 150);
    mLives = mTrayMgr->createLabel(TL_TOPLEFT, "lives", livesnum, 150);
}

/// A function to update the UI
/// this function updates the various UI elements per frame.
/// It is used within the physics frame listener
/// 
void Game::UpdateUI(const Ogre::FrameEvent& evt)
{
    Tpunum = Ogre::StringConverter::toString(evt.timeSinceLastFrame);
    mTpu->setCaption(Tpunum);

    fpsnum = Ogre::StringConverter::toString(1 / evt.timeSinceLastFrame);
    mFps->setCaption(fpsnum);
}

void Game::ObserverUpdate(Keycode keycode, EventType eventtype)
{
    if (keycode == SDLK_ESCAPE && eventtype == EventType::KEYDOWN)
    {
        getRoot()->queueEndRendering();
        _keepRunning = false;
    } 
    if (keycode == SDLK_SPACE && eventtype == EventType::KEYDOWN)
    {
        sndMngr->PlaySound();
    }
}

bool Game::keepRunning()
{
    return _keepRunning;
}

void Game::GameLoopUpdate()
{
    mRoot->renderOneFrame();
    for (auto objects : gameObjects)
    {
        objects->Update();
    }

    CheckPlayerCollision();
}

void Game::CheckPlayerCollision()
{
    playerObject->SetGrounded(false);
    for (int i = 0; i < platformObjects.size(); i++)
    {
        if (playerObject->GetNode()->_getWorldAABB().intersects(platformObjects[i]->GetNode()->_getWorldAABB()))
        {
            float dist = playerObject->GetNode()->_getWorldAABB().getCorner(Ogre::AxisAlignedBox::CornerEnum::FAR_LEFT_BOTTOM).y - 
                platformObjects[i]->GetNode()->_getWorldAABB().getCorner(Ogre::AxisAlignedBox::CornerEnum::FAR_LEFT_TOP).y;
            //std::cout << dist << std::endl;
            if (dist < 1.65f && dist > -1.65f)
            {
                //std::cout << ">>> Player on platform" << std::endl;
                playerObject->SetGrounded(true);
                // RESOLVE CLIPPING
                /*std::cout << "player: ";
                std::cout << playerObject->GetNode()->getPosition().y - playerObject->GetNode()->_getWorldAABB().getHalfSize().y << std::endl;
                std::cout << "platform: ";
                std::cout << platformObjects[i]->GetNode()->_getWorldAABB().getCorner(Ogre::AxisAlignedBox::CornerEnum::FAR_LEFT_TOP).y << std::endl;
                playerObject->GetNode()->setPosition(playerObject->GetNode()->getPosition().x,
                    platformObjects[i]->GetNode()->_getWorldAABB().getCorner(Ogre::AxisAlignedBox::CornerEnum::FAR_LEFT_TOP).y + playerObject->GetNode()->_getWorldAABB().getHalfSize().y,
                    playerObject->GetNode()->getPosition().z);*/
                break;
            }
        }
    }
    Ogre::Vector3 player_screen_pos = cam_->getProjectionMatrix() * cam_->getViewMatrix() *
        playerObject->GetNode()->_getWorldAABB().getCenter();
        //playerObject->GetNode()->convertLocalToWorldPosition(playerObject->GetNode()->getPosition());
    //std::cout << player_screen_pos << std::endl;
    if (player_screen_pos.y <= -1) //DEATH
    {
        //std::cout << ">>> Player out of screen" << std::endl;
        playerObject->SetGrounded(true);
    }
}

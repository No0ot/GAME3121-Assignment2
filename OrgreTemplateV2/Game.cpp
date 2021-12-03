/*! Game class used to build the application and set-up the game world */
#include "Game.h"
#include "SoundManager.h"
#include "CollisionManager.h"

/// Custom FrameListener. 
/// Keeps references to physics objects to call their update functions. 
/// Also keeps a reference to the game instance to call the update on the UI
class PhysicsFrameListener : public Ogre::FrameListener
{
private:
    Game* gameInstance;
    Ogre::Real updateUITime = 0;
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
        updateUITime += evt.timeSinceLastFrame;
        if (updateUITime >= 0.1)
        {
            gameInstance->UpdateUI(evt);
            updateUITime = 0;
        }
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
    temp = mInputManager->GetInputSubject('`', EventType::KEYDOWN);
    this->AttachToSubject(*temp);
    //sndMngr = new SoundManager();
   
    TheSoundManager::Instance()->load("music.wav", "Music", sound_type::SOUND_MUSIC);
    // get a pointer to the already created root
    root = getRoot();
    scnMgr = root->createSceneManager();

    // register our scene with the RTSS
    RTShader::ShaderGenerator* shadergen = RTShader::ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(scnMgr);

    CreateScene();
    CreateCamera();
    CreateFrameListener();

    mPlayerJumps = 0;
    mPlayerLives = 3;
}

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
    TheSoundManager::Instance()->playMusic("Music", -1, 32);
}

/// Create Camera Function:
/// Creates the game world camera and binds it to a scenenode
///
void Game::CreateCamera()
{
    cam_node_ = scnMgr->getRootSceneNode()->createChildSceneNode();
    cam_ = scnMgr->createCamera("myCam");
    cam_->setNearClipDistance(5);
    cam_->setAutoAspectRatio(true);
    cam_node_->attachObject(cam_);
    cam_node_->setPosition(0, 0, 50);

    getRenderWindow()->addViewport(cam_);
}

/// Creates the custom observer class framelistener :
/// Creates the custom PhysicsFrameListener while passing in a vector of all the physics objects along with a refrence to the game instance
///
void Game::CreateFrameListener()
{
    Ogre::FrameListener* frameListener = new PhysicsFrameListener(this);
    root->addFrameListener(frameListener);
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
    bkg_node_ = scnMgr->getRootSceneNode()->createChildSceneNode();
    bkg_node_->attachObject(groundEntity);
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
    lightNode = scnMgr->createSceneNode("LightNode");
    lightNode->attachObject(lightEnt);
    lightNode->attachObject(light1);
    lightNode->setScale(0.01f, 0.01f, 0.01f);
}

/// Create Physics Objects function:
/// Creates the custom meshes and objects used within the scene
///
void Game::CreatePhysicsObjects()
{
    playerObject = new Player(this, this->scnMgr, "Player");
    gameObjects.push_back(playerObject);

    platform_max_y_ = 0;
    for (int i = 0; i < 30; i++)
    {
        Platform* temp = new Platform(this, this->scnMgr, "Platform_" + Ogre::StringConverter::toString(i));
        platformObjects.push_back(temp);
        gameObjects.push_back(temp);
        temp->GetNode()->translate(Ogre::Math::RangeRandom(-15.0f, 15.0f), platform_max_y_, 0);
        platform_max_y_ += Ogre::Math::RangeRandom(5.0f, 8.5f);
    }
    platformObjects[0]->GetNode()->setPosition(playerObject->GetNode()->getPosition().x, playerObject->GetNode()->getPosition().y - 10, platformObjects[0]->GetNode()->getPosition().z);
    //Ogre::Vector4 temp_vect = Ogre::Vector4(1,1,0,1) * (cam_->getProjectionMatrix() * cam_->getViewMatrix()).inverse();
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

    mInfoLabel = mTrayMgr->createLabel(TL_TOP, "TInfo", "Doodle Jump 2", 300);

    mFpsLabel = mTrayMgr->createLabel(TL_TOPRIGHT, "FPS", "FPS:", 150);
    mFps = mTrayMgr->createLabel(TL_TOPRIGHT, "fps", "60", 150);

    mScoreLabel = mTrayMgr->createLabel(TL_TOPLEFT, "Score", "Jumps:", 150);
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
    livesnum = Ogre::StringConverter::toString(mPlayerLives);
    mLives->setCaption(livesnum);
    scorenum = Ogre::StringConverter::toString(mPlayerJumps);
    mScore->setCaption(scorenum);

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
    if (keycode == '`' && eventtype == EventType::KEYDOWN)
    {
        for (auto objects : gameObjects)
        {
            objects->GetNode()->showBoundingBox(!objects->GetNode()->getShowBoundingBox());
        }
        
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

    GameLogicCheck();
}

void Game::GameLogicCheck()
{
    /*std::cout << ">>> playerObject->GetNode()->_getWorldAABB().getCenter().x ";
    std::cout << playerObject->GetNode()->_getWorldAABB().getCenter().x << std::endl;*/
    playerObject->SetGrounded(false);
    for (int i = 0; i < platformObjects.size(); i++)
    {
        if (CollisionManager::AABBCheck(playerObject, platformObjects[i]) == CollisionManager::CollisionType::kBottom)
        {
            if (playerObject->GetVelocity().y <= 0)
            {
                    mPlayerJumps++;
                playerObject->DoJump();
                break;
            }
        }
    }

    // CHECK PLAYER - SCREEN
    if (playerObject->GetNode()->getPosition().y > cam_node_->getPosition().y)
    {
        cam_node_->setPosition(cam_node_->getPosition().x, playerObject->GetNode()->getPosition().y, cam_node_->getPosition().z);
        bkg_node_->setPosition(bkg_node_->getPosition().x, playerObject->GetNode()->getPosition().y, bkg_node_->getPosition().z);
    }
    
    if (CollisionManager::CameraBoundCheck(playerObject, cam_) == CollisionManager::CollisionType::kBottom) //DEATH
    {
        //std::cout << ">>> Player out of screen" << std::endl;
        //playerObject->SetGrounded(true);
        playerObject->GetNode()->setPosition(0, cam_node_->getPosition().y, 0); //reposition to center of screen
        playerObject->SetVelocity(0,0,0);
        mPlayerLives -= 1;
        if (mPlayerLives == 0)
        {
            getRoot()->queueEndRendering();
            _keepRunning = false;
        }
    }

    // CHECK PLATFORM - SCREEN
    for (int i = 0; i < platformObjects.size(); i++)
    {
        if (CollisionManager::CameraBoundCheck(platformObjects[i], cam_) == CollisionManager::CollisionType::kBottom) //reposition
        {
            platformObjects[i]->GetNode()->translate(Ogre::Math::RangeRandom(-15.0f, 15.0f), platform_max_y_, 0);
            platform_max_y_ += Ogre::Math::RangeRandom(5.0f, 8.5f);
        }
    }
}

//! [fullsource]

#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include <iostream>

#include "Game.h"

using namespace Ogre;
using namespace OgreBites;

int main(int argc, char** argv)
{
    try
    {
        Game app;
        app.initApp();
        //app.getRoot()->startRendering();
        while (app.keepRunning())
        {
            app.GameLoopUpdate();
        }
        app.closeApp();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error occurred during execution: " << e.what() << '\n';
        return 1;
    }

    return 0;
}

//! [fullsource]

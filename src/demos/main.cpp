#include <iostream>

#include "../../include/core/precision.h"
#include "../../include/core/core.h"
#include "app.h"
#include "timing.h"


using namespace physicsEngine;

std::unique_ptr<Application> app;


int main() {

    try {
    	app = std::make_unique<Application>(WINDOW_WIDTH, WINDOW_HEIGHT, "Demo");
        // last_frame_time = 0;
        app->setEngineIsRunning(true);
        TimingData::init();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error initializing Application: " << e.what() << std::endl;        
    }

    while (app->isEngineRunning()) 
    {
        app->processInput();
        // update();
        app->render();
    }

    TimingData::deinit();    
    return 0;
}
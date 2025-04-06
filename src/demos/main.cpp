#include <iostream>

#include "../../include/core/precision.h"
#include "../../include/core/core.h"
#include "app.h"
#include "timing.h"


using namespace physicsEngine;

extern Application* getApplication();

int main() {

    std::unique_ptr<Application> app;

    try {
        app.reset(getApplication());
        app->setEngineIsRunning(true);
        TimingData::init();
     }
    catch (const std::exception& e) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, 
                               "Error", 
                               e.what(), 
                               nullptr);
        return 1;
    }

    while (app->isEngineRunning()) {
        app->processInput();
        app->update();
        app->render();
    }
    
    TimingData::deinit();

    return 0;
}
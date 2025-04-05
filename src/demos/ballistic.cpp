#include "app.h"

class BallisticDemo : public Application
{

public:  
    BallisticDemo();

    /** Display the particle positions. */
    virtual void render();

};


BallisticDemo::BallisticDemo()
{

    
}


void BallisticDemo::render()
{
    SDL_Rect ball_rect = {
        WINDOW_WIDTH / 2 - 15/2,
        WINDOW_HEIGHT / 2 - 15/2,
        15,
        15,
    };
    SDL_SetRenderDrawColor(getRenderer(), 255, 255, 255, 255);
    SDL_RenderFillRect(getRenderer(), &ball_rect);

    presentScreen();
}


Application* getApplication()
{
    return new BallisticDemo();
}

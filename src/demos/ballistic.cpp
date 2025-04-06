#include "app.h"
#include "timing.h"
#include <iostream>

#include "../../include/core/particle.h"

using namespace physicsEngine;

class BallisticDemo : public Application
{
    struct AmmoRound
    {
        Particle particle;
        // ShotType type;
        unsigned startTime;

        /** Draws the round. */
        void render(SDL_Renderer* renderer)
        {
            Vector3 position;
            particle.getPosition(&position);

            SDL_Rect ball {
                (int)position.x,
                (int)position.y,
                5,
                5,
            };
            
            // std::cout << "Pos: (" << (int)position.x << ", " << (int)position.y << ")" << std::endl;
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            if (ball.x != 0 && ball.y != 0)
                SDL_RenderFillRect(renderer, &ball);

        }
    };

    AmmoRound *shot = new AmmoRound();

    public:  
        BallisticDemo();

        /** Display the particle positions. */
        void render() override;

        /** Dispatches a round. */
        void fire();

        virtual void key() override;

        virtual void update() override;


};

BallisticDemo::BallisticDemo()
    : Application(WINDOW_WIDTH, WINDOW_HEIGHT, "Ballistic Demo") 
{
}

void BallisticDemo::render()
{
    clearScreen(127, 127, 127, 255);  // Clear screen using the Graphics object

    shot->render(getRenderer());

    // presentScreen();
    Application::render();
}

void BallisticDemo::fire() 
{
    shot->particle.setMass(2.0f); // 2.0kg
    // shot->particle.setVelocity(0.0f, 0.0f, 35.0f); // 35m/s
    shot->particle.setVelocity(35.0f, 0.0f, 0.0f); // 35m/s
    shot->particle.setAcceleration(0.0f, +1.0f, 0.0f);
    shot->particle.setDamping(0.99f);

    // Set the data common to all particle types
    shot->particle.setPosition(10.0f, 20.0f, 0.0f);
    shot->startTime = TimingData::get().lastFrameTimestamp;
    std::cout << "start time: " << shot->startTime << std::endl;
    // shot->type = currentShotType;

    // Clear the force accumulators
    shot->particle.clearAccumulator();
}

// void BallisticDemo::key(unsigned char key)
void BallisticDemo::key()
{
    // switch(key)
    // {
    // case '1': currentShotType = PISTOL; break;
    // case '2': currentShotType = ARTILLERY; break;
    // case '3': currentShotType = FIREBALL; break;
    // case '4': currentShotType = LASER; break;
    // }
    fire();
}

void BallisticDemo::update()
{
    Application::update();
    // std::cout << "Ballistic Demo Update..." << std::endl;
    // Find the duration of the last frame in seconds
    float duration = (float)TimingData::get().lastFrameDuration * 0.001f;
    if (duration <= 0.0f) return;

    // Update the physics of each particle in turn
    // for (AmmoRound *shot = ammo; shot < ammo+ammoRounds; shot++)
    // {
    //     if (shot->type != UNUSED)
    //     {
    //         // Run the physics
            shot->particle.integrate(duration);

            // Check if the particle is now invalid
            // if (shot->particle.getPosition().y < 0.0f ||
            //     shot->startTime+5000 < TimingData::get().lastFrameTimestamp ||
            //     shot->particle.getPosition().z > 200.0f)
            // {
                // We simply set the shot type to be unused, so the
                // memory it occupies can be reused by another shot.
    //             shot->type = UNUSED;
            // }
    //     }
    // }

    
}


Application* getApplication()
{
    return new BallisticDemo();
}


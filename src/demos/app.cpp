#include "app.h"
// #include <stdexcept>

// Custom deleters for SDL_Window and SDL_Renderer
auto windowDeleter = [](SDL_Window* ptr) { if (ptr) SDL_DestroyWindow(ptr); };
auto rendererDeleter = [](SDL_Renderer* ptr) { if (ptr) SDL_DestroyRenderer(ptr); };

Application::Application(int width, int height, const std::string& title) 
    : window(nullptr, windowDeleter),
      renderer(nullptr, rendererDeleter) 
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error("Failed to initialize SDL: " + std::string(SDL_GetError()));
    }
      
    // Initialize SDL_Window
    window.reset(SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    ));
    if (!window) {
        throw std::runtime_error("Failed to create SDL Window: " + std::string(SDL_GetError()));
    }

    // Initialize SDL_Renderer
    renderer.reset(SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
    if (!renderer) {
        throw std::runtime_error("Failed to create SDL Renderer: " + std::string(SDL_GetError()));
    }
}

Application::~Application() 
{
    SDL_Quit();
}

void Application::clearScreen(Uint8 r, Uint8 g, Uint8 b, Uint8 a) 
{
    SDL_SetRenderDrawColor(renderer.get(), r, g, b, a);
    SDL_RenderClear(renderer.get());
}

void Application::presentScreen() 
{
    SDL_RenderPresent(renderer.get());
}

SDL_Renderer* Application::getRenderer() const 
{
    return renderer.get();
}

void Application::processInput(void) 
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
            engineIsRunning = false;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    engineIsRunning = false;
                }
                break;
        }
    }
}

void Application::render(void) 
{
    clearScreen(127, 127, 127, 255);  // Clear screen using the Graphics object

    // HERE I'LL RENDER THE SIMULATION

    presentScreen();  // Present the screen using the Graphics object
}

bool Application::isEngineRunning() 
{
    return engineIsRunning;
}

void Application::setEngineIsRunning(bool state)
{
    engineIsRunning = state;

}
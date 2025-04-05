#ifndef APP_H
#define APP_H

#include <SDL.h>
#include <memory>
#include <string>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class Application {
    private:
        std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> window;
        std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> renderer;

        bool engineIsRunning = false;

    public:
        Application(int width, int height, const std::string& title);
        ~Application();

        // Rendering functions
        void clearScreen(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        void presentScreen();

        // Accessors
        SDL_Renderer* getRenderer() const;

        void processInput();
        void render();
        bool isEngineRunning();
        void setEngineIsRunning(bool state);
};

Application* getApplication();


#endif
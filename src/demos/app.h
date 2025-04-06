#ifndef APP_H
#define APP_H

#include <SDL.h>
#include <memory>
#include <string>
#include <unordered_map>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class Application {
    private:
        std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> window;
        std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> renderer;

        bool engineIsRunning;

        std::unordered_map<SDL_Keycode, bool> keyStates;

    public:
        Application(int width, int height, const std::string& title);
        virtual ~Application();

        // Rendering functions
        void clearScreen(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        void presentScreen();

        // Accessors
        SDL_Renderer* getRenderer() const;

        bool isEngineRunning();
        void setEngineIsRunning(bool state);

        // Add these virtual methods for demo implementations
        virtual void init() {}
        
        virtual void processInput();
        virtual void render() = 0;
        virtual void update()= 0;
        virtual void key();
  
};

Application* getApplication();


#endif
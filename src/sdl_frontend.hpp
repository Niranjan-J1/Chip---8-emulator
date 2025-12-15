#pragma once
#include <SDL.h>
#include <iostream>

class SDLFrontend {
public:
    SDLFrontend();
    ~SDLFrontend();

    bool init();
    void runTestWindow();

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};

#include "window.hpp"
#include <iostream>
using namespace std;

Window::Window(const char* WindowName, int Width, int Height) {
    frame_rate = 10;
    frameSlower = 0;
    closeRequest = 0;

    winWidth = Width;
    winHeight = Height - 100;


    //Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Error while initializing SDL :" << SDL_GetError() << endl;
        return;
    }


    //Create window
    window = SDL_CreateWindow(WindowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        cout << "Couldn't create window :" << SDL_GetError() << endl;
        return;
    }
    SDL_GetWindowSize(window, &winWidth, &winHeight); //check windows size


    //Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        cout << "Couldn't create renderer :" << SDL_GetError() << endl;
        return;
    }

    SDL_RenderClear(renderer);
    return;
}

int Window::Destroy() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return EXIT_FAILURE;
}

void Window::CheckKeys() {
    const Uint8* keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_ESCAPE]) {
        closeRequest = 1;
        return;
    }
}

int Window::Refresh() {
    SDL_RenderPresent(renderer);
    return 1;
}

SDL_Renderer** Window::GetRenderer() {
    return &renderer;
}
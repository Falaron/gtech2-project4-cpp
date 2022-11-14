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


    //Init TTF
    if (TTF_Init() < 0)
    {
        cout << "Couldn't initialize SDL TTF:" << SDL_GetError() << endl;
        return;
    }
    TTF_Init();
    //font = TTF_OpenFont("arial.ttf", 25);
    //color = { 255, 0, 0 };


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
    TTF_Quit();
    SDL_Quit();

    return EXIT_FAILURE;
}

void Window::ClearRenderer(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
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

int Window::DrawText() {
    string text = "BONJOUR";
    surface = TTF_RenderText_Solid(font, text.c_str(), color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_QueryTexture(texture, NULL, NULL, 0, 0);
    SDL_Rect textRect = { 50, 100, 100, 150 };
    SDL_RenderCopy(renderer, texture, NULL, &textRect);
    return  1;
}

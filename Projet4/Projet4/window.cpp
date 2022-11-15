#include "window.hpp"
#include <iostream>
#include <string>
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
        cout << "Couldn't initialize SDL TTF:" << TTF_GetError() << endl;
        return;
    }

    font = TTF_OpenFont("font/barlow.ttf", 25);
    if (!font) {
        cout << "Failed to load font: " << TTF_GetError() << endl;
    }
    color = { 255, 255, 255 };
    //Input TTF
    SDL_StartTextInput();


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


    //Init SDL_Image
    if (IMG_Init(IMG_INIT_PNG) == 0) {
        cout << "Error SDL2_image Initialization" << endl;
        return;
    }

    return;
}

int Window::Destroy() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    SDL_StopTextInput();
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

int Window::DrawText(const char* text, int positionX, int positionY) {
    surface = TTF_RenderText_Solid(font, text, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect textRect = { positionX, positionY, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &textRect);
    return  1;
}

int Window::Input() {
    string in;
    bool running = true;

    while (running) {
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_TEXTINPUT) {
                in += ev.text.text;
                cout << " > " << in << endl;
            }
            else if (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_BACKSPACE && in.size()) {
                in.pop_back();
                cout << " > " << in << endl;
            } else if (ev.type == SDL_QUIT) {
                running = false;
            }
        }
    }
    return 1;
}

int Window::showImage(const char* img_name, int positionX, int positionY, int width, int height) {
    SDL_Surface* logoSurface = IMG_Load(img_name);
    SDL_Texture* logoTexture = SDL_CreateTextureFromSurface(renderer, logoSurface);
    SDL_FreeSurface(logoSurface);

    SDL_RenderClear(renderer);
    SDL_Rect imgRect = { positionX, positionY, width, height };
    SDL_RenderCopy(renderer, logoTexture, NULL, &imgRect);
    SDL_RenderPresent(renderer);

    return 1;
}
#include <SDL.h>
#include "SDL_ttf.h"
#include "SDL_image.h"

class Window
{
public:
    Window(const char* WindowName, int Width, int Height);
    int Refresh();
    int Destroy();
    SDL_Window* GetSDLWindow();
    SDL_Renderer* GetRenderer();
    void ClearRenderer(SDL_Renderer* renderer);
    void CheckKeys();
    int DrawText(const char* text, int positionX, int positionY);
    int Input();
    int showImage(const char* img_name, int positionX, int positionY, int width, int height);

    int winWidth, winHeight;

    SDL_Event event;
    int closeRequest;
    Uint32 frame_time_start, frame_time;
    Uint32 frame_rate;
    int frameSlower;

    SDL_Surface* surface;
    SDL_Texture* texture;
    TTF_Font* font;
    SDL_Color color;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
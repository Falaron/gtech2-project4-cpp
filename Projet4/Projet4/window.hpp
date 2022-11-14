#include <SDL.h>

class Window
{
public:
    Window(const char* WindowName, int Width, int Height);
    int Refresh();
    int Destroy();
    SDL_Renderer** GetRenderer();
    void ClearRenderer(SDL_Renderer* renderer);
    void CheckKeys();

    int winWidth, winHeight;

    SDL_Event event;
    int closeRequest;
    Uint32 frame_time_start, frame_time;
    Uint32 frame_rate;
    int frameSlower;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
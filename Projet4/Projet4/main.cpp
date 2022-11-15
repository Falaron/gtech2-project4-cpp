#include "window.hpp"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    //Init Window
    Window* main_window = new Window("Baby", 360, 611);

    while (main_window->closeRequest == 0) {
        main_window->frame_time_start = SDL_GetTicks();

        SDL_PollEvent(&main_window->event);

        main_window->frame_time = SDL_GetTicks() - main_window->frame_time_start;

        while (SDL_PollEvent(&main_window->event) != 0)
        {
            if (main_window->event.type == SDL_QUIT) {
                main_window->closeRequest = 1;
                break;
            }
        }

        if (main_window->frame_time < main_window->frame_rate)
        {
            if (main_window->frameSlower >= 12) {

                //Stuff in frame
                main_window->DrawText("Hello 1", 10, 10);
                main_window->DrawText("Hello 2", main_window->winWidth/2-40, 50);
                //main_window->Input();
                main_window->CheckKeys();
                main_window->showImage("img/logo.png",main_window->winWidth/2-40,7,83,32);
                main_window->Refresh();
                main_window->frameSlower = 0;
            }
            main_window->frameSlower++;
            SDL_Delay(main_window->frame_rate - main_window->frame_time);
        }
    }
    return main_window->Destroy();
}
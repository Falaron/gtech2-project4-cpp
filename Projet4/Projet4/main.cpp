#include "window.hpp"

using namespace std;

int main() {
    //Init Window
    Window* main_window = new Window("Baby", 1000, 600);

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
                main_window->frameSlower = 0;
            }
            main_window->frameSlower++;
            SDL_Delay(main_window->frame_rate - main_window->frame_time);
        }
    }
    return main_window->Destroy();
}
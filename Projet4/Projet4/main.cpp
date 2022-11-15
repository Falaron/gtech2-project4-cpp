#include "window.hpp"
#include <iostream>
#include "View.hpp"
#include "Button.hpp"
#include "Widget.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    //Init Window
    Window* main_window = new Window("Baby", 360, 611);

    View *view = new View(main_window->GetSDLWindow(), main_window->GetRenderer());
    view->setFont(main_window->font);
    Button* button1 = new Button("coucou");
    view->addWidget(button1);


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
                view->render();

                
                main_window->CheckKeys();
                main_window->showImage("img/logo.png",main_window->winWidth/2-40,7,83,32);
                main_window->Refresh();
                main_window->frameSlower = 0;
            }
            main_window->frameSlower++;
            SDL_Delay(main_window->frame_rate - main_window->frame_time);
        }
    }
        delete view;
        view = 0;
    return main_window->Destroy();
}
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

    //init main view
    View *viewMain = new View(main_window->GetSDLWindow(), main_window->GetRenderer());
    viewMain->setFont(main_window->font);
    Button* button1 = new Button("PageMain");
    viewMain->addWidget(button1);

    //init view Feed
    View* viewFeed = new View(main_window->GetSDLWindow(), main_window->GetRenderer());
    viewFeed->setFont(main_window->font);
    Button* button2 = new Button("PageFeed");
    viewFeed->addWidget(button2);

    //init view Regurgited
    View* viewRegurgited = new View(main_window->GetSDLWindow(), main_window->GetRenderer());
    viewRegurgited->setFont(main_window->font);
    Button* button3 = new Button("PageRegurgited");
    viewRegurgited->addWidget(button3);

    //init view Settings
    View* viewSettings = new View(main_window->GetSDLWindow(), main_window->GetRenderer());
    viewSettings->setFont(main_window->font);
    Button* button4 = new Button("PageSettings");
    viewSettings->addWidget(button4);

    //init view Shop
    View* viewShop = new View(main_window->GetSDLWindow(), main_window->GetRenderer());
    viewShop->setFont(main_window->font);
    Button* button5 = new Button("PageShop");
    viewShop->addWidget(button5);


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
                viewFeed->render();
                main_window->CheckKeys();
                main_window->Refresh();
                main_window->frameSlower = 0;
            }
            main_window->frameSlower++;
            SDL_Delay(main_window->frame_rate - main_window->frame_time);
        }
    }
        delete viewFeed;
        viewFeed = 0;
    return main_window->Destroy();
}
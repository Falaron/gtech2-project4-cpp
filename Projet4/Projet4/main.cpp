#include "window.hpp"
#include <iostream>
#include "View.hpp"
#include "Button.hpp"
#include "Widget.hpp"
#include "ViewManager.cpp"
#include "Box.h"
using namespace std;




void goToFeed()
{
    currentView = viewFeed;
}

void goToSettings()
{
	currentView = viewSettings;
}

void goToRegurgited()
{
	currentView = viewRegurgited;
}

void goToShop()
{
	currentView = viewShop;
}

void goToMain()
{
	currentView = viewMain;
}

int main(int argc, char* argv[])
{
    //Init Window

    Window* main_window = new Window("Baby", 360, 611);
    /*SDL_SetRenderDrawColor(main_window->GetRenderer(), 49, 49, 49, SDL_ALPHA_OPAQUE);*/
    /*main_window->ClearRenderer(main_window->GetRenderer()); */
    /*SDL_RenderPresent(renderer);*/


    //init main view
    View *viewMain = new View(main_window->GetSDLWindow(), main_window->GetRenderer());
    viewMain->setFont(main_window->font);

    Box* GLOBALE = new Box();
	
	GLOBALE->setColor(49, 49, 49);
	GLOBALE->setPosition(0, 0);
	GLOBALE->setSize(main_window->winWidth, main_window->winHeight);
	//viewMain->addWidget(GLOBALE);


    Box* header = new Box();
	header->setColor(80, 80, 80);   
    header->setSize(main_window->winWidth, 45);
    viewMain->addWidget(header);
	
    Button* button1 = new Button("PageMain");
    button1->setOnClickCallback(goToFeed);
    viewMain->addWidget(button1);

    //init view Feed
    View *viewFeed = new View(main_window->GetSDLWindow(), main_window->GetRenderer());
    viewFeed->setFont(main_window->font);
    //viewFeed->addWidget(GLOBALE);
    Button* button2 = new Button("PageFeed");
    button2->setOnClickCallback(goToMain);
    viewFeed->addWidget(button2);

    //init view Regurgited
    View *viewRegurgited = new View(main_window->GetSDLWindow(), main_window->GetRenderer());
    viewRegurgited->setFont(main_window->font);
    //viewRegurgited->addWidget(GLOBALE);
    Button* button3 = new Button("PageRegurgited");
    viewRegurgited->addWidget(button3);

    //init view Settings
    View *viewSettings = new View(main_window->GetSDLWindow(), main_window->GetRenderer());
    viewSettings->setFont(main_window->font);
    //viewSettings->addWidget(GLOBALE);
    Button* button4 = new Button("PageSettings");
    viewSettings->addWidget(button4);

    //init view Shop
    View *viewShop = new View(main_window->GetSDLWindow(), main_window->GetRenderer());
    viewShop->setFont(main_window->font);
    //viewShop->addWidget(GLOBALE);
    Button* button5 = new Button("PageShop");
    viewShop->addWidget(button5);


    currentView = viewMain;
    

    


    while (main_window->closeRequest == 0) {
        main_window->frame_time_start = SDL_GetTicks();

        main_window->frame_time = SDL_GetTicks() - main_window->frame_time_start;

        while (SDL_PollEvent(&main_window->event) != 0)
        {
            if (main_window->event.type == SDL_QUIT) {
                main_window->closeRequest = 1;
                break;
            }

            currentView->handleEvent(main_window->event);
        }

        if (main_window->frame_time < main_window->frame_rate)
        {
            if (main_window->frameSlower >= 12) {

                //Stuff in frame

                currentView->render();

                
               
               // main_window->showImage("img/logo.png",main_window->winWidth/2-40,7,83,32);

                
                main_window->CheckKeys();

                main_window->Refresh();
                main_window->frameSlower = 0;
            }
            main_window->frameSlower++;
            SDL_Delay(main_window->frame_rate - main_window->frame_time);
        }
    }
        // Free the memory
        delete viewMain;
        viewMain = 0;

        delete viewFeed;
        viewFeed = 0;

        delete viewSettings;
        viewSettings = 0;

        delete viewShop;
        viewShop = 0;

        delete viewRegurgited;
        viewRegurgited = 0;

    return main_window->Destroy();
}
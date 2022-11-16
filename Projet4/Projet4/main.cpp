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
	viewMain->addWidget(GLOBALE);


    Box* header = new Box();
	header->setColor(15, 15, 15);  
    header->setSize(main_window->winWidth, 45);
    viewMain->addWidget(header);

    Button* Logo = new Button("Logo");
    Logo->setOnClickCallback(goToMain);
    Logo->setSize(75, 35);
    Logo->setPosition(145, 5);
    viewMain->addWidget(Logo);

    Button* buttonShop = new Button("L");
    buttonShop->setOnClickCallback(goToShop);
    buttonShop->setSize(30, 30);
    buttonShop->setPosition(290, 7);
    viewMain->addWidget(buttonShop);
	
    Button* buttonSettings = new Button("O");
    buttonSettings->setOnClickCallback(goToSettings);
    buttonSettings->setSize(30, 30);
    buttonSettings->setPosition(325, 7);
    viewMain->addWidget(buttonSettings);

    Box* footer = new Box();
    footer->setColor(15, 15, 15);
    footer->setSize(main_window->winWidth, 45);
    footer->setPosition(0, 566);
    viewMain->addWidget(footer);

    Button* BabyNCo = new Button("Baby+");
    BabyNCo->setSize(75, 35);
    BabyNCo->setPosition(5, 571);
    viewMain->addWidget(BabyNCo);

    Button* GreyBird = new Button("GreyBird");
    GreyBird->setSize(75, 35);
    GreyBird->setPosition(280, 571);
    viewMain->addWidget(GreyBird);



    Box* infoPanelBig = new Box();
    infoPanelBig->setSize(340, 180);
    infoPanelBig->setPosition(10, 65);
    infoPanelBig->setColor(15, 15, 15);
    viewMain->addWidget(infoPanelBig);

    Box* infoPanelMid = new Box();
    infoPanelMid->setSize(340, 140);
    infoPanelMid->setPosition(10, 85);
    infoPanelMid->setColor(21, 21, 21);
    viewMain->addWidget(infoPanelMid);



    Box* panelBigRefill = new Box();
    panelBigRefill->setSize(340, 140);
    panelBigRefill->setPosition(10, 260);
    panelBigRefill->setColor(15, 15, 15);
    viewMain->addWidget(panelBigRefill);

    Box* panelMidRefill = new Box();
    panelMidRefill->setSize(340, 100);
    panelMidRefill->setPosition(10, 280);
    panelMidRefill->setColor(21, 21, 21);
    viewMain->addWidget(panelMidRefill);

    Button* buttonRefill = new Button("refill");
    buttonRefill->setSize(130, 20);
    buttonRefill->setPosition(200, 335);
    buttonRefill->setColor(220, 20, 60);
    //button1->setOnClickCallback();  --> refill bottle
    viewMain->addWidget(buttonRefill);



    Box* panelBigFeed = new Box();
    panelBigFeed->setSize(340, 140);
    panelBigFeed->setPosition(10, 410);
    panelBigFeed->setColor(15, 15, 15);
    viewMain->addWidget(panelBigFeed);

    Box* panelMidFeed = new Box();
    panelMidFeed->setSize(340, 100);
    panelMidFeed->setPosition(10, 430);
    panelMidFeed->setColor(21, 21, 21);
    viewMain->addWidget(panelMidFeed);

    Button* buttonFeed = new Button("Feed Arthur");
    buttonFeed->setSize(130, 20);
    buttonFeed->setPosition(200, 485);
    buttonFeed->setColor(220, 20, 60);
    buttonFeed->setOnClickCallback(goToFeed);
    viewMain->addWidget(buttonFeed);



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
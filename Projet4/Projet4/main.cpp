#include "window.hpp"
#include <iostream>
#include "View.hpp"
#include "Button.hpp"
#include "Widget.hpp"
#include "Image.hpp"
#include "Text.hpp"
#include "ViewManager.hpp"
#include "Box.h"
#include "bottle.hpp"
#include "string"
#include "List.h"
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
    Bottle bottle;
    List list;

    Window* main_window = new Window("Baby", 360, 611);
    /*SDL_SetRenderDrawColor(main_window->GetRenderer(), 49, 49, 49, SDL_ALPHA_OPAQUE);*/
    /*main_window->ClearRenderer(main_window->GetRenderer()); */
    /*SDL_RenderPresent(renderer);*/


    //init main view
    viewMain = new View(main_window->GetSDLWindow(), main_window->GetRenderer());
    viewFeed = new View(main_window->GetSDLWindow(), main_window->GetRenderer());
    viewSettings = new View(main_window->GetSDLWindow(), main_window->GetRenderer());
    viewShop = new View(main_window->GetSDLWindow(), main_window->GetRenderer());
    viewRegurgited = new View(main_window->GetSDLWindow(), main_window->GetRenderer());
    viewMain->setFont(main_window->font);

    Box* GLOBALE = new Box();

    GLOBALE->setColor(49, 49, 49);
    GLOBALE->setPosition(0, 0);
    GLOBALE->setSize(main_window->winWidth, main_window->winHeight);
    viewMain->addWidget(GLOBALE);


    //View HomePage
    {
        Box* header = new Box();
        header->setColor(15, 15, 15);
        header->setSize(main_window->winWidth, 45);
        viewMain->addWidget(header);

        Image* imageLogo = new Image("img/logo.png");
        imageLogo->setOnClickCallback(goToMain);
        imageLogo->setSize(83, 32);
        imageLogo->setPosition(main_window->winWidth / 2 - 40, 5);
        viewMain->addWidget(imageLogo);

        Image* imageShop = new Image("img/todo.png");
        imageShop->setOnClickCallback(goToShop);
        imageShop->setSize(30, 30);
        imageShop->setPosition(280, 7);
        viewMain->addWidget(imageShop);

        Image* imageSettings = new Image("img/settings.png");
        imageSettings->setOnClickCallback(goToSettings);
        imageSettings->setSize(30, 30);
        imageSettings->setPosition(315, 7);
        viewMain->addWidget(imageSettings);

        Box* footer = new Box();
        footer->setColor(15, 15, 15);
        footer->setSize(main_window->winWidth, 45);
        footer->setPosition(0, 566);
        viewMain->addWidget(footer);

        Image* imageLogoFooter = new Image("img/logo_footer.png");
        imageLogoFooter->setSize(110, 23);
        imageLogoFooter->setPosition(10, 571);
        viewMain->addWidget(imageLogoFooter);

        Image* imageCreators = new Image("img/creators.png");
        imageCreators->setSize(93, 26);
        imageCreators->setPosition(250, 576);
        viewMain->addWidget(imageCreators);


        //Center
        Box* infoPanelBig = new Box();
        infoPanelBig->setSize(340, 180);
        infoPanelBig->setPosition(10, 65);
        infoPanelBig->setColor(15, 15, 15);
        viewMain->addWidget(infoPanelBig);
        //Border
        Box* infoPanelMid = new Box();
        infoPanelMid->setSize(340, 140);
        infoPanelMid->setPosition(10, 85);
        infoPanelMid->setColor(21, 21, 21);
        viewMain->addWidget(infoPanelMid);
        //Adding text baby informations
        Text* Title1 = new Text();
        Title1->setText("Baby's Informations");
        Title1->setColor(255, 255, 255);
        Title1->setPosition(15, 65);
        viewMain->addWidget(Title1);
        //Content
        Image* imageBottle = new Image("img/bottle.png");
        imageBottle->setSize(49, 49);
        imageBottle->setPosition(45, 120);
        viewMain->addWidget(imageBottle);
        //Adding text bottle content
        Text* bottleContent = new Text();
        bottleContent->setText("Bottle content :");
        bottleContent->setColor(255, 255, 255);
        bottleContent->setPosition(20, 170);
        viewMain->addWidget(bottleContent);
        //Adding text content variable
        Text* bottleCurrentValue = new Text();
        string s = to_string(bottle.GetBottleQuantity()) + "ml";
        char const* pchar = s.c_str();
        bottleCurrentValue->setText(pchar);
        bottleCurrentValue->setColor(255, 255, 255);
        bottleCurrentValue->setPosition(23, 185);
        viewMain->addWidget(bottleCurrentValue);
        //Adding text content variable
        Text* bottleMaxValue = new Text();
        string s2 = " / " + to_string(bottle.GetBottleVolume()) + "ml";
        char const* pchar2 = s2.c_str();
        bottleMaxValue->setText(pchar2);
        bottleMaxValue->setColor(255, 255, 255);
        bottleMaxValue->setPosition(69, 185);
        viewMain->addWidget(bottleMaxValue);

        Image* imageTimer = new Image("img/time.png");
        imageTimer->setSize(49, 49);
        imageTimer->setPosition(160, 120);
        viewMain->addWidget(imageTimer);
        //Adding text Feed Time
        Text* feedTimeText = new Text();
        feedTimeText->setText("Feed Time :");
        feedTimeText->setColor(255, 255, 255);
        feedTimeText->setPosition(145, 170);
        viewMain->addWidget(feedTimeText);
        //Adding text content variable
        Text* currentTime = new Text();
        string sCurrentTime = to_string(bottle.GetFeedIntervalH()) + " h";
        char const* pCurrentTime = sCurrentTime.c_str();
        currentTime->setText(pCurrentTime);
        currentTime->setColor(255, 255, 255);
        currentTime->setPosition(175, 185);
        viewMain->addWidget(currentTime);

        Image* imageBaby = new Image("img/baby_img.png");
        imageBaby->setSize(49, 49);
        imageBaby->setPosition(275, 120);
        viewMain->addWidget(imageBaby);
        //Adding text Quantity Baby
        Text* quantityBaby = new Text();
        quantityBaby->setText("Quantity :");
        quantityBaby->setColor(255, 255, 255);
        quantityBaby->setPosition(270, 170);
        viewMain->addWidget(quantityBaby);
        //Adding text content variable
        Text* babyQuantity = new Text();
        string sbabyQuantity = to_string(bottle.GetBabyQuantity()) + " ml";
        char const* pbabyQuantity = sbabyQuantity.c_str();
        babyQuantity->setText(pbabyQuantity);
        babyQuantity->setColor(255, 255, 255);
        babyQuantity->setPosition(280, 185);
        viewMain->addWidget(babyQuantity);


        //Center
        Box* panelBigRefill = new Box();
        panelBigRefill->setSize(340, 140);
        panelBigRefill->setPosition(10, 260);
        panelBigRefill->setColor(15, 15, 15);
        viewMain->addWidget(panelBigRefill);
        //Border
        Box* panelMidRefill = new Box();
        panelMidRefill->setSize(340, 100);
        panelMidRefill->setPosition(10, 280);
        panelMidRefill->setColor(21, 21, 21);
        viewMain->addWidget(panelMidRefill);
        //Adding text refill the bottle
        Text* Title2 = new Text();
        Title2->setText("Refill the bottle");
        Title2->setColor(255, 255, 255);
        Title2->setPosition(15, 260);
        viewMain->addWidget(Title2);
        //Content
        Image* imageBottle2 = new Image("img/bottle.png");
        imageBottle2->setSize(49, 49);
        imageBottle2->setPosition(45, 290);
        viewMain->addWidget(imageBottle2);
        //Adding text bottle content
        Text* bottleRefill = new Text();
        bottleRefill->setText("You must refill");
        bottleRefill->setColor(255, 255, 255);
        bottleRefill->setPosition(20, 340);
        viewMain->addWidget(bottleRefill);
        Text* bottleRefill2 = new Text();
        bottleRefill2->setText("the bottle");
        bottleRefill2->setColor(255, 255, 255);
        bottleRefill2->setPosition(35, 355);
        viewMain->addWidget(bottleRefill2);
        //Refill button
        Button* buttonRefill = new Button("refill");
        buttonRefill->setSize(130, 20);
        buttonRefill->setPosition(200, 335);
        buttonRefill->setColor(220, 20, 60);
        //button1->setOnClickCallback();  --> refill bottle
        viewMain->addWidget(buttonRefill);


        //Center
        Box* panelBigFeed = new Box();
        panelBigFeed->setSize(340, 140);
        panelBigFeed->setPosition(10, 410);
        panelBigFeed->setColor(15, 15, 15);
        viewMain->addWidget(panelBigFeed);
        //Border
        Box* panelMidFeed = new Box();
        panelMidFeed->setSize(340, 100);
        panelMidFeed->setPosition(10, 430);
        panelMidFeed->setColor(21, 21, 21);
        viewMain->addWidget(panelMidFeed);
        //Adding text feed my baby
        Text* Title3 = new Text();
        Title3->setText("Feed my baby");
        Title3->setColor(255, 255, 255);
        Title3->setPosition(15, 410);
        viewMain->addWidget(Title3);

        Image* imageTimer2 = new Image("img/time.png");
        imageTimer2->setSize(49, 49);
        imageTimer2->setPosition(45, 440);
        viewMain->addWidget(imageTimer2);
        //Adding text Feed Time
        Text* feedTimeLeft = new Text();
        feedTimeLeft->setText("Feed Time Left");
        feedTimeLeft->setColor(255, 255, 255);
        feedTimeLeft->setPosition(15, 490);
        viewMain->addWidget(feedTimeLeft);
        //Adding text content variable
        Text* currentTime2 = new Text();
        string sCurrentTime2 = to_string(bottle.GetFeedTimeLeftH()) + " h";
        char const* pCurrentTime2 = sCurrentTime2.c_str();
        currentTime2->setText(pCurrentTime2);
        currentTime2->setColor(255, 255, 255);
        currentTime2->setPosition(60, 505);
        viewMain->addWidget(currentTime2);
        //button feed
        Button* buttonFeed = new Button("Feed Arthur");
        buttonFeed->setSize(130, 20);
        buttonFeed->setPosition(200, 485);
        buttonFeed->setColor(220, 20, 60);
        buttonFeed->setOnClickCallback(goToFeed);
        viewMain->addWidget(buttonFeed);
    }

    //View Feed
    {
        viewFeed->setFont(main_window->font);
        //viewFeed->addWidget(GLOBALE);
        Button* button2 = new Button("PageHome");
        button2->setOnClickCallback(goToMain);
        button2->setSize(20, 20);
        viewFeed->addWidget(button2);

        Box* header = new Box();
        header->setColor(15, 15, 15);
        header->setSize(main_window->winWidth, 45);
        viewFeed->addWidget(header);

        Image* imageBack = new Image("img/back.png");
        imageBack->setSize(20, 20);
        imageBack->setPosition(15, 13);
        viewFeed->addWidget(imageBack);

        Image* imageLogo = new Image("img/logo.png");
        imageLogo->setOnClickCallback(goToMain);
        imageLogo->setSize(83, 32);
        imageLogo->setPosition(main_window->winWidth / 2 - 40, 5);
        viewFeed->addWidget(imageLogo);

        Image* imageShop = new Image("img/todo.png");
        imageShop->setOnClickCallback(goToShop);
        imageShop->setSize(30, 30);
        imageShop->setPosition(280, 7);
        viewFeed->addWidget(imageShop);

        Image* imageSettings = new Image("img/settings.png");
        imageSettings->setOnClickCallback(goToSettings);
        imageSettings->setSize(30, 30);
        imageSettings->setPosition(315, 7);
        viewFeed->addWidget(imageSettings);

        Box* footer = new Box();
        footer->setColor(15, 15, 15);
        footer->setSize(main_window->winWidth, 45);
        footer->setPosition(0, 566);
        viewFeed->addWidget(footer);

        Image* imageLogoFooter = new Image("img/logo_footer.png");
        imageLogoFooter->setSize(110, 23);
        imageLogoFooter->setPosition(10, 571);
        viewFeed->addWidget(imageLogoFooter);

        Image* imageCreators = new Image("img/creators.png");
        imageCreators->setSize(93, 26);
        imageCreators->setPosition(250, 576);
        viewFeed->addWidget(imageCreators);



        //Center
        Box* panelBigRefill = new Box();
        panelBigRefill->setSize(340, 140);
        panelBigRefill->setPosition(10, 65);
        panelBigRefill->setColor(15, 15, 15);
        viewFeed->addWidget(panelBigRefill);
        //Border
        Box* panelMidRefill = new Box();
        panelMidRefill->setSize(340, 100);
        panelMidRefill->setPosition(10, 85);
        panelMidRefill->setColor(21, 21, 21);
        viewFeed->addWidget(panelMidRefill);
        //Adding text refill the bottle
        Text* Title = new Text();
        Title->setText("How much you gave to the Baby");
        Title->setColor(255, 255, 255);
        Title->setPosition(15, 65);
        viewFeed->addWidget(Title);

        //Center
        Box* panel2 = new Box();
        panel2->setSize(340, 140);
        panel2->setPosition(10, 220);
        panel2->setColor(15, 15, 15);
        viewFeed->addWidget(panel2);
        //Border
        Box* panelMid2 = new Box();
        panelMid2->setSize(340, 100);
        panelMid2->setPosition(10, 240);
        panelMid2->setColor(21, 21, 21);
        viewFeed->addWidget(panelMid2);
        //button regurgited
        Button* buttonRegurgited = new Button("Baby regurgited his milk");
        buttonRegurgited->setSize(200, 20);
        buttonRegurgited->setPosition(80, 280);
        buttonRegurgited->setColor(220, 20, 60);
        buttonRegurgited->setOnClickCallback(goToFeed);
        viewFeed->addWidget(buttonRegurgited);
    }

    ////View Regurgited
    //{
    //    viewRegurgited->setFont(main_window->font);
    //    //viewFeed->addWidget(GLOBALE);
    //    Button* button2 = new Button("PageHome");
    //    button2->setOnClickCallback(goToMain);
    //    button2->setSize(20, 20);
    //    viewRegurgited->addWidget(button2);

    //    Box* header = new Box();
    //    header->setColor(15, 15, 15);
    //    header->setSize(main_window->winWidth, 45);
    //    viewRegurgited->addWidget(header);

    //    Image* imageBack = new Image("img/back.png");
    //    imageBack->setSize(20, 20);
    //    imageBack->setPosition(15, 13);
    //    viewRegurgited->addWidget(imageBack);

    //    Image* imageLogo = new Image("img/logo.png");
    //    imageLogo->setOnClickCallback(goToMain);
    //    imageLogo->setSize(83, 32);
    //    imageLogo->setPosition(main_window->winWidth / 2 - 40, 5);
    //    viewRegurgited->addWidget(imageLogo);

    //    Image* imageShop = new Image("img/todo.png");
    //    imageShop->setOnClickCallback(goToShop);
    //    imageShop->setSize(30, 30);
    //    imageShop->setPosition(280, 7);
    //    viewRegurgited->addWidget(imageShop);

    //    Image* imageSettings = new Image("img/settings.png");
    //    imageSettings->setOnClickCallback(goToSettings);
    //    imageSettings->setSize(30, 30);
    //    imageSettings->setPosition(315, 7);
    //    viewRegurgited->addWidget(imageSettings);

    //    Box* footer = new Box();
    //    footer->setColor(15, 15, 15);
    //    footer->setSize(main_window->winWidth, 45);
    //    footer->setPosition(0, 566);
    //    viewRegurgited->addWidget(footer);

    //    Image* imageLogoFooter = new Image("img/logo_footer.png");
    //    imageLogoFooter->setSize(110, 23);
    //    imageLogoFooter->setPosition(10, 571);
    //    viewRegurgited->addWidget(imageLogoFooter);

    //    Image* imageCreators = new Image("img/creators.png");
    //    imageCreators->setSize(93, 26);
    //    imageCreators->setPosition(250, 576);
    //    viewRegurgited->addWidget(imageCreators);



    //    //Center
    //    Box* panelBigRefill = new Box();
    //    panelBigRefill->setSize(340, 140);
    //    panelBigRefill->setPosition(10, 65);
    //    panelBigRefill->setColor(15, 15, 15);
    //    viewRegurgited->addWidget(panelBigRefill);
    //    //Border
    //    Box* panelMidRefill = new Box();
    //    panelMidRefill->setSize(340, 100);
    //    panelMidRefill->setPosition(10, 85);
    //    panelMidRefill->setColor(21, 21, 21);
    //    viewRegurgited->addWidget(panelMidRefill);
    //    //Adding text refill the bottle
    //    Text* Title = new Text();
    //    Title->setText("How much Baby regugited");
    //    Title->setColor(255, 255, 255);
    //    Title->setPosition(15, 65);
    //    viewRegurgited->addWidget(Title);

    //    //Center
    //    Box* panel2 = new Box();
    //    panel2->setSize(340, 140);
    //    panel2->setPosition(10, 220);
    //    panel2->setColor(15, 15, 15);
    //    viewRegurgited->addWidget(panel2);
    //    //Border
    //    Box* panelMid2 = new Box();
    //    panelMid2->setSize(340, 100);
    //    panelMid2->setPosition(10, 240);
    //    panelMid2->setColor(21, 21, 21);
    //    viewRegurgited->addWidget(panelMid2);
    //    //button regurgited
    //    Button* buttonRegurgited = new Button("Baby regurgited his milk");
    //    buttonRegurgited->setSize(200, 20);
    //    buttonRegurgited->setPosition(80, 280);
    //    buttonRegurgited->setColor(220, 20, 60);
    //    buttonRegurgited->setOnClickCallback(goToFeed);
    //    viewRegurgited->addWidget(buttonRegurgited);
    //}
	
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
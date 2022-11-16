#include "Box.h"

#include "View.hpp"

#include <SDL.h>
#include <SDL_ttf.h>



Box::Box()
	: boxTexture(0)
{

}

 
Box::~Box()
{
	if (this->boxTexture) {
		SDL_DestroyTexture(this->boxTexture);
	}
}

void Box::render(SDL_Renderer* renderer)
{
	const int BORDER_SIZE = 1;

	// Draw a border.
	SDL_Rect rect = { this->posX, this->posY, this->width, this->height };

	
	SDL_SetRenderDrawColor(renderer, color.getR(), color.getG(), color.getB(), 0xFF);
	SDL_RenderFillRect(renderer, &rect);

	// Draw the inside of the button.
	rect.x += BORDER_SIZE;
	rect.y += BORDER_SIZE;
	rect.w -= BORDER_SIZE * 2;
	rect.h -= BORDER_SIZE * 2;

	/*SDL_SetRenderDrawColor(renderer, color.getR(), color.getG(), color.getB(), 0xFF);
	SDL_RenderFillRect(renderer, &rect);*/


}

//void Box::onAddToView(View* v)
//{
//	// Generate label texture.
//	/*SDL_Surface* temp = TTF_RenderText_Blended(this->view->getFont(), this->label.c_str(), { 0, 0, 0, 255 });*/
//	this->boxTexture  = SDL_CreateTextureFromSurface(this->view->getSDLRenderer(), temp);
//	SDL_FreeSurface(temp);
//}

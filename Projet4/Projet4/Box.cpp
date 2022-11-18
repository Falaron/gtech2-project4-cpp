#include "Box.h"

#include "View.hpp"

#include <SDL.h>
#include <SDL_ttf.h>


// Declaration of the static member
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

	// Draw the inside of the button.
	SDL_SetRenderDrawColor(renderer, color.getR(), color.getG(), color.getB(), 0xFF);
	SDL_RenderFillRect(renderer, &rect);

	rect.x += BORDER_SIZE;
	rect.y += BORDER_SIZE;
	rect.w -= BORDER_SIZE * 2;
	rect.h -= BORDER_SIZE * 2;



}



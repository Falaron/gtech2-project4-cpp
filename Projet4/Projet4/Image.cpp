#include "Image.hpp"

#include "View.hpp"

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>



Image::Image(const char* label)
	: label(label), onClickCallback(0)
	, labelTexture(0)
{

}

Image::~Image()
{
	if (this->labelTexture) {
		SDL_DestroyTexture(this->labelTexture);
	}
}

void Image::render(SDL_Renderer* r)
{
	const int BORDER_SIZE = 1;

	// Draw a border.
	SDL_Rect rect = { this->posX, this->posY, this->width, this->height };
	SDL_RenderCopy(this->view->getSDLRenderer(), this->labelTexture, 0, &rect);
}

void Image::onAddToView(View* v)
{
	// Generate label texture.
	SDL_Surface* logoSurface = IMG_Load(this->label.c_str());
	this->labelTexture = SDL_CreateTextureFromSurface(this->view->getSDLRenderer(), logoSurface);
	SDL_FreeSurface(logoSurface);
}


void Image::onMouseClick()
{
	if (this->onClickCallback)
		this->onClickCallback();
}

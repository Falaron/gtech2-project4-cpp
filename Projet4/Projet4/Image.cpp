#include "Image.hpp"

#include "View.hpp"

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>



Image::Image(const char* label)
	: label(label), onClickCallback(0)
	, imageTexture(0)
{

}

Image::~Image()
{
	if (this->imageTexture) {
		SDL_DestroyTexture(this->imageTexture);
	}
}

void Image::render(SDL_Renderer* r)
{
	const int BORDER_SIZE = 1;

	// Draw a border.
	SDL_Rect rect = { this->posX, this->posY, this->width, this->height };
	SDL_RenderCopy(this->view->getSDLRenderer(), this->imageTexture, 0, &rect);
}

void Image::onAddToView(View* v)
{
	// Generate image texture.
	SDL_Surface* logoSurface = IMG_Load(this->label.c_str());
	this->imageTexture = SDL_CreateTextureFromSurface(this->view->getSDLRenderer(), logoSurface);
	SDL_FreeSurface(logoSurface);
}

// called when the mouse is clicking the button
void Image::onMouseClick()
{
	if (this->onClickCallback)
		this->onClickCallback();
}

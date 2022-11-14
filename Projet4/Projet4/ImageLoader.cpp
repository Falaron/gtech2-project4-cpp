#include <SDL_image.h>
#include "ImageLoader.hpp"

SDL_Texture* ImageLoader::LoadImage(const char* image, SDL_Renderer* ren)
{
	SDL_Surface* tempSurface = IMG_Load(image);
	SDL_Texture* img = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_FreeSurface(tempSurface);

	return img;
};
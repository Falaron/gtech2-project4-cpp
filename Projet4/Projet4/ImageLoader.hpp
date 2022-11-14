#pragma once

#include "window.hpp"
#include <SDL_image.h>

 class ImageLoader
 {

 public:
     ImageLoader();
     ~ImageLoader();
     static SDL_Texture *LoadImage(const char *fileName, SDL_Renderer *ren);
 };
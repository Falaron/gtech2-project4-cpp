#pragma once

#include "Window.hpp"

 class ImageLoader
 {

 public:
     ImageLoader();
     ~ImageLoader();
     static SDL_Texture *LoadImage(const char *fileName, SDL_Renderer *ren);
 };
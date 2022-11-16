#pragma once

#include "Widget.hpp"
#include "SDL_image.h"

#include <string>

struct SDL_Texture;



class Image : public Widget
{
	friend class View;

public:

	Image(const char* label = "");
	~Image();

	virtual void render(SDL_Renderer* r) override;

	virtual void onAddToView(View* v) override;

	virtual void onMouseClick() override;
<<<<<<< HEAD
	virtual void onMouseHover() override;
	virtual void onMouseUnhover() override;
=======

>>>>>>> c7aa9c055fe185227c88ca4c131f59cc3ce22b4e
	void setOnClickCallback(void (*c)()) { onClickCallback = c; }



private:

	std::string label;
	SDL_Texture* labelTexture;

	void (*onClickCallback)();
};

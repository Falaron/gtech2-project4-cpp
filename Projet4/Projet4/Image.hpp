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
    // Render the image
	virtual void render(SDL_Renderer* r) override;
    // Add ti view
	virtual void onAddToView(View* v) override;

	virtual void onMouseClick() override;

    // Callback when the button is clicked.
	void setOnClickCallback(void (*c)()) { onClickCallback = c; }



private:

	std::string label;
	SDL_Texture* imageTexture;

	void (*onClickCallback)();
};

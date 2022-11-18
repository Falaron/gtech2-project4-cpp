#pragma once

#include "Widget.hpp"

#include <string>

struct SDL_Texture;



class Text : public Widget
{
public:

	Text();
	~Text();
    // Set the text
	void setText(const char* text);

	virtual void render(SDL_Renderer*) override;

	virtual void onAddToView(View* v) override;

private:
    // Regenerate the SDL texture
	void regenerateSDLTexture();



private:

	std::string text;
	SDL_Texture* texture;
};

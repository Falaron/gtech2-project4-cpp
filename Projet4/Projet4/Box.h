#pragma once

#include "Widget.hpp"



struct SDL_Texture;



class Box : public Widget
{
	friend class View;

public:

	Box();
	~Box();

	virtual void render(SDL_Renderer* r) override;
	



private:

	
	SDL_Texture* boxTexture;

	
};

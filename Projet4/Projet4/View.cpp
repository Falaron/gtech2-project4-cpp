#include "View.hpp"

#include "Widget.hpp"

#include <SDL.h>

    // Constructor with forwareded parameters
View::View(SDL_Window* window, SDL_Renderer* renderer)
	: hoveredWidget( 0 ), font( 0 ), window(window), renderer(renderer)
{

}

View::~View()
{
	for ( Widget* w : widgets ) {
		delete w;
	}
}
// rendering the view
void View::render()
{
	// Clear screen.
	SDL_SetRenderDrawColor(renderer, backgroundColor.getR(), backgroundColor.getG(), backgroundColor.getB(), 0xFF);
	SDL_RenderClear(renderer);

	// Render widgets.
	for ( Widget* w : widgets ) {
		w->render(renderer);
	}

	// Present.
	SDL_RenderPresent(renderer);
}

// Add a widget to the view
void View::addWidget( Widget* w )
{
	widgets.push_back( w );
	w->view = this;
	w->onAddToView(this);
}

void View::setBackgroundColor(unsigned char r, unsigned char g, unsigned char b)
{
	backgroundColor = Color(r, g, b);
}
// Handle all type of events
void View::handleEvent( const SDL_Event& e )
{
	switch (e.type) {
	// Mouse down event.
	case SDL_MOUSEBUTTONDOWN:
		{
			Widget* w = this->getHoveredWidget();
			if (w) {
				w->onMouseClick();
			}
		}
		break;

	// Mouse move event.
	case SDL_MOUSEMOTION:
		{
			Widget* w = this->getHoveredWidget();

			// Mouse hover mechanic (Proceed to switch).
			if (this->hoveredWidget != w) {
				if (this->hoveredWidget) {
					this->hoveredWidget->onMouseUnhover();
				}

				this->hoveredWidget = w;

				if (this->hoveredWidget) {
					this->hoveredWidget->onMouseHover();
				}
			}
		}
		break;
	}
}

Widget* View::getHoveredWidget() const
{
	for (auto i = widgets.rbegin(); i < widgets.rend(); ++i) {
		if ((*i)->isMouseHovering()) {
			return *i;
		}
	}
	return 0;
}
// Get the pos of mouse
void View::getMousePos(int* x, int* y) const
{


	SDL_GetMouseState(x, y);
	
}
// Get the width
int View::getWidth() const
{
	int w;
	SDL_GetWindowSize(window, &w, 0);
	return w;
}
// Get the height
int View::getHeight() const
{
	int h;
	SDL_GetWindowSize(window, 0, &h);
	return h;
}

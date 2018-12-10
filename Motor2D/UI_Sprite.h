#ifndef _UI_WINDOW_
#define _UI_WINDOW_

#include "UI_Element.h"
#include "SDL\include\SDL.h"
class UI_Sprite : public UI_Element
{
public:
	UI_Sprite(iPoint pos, j1Module* callback);
	virtual ~UI_Sprite();

	virtual void Draw();

protected:
	SDL_Texture* tex;
};

#endif //_UI_WINDOW_
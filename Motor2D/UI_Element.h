#ifndef _UI_ELEMENT_
#define _UI_ELEMENT_

#include "p2Point.h"
#include "p2List.h"
#include "j1Module.h"

enum UiElemType
{
	NONE,
	SPRITE,
	LABEL,
	BUTTON,
	WINDOW,
};

#include "SDL\include\SDL.h"

class UI_Element
{
public:
	UI_Element(UiElemType type, iPoint pos, j1Module* callback);
	virtual ~UI_Element();

	virtual bool PreUpdate(float d_time) { return true; };
	virtual bool Update(float d_time) { return true; };
	virtual bool CleanUp() { return true; };
	virtual void Draw() { return; };
	virtual void SetArea(uint w, uint h) { return; };

public:

	UiElemType			type;
	SDL_Rect			world_area;
	iPoint				position;

protected:

	j1Module * callback = nullptr;
};

#endif //_UI_ELEMENT_
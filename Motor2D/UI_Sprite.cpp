#include "UI_Sprite.h"
#include "j1App.h"
#include "j1Render.h"

UI_Sprite::UI_Sprite(iPoint pos, j1Module* callback) : UI_Element(WINDOW, pos, callback)
{

}

UI_Sprite::~UI_Sprite()
{

}

void UI_Sprite::Draw()
{
	App->render->Blit()
}

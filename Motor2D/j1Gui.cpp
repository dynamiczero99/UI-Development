#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"

j1Gui::j1Gui() : j1Module()
{
	name.create("gui");
}

// Destructor
j1Gui::~j1Gui()
{}

// Called before render is available
bool j1Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");

	return ret;
}

// Called before the first frame
bool j1Gui::Start()
{
	atlas = App->tex->Load(atlas_file_name.GetString());

	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	for (p2List_item<UI_Element*>* iterator = uiList.start; iterator; iterator = iterator->next)
	{
		iterator->data->Update();
	}
	return true;
}

bool j1Gui::Update(float dt)
{
	

	return true;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{
	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");

	return true;
}

UI_Element * j1Gui::CreateUIElement(UiElemType type, iPoint position, j1Module * callback, SDL_Rect* texSection)
{
	UI_Element* ret = nullptr;

	switch (type)
	{
	case SPRITE:
		ret = new UI_Sprite(atlas, texSection, position, callback);
	}

	if (ret != nullptr)
	uiList.add(ret);

	return ret;
}

// const getter for atlas
const SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}

// class Gui ---------------------------------------------------


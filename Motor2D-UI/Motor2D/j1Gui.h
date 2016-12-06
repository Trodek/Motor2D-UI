#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include "UIElement.h"
#include "p2Stack.h"
#include "p2PQueue.h"

// TODO 1: Create your structure of classes

// ---------------------------------------------------

enum Reaction {
	MouseEnter, MouseLeave, RightClick, LeftClick, RightClickUp, LeftClickUp, Tab, Drag, None
};

class UIElement;

class j1Gui : public j1Module
{
public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Update Elements
	bool Update(float dt);

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	void UIReaction(UIElement* element, int react);

	// TODO 2: Create the factory methods
	// Gui creation functions

	SDL_Texture* GetAtlas() const;

	UIElement* CreateUIElement(UItypes type, int pos_x, int pos_y, int w = 0, int h = 0, UIElement* parent = nullptr);

private:

	SDL_Texture* atlas;
	p2SString atlas_file_name;

	p2List<UIElement*> UIelements;
	p2PQueue<UIElement*> draw_queue;
	p2Stack<UIElement*> react_stack;

	iPoint last_mouse;

public:
	UIElement* focused_element = nullptr;
};

#endif // __j1GUI_H__
#ifndef _UIELEMENT_
#define _UIELEMENT_

#include "SDL\include\SDL.h"

class j1Module;

enum UItypes {
	CheckBox, InputText, OutputField, Button, Label, Image, Window, Unknow
};

class UIElement {
public:
	UIElement(): type(Unknow){}
	UIElement(UItypes type, int pos_x, int pos_y, UIElement* parent, bool can_react = true, int width = 0, int height = 0): type(type),
		parent(parent),can_react(can_react), position({pos_x, pos_y, width, height})
	{
		if (parent != nullptr) {
			priority = parent->priority + 1;
			SetPos(pos_x, pos_y);
		}
	}
	virtual bool Update()
	{
		return true;
	}

	virtual void Draw() {}

	UItypes GetType()const { return type; }
	
	void SetPos(int x, int y) {
		if (!is_static) {
			position.x = x; 
			position.y = y;
		}
	}

	int GetPriority()const {
		return priority;
	}

	iPoint GetPosition()const {
		if (parent != nullptr) {
			return{ position.x + parent->GetPosition().x,position.y + parent->GetPosition().y };
		}
		else return{ position.x,position.y };
	}

	iPoint GetLocalPosition()const {
		return{ position.x,position.y };
	}

	UIElement* GetParent()const {
		return parent;
	}

public:
	SDL_Rect position;
	bool can_react = true;
	bool mouse_over = false;
	j1Module* listener;
	bool is_static = false;
	iPoint last_position;
private:
	UItypes type;
	UIElement* parent = nullptr;
	int priority = 0;

private:

};

#endif
#ifndef _UISTATICIMAGE_
#define _UISTATICIMAGE_

#include "UIElement.h"
#include "j1Render.h"
#include "j1Gui.h"
#include "j1App.h"

class UIImage : public UIElement {
public:

	UIImage() : UIElement(Image, 0, 0,nullptr) {}
	UIImage(int pos_x, int pos_y, int w, int h, UIElement* parent) : UIElement(Image, pos_x, pos_y, parent, true, w, h) {  }

	UIImage(UItypes type, int x, int y, UIElement* parent, bool can_react = true, int width = 0, int height = 0) : UIElement(type, x, y, parent, can_react, width, height) {  }

	void InnerDraw() {
		App->render->Blit(App->gui->GetAtlas(), draw_offset.x, draw_offset.y, &image_rect,false);
	}

	void SetRect(SDL_Rect img_rect) {
		image_rect = img_rect;
	}

public:
	SDL_Rect image_rect = { 0,0,0,0 };
private:
	
private:

};

#endif
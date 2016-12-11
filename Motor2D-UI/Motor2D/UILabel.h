#ifndef _UILABEL_
#define _UILABEL_

#include "UIElement.h"
#include "p2SString.h"
#include "j1App.h"
#include "j1Fonts.h"

class UILabel : public UIElement {
public:

	UILabel() : UIElement(Label, 0, 0, nullptr) {	}
	UILabel(int pos_x, int pos_y, int w, int h, UIElement* parent) : UIElement(Label, pos_x, pos_y, parent, true, w, h){}
	UILabel(UItypes type, int pos_x, int pos_y, int w, int h, UIElement* parent) : UIElement(type, pos_x, pos_y, parent, true, w, h) {}

	void InnerDraw() {
		text_texture = App->font->Print(text.GetString());
		SDL_QueryTexture(text_texture, NULL, NULL, &texture_rect.w, &texture_rect.h);

		App->render->Blit(text_texture, position.x, position.y,&texture_rect,false);
	}

	void SetText(char* txt) {
		text = txt;
	}

public:
	p2SString text = "";
	SDL_Texture* text_texture;
	SDL_Rect texture_rect = { 0, 0, 0, 0 };
private:
	
};

#endif
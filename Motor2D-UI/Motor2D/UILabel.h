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
		if (text_texture != nullptr)
			SDL_DestroyTexture(text_texture);
		text_texture = App->font->Print(text.c_str());
		SDL_QueryTexture(text_texture, NULL, NULL, &texture_rect.w, &texture_rect.h);
		App->render->Blit(text_texture, draw_offset.x, draw_offset.y,&texture_rect,false);
	}

	void SetText(char* txt) {
		text = txt;
	}

public:
	std::string text = "";
	SDL_Texture* text_texture;
	SDL_Rect texture_rect = { 0, 0, 0, 0 };
private:
	
};

#endif
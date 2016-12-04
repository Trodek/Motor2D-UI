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
		App->render->Blit(App->font->Print(text.GetString()), position.x, position.y,NULL,false);
	}

	void SetText(char* txt) {
		text = txt;
	}

public:
	p2SString text;
private:
};

#endif
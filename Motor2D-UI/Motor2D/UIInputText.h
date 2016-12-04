#ifndef _UIINPUTTEXT_
#define _UIINPUTTEXT_

#include "UILabel.h"
#include "j1Gui.h"
#include "p2SString.h"
#include "j1Render.h"
#include "j1App.h"
#include "j1Fonts.h"

class UIInputText : public UILabel {
public:
	UIInputText(int x, int y, int w, int h, UIElement* parent) : UILabel(InputText, x, y, w, h, parent){}
	~UIInputText(){}

	void Draw() {
		iPoint pos = GetPosition();
		App->render->Blit(App->font->Print(text.GetString()), pos.x, pos.y, NULL, false);
	}
	bool Update() {
		if (App->gui->focused_element == this) {
			App->render->DrawQuad({ GetPosition().x, GetPosition().y, 1, 3 }, 0, 0, 0);
		}
	}

	void SetDefaultText(char* text) {
		default_text = text;
	}
private:
	uint cursor_position;
	p2SString default_text;
};

#endif
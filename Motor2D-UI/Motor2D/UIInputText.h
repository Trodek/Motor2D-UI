#ifndef _UIINPUTTEXT_
#define _UIINPUTTEXT_

#include "UILabel.h"
#include "j1Gui.h"
#include "p2SString.h"
#include "j1Render.h"
#include "j1App.h"
#include "j1Fonts.h"
#include "j1Input.h"

class UIInputText : public UILabel {
public:
	UIInputText(int x, int y, int w, int h, UIElement* parent) : UILabel(InputText, x, y, w, h, parent){}
	~UIInputText(){}

	void InnerDraw() {
		text_texture = App->font->Print(text.GetString());
		SDL_QueryTexture(text_texture, NULL, NULL, &texture_rect.w, &texture_rect.h);
		App->render->Blit(text_texture, position.x, position.y, &texture_rect, false);
		if (App->gui->focused_element == this)
			App->render->DrawQuad({ position.x+cursor_position, position.y, 2, position.h }, 255U, 255U, 255U, 255U);
	}
	bool Update() {
		if (App->gui->focused_element == this) {
			if (!active) {
				active = true;
				text.Clear();
				App->input->StartInputText(&text, &cursor_position);
			}

		}
		else {
			if (text.Length() < 1 && active) 
				text = default_text;
			if (active) {
				active = false;
				if(App->input->input_text == &text)
					App->input->EndInputText();
			}
		}
		return true;
	}

	void SetDefaultText(char* text) {
		default_text = text;
	}
private:
	int cursor_position;
	p2SString default_text;
	bool active = true;
};

#endif
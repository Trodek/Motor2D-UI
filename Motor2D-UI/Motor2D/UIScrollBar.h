#ifndef _UISCROLLBAR_
#define _UISCROLLBAR_

#include "UIElement.h"
#include "UIImage.h"
#include "j1App.h"
#include "j1Gui.h"

class UIScrollBar :public UIElement {
public:
	UIScrollBar(int x, int y, int w, int h, UIElement* parent) : UIElement(ScrollBar, x, y, parent, true, w, h)	{	}

	~UIScrollBar(){}

	void SetBar(int rect_x, int rect_y, int w, int h) 
	{
		bar = (UIImage*)App->gui->CreateUIElement(Image, (position.w - w) / 2, (position.h - h) / 2, w, h, this);
		bar->SetRect({ rect_x,rect_y,w,h });
		bar->can_react = false;
	}

	void SetScroll(int rect_x, int rect_y, int w, int h)
	{
		scroll = (UIImage*)App->gui->CreateUIElement(Image, 0, 0, w, h, this);
		scroll->SetRect({ rect_x,rect_y,w,h });
	}

	bool Update() 
	{
		if (position.w > position.h) {
			//scroll->position.y = 0;
			if (pos_diff != scroll->GetLocalPosition().x - bar->GetLocalPosition().x) {
				pos_diff = scroll->GetLocalPosition().x - bar->GetLocalPosition().x;
				target->Scroll('h', (float)pos_diff / (float)(bar->position.w - scroll->position.w)); //horizontal scrollbar
			}
		}
		else if (position.h > position.w) {
			//scroll->position.x = 0;
			if (pos_diff != scroll->GetLocalPosition().y - bar->GetLocalPosition().y) {
				pos_diff = scroll->GetLocalPosition().y - bar->GetLocalPosition().y;
				target->Scroll('v', (float)pos_diff / (float)(bar->position.h - scroll->position.h)); //verticall scrollbar
			}
		}
		return true;
	}

private:
	UIImage* bar;
	UIImage* scroll;
	int pos_diff = 0;

public:

	UIElement* target;
};

#endif // !_UISCROLLBAR_


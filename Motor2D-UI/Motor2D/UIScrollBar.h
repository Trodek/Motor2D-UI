#ifndef _UISCROLLBAR_
#define _UISCROLLBAR_

#include "UIElement.h"
#include "UIStaticImage.h"
#include "j1App.h"
#include "j1Gui.h"

class UIScrollBar :public UIElement {
public:
	UIScrollBar(int x, int y, int w, int h, UIElement* parent) : UIElement(ScrollBar, x, y, parent, true, w, h)	{	}

	~UIScrollBar(){}

	void SetBar(int rect_x, int rect_y, int w, int h) 
	{
		bar = (UIStaticImage*)App->gui->CreateUIElement(Image, position.x + (position.w - w) / 2, position.y + (position.h - h) / 2, w, h, this);
		bar->SetRect({ rect_x,rect_y,w,h });
		bar->can_react = false;
	}

	void SetScroll(int rect_x, int rect_y, int w, int h)
	{
		scroll = (UIStaticImage*)App->gui->CreateUIElement(Image, bar->GetLocalPosition().x, bar->GetLocalPosition().y, w, h, bar);
		scroll->SetRect({ rect_x,rect_y,w,h });
	}


private:
	UIStaticImage* bar;
	UIStaticImage* scroll;

public:

	UIElement* target;
};

#endif // !_UISCROLLBAR_


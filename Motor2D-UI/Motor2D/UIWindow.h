#ifndef _UIWINDOW_
#define _UIWINDOW_

#include "UIImage.h"
#include "p2SString.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1App.h"
#include "j1Gui.h"

class UIWindow : public UIImage {
public:
	//Constructor
	UIWindow(int x, int y, int w, int h, UIElement* parent) : UIImage(Window, x, y, parent, true, w, h)
	{
	}
	// Destructor
	~UIWindow() {}

	// Draw
	void InnerDraw()
	{
		if (visible){
			App->render->Blit(App->gui->GetAtlas(), draw_offset.x, draw_offset.y, &image_rect, false); 
		}
	}

public:
	bool visible = true;
private:

private:
};
#endif // !_UIBUTTON_

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
	UIWindow(int x, int y, int w, int h, UIElement* parent) : UIImage(Button, x, y, parent, true, w, h)
	{
	}
	// Destructor
	~UIWindow() {}

	// Draw
	void Draw()
	{
		if (visible){
			iPoint pos = GetPosition();
			App->render->Blit(App->gui->GetAtlas(), pos.x, pos.y, &image_rect, false); 
		}
	}

public:
	bool visible = true;
private:

private:
};
#endif // !_UIBUTTON_

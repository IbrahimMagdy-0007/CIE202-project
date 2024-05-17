#include "toolbar.h"
#include "game.h"
//#include "grid.h"


////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
toolbar::toolbar(game* pG)
{	
	height = config.toolBarHeight;
	width = config.windWidth;
	this->pGame = pG;
	window* pWind = pGame->getWind();
	
	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each toolbar item
	toolbarItemImages[ITM_SIGN] = "images\\toolbarItems\\toolbar_sign.jpg";
	toolbarItemImages[ITM_Robot] = "images\\toolbarItems\\toolbar_robot.jpg";
	toolbarItemImages[ITM_CAR] = "images\\toolbarItems\\toolbar_Car.jpg";
	toolbarItemImages[ITM_BOAT] = "images\\toolbarItems\\toolbar_Boat.jpg";
	toolbarItemImages[ITM_ROCKET] = "images\\toolbarItems\\toolbar_Rocket.jpg";
	toolbarItemImages[ITM_HOME] = "images\\toolbarItems\\toolbar_Home.jpg";
	toolbarItemImages[ITM_INCREASE] = "images\\toolbarItems\\toolbar_INC.jpg";
	toolbarItemImages[ITM_DECREASE] = "images\\toolbarItems\\toolbar_DEC.jpg";
	toolbarItemImages[ITM_ROTATE] = "images\\toolbarItems\\toolbar_ROT.jpg";
	toolbarItemImages[ITM_REFRESH] = "images\\toolbarItems\\toolbar_REF.jpg";
	toolbarItemImages[ITM_HINT] = "images\\toolbarItems\\toolbar_HINT.jpg";
	toolbarItemImages[ITM_DELETE] = "images\\toolbarItems\\toolbar_DEL.jpg";
	toolbarItemImages[ITM_SAVE] = "images\\toolbarItems\\toolbar_SAVE.jpg";
	toolbarItemImages[ITM_SELECT] = "images\\toolbarItems\\toolbar_SELECT.jpg";
	toolbarItemImages[ITM_EXIT] = "images\\toolbarItems\\toolbar_Exit.jpg";
	toolbarItemImages[ITM_INCREASE] = "images\\toolbarItems\\toolbar_INC.jpg";
	toolbarItemImages[ITM_EXIT] = "images\\toolbarItems\\toolbar_Exit.jpg";

	//TODO: Prepare image for each toolbar item and add it to the list

	//Draw toolbar item one image at a time
	for (int i = 0; i < ITM_CNT; i++)
		pWind->DrawImage(toolbarItemImages[i], i * config.toolbarItemWidth, 0, config.toolbarItemWidth, height);


	//Draw a line under the toolbar
	pWind->SetPen(DARKBLUE, 3);
	pWind->DrawLine(0, height,width , height);
}



//handles clicks on toolbar icons, returns ITM_CNT if the click is not inside the toolbar
toolbarItem toolbar::getItemClicked(int x)
{
	
	if (x > ITM_CNT * config.toolbarItemWidth)	//click outside toolbar boundaries
		return ITM_CNT;
	
	
	//Check whick toolbar item was clicked
	//==> This assumes that toolbar items are lined up horizontally <==
	//Divide x coord of the point clicked by the icon width (int division)
	//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

	return (toolbarItem)(x / config.toolbarItemWidth);

}


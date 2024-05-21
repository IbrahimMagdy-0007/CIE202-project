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

	toolbarItemImages[ITM_Actual_Lives] = to_string(pGame->getCurrentLives());
	toolbarItemImages[ITM_String_Lives] = " Lives: ";
	toolbarItemImages[ITM_String_Score] = "Score = ";
	toolbarItemImages[ITM_Actual_Score] = to_string(pGame->getCurrentScore());
	toolbarItemImages[ITM_String_Level] = "Level = ";
	toolbarItemImages[ITM_Actual_Level] = to_string(pGame->getCurrentGameLevel());

	//TODO: Prepare image for each toolbar item and add it to the list

	//Draw toolbar item one image at a time
	//Draw toolbar item one image at a time
	for (int i = 0; i < ITM_CNT; i++)
	{
		if (i < 15)
			pWind->DrawImage(toolbarItemImages[i], i * config.toolbarItemWidth, 0, config.toolbarItemWidth, height);
		//pWind->DrawImage()
		else if (i == 15)
		{
			pWind->SetPen(RED, 200);
			pWind->SetFont(20, BOLD, BY_NAME);
			pWind->DrawString(i * config.toolbarItemWidth + 1, 0, toolbarItemImages[i]);
		}
		else if (i == 16)
		{
			pWind->SetPen(BLACK, 20);
			pWind->SetFont(20, BOLD, BY_NAME);
			pWind->DrawString((i - 1) * config.toolbarItemWidth + 20, 0, toolbarItemImages[i]);
		}
		else if (i == 17)
		{
			pWind->SetPen(BLACK, 20);
			pWind->SetFont(20, BOLD, BY_NAME);
			pWind->DrawString((i - 2) * config.toolbarItemWidth + 1, 18, toolbarItemImages[i]);
		}
		else if (i == 18)
		{
			pWind->SetPen(BLACK, 20);
			pWind->SetFont(20, BOLD, BY_NAME);
			pWind->DrawString((i - 3) * config.toolbarItemWidth + 65, 18, toolbarItemImages[i]);
		}
		else if (i == 19)
		{
			pWind->SetPen(BLACK, 20);
			pWind->SetFont(20, BOLD, BY_NAME);
			pWind->DrawString((i - 4) * config.toolbarItemWidth + 1, 35, toolbarItemImages[i]);
		}
		else if (i == 20)
		{
			pWind->SetPen(BLACK, 20);
			pWind->SetFont(20, BOLD, BY_NAME);
			pWind->DrawString((i - 5) * config.toolbarItemWidth + 60, 35, toolbarItemImages[i]);
		}
	}



	//Draw a line under the toolbar
	pWind->SetPen(DARKBLUE, 3);
	pWind->DrawLine(0, height, width, height);
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

void toolbar::settimer(int newtime)
{
	timer = newtime;
}

void toolbar::updatetime()
{

	window* mywindow;
	mywindow = pGame->getWind();
	mywindow->SetPen(LAVENDER);
	mywindow->SetBrush(LAVENDER);
	mywindow->DrawRectangle(1250,10,1350,30);
	mywindow->SetPen(BLACK);
	mywindow->SetFont(24, BOLD, BY_NAME, "Arial");
	mywindow->DrawString(1260, 12, "timer");
	mywindow->DrawInteger(1320, 12, timer);

}
int toolbar::gettime()
{
	return timer;
}

void toolbar::updateLevel() {

	toolbarItemImages[ITM_Actual_Level] = to_string(pGame->getCurrentGameLevel());
	window* pWind = pGame->getWind();
	pWind->SetPen(BLACK, 20);
	pWind->SetFont(20, BOLD, BY_NAME);
	pWind->DrawString((ITM_Actual_Level - 5) * config.toolbarItemWidth + 60, 35, toolbarItemImages[ITM_Actual_Level]);
}
void toolbar::updateLives() {

	toolbarItemImages[ITM_Actual_Lives] = to_string(pGame->getCurrentLives());


	window* pWind = pGame->getWind();
	pWind->SetPen(BLACK, 20);
	pWind->SetFont(20, BOLD, BY_NAME);
	pWind->DrawString((ITM_Actual_Lives - 5) * config.toolbarItemWidth + 60, 35, toolbarItemImages[ITM_Actual_Lives]);
}

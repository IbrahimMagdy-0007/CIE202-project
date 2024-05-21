#pragma once
#include "gameConfig.h"
////////////////////////////////////////////////////  class toolbar   //////////////////////////////////////////////
class game;
class toolbar
{

private:
	int height, width;	
	string toolbarItemImages[ITM_CNT]; //array to hold paths to images of diffrent items in the toolbar
	game* pGame;
	int timer;
public:
	toolbar(game* r_pGame);
	toolbarItem getItemClicked(int x);	//handles clicks on toolbar icons, returns the "enum" of the clicekd item
	void settimer(int newtime);
	void updatetime();
	void updateLevel();
	void updateLives();
	int gettime();
};


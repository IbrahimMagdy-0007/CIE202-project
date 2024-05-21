#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"


//The folowing struct contains all game configurations
// (MAY be loaded from a configuration file later)
__declspec(selectany) //This line to prevent "redefinition error"
struct 		
{
	int	windWidth=1400, windHeight=600,	//Window width and height
		wx=5, wy=5,			//Window starting coordinates

		//The window is divded into 3 areas: toolbar, Working area, and statusbar
		toolBarHeight=60,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		toolbarItemWidth = 70,			//Width of each icon in toolbar
		statusBarHeight=50;	//Status Bar Height
	
	int remainingHeight = windHeight - toolBarHeight - statusBarHeight;

	int gridHeight = int(remainingHeight * (2 / 3.0)); 		//The grid is where bricks can be drawn

	//Default colors
	color	penColor = RED,			//color used to draw borders/write messages
			fillColor = BLUE,			//shapes fill color (Default)
			bkGrndColor= LAVENDER,		//Screen Background color
			statusBarColor = LIGHTSEAGREEN;	//background color of the status
	int penWidth=3;			//width of the pen that draws shapes


	color gridDotsColor = RED;
	int gridSpacing=30;	//spacing between grid points

	////// Configuration for the composite shapes //////
	// default Ref Point for any newly created shape 
	int RefX = windWidth *  (2.0 / 3);
	int RefY = windHeight * (0.5);

	////-----  Sign Shape Confoguration ---------////
	// For the Sign shape, define width and height of both rectangles
	struct {
		int baseWdth = 20, baseHeight = 80;
		int topWdth = 100, topHeight = 50;
	}sighShape;

	struct {
		int bodyWidth =100 , bodyHeight = 40; // Dimensions for the car body
		int wheel1Radius = 15, wheel2Radius = 15;
		int headWidth = 25, headHight = 10;
	}carShape;
	
	struct {
		int bodyWidth = 50, bodyHeight = 100; // Dimensions for the robot body
		int headRadius = 20; // Radius for the robot head
		int eyeRadius = 5; // Radius for the robot eyes
		int footWidth = 20, footHeight = 100; // Dimensions for the robot feet
	}RobotShape;
	
	struct {
		int hullWidth = 50, hullHeight = 20; // Dimensions for the boat hull
		int cabinWidth = 150, cabinHeight = 50; // Dimensions for the boat cabin
		int mastWidth = 10, mastHeight = 80; // Dimensions for the boat mast
		int sailWidth = 60, sailHeight = 60;// Dimensions for the boat sail
		int flagradius = 20;
	}BoatShape;

	struct {
		int bodyWidth = 50, bodyHeight = 150; // Dimensions for the rocket body
		int finWidth = 100, finHeight = 25; // Dimensions for the fins
		int topWidth = 50, topHeight = 25; // Dimensions for the nose cone
	}RocketShape;

	struct {
		int bodyWidth = 150, bodyHeight = 100; // Dimensions for the home body
		int roofWidth = 100, roofHeight = 40; // Dimensions for the home roof
		int doorWidth = 50, doorHeight =70 ; // Dimensions for the home door
	}HomeShape;

}config;


enum toolbarItem //The items of the  toolbar (you should add more items)
{
	//Note: Items are ordered here as they appear in the toolbar
	//If you want to change the toolbar items order, just change the order here
	ITM_SIGN,//Sign shape item
	ITM_Robot,
	ITM_ROCKET,
	ITM_CAR,
	ITM_BOAT,
	ITM_HOME,
	ITM_INCREASE,
	ITM_DECREASE,
	ITM_ROTATE,
	ITM_REFRESH,
	ITM_HINT,
	ITM_DELETE,
	ITM_SAVE,
	ITM_SELECT,
	ITM_EXIT,
	ITM_Actual_Lives,
	ITM_String_Lives,
	ITM_String_Score,
	ITM_Actual_Score,
	ITM_String_Level,
	ITM_Actual_Level,
	ITM_CNT	//no. of toolbar items ==> This should be the last line in this enum

};




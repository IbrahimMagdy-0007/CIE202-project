#include "game.h"
#include "gameConfig.h"



game::game()
{


	toolbarItemNames[ITM_SIGN] = "Sign";
	toolbarItemNames[ITM_Robot] = "Robot";
	toolbarItemNames[ITM_CAR] = "Car";
	toolbarItemNames[ITM_BOAT] = "Boat";
	toolbarItemNames[ITM_ROCKET] = "Rocket";
	toolbarItemNames[ITM_HOME] = "Home";
	toolbarItemNames[ITM_INCREASE] = "Increase";
	toolbarItemNames[ITM_DECREASE] = "Decrease";
	toolbarItemNames[ITM_ROTATE] = "Rotate";
	toolbarItemNames[ITM_REFRESH] = "Refresh";
	toolbarItemNames[ITM_HINT] = "Hint";
	toolbarItemNames[ITM_DELETE] = "Delete";
	toolbarItemNames[ITM_SAVE] = "Save";
	toolbarItemNames[ITM_SELECT] = "Select";
	toolbarItemNames[ITM_EXIT] = "Exit";


	//Create the main window
	createWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//Create and draw the toolbar
	createToolBar();

	//Create and draw the grid
	createGrid();
	shapesGrid->draw();	//draw the grid and all shapes it contains.

	//Create and clear the status bar
	clearStatusBar();
}

game::~game()
{
	delete pWind;
	delete shapesGrid;
}


//////////////////////////////////////////////////////////////////////////////////////////
void game::createWind(int w, int h, int x, int y)
{
	pWind = new window(w, h, x, y);
	pWind->SetBrush(config.bkGrndColor);
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->DrawRectangle(0, 0, w, h);
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the mode
void game::createToolBar()
{
	gameToolbar = new toolbar(this);
}

void game::createGrid()
{
	//calc some grid parameters
	point gridUpperLeftPoint = { 0, config.toolBarHeight };
	int gridHeight = config.windHeight - config.toolBarHeight - config.statusBarHeight;
	//create the grid
	shapesGrid = new grid(gridUpperLeftPoint, config.windWidth, gridHeight, this);
}
int level = 0;
operation* game::createRequiredOperation(toolbarItem clickedItem)
{
	operation* op = nullptr;
	switch (clickedItem)
	{
	case ITM_SIGN:
		op = new operAddSign(this);
		break;
	case ITM_Robot:
		op = new operaaddrobot(this);
		break;
	case ITM_CAR:
		op = new operaddcar(this);
		break;
	case ITM_BOAT:
		op = new operaddboat(this);
		break;
	case ITM_ROCKET:
		op = new operaddrocket(this);
		break;
	case ITM_HOME:
		op = new operaddhome(this);
		break;
	case ITM_INCREASE:
		op = new resizeUp(this);
		break;
	case ITM_DECREASE:
		op = new resizeDown(this);
		break;
	case ITM_ROTATE:
		op = new operRotate(this);
		break;
	case ITM_REFRESH:
		op = new operRefresh(this);
		break;
	case ITM_HINT:
		op = new operHint(this);
		break;
	case ITM_DELETE:
		op = new operDelete(this);
		break;
	case ITM_SAVE:
		op = new operSave(this);
		break;
	case ITM_SELECT:
		op = new operSelect(this);
		break;
	case ITM_EXIT:
		op = new operExit(this);
		break;
	}
	return op;
}

//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}
void game::cleanUp() {
	

	if (shapesGrid != nullptr) {
		delete shapesGrid;
		shapesGrid = nullptr;
	}
}


window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}
void game::levelUp() {

	Current_gameLevel++;
	getToolbar()->updateLevel();
}



string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return shapesGrid;
}



////////////////////////////////////////////////////////////////////////
void game::run()
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	int test;
	bool isExit = false;
	operation* op;
	char keyPressed;
	int timer = clock();
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - SHAPE HUNT (CIE 101 / CIE202 - project) - - - - - - - - - -");
	toolbarItem clickedItem = ITM_CNT;
	do
	{
	
		if (clock() - timer > 1000)
		{
			timer = clock();
			timecounter--;
			gameToolbar->settimer(timecounter);
			gameToolbar->updatetime();
			test = gameToolbar->gettime();
			if (test <= 0)
			{
				setCurrentLives(getCurrentLives() - 1);
				gameToolbar->settimer(500);
			}

		}
		//printMessage("Ready...");
		//1- Get user click
		pWind->GetMouseClick(x, y);    //Get the coordinates of the user click
		//2-Explain the user click
		//If user clicks on the Toolbar, ask toolbar which item is clicked
		if (y >= 0 && y < config.toolBarHeight)
		{
			clickedItem = gameToolbar->getItemClicked(x);

			// Print a message to the status bar
			string message = "Clicked on " + toolbarItemNames[clickedItem];
			printMessage(message);

			//3-create the approp operation accordin to item clicked by the user
			operation* op = createRequiredOperation(clickedItem);
			if (op)
				op->Act();

			//4-Redraw the grid after each action
			shapesGrid->draw();

		}
		pWind->GetKeyPress(keyPressed);
		if (shapesGrid->getActiveshape() != nullptr) {
			if (keyPressed) {
				if (keyPressed == 8 || keyPressed == 'w') {
					printMessage("ARROW_UP/W is being clicked");
					op = new moveup(this);
					op->Act();
					shapesGrid->draw();
				}
				else if (keyPressed == 2 || keyPressed == 's') {
					printMessage("ARROW_DOWN/S is being clicked");
					op = new movedown(this);
					op->Act();
					shapesGrid->draw();
				}
				else if (keyPressed == 6 || keyPressed == 'd') {
					printMessage("ARROW_RIGHT/D is being clicked");
					op = new moveright(this);
					op->Act();
					shapesGrid->draw();
				}
				else if (keyPressed == 4 || keyPressed == 'a') {
					printMessage("ARROW_LEFT/A is being clicked");
					op = new moveleft(this);
					op->Act();
					shapesGrid->draw();
				}
				shapesGrid->detectmatching();
			}
		}
		
	}while (clickedItem != ITM_EXIT);
}





int game::getCurrentGameLevel() const
{
	return Current_gameLevel;
}

int game::getCurrentLives() const
{
	return Lives;
}

int game::getCurrentScore() const
{
	return Current_score;
}

void game::setCurrentScore(int num)
{
	Current_score = num;
}
void game::setCurrentLives(int l)
{
	Lives = l;
}

void game::setCurrentGameLevel(int level)
{
	Current_gameLevel = level;
}
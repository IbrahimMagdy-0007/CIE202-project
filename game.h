#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "operations.h"
#include "grid.h"
#include "ctime"


//Main class that coordinates the game operation
class game
{

	/// Add more members if needed
	bool is_game_saved;
	toolbar* gameToolbar;
	
	window* pWind;	//Pointer to the CMU graphics window
	grid* shapesGrid;
	int Current_gameLevel = 1;
	int Lives = 5;
	int Current_score = 0;
	int timecounter = 500;

public:
	game();
	~game();

	string getSrting() const;	 //Returns a string entered by the user
	void createWind(int, int, int, int); //creates the game window
	void clearStatusBar() const;	//Clears the status bar
	void printMessage(string msg) const;	//Print a message on Status bar
	void createToolBar();		//creates the toolbar
	void createGrid();         //creates the shapes grid
	//void Decrementscore();
	//void Decrementlevel();
	
	
	window* getWind() const;		//returns a pointer to the graphics window
	grid* getGrid() const;		//returns a pointer to the shapes grid

	//creates an operation according to the toolbar item clicked
	operation* createRequiredOperation(toolbarItem clickedItem);

	std::string toolbarItemNames[ITM_CNT];
	int getCurrentGameLevel() const;
	int getCurrentLives() const;
	int getCurrentScore() const;
	void setCurrentScore(int num);
	void cleanUp();

	void run();	//start the game
	void setCurrentGameLevel(int level);
	bool isSaved() const {
		return is_game_saved;
	}

	void setSaved(bool isSaved) {
		is_game_saved = isSaved;
	}
	toolbar* getToolbar() {
		return gameToolbar;
	}
	void levelUp();
	void decreaseLives(int amount) {
		// Decrease the lives
		Lives -= amount;

		// Update the lives on the toolbar
		getToolbar()->updateLives();
	}
	void setCurrentLives(int l);
};


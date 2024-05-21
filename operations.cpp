#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
#include <fstream>
#include <vector>
#include <iostream>
/////////////////////////////////// class operation  //////////////////
operation::operation(game* r_pGame)
{
	pGame = r_pGame;
}


/////////////////////////////////// class operAddSign  //////////////////

operAddSign::operAddSign(game* r_pGame):operation(r_pGame)
{
}

void operAddSign::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Sign(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}


operaddcar::operaddcar(game* r_pGame) :operation(r_pGame)
{}
void operaddcar::Act()
{
	window* pw = pGame->getWind();

	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point carShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new car(pGame, carShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
}


operaaddrobot::operaaddrobot(game*r_pGame):operation(r_pGame)
{}
void operaaddrobot::Act()
{
	window* pw = pGame->getWind();

	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point robotShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Robot(pGame, robotShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
}


operaddboat::operaddboat(game* r_pGame) :operation(r_pGame)
{}
void operaddboat::Act()
{
	window* pw = pGame->getWind();

	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point boatShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Boat(pGame, boatShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
}

operaddrocket::operaddrocket(game* r_pGame) :operation(r_pGame)
{}
void operaddrocket::Act()
{
	window* pw = pGame->getWind();

	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point rocketShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Rocket(pGame, rocketShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
}

operaddhome::operaddhome(game* r_pGame) :operation(r_pGame)
{}
void operaddhome::Act()
{
	window* pw = pGame->getWind();

	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point homeShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Home(pGame, homeShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);
}
resizeUp::resizeUp(game* r_pGame) : operation(r_pGame)
{}

void resizeUp::Act()
{
	grid* pGrid = pGame->getGrid();
	shape* psh = pGrid->getActiveshape();
	point ref = psh->getRefPoint();
	psh->resizeUp();
}
resizeDown::resizeDown(game* r_pGame) : operation(r_pGame) {}
void resizeDown::Act() {

	grid* pGrid = pGame->getGrid();
	shape* psh = pGrid->getActiveshape();
	point ref = psh->getRefPoint();
	psh->resizeDown();
}

operRotate::operRotate(game* r_pGame) : operation(r_pGame) {}
void operRotate::Act()
{
	grid* pGrid = pGame->getGrid();
	shape* activeShape = pGrid->getActiveshape();
	if (activeShape) {
		activeShape->Rotate90Clockwise();
		pGrid->draw();
	}
}

operRefresh::operRefresh(game* r_pGame) : operation(r_pGame) {}
void operRefresh::Act() {

}

operHint::operHint(game* r_pGame) : operation(r_pGame) {}
void operHint::Act() {

}

operDelete::operDelete(game* r_pGame) : operation(r_pGame) {}
void operDelete::Act() {
	
		
		grid* pGrid = pGame->getGrid();
		shape* psh = pGrid->getActiveshape();
		if (psh != nullptr) {
			
			pGrid->delete_shape();
		}
	
}

operSave::operSave(game* r_pGame) : operation(r_pGame) {}
void operSave::Act() {
	
	grid* shapesGrid = pGame->getGrid();
	ofstream Gameinformation("Gameinformation.txt");
	

	int lives = pGame->getCurrentLives();
	int score = pGame->getCurrentScore();
	int levels = pGame->getCurrentGameLevel();
	cout << lives << score << levels<<endl;
	if (Gameinformation.is_open()) {

		Gameinformation << lives << " ";
		Gameinformation << score << " ";
		Gameinformation << levels << " " << endl;
	}
	shape* s = shapesGrid->getActiveshape();
	s->save(Gameinformation);
	shapesGrid->saveshapes(Gameinformation);

	Gameinformation.close();
}
operLoad::operLoad(game* r_pGame) : operation(r_pGame) {

}

void operLoad::Act()

{
	ifstream Gameinformation("GameProgress.txt");

	int lines = 0;
	int lives, score, level;
	int  refpointx, refpointy;
	vector<ShapeProperties> shapes;
	Gameinformation >> lives  >> score  >> level;

	while (Gameinformation >> refpointx >> refpointy) {
		ShapeProperties shape;
		Gameinformation >> refpointx, refpointy,
			shape.refPointX = refpointx;
		shape.refPointY = refpointy;
		shapes.push_back(shape);
	}
	Gameinformation.close();
}
void operSelect::Act() {

	pGame->printMessage("Enter game level: ");
	int level = std::stoi(pGame->getSrting());
	pGame->setCurrentGameLevel(level);
	pGame->getToolbar()->updateLevel();
	int numShapes = 2 * level - 1;
	for (int i = 0; i < numShapes; ++i) {
		operation* addShapeOp = new operAddRandomShape(pGame);
		addShapeOp->Act();  
		delete addShapeOp;  // Delete the operation to avoid memory leaks
	}
}
moveup::moveup(game* r_pGame):operation(r_pGame)
{
}

void moveup::Act()
{
	grid* pGrid = pGame->getGrid();
	shape* currentShape = pGrid->getActiveshape();
	currentShape->moveup(config.gridSpacing);
	pGrid->setActiveShape(currentShape);
}

movedown::movedown(game* r_pGame) :operation(r_pGame)
{
}

void movedown::Act()
{
	grid* pGrid = pGame->getGrid();
	shape* currentShape = pGrid->getActiveshape();
	currentShape->movedown(config.gridSpacing);
	pGrid->setActiveShape(currentShape);
}

moveright::moveright(game* r_pGame):operation(r_pGame)
{
}

void moveright::Act()
{
	grid* pGrid = pGame->getGrid();
	shape* currentShape = pGrid->getActiveshape();
	currentShape->moveright(config.gridSpacing);
	pGrid->setActiveShape(currentShape);

}

moveleft::moveleft(game* r_pGame) :operation(r_pGame)
{
}

void moveleft::Act()
{
	grid* pGrid = pGame->getGrid();
	shape* currentShape = pGrid->getActiveshape();
	currentShape->moveleft(config.gridSpacing);
	pGrid->setActiveShape(currentShape);
}
void operExit::Act()
{
	if (!pGame->isSaved()) {
		operSave saveOp(pGame);
		saveOp.Act();
	}

	pGame->cleanUp();
	exit(0);
}

operAddRandomShape::operAddRandomShape(game* r_pGame) : operation(r_pGame) {}

void operAddRandomShape::Act() {
	window* pw = pGame->getWind();
	int xGrid = rand() % 400 + 100;
	int yGrid = rand() % 400 + 100;
	point shapeRef = { xGrid,yGrid };

	shape* psh;
	int randomShape = rand() % 6;
	switch (randomShape) {
	case 0:
		psh = new Sign(pGame, shapeRef);
		break;
	case 1:
		psh = new car(pGame, shapeRef);
		break;
	case 2:
		psh = new Robot(pGame, shapeRef);
		break;
	case 3:
		psh = new Boat(pGame, shapeRef);
		break;
	case 4:
		psh = new Rocket(pGame, shapeRef);
		break;
	case 5:
		psh = new Home(pGame, shapeRef);
		break;
	}

	// Add random rotation
	int randomRotation = rand() % 4;
	for (int i = 0; i < randomRotation; i++) {
		psh->Rotate90Clockwise();
	}
	//int randomSize = rand() % 2;  // generates a number between 0 and 2
		//for (int i = 0; i < randomSize; i++) {
			//psh->resizeUp();
	//	}

	grid* pGrid = pGame->getGrid();
	bool success = pGrid->addShape(psh);  // Add the new shape to the grid directly

}

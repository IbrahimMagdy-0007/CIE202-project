#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
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

}
resizeDown::resizeDown(game* r_pGame) : operation(r_pGame) {}
void resizeDown::Act() {

}

operRotate::operRotate(game* r_pGame) : operation(r_pGame) {}
void operRotate::Act()
{

}

operRefresh::operRefresh(game* r_pGame) : operation(r_pGame) {}
void operRefresh::Act() {

}

operHint::operHint(game* r_pGame) : operation(r_pGame) {}
void operHint::Act() {

}

operDelete::operDelete(game* r_pGame) : operation(r_pGame) {}
void operDelete::Act() {

}

operSave::operSave(game* r_pGame) : operation(r_pGame) {}
void operSave::Act() {

}

operSelect::operSelect(game* r_pGame) : operation(r_pGame) {}
void operSelect::Act() {

}
oppdelete::oppdelete(game* r_pGame) :operation(r_pGame)
{
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
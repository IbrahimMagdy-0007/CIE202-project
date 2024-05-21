#include "grid.h"
#include "game.h"
#include "gameConfig.h"
#include "iostream"

grid::grid(point r_uprleft, int wdth, int hght, game* pG)
{
	uprLeft = r_uprleft;
	height = hght;
	width = wdth;
	pGame = pG;
	rows = height / config.gridSpacing;
	cols = width / config.gridSpacing;
	shapeCount = 0;

	for (int i = 0; i < MaxShapeCount; i++)
		shapeList[i] = nullptr;

	activeShape = nullptr;

}

grid::~grid()
{
	for (int i = 0; i < shapeCount; i++)
		delete shapeList[i];
}

void grid::draw() const
{
	clearGridArea();
	window* pWind = pGame->getWind();
	
	pWind->SetPen(config.gridDotsColor,1);
	pWind->SetBrush(config.gridDotsColor);

	//draw dots showing the grid reference points
	for (int r = 1; r < rows; r++)
		for (int c = 0; c < cols; c++)
			pWind->DrawCircle(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y, 1);
			//pWind->DrawPixel(c * config.gridSpacing, r * config.gridSpacing + uprLeft.y);

	//Draw ALL shapes
	for (int i = 0; i < shapeCount; i++)
			if (shapeList[i])
				shapeList[i]->draw();	//draw each shape

	//Draw the active shape
	if(activeShape)
		activeShape->draw();
}

void grid::clearGridArea() const
{
	window* pWind = pGame->getWind();	
	pWind->SetPen(config.bkGrndColor, 1);
	pWind->SetBrush(config.bkGrndColor);
	pWind->DrawRectangle(uprLeft.x, uprLeft.y, uprLeft.x + width, uprLeft.y + height);
}

//Adds a shape to the randomly created shapes list.

bool grid::addShape(shape* newShape)
{
	// Check that shape count doesn't exceed maximum count
	if (shapeCount >= MaxShapeCount)
		return false;

	// Check that the shape can be drawn without being clipped by grid boundaries
	point shapeRef = newShape->getRefPoint();
	int shapeWidth = 0, shapeHeight = 0;


	// Calculate the width and height of the shape based on its type
	if (dynamic_cast<Sign*>(newShape)) {
		shapeWidth = config.sighShape.topWdth;
		shapeHeight = config.sighShape.topHeight + config.sighShape.baseHeight;
	}
	else if (dynamic_cast<car*>(newShape)) {
		shapeWidth = config.carShape.bodyWidth + 2 * config.carShape.wheel1Radius;
		shapeHeight = config.carShape.bodyHeight + config.carShape.bodyHeight - 20;
	}
	else if (dynamic_cast<Robot*>(newShape)) {
		shapeWidth = config.RobotShape.bodyWidth;
		shapeHeight = config.RobotShape.bodyHeight + config.RobotShape.headRadius * 2;
	}
	else if (dynamic_cast<Boat*>(newShape)) {
		shapeWidth = config.BoatShape.hullWidth;
		shapeHeight = config.BoatShape.hullHeight + config.BoatShape.mastHeight;
	}
	else if (dynamic_cast<Rocket*>(newShape)) {
		shapeWidth = config.RocketShape.bodyWidth;
		shapeHeight = config.RocketShape.bodyHeight + config.RocketShape.topHeight;
	}
	else if (dynamic_cast<Home*>(newShape)) {
		shapeWidth = config.HomeShape.bodyWidth;
		shapeHeight = config.HomeShape.bodyHeight;
	}

	if (shapeRef.x + shapeWidth > width || shapeRef.y + shapeHeight > height) {
		delete newShape;
		return false;
	}

	// If all checks pass, add the shape to the list
	shapeList[shapeCount++] = newShape;
	return true;
}

void grid::setActiveShape(shape* actShape)
{
	activeShape = actShape;
}

shape* grid::getActiveshape()
{
	return activeShape;
}
shape* grid::getShapesList()
{

	return *shapeList;
}


void grid::delete_shape()
{
	if (activeShape != nullptr)
	{
		delete activeShape;
		activeShape = nullptr;
	}
}

void grid::drawAllButActiveShape()
{
	if (activeShape)
	{
		delete activeShape;
		activeShape = nullptr;
	}
}




void grid::saveshapes(ofstream& outfile) const
{
	for (int i = 0; i < shapeCount; i++)
	{
		if (shapeList[i] != nullptr)
		{
			shapeList[i]->save(outfile);
		}
	}
}

void grid::detectmatching()
{
	for (int i = 0; i < MaxShapeCount; i++) {

		if (activeShape && shapeList[i]) {
			if (activeShape->matching(shapeList[i])) {
				delete activeShape;
				delete[] shapeList[i];
				activeShape = nullptr;
				shapeList[i] = nullptr;
				
				pGame->setCurrentScore(pGame->getCurrentScore() + 3);
				
			}
		}
	}
	pGame->setCurrentScore(pGame->getCurrentScore() - 1);

	if (all_matched()) {
		pGame->setCurrentGameLevel(pGame->getCurrentGameLevel() + 1);
	}
}



bool grid::all_matched()
{
	for (int i = 0; i < MaxShapeCount; i++)
	{
		if (shapeList[i]) {
			return false;
		}
	}
	return true;
}

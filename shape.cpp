#include "shape.h"
#include "game.h"
#include "gameConfig.h"

shape::shape(game* r_pGame, point ref)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	borderColor = config.penColor;
}
void shape:: setRefPoint(point p)
{
	RefPoint = p;
}
point shape::getRefPoint()
{
	return RefPoint;
}

void shape::moveup(double d) {
	point point1 = this->getRefPoint();
	point point2;
	point2.x = point1.x;
	point2.y = point1.y - d;

	this->setRefPoint(point2);
}

void shape::movedown(double d) {
	point point1 = this->getRefPoint();
	point point2;
	point2.x = point1.x;
	point2.y = point1.y + d;

	this->setRefPoint(point2);
}

void shape::moveleft(double d) {
	point point1 = this->getRefPoint();
	point point2;
	point2.x = point1.x - d;
	point2.y = point1.y;

	this->setRefPoint(point2);
}
void shape::moveright(double d) {
	point point1 = this->getRefPoint();
	point point2;
	point2.x = point1.x + d;
	point2.y = point1.y;

	this->setRefPoint(point2);
}
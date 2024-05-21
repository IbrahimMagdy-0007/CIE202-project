#include "shape.h"
#include "game.h"
#include "gameConfig.h"
#include <fstream>
#include <iostream>


shape::shape(game* r_pGame, point ref)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	borderColor = config.penColor;
	int rotationcount = 0;
	int resizecount = 0;
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

void shape::save(ofstream& outfile)
{
	outfile << RefPoint.x << " " << RefPoint.y;
		

}

string shape::gettype()
{
	return "type";
}

int shape::getrotatecounter()
{
	return rotatecounter;
}

int shape::getsizecounter()
{
	return sizecounter;
}

bool shape::matching(shape* s)
{
	//cout <<'{' << s->gettype() << ',' << s->getRefPoint().x << ',' << s->getRefPoint().y << '}' << '{' << this->gettype() << ',' << this->getRefPoint().x << ',' << this->getRefPoint().y << '}' << endl;
	if ((s->gettype() == this->gettype()) &&
		(s->getrotatecounter() == this->getrotatecounter()) &&
		(s->getsizecounter() == this->getsizecounter()) && (s->getRefPoint().x == this->getRefPoint().x) && (s->getRefPoint().y == this->getRefPoint().y)) {
		return true;
	}
	else
		return false;

}


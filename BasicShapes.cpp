#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////

Rect::Rect(game* r_pGame, point ref, int r_hght, int r_wdth) :shape(r_pGame, ref)
{
	pGame = r_pGame;
	hght = r_hght;
	wdth = r_wdth;
}

void Rect::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);
	point upperLeft, lowerBottom;
	upperLeft.x = RefPoint.x - wdth / 2;
	upperLeft.y = RefPoint.y - hght / 2;
	lowerBottom.x = RefPoint.x + wdth / 2;
	lowerBottom.y = RefPoint.y + hght / 2;

	pW->DrawRectangle(upperLeft.x, upperLeft.y, lowerBottom.x, lowerBottom.y, FILLED);
}
void Rect::Rotate90Clockwise(const point& center) {
	// Rotate the rectangle 90 degrees clockwise around the given center point
	int newCenterX = center.x - (RefPoint.y - center.y);
	int newCenterY = center.y + (RefPoint.x - center.x);
	RefPoint.x = newCenterX;
	RefPoint.y = newCenterY;
	// Swap the width and height
	swap(wdth, hght);
}
void Rect::resizeUp()
{
	hght *= 2;
	wdth *= 2;
}

void Rect::resizeDown()
{
	hght /= 2;
	wdth /= 2;
}

////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//TODO: Add implementation for class circle here
circle::circle(game* r_pGame, point ref, int r) :shape(r_pGame, ref)
{
	rad = r;
}

void circle::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	pW->SetPen(borderColor, config.penWidth);
	pW->SetBrush(fillColor);
	pW->DrawCircle(RefPoint.x, RefPoint.y, rad, FILLED);
}
void circle::Rotate90Clockwise(const point& center) {
	// Rotate the circle 90 degrees clockwise around the given center point
	int newCenterX = center.x - (RefPoint.y - center.y);
	int newCenterY = center.y + (RefPoint.x - center.x);
	RefPoint.x = newCenterX;
	RefPoint.y = newCenterY;
}
void circle::resizeUp()
{
	rad *= 2;
}

void circle::resizeDown()
{
	rad /= 2;
}


////////////////////////////////////////////////////  class triangle  ///////////////////////////////////////
//TODO: Add implementation for class triangle here

Triangle::Triangle(game* pGame, point ref, int r_height, int r_baseWidth)
	: shape(pGame, ref), height(r_height), baseWidth(r_baseWidth) {}

void Triangle::draw() const {

	window* pW = pGame->getWind();
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);


	point top, left, right;
	top.x = RefPoint.x;
	top.y = RefPoint.y - height / 2;

	left.x = RefPoint.x - baseWidth / 2;
	left.y = RefPoint.y + height / 2;

	right.x = RefPoint.x + baseWidth / 2;
	right.y = RefPoint.y + height / 2;


	pW->DrawTriangle(top.x, top.y, left.x, left.y, right.x, right.y, FILLED);
}

void Triangle::Rotate90Clockwise(const point& center) {
	// Rotate the triangle 90 degrees clockwise around its reference point
	int newCenterX = center.x - (RefPoint.y - center.y);
	int newCenterY = center.y + (RefPoint.x - center.x);
	RefPoint.x = newCenterX;
	RefPoint.y = newCenterY;
	// Swap the base and height
	swap(baseWidth, height);
}
void Triangle::resizeUp()
{
	baseWidth *= 2;
}

void Triangle::resizeDown()
{
	baseWidth /= 2;
}
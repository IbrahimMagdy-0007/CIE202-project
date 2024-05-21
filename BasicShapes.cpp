#include "BasicShapes.h"
#include "gameConfig.h"
#include "game.h"
#include<fstream>
point circle::sizeref() const { return RefPoint; }
point Rect::sizeref() const { return RefPoint; }
point Triangle::sizeref() const { return RefPoint; }








////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////
Rect::Rect(game* r_pGame, point ref, int r_hght, int r_wdth) :shape(r_pGame, ref)
{
	pGame = r_pGame;
	hght = r_hght;
	wdth = r_wdth;
}
void Rect::setHeight(float nHeight)
{
	hght = nHeight;
}
void Rect::setWidth(float nWidth)
{
	wdth = nWidth;
}
float Rect::getHeight() const
{
	return hght;
}
float Rect::getWidth() const
{
	return wdth;
}

void Rect::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	if (pGame->getCurrentGameLevel() >= 3) {
		pW->SetPen(BLACK, config.penWidth);
		pW->SetBrush(BLACK);
	}
	else {
		pW->SetPen(config.penColor, config.penWidth);
		pW->SetBrush(config.fillColor);
	}
	point upperLeft, lowerBottom;
	upperLeft.x = RefPoint.x - wdth / 2;
	upperLeft.y = RefPoint.y - hght / 2;
	lowerBottom.x = RefPoint.x + wdth / 2;
	lowerBottom.y = RefPoint.y + hght / 2;

	pW->DrawRectangle(upperLeft.x, upperLeft.y, lowerBottom.x, lowerBottom.y, FILLED);
}
void Rect::Rotate90Clockwise() {
	// Rotate the rectangle 90 degrees clockwise around the given center point
	window* pW = pGame->getWind();
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);
	point upperLeft, lowerBottom;
	int x = hght;
	hght = wdth;
	wdth = x;
	upperLeft.x = RefPoint.x - wdth / 2;
	upperLeft.y = RefPoint.y - hght / 2;
	lowerBottom.x = RefPoint.x + wdth / 2;
	lowerBottom.y = RefPoint.y + hght / 2;

}

void Rect::save(ofstream& outFile)  {
	outFile << "Rect " << RefPoint.x << " " << RefPoint.y << " " << hght << " " << wdth << "\n";
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
float circle::getRad() const
{
	return rad;
}
void circle::setRad(float nRad)
{
	rad = nRad;
}
void circle::draw() const
{
	window* pW = pGame->getWind();	//get interface window
	if (pGame->getCurrentGameLevel() >= 3) {
		pW->SetPen(BLACK, config.penWidth);
		pW->SetBrush(BLACK);
	}
	else {
		pW->SetPen(borderColor, config.penWidth);
		pW->SetBrush(fillColor);
	}
	pW->DrawCircle(RefPoint.x, RefPoint.y, rad, FILLED);
}
void circle::Rotate90Clockwise() {}

void circle::save(ofstream& outFile)  {
	outFile << "Circle " << RefPoint.x << " " << RefPoint.y << " " << rad << "\n";
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
	: shape(pGame, ref), height(r_height), baseWidth(r_baseWidth) {
}
float Triangle::getbasewidth() const
{
	return baseWidth;
}
void Triangle::setbasewidth(float nbase) {
	baseWidth = nbase;
}
float Triangle::gethight() const
{
	return height;
}
void Triangle::sethight(float nhight) {
	height = nhight;
}

void Triangle::draw() const {

	window* pW = pGame->getWind();
	if (pGame->getCurrentGameLevel() >= 3) {
		pW->SetPen(BLACK, config.penWidth);
		pW->SetBrush(BLACK);
	}
	else {
		pW->SetPen(config.penColor, config.penWidth);
		pW->SetBrush(config.fillColor);
	}

	point top, left, right;
	top.x = RefPoint.x;
	top.y = RefPoint.y - height / 2;

	left.x = RefPoint.x - baseWidth / 2;
	left.y = RefPoint.y + height / 2;

	right.x = RefPoint.x + baseWidth / 2;
	right.y = RefPoint.y + height / 2;

	pW->DrawTriangle(top.x, top.y, left.x, left.y, right.x, right.y, FILLED);
}

void Triangle::Rotate90Clockwise() {
	window* pW = pGame->getWind();
	pW->SetPen(config.penColor, config.penWidth);
	pW->SetBrush(config.fillColor);

	// Swap height and width
	int x = baseWidth;
	baseWidth = height;
	height = x;

	
}

void Triangle::save(std::ofstream& outFile)  {
	outFile << "Triangle " << RefPoint.x << " " << RefPoint.y << " " << height << " " << baseWidth << "\n";
}


void Triangle::resizeUp()
{
	baseWidth *= 2;
}

void Triangle::resizeDown()
{
	baseWidth /= 2;
}
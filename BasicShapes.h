//Header file for Basic shapes in the game
#pragma once
#include "shape.h"

////////////////////////////////////////////////////  class Rect  ///////////////////////////////////////
//Rectanle class
/*							wdth
					---------------------
					|					|
			hght    |		 x			|     x is the reference point of the rectangle
					|					|
					--------------------
*/


class Rect :public shape
{
	int hght, wdth;	//height and width of the recangle
public:
	Rect(game* r_pGame, point ref, int r_hght, int r_wdth);
	void setHeight(float nHeight);
	void setWidth(float nWidth);
	float getHeight() const;
	float getWidth() const;
	virtual void draw() const;
	void Rotate90Clockwise();
	void resizeUp() override;
	void resizeDown() override;
	point sizeref() const;
	void save(ofstream& outfile) override;


};




////////////////////////////////////////////////////  class circle  ///////////////////////////////////////
//Reference point of the circle is its center
class circle :public shape
{
	//Add data memebrs for class circle
	int rad;
public:
	circle(game* r_pGame, point ref, int r);
	float getRad() const;
	void setRad(float nRad);	//add more parameters for the constructor if needed
	virtual void draw() const;
	void Rotate90Clockwise();
	void resizeUp() override;
	void resizeDown() override;
	point sizeref() const;
	void save(ofstream& outfile) override;
};


class Triangle : public shape {
private:
	int height, baseWidth;
	
public:

	Triangle(game* pGame, point ref, int r_height, int r_baseWidth);
	float getbasewidth() const;
	void setbasewidth(float nbase);
	float gethight() const;
	void sethight(float nhight);
	virtual void draw() const override;

	void Rotate90Clockwise();
	void resizeUp() override;
	void resizeDown() override;
	point sizeref() const;
	void save(ofstream& outfile) override;

};
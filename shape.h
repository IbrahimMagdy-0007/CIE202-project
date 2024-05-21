#pragma once
#include <string>
using namespace std;
#include "CMUgraphicsLib\CMUgraphics.h"

class game;     //forward declaration

struct point
{
	int x, y;
};

enum ShapeType
{
	//Basic shapes
	RCT,	//rectangle
	CRC,	//circle
	TRI,	//triangle

	//Composite shapes
	SIGN,	//a street sign
	CAR,
	ROBOT,
	BOAT,
	ROCKET,
	HOME,
	//TODO: Add more types
};

//Base class for all shapes including Basic shapes, Composite shapes
class shape
{
protected:
	point RefPoint;		//Each shape must have a reference point
    game* pGame;        //pointer to game object
	color fillColor;	//shape fill color
	color borderColor;	//shape border color
	int rotatecounter = 0;
	int sizecounter = 0;
public:
    shape(game* r_pGame, point ref);
    virtual void draw() const=0;//for a shape to draw itself on the screen
	void setRefPoint(point p);
	point getRefPoint();
	virtual void resizeUp() = 0;
	virtual void resizeDown() = 0;
	virtual void moveup(double d);
	virtual void movedown(double d);
	virtual void moveright(double d);
	virtual void moveleft(double d);
	virtual void Rotate90Clockwise() = 0;
	virtual void save(ofstream& outfile) ;
	virtual string gettype();
	virtual int getrotatecounter();
	virtual int getsizecounter();
	bool matching(shape* s);

							  
	//-- The following functions should be supported by the shape class
	//-- It should be overridden by each inherited shape
	//-- Decide the parameters that you should pass to each function	

	//virtual void rotate() = 0;	//Rotate the shape
	//virtual void resize() = 0;	//Resize the shape
	//virtual void move() = 0;		//Move the shape
	//virtual void save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	//virtual void load(ifstream &Infile) = 0;	//Load the shape parameters to the file

};




struct ShapeProperties {
	
	int refPointX;
	int refPointY;

};
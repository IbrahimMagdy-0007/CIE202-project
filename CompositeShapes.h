#pragma once
#include "Basicshapes.h"


////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
//This class reprsents the composite shape "sign"
//The sign is composed of 2 Recatngles
/*				

					 ------------------
					|				   |
					|		 x		   |     x is the reference point of the Sign shape
					|			       |
					 ------------------
						   |   |
						   |   |
						   | . |
						   |   |
						   |   |
							---
*/

//Note: sign reference point is the center point of the top rectangle
class Sign :public shape
{
	Rect* base;
	Rect* top;
public:
	Sign(game* r_pGame, point ref);
	virtual void draw() const;


};

class car : public shape {
private:
	Rect* body;
	circle* wheel1;
	circle* wheel2;
	Rect* head;
public:
	car(game* r_pGame, point ref);
	virtual void draw() const;
};



class Robot : public shape {
private:
	Rect* body;
	circle* head;
	circle* leftEye;
	circle* rightEye;
	Rect* leftFoot;
	Rect* rightFoot;


public:
	Robot(game* r_pGame, point ref);
	virtual void draw() const;
};




class Boat : public shape {
private:
	Rect* hull;
	Rect* cabin;
	Rect* mast;
	Triangle* sail;
	circle* flag;


public:
	Boat(game* r_pGame, point ref);
	virtual void draw() const ;
};


class Rocket : public shape {
private:
	Rect* body;
	Rect* fin1;
	Rect* fin2;
	Triangle* top;

public:
	Rocket(game* r_pGame, point ref);
	virtual void draw() const;
};


class Home : public shape {
private:
	Rect* body;
	Triangle* roof;
	Rect* door;

public:
	Home(game* r_pGame, point ref);
	virtual void draw() const override;
};
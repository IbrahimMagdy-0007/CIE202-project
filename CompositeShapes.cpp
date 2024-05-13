#include "CompositeShapes.h"
#include "gameConfig.h"

////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
Sign::Sign(game* r_pGame, point ref):shape(r_pGame, ref)
{
	//calc the ref point of the Sign base and top rectangles relative to the Sign shape
	point topRef = ref;	//top rect ref is the same as the sign
	point baseRef = { ref.x, ref.y + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	base = new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
}

void Sign::draw() const
{
	base->draw();
	top->draw();
}






car::car(game* r_pGame, point ref) : shape(r_pGame, ref) {


    point bodyRef;
    point wheel1Ref;
    point wheel2Ref;
    point headRef;


    bodyRef = ref;
    wheel1Ref = { ref.x - (config.carShape.wheel1Radius * 2), ref.y+15 };
    wheel2Ref = { ref.x + (config.carShape.wheel2Radius * 2), ref.y+15 };
    headRef = { ref.x ,ref.y - 20 };
    // Create the car body and wheels with their respective reference points
    body = new Rect(pGame, bodyRef, config.carShape.bodyHeight, config.carShape.bodyWidth);
    wheel1 = new circle(pGame, wheel1Ref, config.carShape.wheel1Radius);
    wheel2 = new circle(pGame, wheel2Ref, config.carShape.wheel2Radius);
    head = new Rect(pGame, headRef, config.carShape.bodyHeight-20, config.carShape.bodyWidth-20);
};

    void car:: draw() const {
        
        
        body->draw();
        wheel1->draw();
        wheel2->draw();
        head->draw();
    }


    Robot::Robot(game* r_pGame, point ref) : shape(r_pGame, ref) {
    
    point bodyRef = ref;
    point headRef = { ref.x, ref.y - config.RobotShape.bodyHeight/1.5 };
    point leftEyeRef = { ref.x - config.RobotShape.bodyWidth/6 , ref.y - config.RobotShape.bodyHeight  + config.RobotShape.headRadius*1.5  };
    point rightEyeRef = { ref.x + config.RobotShape.bodyWidth/6 , ref.y - config.RobotShape.bodyHeight  + config.RobotShape.headRadius*1.5  };
    point leftFootRef = { ref.x - config.RobotShape.bodyWidth/2 , ref.y + config.RobotShape.bodyHeight };
    point rightFootRef = { ref.x + config.RobotShape.bodyWidth  - config.RobotShape.footWidth, ref.y + config.RobotShape.bodyHeight };

    
    body = new Rect(pGame, bodyRef, config.RobotShape.bodyHeight, config.RobotShape.bodyWidth);
    head = new circle(pGame, headRef, config.RobotShape.headRadius);
    leftEye = new circle(pGame, leftEyeRef, config.RobotShape.eyeRadius);
    rightEye = new circle(pGame, rightEyeRef, config.RobotShape.eyeRadius);
    leftFoot = new Rect(pGame, leftFootRef, config.RobotShape.footHeight, config.RobotShape.footWidth);
    rightFoot = new Rect(pGame, rightFootRef, config.RobotShape.footHeight, config.RobotShape.footWidth);
}

void Robot::draw() const {
    body->draw();
    head->draw();
    leftEye->draw();
    rightEye->draw();
    leftFoot->draw();
    rightFoot->draw();
}



Boat::Boat(game* r_pGame, point ref) : shape(r_pGame, ref) {

    point hullRef = { ref.x - config.BoatShape.mastWidth / 2,ref.y - config.BoatShape.hullHeight  };
    point cabinRef = { ref.x - config.BoatShape.hullWidth  + config.BoatShape.cabinWidth / 2, ref.y + config.BoatShape.hullHeight / 2 };
    point mastRef = { ref.x- config.BoatShape.mastWidth , ref.y - config.BoatShape.hullHeight / 8 - config.BoatShape.mastHeight / 2};
    point sailRef = { ref.x - config.BoatShape.mastWidth , ref.y - config.BoatShape.hullHeight / 2 - config.BoatShape.mastHeight };
    point flagRef = { ref.x-config.BoatShape.mastWidth / 3, ref.y - config.BoatShape.hullHeight / 2 - config.BoatShape.mastHeight };


    hull = new Rect(pGame, hullRef, config.BoatShape.hullHeight, config.BoatShape.hullWidth);
    cabin = new Rect(pGame, cabinRef, config.BoatShape.cabinHeight, config.BoatShape.cabinWidth);
    mast = new Rect(pGame, mastRef, config.BoatShape.mastHeight, config.BoatShape.mastWidth);
    sail = new Triangle(pGame, sailRef, config.BoatShape.sailHeight, config.BoatShape.sailWidth);
    flag = new circle(pGame, flagRef, 15); // Assuming flag is represented by a small circle
}

void Boat::draw() const {
    hull->draw();
    cabin->draw();
    mast->draw();
    sail->draw();
    flag->draw();
}


Rocket::Rocket(game* r_pGame, point ref) : shape(r_pGame, ref) {

    point bodyRef = ref;
    point fin1Ref = { ref.x , ref.y + config.RocketShape.bodyHeight/2 };
    point fin2Ref = { ref.x , ref.y +config.RocketShape.bodyHeight/1.75 };
    point noseRef = { ref.x , ref.y -config.RocketShape.bodyHeight/1.75 };


    body = new Rect(pGame, bodyRef, config.RocketShape.bodyHeight, config.RocketShape.bodyWidth);
    fin1 = new Rect(pGame, fin1Ref, config.RocketShape.finHeight, config.RocketShape.finWidth);
    fin2 = new Rect(pGame, fin2Ref, config.RocketShape.finHeight, config.RocketShape.finWidth);
    top = new Triangle(pGame, noseRef, config.RocketShape.topHeight, config.RocketShape.topWidth);
}

void Rocket::draw() const {
    body->draw();
    fin1->draw();
    fin2->draw();
    top->draw();
}


Home::Home(game* r_pGame, point ref) : shape(r_pGame, ref) {
    
    point bodyRef = ref;
    point roofRef = { ref.x, ref.y - config.HomeShape.roofHeight*1.75};
    point doorRef = { ref.x , ref.y + config.HomeShape.bodyHeight - config.HomeShape.doorHeight*1.25 };

    
    body = new Rect(pGame, bodyRef, config.HomeShape.bodyHeight, config.HomeShape.bodyWidth);
    roof = new Triangle(pGame, roofRef, config.HomeShape.roofHeight, config.HomeShape.roofWidth);
    door = new Rect(pGame, doorRef, config.HomeShape.doorHeight, config.HomeShape.doorWidth);
}

void Home::draw() const {
    body->draw();
    roof->draw();
    door->draw();
}

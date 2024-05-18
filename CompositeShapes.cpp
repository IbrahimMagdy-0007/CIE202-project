#include "CompositeShapes.h"
#include "gameConfig.h"

////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
Sign::Sign(game* r_pGame, point ref) :shape(r_pGame, ref)
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
void Sign::Rotate90Clockwise(const point& center) {
    base->Rotate90Clockwise(center);
    top->Rotate90Clockwise(center);
}
void Sign::resizeUp()
{
    base->resizeUp();
    top->resizeUp();
}
void Sign::resizeDown()
{
    base->resizeDown();
    top->resizeDown();
}

void Sign::moveup(double d)
{
    base->moveup(d);
    top->moveup(d);
}

void Sign::movedown(double d)
{
    base->movedown(d);
    top->movedown(d);
}

void Sign::moveright(double d)
{
    base->moveright(d);
    top->moveright(d);
}

void Sign::moveleft(double d)
{
    base->moveleft(d);
    top->moveleft(d);
}

car::car(game* r_pGame, point ref) : shape(r_pGame, ref) {


    point bodyRef;
    point wheel1Ref;
    point wheel2Ref;
    point headRef;


    bodyRef = ref;
    wheel1Ref = { ref.x - (config.carShape.wheel1Radius * 2), ref.y + 15 };
    wheel2Ref = { ref.x + (config.carShape.wheel2Radius * 2), ref.y + 15 };
    headRef = { ref.x ,ref.y - 20 };
    // Create the car body and wheels with their respective reference points
    body = new Rect(pGame, bodyRef, config.carShape.bodyHeight, config.carShape.bodyWidth);
    wheel1 = new circle(pGame, wheel1Ref, config.carShape.wheel1Radius);
    wheel2 = new circle(pGame, wheel2Ref, config.carShape.wheel2Radius);
    head = new Rect(pGame, headRef, config.carShape.bodyHeight - 20, config.carShape.bodyWidth - 20);
};

void car::draw() const {


    body->draw();
    wheel1->draw();
    wheel2->draw();
    head->draw();
}
void car::Rotate90Clockwise(const point& center) {
    body->Rotate90Clockwise(center);
    wheel1->Rotate90Clockwise(center);
    wheel2->Rotate90Clockwise(center);
    head->Rotate90Clockwise(center);
}
void car::resizeUp()
{
    body->resizeUp();
    wheel1->resizeUp();
    wheel2->resizeUp();

}
void car::resizeDown()
{
    body->resizeDown();
    wheel1->resizeDown();
    wheel2->resizeDown();
}

void car::moveup(double d)
{
    body->moveup(d);
    wheel1->moveup(d);
    wheel2->moveup(d);
    head->moveup(d);
}

void car::movedown(double d)
{
    body->movedown(d);
    wheel1->movedown(d);
    wheel2->movedown(d);
    head->movedown(d);
}

void car::moveright(double d)
{
    body->moveright(d);
    wheel1->moveright(d);
    wheel2->moveright(d);
    head->moveright(d);
}

void car::moveleft(double d)
{
    body->moveleft(d);
    wheel1->moveleft(d);
    wheel2->moveleft(d);
    head->moveleft(d);
}

Robot::Robot(game* r_pGame, point ref) : shape(r_pGame, ref) {

    point bodyRef = ref;
    point headRef = { ref.x, ref.y - config.RobotShape.bodyHeight / 1.5 };
    point leftEyeRef = { ref.x - config.RobotShape.bodyWidth / 6 , ref.y - config.RobotShape.bodyHeight + config.RobotShape.headRadius * 1.5 };
    point rightEyeRef = { ref.x + config.RobotShape.bodyWidth / 6 , ref.y - config.RobotShape.bodyHeight + config.RobotShape.headRadius * 1.5 };
    point leftFootRef = { ref.x - config.RobotShape.bodyWidth / 2 , ref.y + config.RobotShape.bodyHeight };
    point rightFootRef = { ref.x + config.RobotShape.bodyWidth - config.RobotShape.footWidth, ref.y + config.RobotShape.bodyHeight };


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

void Robot::Rotate90Clockwise(const point& center) {
    body->Rotate90Clockwise(center);
    head->Rotate90Clockwise(center);
    leftEye->Rotate90Clockwise(center);
    rightEye->Rotate90Clockwise(center);
    leftFoot->Rotate90Clockwise(center);
    rightFoot->Rotate90Clockwise(center);
}
void Robot::resizeUp()
{
    body->resizeUp();
    head->resizeUp();
    leftEye->resizeUp();
    rightEye->resizeUp();
    leftFoot->resizeUp();
    rightFoot->resizeUp();
}
void Robot::resizeDown()
{
    body->resizeDown();
    head->resizeDown();
    leftEye->resizeDown();
    rightEye->resizeDown();
    leftFoot->resizeDown();
    rightFoot->resizeDown();
}

void Robot::moveup(double d)
{
    body->moveup(d);
    head->moveup(d);
    leftEye->moveup(d);
    rightEye->moveup(d);
    leftFoot->moveup(d);
    rightFoot->moveup(d);
}

void Robot::movedown(double d)
{
    body->movedown(d);
    head->movedown(d);
    leftEye->movedown(d);
    rightEye->movedown(d);
    leftFoot->movedown(d);
    rightFoot->movedown(d);
}

void Robot::moveright(double d)
{
    body->moveright(d);
    head->moveright(d);
    leftEye->moveright(d);
    rightEye->moveright(d);
    leftFoot->moveright(d);
    rightFoot->moveright(d);
}

void Robot::moveleft(double d)
{
    body->moveleft(d);
    head->moveleft(d);
    leftEye->moveleft(d);
    rightEye->moveleft(d);
    leftFoot->moveleft(d);
    rightFoot->moveleft(d);
}


Boat::Boat(game* r_pGame, point ref) : shape(r_pGame, ref) {

    point hullRef = { ref.x - config.BoatShape.mastWidth / 2,ref.y - config.BoatShape.hullHeight };
    point cabinRef = { ref.x - config.BoatShape.hullWidth + config.BoatShape.cabinWidth / 2, ref.y + config.BoatShape.hullHeight / 2 };
    point mastRef = { ref.x - config.BoatShape.mastWidth , ref.y - config.BoatShape.hullHeight / 8 - config.BoatShape.mastHeight / 2 };
    point sailRef = { ref.x - config.BoatShape.mastWidth , ref.y - config.BoatShape.hullHeight / 2 - config.BoatShape.mastHeight };
    point flagRef = { ref.x - config.BoatShape.mastWidth / 3, ref.y - config.BoatShape.hullHeight / 2 - config.BoatShape.mastHeight };


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


void Boat::Rotate90Clockwise(const point& center) {
    hull->Rotate90Clockwise(center);
    cabin->Rotate90Clockwise(center);
    mast->Rotate90Clockwise(center);
    sail->Rotate90Clockwise(center);
    flag->Rotate90Clockwise(center);
}

void Boat::resizeUp()
{
    hull->resizeUp();
    cabin->resizeUp();
    mast->resizeUp();
    sail->resizeUp();
    flag->resizeUp();
}
void Boat::resizeDown()
{
    hull->resizeDown();
    cabin->resizeDown();
    mast->resizeDown();
    sail->resizeDown();
    flag->resizeDown();
}
void Boat::moveup(double d)
{
    hull->moveup(d);
    cabin->moveup(d);
    mast->moveup(d);
    sail->moveup(d);
    flag->moveup(d);
}

void Boat::movedown(double d)
{
    hull->movedown(d);
    cabin->movedown(d);
    mast->movedown(d);
    sail->movedown(d);
    flag->movedown(d);
}

void Boat::moveright(double d)
{
    hull->moveright(d);
    cabin->moveright(d);
    mast->moveright(d);
    sail->moveright(d);
    flag->moveright(d);
}

void Boat::moveleft(double d)
{
    hull->moveleft(d);
    cabin->moveleft(d);
    mast->moveleft(d);
    sail->moveleft(d);
    flag->moveleft(d);
}
Rocket::Rocket(game* r_pGame, point ref) : shape(r_pGame, ref) {

    point bodyRef = ref;
    point fin1Ref = { ref.x , ref.y + config.RocketShape.bodyHeight / 2 };
    point fin2Ref = { ref.x , ref.y + config.RocketShape.bodyHeight / 1.75 };
    point noseRef = { ref.x , ref.y - config.RocketShape.bodyHeight / 1.75 };


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

void Rocket::Rotate90Clockwise(const point& center) {
    body->Rotate90Clockwise(center);
    fin1->Rotate90Clockwise(center);
    fin2->Rotate90Clockwise(center);
    top->Rotate90Clockwise(center);
}
void Rocket::resizeUp()
{
    body->resizeUp();
    fin1->resizeUp();
    fin2->resizeUp();
    top->resizeUp();
}
void Rocket::resizeDown()
{
    body->resizeDown();
    fin1->resizeDown();
    fin2->resizeDown();
    top->resizeDown();
}

void Rocket::moveup(double d)
{
    body->moveup(d);
    fin1->moveup(d);
    fin2->moveup(d);
    top->moveup(d);
}

void Rocket::movedown(double d)
{
    body->movedown(d);
    fin1->movedown(d);
    fin2->movedown(d);
    top->movedown(d);
}

void Rocket::moveright(double d)
{
    body->moveright(d);
    fin1->moveright(d);
    fin2->moveright(d);
    top->moveright(d);
}

void Rocket::moveleft(double d)
{
    body->moveleft(d);
    fin1->moveleft(d);
    fin2->moveleft(d);
    top->moveleft(d);
}

Home::Home(game* r_pGame, point ref) : shape(r_pGame, ref) {

    point bodyRef = ref;
    point roofRef = { ref.x, ref.y - config.HomeShape.roofHeight * 1.75 };
    point doorRef = { ref.x , ref.y + config.HomeShape.bodyHeight - config.HomeShape.doorHeight * 1.25 };


    body = new Rect(pGame, bodyRef, config.HomeShape.bodyHeight, config.HomeShape.bodyWidth);
    roof = new Triangle(pGame, roofRef, config.HomeShape.roofHeight, config.HomeShape.roofWidth);
    door = new Rect(pGame, doorRef, config.HomeShape.doorHeight, config.HomeShape.doorWidth);
}

void Home::draw() const {
    body->draw();
    roof->draw();
    door->draw();
}

void Home::Rotate90Clockwise(const point& center) {
    body->Rotate90Clockwise(center);
    roof->Rotate90Clockwise(center);
    door->Rotate90Clockwise(center);
}

void Home::resizeUp()
{
    body->resizeUp();
    roof->resizeUp();
    door->resizeUp();
}
void Home::resizeDown()
{
    body->resizeDown();
    roof->resizeDown();
    door->resizeDown();
}
void Home::moveup(double d)
{
    body->moveup(d);
    body->moveup(d);
    roof->moveup(d);
    door->moveup(d);
}

void Home::movedown(double d)
{
    body->movedown(d);
    body->movedown(d);
    roof->movedown(d);
    door->movedown(d);
}

void Home::moveright(double d)
{
    body->moveright(d);
    body->moveright(d);
    roof->moveright(d);
    door->moveright(d);
}

void Home::moveleft(double d)
{
    body->moveleft(d);
    body->moveleft(d);
    roof->moveleft(d);
    door->moveleft(d);
}
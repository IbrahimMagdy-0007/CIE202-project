#include "CompositeShapes.h"
#include "gameConfig.h"
#include<fstream>

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

void Sign::save(ofstream& outFile)  {
    outFile << "Sign " << RefPoint.x << " " << RefPoint.y << "\n";
    top->save(outFile);
    base->save(outFile);
}

void Sign::Rotate90Clockwise() {

    point NEWREFRENCE;
    NEWREFRENCE.x = (base->getRefPoint().x - top->getRefPoint().x) * 0 - (base->getRefPoint().y - top->getRefPoint().y) * 1 + top->getRefPoint().x;
    NEWREFRENCE.y = (base->getRefPoint().y - top->getRefPoint().y) * 0 + (base->getRefPoint().x - top->getRefPoint().x) * 1 + top->getRefPoint().y;


    base->setRefPoint(NEWREFRENCE);

    base->Rotate90Clockwise();
    top->Rotate90Clockwise();
    if (rotatecounter < 4) {
        rotatecounter += 1;
    }
    if (rotatecounter == 4) {
        rotatecounter = 0;
    }
}
void Sign::resizeUp()
{
    point UPDATEPOINT;

    UPDATEPOINT.x = (base->sizeref().x - top->sizeref().x) * 2 + top->sizeref().x;
    UPDATEPOINT.y = (base->sizeref().y - top->sizeref().y) * 2 + top->sizeref().y;

    base->setRefPoint(UPDATEPOINT);
    
    base->resizeUp();
    top->resizeUp();
    sizecounter += 1;
}
void Sign::resizeDown()
{
    point UPDATEPOINT;

    UPDATEPOINT.x = (base->sizeref().x - top->sizeref().x) * 0.5 + top->sizeref().x;
    UPDATEPOINT.y = (base->sizeref().y - top->sizeref().y) * 0.5 + top->sizeref().y;

    base->setRefPoint(UPDATEPOINT);
    base->resizeDown();
    top->resizeDown();
    sizecounter -= 1;
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
string Sign::gettype()
{
    return "sign";
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
void car::Rotate90Clockwise() {
    point bodyRef = body->getRefPoint();

    // Calculate new reference points
    point newWheel1Ref;
    newWheel1Ref.x = (wheel1->getRefPoint().x - bodyRef.x) * 0 - (wheel1->getRefPoint().y - bodyRef.y) * 1 + bodyRef.x;
    newWheel1Ref.y = (wheel1->getRefPoint().y - bodyRef.y) * 0 + (wheel1->getRefPoint().x - bodyRef.x) * 1 + bodyRef.y;

    point newWheel2Ref;
    newWheel2Ref.x = (wheel2->getRefPoint().x - bodyRef.x) * 0 - (wheel2->getRefPoint().y - bodyRef.y) * 1 + bodyRef.x;
    newWheel2Ref.y = (wheel2->getRefPoint().y - bodyRef.y) * 0 + (wheel2->getRefPoint().x - bodyRef.x) * 1 + bodyRef.y;

    point newHeadRef;
    newHeadRef.x = (head->getRefPoint().x - bodyRef.x) * 0 - (head->getRefPoint().y - bodyRef.y) * 1 + bodyRef.x;
    newHeadRef.y = (head->getRefPoint().y - bodyRef.y) * 0 + (head->getRefPoint().x - bodyRef.x) * 1 + bodyRef.y;

    // Set new reference points
    wheel1->setRefPoint(newWheel1Ref);
    wheel2->setRefPoint(newWheel2Ref);
    head->setRefPoint(newHeadRef);

    // Rotate each part
    body->Rotate90Clockwise();
    wheel1->Rotate90Clockwise();
    wheel2->Rotate90Clockwise();
    head->Rotate90Clockwise();

    if (rotatecounter < 4) {
        rotatecounter += 1;
    }
    if (rotatecounter = 4) {
        rotatecounter = 0;
    }
}


void car::save(std::ofstream& outFile)  {
    outFile << "Car " << RefPoint.x << " " << RefPoint.y << "\n";
    body->save(outFile);
    wheel1->save(outFile);
    wheel2->save(outFile);
    head->save(outFile);
}
void car::resizeUp()
{
    point newWheel1Ref, newWheel2Ref, newHeadRef;

    // Adjust reference points relative to the body
    newWheel1Ref.x = (wheel1->sizeref().x - body->sizeref().x) * 2 + body->sizeref().x;
    newWheel1Ref.y = (wheel1->sizeref().y - body->sizeref().y) * 2 + body->sizeref().y;

    newWheel2Ref.x = (wheel2->sizeref().x - body->sizeref().x) * 2 + body->sizeref().x;
    newWheel2Ref.y = (wheel2->sizeref().y - body->sizeref().y) * 2 + body->sizeref().y;

    newHeadRef.x = (head->sizeref().x - body->sizeref().x) * 2 + body->sizeref().x;
    newHeadRef.y = (head->sizeref().y - body->sizeref().y) * 2 + body->sizeref().y;

    // Set new reference points
    wheel1->setRefPoint(newWheel1Ref);
    wheel2->setRefPoint(newWheel2Ref);
    head->setRefPoint(newHeadRef);

    // Resize each part
    body->resizeUp();
    wheel1->resizeUp();
    wheel2->resizeUp();
    head->resizeUp();
    sizecounter += 1;
}

void car::resizeDown()
{
    point newWheel1Ref, newWheel2Ref, newHeadRef;

    // Adjust reference points relative to the body
    newWheel1Ref.x = (wheel1->sizeref().x - body->sizeref().x) * 0.5 + body->sizeref().x;
    newWheel1Ref.y = (wheel1->sizeref().y - body->sizeref().y) * 0.5 + body->sizeref().y;

    newWheel2Ref.x = (wheel2->sizeref().x - body->sizeref().x) * 0.5 + body->sizeref().x;
    newWheel2Ref.y = (wheel2->sizeref().y - body->sizeref().y) * 0.5 + body->sizeref().y;

    newHeadRef.x = (head->sizeref().x - body->sizeref().x) * 0.5 + body->sizeref().x;
    newHeadRef.y = (head->sizeref().y - body->sizeref().y) * 0.5 + body->sizeref().y;

    // Set new reference points
    wheel1->setRefPoint(newWheel1Ref);
    wheel2->setRefPoint(newWheel2Ref);
    head->setRefPoint(newHeadRef);

    // Resize each part
    body->resizeDown();
    wheel1->resizeDown();
    wheel2->resizeDown();
    head->resizeDown();
    sizecounter -= 1;
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
string car::gettype()
{
    return "car";
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

void Robot::save(ofstream& outFile)  {
    outFile << "Robot " << RefPoint.x << " " << RefPoint.y << "\n";
    body->save(outFile);
    head->save(outFile);
    leftEye->save(outFile);
    rightEye->save(outFile);
    leftFoot->save(outFile);
    rightFoot->save(outFile);
}

void Robot::Rotate90Clockwise() {
    point bodyRef = body->getRefPoint();

    // Calculate new reference points
    point newHeadRef;
    newHeadRef.x = (head->getRefPoint().x - bodyRef.x) * 0 - (head->getRefPoint().y - bodyRef.y) * 1 + bodyRef.x;
    newHeadRef.y = (head->getRefPoint().y - bodyRef.y) * 0 + (head->getRefPoint().x - bodyRef.x) * 1 + bodyRef.y;

    point newLeftEyeRef;
    newLeftEyeRef.x = (leftEye->getRefPoint().x - bodyRef.x) * 0 - (leftEye->getRefPoint().y - bodyRef.y) * 1 + bodyRef.x;
    newLeftEyeRef.y = (leftEye->getRefPoint().y - bodyRef.y) * 0 + (leftEye->getRefPoint().x - bodyRef.x) * 1 + bodyRef.y;

    point newRightEyeRef;
    newRightEyeRef.x = (rightEye->getRefPoint().x - bodyRef.x) * 0 - (rightEye->getRefPoint().y - bodyRef.y) * 1 + bodyRef.x;
    newRightEyeRef.y = (rightEye->getRefPoint().y - bodyRef.y) * 0 + (rightEye->getRefPoint().x - bodyRef.x) * 1 + bodyRef.y;

    point newLeftFootRef;
    newLeftFootRef.x = (leftFoot->getRefPoint().x - bodyRef.x) * 0 - (leftFoot->getRefPoint().y - bodyRef.y) * 1 + bodyRef.x;
    newLeftFootRef.y = (leftFoot->getRefPoint().y - bodyRef.y) * 0 + (leftFoot->getRefPoint().x - bodyRef.x) * 1 + bodyRef.y;

    point newRightFootRef;
    newRightFootRef.x = (rightFoot->getRefPoint().x - bodyRef.x) * 0 - (rightFoot->getRefPoint().y - bodyRef.y) * 1 + bodyRef.x;
    newRightFootRef.y = (rightFoot->getRefPoint().y - bodyRef.y) * 0 + (rightFoot->getRefPoint().x - bodyRef.x) * 1 + bodyRef.y;

    // Set new reference points
    head->setRefPoint(newHeadRef);
    leftEye->setRefPoint(newLeftEyeRef);
    rightEye->setRefPoint(newRightEyeRef);
    leftFoot->setRefPoint(newLeftFootRef);
    rightFoot->setRefPoint(newRightFootRef);

    // Rotate each part
    body->Rotate90Clockwise();
    head->Rotate90Clockwise();
    leftEye->Rotate90Clockwise();
    rightEye->Rotate90Clockwise();
    leftFoot->Rotate90Clockwise();
    rightFoot->Rotate90Clockwise();

    if (rotatecounter < 4) {
        rotatecounter += 1;
    }
    if (rotatecounter = 4) {
        rotatecounter = 0;
    }
}
void Robot::resizeUp()
{
    point newHeadRef, newLeftEyeRef, newRightEyeRef, newLeftFootRef, newRightFootRef;

    // Adjust reference points relative to the body
    newHeadRef.x = (head->sizeref().x - body->sizeref().x) * 2 + body->sizeref().x;
    newHeadRef.y = (head->sizeref().y - body->sizeref().y) * 2 + body->sizeref().y;

    newLeftEyeRef.x = (leftEye->sizeref().x - body->sizeref().x) * 2 + body->sizeref().x;
    newLeftEyeRef.y = (leftEye->sizeref().y - body->sizeref().y) * 2 + body->sizeref().y;

    newRightEyeRef.x = (rightEye->sizeref().x - body->sizeref().x) * 2 + body->sizeref().x;
    newRightEyeRef.y = (rightEye->sizeref().y - body->sizeref().y) * 2 + body->sizeref().y;

    newLeftFootRef.x = (leftFoot->sizeref().x - body->sizeref().x) * 2 + body->sizeref().x;
    newLeftFootRef.y = (leftFoot->sizeref().y - body->sizeref().y) * 2 + body->sizeref().y;

    newRightFootRef.x = (rightFoot->sizeref().x - body->sizeref().x) * 2 + body->sizeref().x;
    newRightFootRef.y = (rightFoot->sizeref().y - body->sizeref().y) * 2 + body->sizeref().y;

    // Set new reference points
    head->setRefPoint(newHeadRef);
    leftEye->setRefPoint(newLeftEyeRef);
    rightEye->setRefPoint(newRightEyeRef);
    leftFoot->setRefPoint(newLeftFootRef);
    rightFoot->setRefPoint(newRightFootRef);

    // Resize each part
    body->resizeUp();
    head->resizeUp();
    leftEye->resizeUp();
    rightEye->resizeUp();
    leftFoot->resizeUp();
    rightFoot->resizeUp();
    sizecounter += 1;
}

void Robot::resizeDown()
{

    point newHeadRef, newLeftEyeRef, newRightEyeRef, newLeftFootRef, newRightFootRef;

    // Adjust reference points relative to the body
    newHeadRef.x = (head->sizeref().x - body->sizeref().x) * 0.5 + body->sizeref().x;
    newHeadRef.y = (head->sizeref().y - body->sizeref().y) * 0.5 + body->sizeref().y;

    newLeftEyeRef.x = (leftEye->sizeref().x - body->sizeref().x) * 0.5 + body->sizeref().x;
    newLeftEyeRef.y = (leftEye->sizeref().y - body->sizeref().y) * 0.5 + body->sizeref().y;

    newRightEyeRef.x = (rightEye->sizeref().x - body->sizeref().x) * 0.5 + body->sizeref().x;
    newRightEyeRef.y = (rightEye->sizeref().y - body->sizeref().y) * 0.5 + body->sizeref().y;

    newLeftFootRef.x = (leftFoot->sizeref().x - body->sizeref().x) * 0.5 + body->sizeref().x;
    newLeftFootRef.y = (leftFoot->sizeref().y - body->sizeref().y) * 0.5 + body->sizeref().y;

    newRightFootRef.x = (rightFoot->sizeref().x - body->sizeref().x) * 0.5 + body->sizeref().x;
    newRightFootRef.y = (rightFoot->sizeref().y - body->sizeref().y) * 0.5 + body->sizeref().y;

    // Set new reference points
    head->setRefPoint(newHeadRef);
    leftEye->setRefPoint(newLeftEyeRef);
    rightEye->setRefPoint(newRightEyeRef);
    leftFoot->setRefPoint(newLeftFootRef);
    rightFoot->setRefPoint(newRightFootRef);

    // Resize each part
    body->resizeDown();
    head->resizeDown();
    leftEye->resizeDown();
    rightEye->resizeDown();
    leftFoot->resizeDown();
    rightFoot->resizeDown();
    sizecounter -= 1;
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
string Robot::gettype()
{
    return "Robot";
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

void Boat::save(ofstream& outFile)  {
    outFile << "Boat " << RefPoint.x << " " << RefPoint.y << "\n";
    hull->save(outFile);
    cabin->save(outFile);
    mast->save(outFile);
    sail->save(outFile);
    flag->save(outFile);
}

void Boat::Rotate90Clockwise() {
    point hullRef = hull->getRefPoint();

    // Calculate new reference points
    point newCabinRef;
    newCabinRef.x = (cabin->getRefPoint().x - hullRef.x) * 0 - (cabin->getRefPoint().y - hullRef.y) * 1 + hullRef.x;
    newCabinRef.y = (cabin->getRefPoint().y - hullRef.y) * 0 + (cabin->getRefPoint().x - hullRef.x) * 1 + hullRef.y;

    point newMastRef;
    newMastRef.x = (mast->getRefPoint().x - hullRef.x) * 0 - (mast->getRefPoint().y - hullRef.y) * 1 + hullRef.x;
    newMastRef.y = (mast->getRefPoint().y - hullRef.y) * 0 + (mast->getRefPoint().x - hullRef.x) * 1 + hullRef.y;

    point newSailRef;
    newSailRef.x = (sail->getRefPoint().x - hullRef.x) * 0 - (sail->getRefPoint().y - hullRef.y) * 1 + hullRef.x;
    newSailRef.y = (sail->getRefPoint().y - hullRef.y) * 0 + (sail->getRefPoint().x - hullRef.x) * 1 + hullRef.y;

    point newFlagRef;
    newFlagRef.x = (flag->getRefPoint().x - hullRef.x) * 0 - (flag->getRefPoint().y - hullRef.y) * 1 + hullRef.x;
    newFlagRef.y = (flag->getRefPoint().y - hullRef.y) * 0 + (flag->getRefPoint().x - hullRef.x) * 1 + hullRef.y;

    // Set new reference points
    cabin->setRefPoint(newCabinRef);
    mast->setRefPoint(newMastRef);
    sail->setRefPoint(newSailRef);
    flag->setRefPoint(newFlagRef);

    // Rotate each part
    hull->Rotate90Clockwise();
    cabin->Rotate90Clockwise();
    mast->Rotate90Clockwise();
    sail->Rotate90Clockwise();
    flag->Rotate90Clockwise();
    if (rotatecounter < 4) {
        rotatecounter += 1;
    }
    if (rotatecounter = 4) {
        rotatecounter = 0;
    }
}

void Boat::resizeUp()
{
    point newHullRef, newCabinRef, newMastRef, newSailRef, newFlagRef;

    // Adjust reference points relative to their current positions
    newHullRef.x = (hull->sizeref().x - hull->sizeref().x) * 2 + hull->sizeref().x;
    newHullRef.y = (hull->sizeref().y - hull->sizeref().y) * 2 + hull->sizeref().y;

    newCabinRef.x = (cabin->sizeref().x - hull->sizeref().x) * 2 + hull->sizeref().x;
    newCabinRef.y = (cabin->sizeref().y - hull->sizeref().y) * 2 + hull->sizeref().y;

    newMastRef.x = (mast->sizeref().x - hull->sizeref().x) * 2 + hull->sizeref().x;
    newMastRef.y = (mast->sizeref().y - hull->sizeref().y) * 2 + hull->sizeref().y;

    newSailRef.x = (sail->sizeref().x - hull->sizeref().x) * 2 + hull->sizeref().x;
    newSailRef.y = (sail->sizeref().y - hull->sizeref().y) * 2 + hull->sizeref().y;

    newFlagRef.x = (flag->sizeref().x - hull->sizeref().x) * 2 + hull->sizeref().x;
    newFlagRef.y = (flag->sizeref().y - hull->sizeref().y) * 2 + hull->sizeref().y;

    // Set new reference points
    hull->setRefPoint(newHullRef);
    cabin->setRefPoint(newCabinRef);
    mast->setRefPoint(newMastRef);
    sail->setRefPoint(newSailRef);
    flag->setRefPoint(newFlagRef);

    // Resize each part
    hull->resizeUp();
    cabin->resizeUp();
    mast->resizeUp();
    sail->resizeUp();
    flag->resizeUp();
    sizecounter += 1;
}


void Boat::resizeDown()
{
    point newHullRef, newCabinRef, newMastRef, newSailRef, newFlagRef;

    // Adjust reference points relative to their current positions
    newHullRef.x = (hull->sizeref().x - hull->sizeref().x) * 0.5 + hull->sizeref().x;
    newHullRef.y = (hull->sizeref().y - hull->sizeref().y) * 0.5 + hull->sizeref().y;

    newCabinRef.x = (cabin->sizeref().x - hull->sizeref().x) * 0.5 + hull->sizeref().x;
    newCabinRef.y = (cabin->sizeref().y - hull->sizeref().y) * 0.5 + hull->sizeref().y;

    newMastRef.x = (mast->sizeref().x - hull->sizeref().x) * 0.5 + hull->sizeref().x;
    newMastRef.y = (mast->sizeref().y - hull->sizeref().y) * 0.5 + hull->sizeref().y;

    newSailRef.x = (sail->sizeref().x - hull->sizeref().x) * 0.5 + hull->sizeref().x;
    newSailRef.y = (sail->sizeref().y - hull->sizeref().y) * 0.5 + hull->sizeref().y;

    newFlagRef.x = (flag->sizeref().x - hull->sizeref().x) * 0.5 + hull->sizeref().x;
    newFlagRef.y = (flag->sizeref().y - hull->sizeref().y) * 0.5 + hull->sizeref().y;

    // Set new reference points
    hull->setRefPoint(newHullRef);
    cabin->setRefPoint(newCabinRef);
    mast->setRefPoint(newMastRef);
    sail->setRefPoint(newSailRef);
    flag->setRefPoint(newFlagRef);

    // Resize each part
    hull->resizeDown();
    cabin->resizeDown();
    mast->resizeDown();
    sail->resizeDown();
    flag->resizeDown();
    sizecounter -= 1;
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
string Boat::gettype()
{
    return "Boat";
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

void Rocket::save(std::ofstream& outFile) {
    outFile << "Rocket " << RefPoint.x << " " << RefPoint.y << "\n";
    body->save(outFile);
    fin1->save(outFile);
    fin2->save(outFile);
    top->save(outFile);
}


void Rocket::Rotate90Clockwise() {
    point bodyRef = body->getRefPoint();

    // Calculate new reference points
    point newFin1Ref;
    newFin1Ref.x = (fin1->getRefPoint().x - bodyRef.x) * 0 - (fin1->getRefPoint().y - bodyRef.y) * 1 + bodyRef.x;
    newFin1Ref.y = (fin1->getRefPoint().y - bodyRef.y) * 0 + (fin1->getRefPoint().x - bodyRef.x) * 1 + bodyRef.y;

    point newFin2Ref;
    newFin2Ref.x = (fin2->getRefPoint().x - bodyRef.x) * 0 - (fin2->getRefPoint().y - bodyRef.y) * 1 + bodyRef.x;
    newFin2Ref.y = (fin2->getRefPoint().y - bodyRef.y) * 0 + (fin2->getRefPoint().x - bodyRef.x) * 1 + bodyRef.y;

    point newNoseRef;
    newNoseRef.x = (top->getRefPoint().x - bodyRef.x) * 0 - (top->getRefPoint().y - bodyRef.y) * 1 + bodyRef.x;
    newNoseRef.y = (top->getRefPoint().y - bodyRef.y) * 0 + (top->getRefPoint().x - bodyRef.x) * 1 + bodyRef.y;

    // Set new reference points
    fin1->setRefPoint(newFin1Ref);
    fin2->setRefPoint(newFin2Ref);
    top->setRefPoint(newNoseRef);

    // Rotate each part
    body->Rotate90Clockwise();
    fin1->Rotate90Clockwise();
    fin2->Rotate90Clockwise();
    top->Rotate90Clockwise();
    if (rotatecounter < 4) {
        rotatecounter += 1;
    }
    if (rotatecounter = 4) {
        rotatecounter = 0;
    }
}
void Rocket::resizeUp()
{
    point newBodyRef = body->sizeref();
    point newFin1Ref, newFin2Ref, newNoseRef;

    // Adjust reference points relative to the body
    newFin1Ref.x = (fin1->sizeref().x - body->sizeref().x) * 2 + body->sizeref().x;
    newFin1Ref.y = (fin1->sizeref().y - body->sizeref().y) * 2 + body->sizeref().y;

    newFin2Ref.x = (fin2->sizeref().x - body->sizeref().x) * 2 + body->sizeref().x;
    newFin2Ref.y = (fin2->sizeref().y - body->sizeref().y) * 2 + body->sizeref().y;

    newNoseRef.x = (top->sizeref().x - body->sizeref().x) * 2 + body->sizeref().x;
    newNoseRef.y = (top->sizeref().y - body->sizeref().y) * 2 + body->sizeref().y;

    // Set new reference points
    fin1->setRefPoint(newFin1Ref);
    fin2->setRefPoint(newFin2Ref);
    top->setRefPoint(newNoseRef);

    // Resize each part
    body->resizeUp();
    fin1->resizeUp();
    fin2->resizeUp();
    top->resizeUp();
    sizecounter += 1;
}
void Rocket::resizeDown()
{
    point newBodyRef = body->sizeref();
    point newFin1Ref, newFin2Ref, newNoseRef;

    // Adjust reference points relative to the body
    newFin1Ref.x = (fin1->sizeref().x - body->sizeref().x) * 0.5 + body->sizeref().x;
    newFin1Ref.y = (fin1->sizeref().y - body->sizeref().y) * 0.5 + body->sizeref().y;

    newFin2Ref.x = (fin2->sizeref().x - body->sizeref().x) * 0.5 + body->sizeref().x;
    newFin2Ref.y = (fin2->sizeref().y - body->sizeref().y) * 0.5 + body->sizeref().y;

    newNoseRef.x = (top->sizeref().x - body->sizeref().x) * 0.5 + body->sizeref().x;
    newNoseRef.y = (top->sizeref().y - body->sizeref().y) * 0.5 + body->sizeref().y;

    // Set new reference points
    fin1->setRefPoint(newFin1Ref);
    fin2->setRefPoint(newFin2Ref);
    top->setRefPoint(newNoseRef);

    // Resize each part
    body->resizeDown();
    fin1->resizeDown();
    fin2->resizeDown();
    top->resizeDown();
    sizecounter -= 1;
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
string Rocket::gettype()
{
    return "Rocket";
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

void Home::save(std::ofstream& outFile)  {
    outFile << "Home " << RefPoint.x << " " << RefPoint.y << "\n";
    body->save(outFile);
    roof->save(outFile);
    door->save(outFile);
}

void Home::Rotate90Clockwise() {
    point bodyRef = body->getRefPoint();

    // Calculate new reference points
    point newRoofRef;
    newRoofRef.x = (roof->getRefPoint().x - bodyRef.x) * 0 - (roof->getRefPoint().y - bodyRef.y) * 1 + bodyRef.x;
    newRoofRef.y = (roof->getRefPoint().y - bodyRef.y) * 0 + (roof->getRefPoint().x - bodyRef.x) * 1 + bodyRef.y;

    point newDoorRef;
    newDoorRef.x = (door->getRefPoint().x - bodyRef.x) * 0 - (door->getRefPoint().y - bodyRef.y) * 1 + bodyRef.x;
    newDoorRef.y = (door->getRefPoint().y - bodyRef.y) * 0 + (door->getRefPoint().x - bodyRef.x) * 1 + bodyRef.y;

    // Set new reference points
    roof->setRefPoint(newRoofRef);
    door->setRefPoint(newDoorRef);

    // Rotate each part
    body->Rotate90Clockwise();
    roof->Rotate90Clockwise();
    door->Rotate90Clockwise();

    if (rotatecounter < 4) {
        rotatecounter += 1;
    }
    if (rotatecounter = 4) {
        rotatecounter = 0;
    }
}

void Home::resizeUp()
{
    point newBodyRef = body->sizeref();
    point newRoofRef, newDoorRef;

    // Adjust reference points relative to the body
    newRoofRef.x = (roof->sizeref().x - body->sizeref().x) * 2 + body->sizeref().x;
    newRoofRef.y = (roof->sizeref().y - body->sizeref().y) * 2 + body->sizeref().y;

    newDoorRef.x = (door->sizeref().x - body->sizeref().x) * 2 + body->sizeref().x;
    newDoorRef.y = (door->sizeref().y - body->sizeref().y) * 2 + body->sizeref().y;

    // Set new reference points
    roof->setRefPoint(newRoofRef);
    door->setRefPoint(newDoorRef);

    // Resize each part
    body->resizeUp();
    roof->resizeUp();
    door->resizeUp();
    sizecounter -= 1;
}
void Home::resizeDown()
{
    point newBodyRef = body->sizeref();
    point newRoofRef, newDoorRef;

    // Adjust reference points relative to the body
    newRoofRef.x = (roof->sizeref().x - body->sizeref().x) * 0.5 + body->sizeref().x;
    newRoofRef.y = (roof->sizeref().y - body->sizeref().y) * 0.5 + body->sizeref().y;

    newDoorRef.x = (door->sizeref().x - body->sizeref().x) * 0.5 + body->sizeref().x;
    newDoorRef.y = (door->sizeref().y - body->sizeref().y) * 0.5 + body->sizeref().y;

    // Set new reference points
    roof->setRefPoint(newRoofRef);
    door->setRefPoint(newDoorRef);

    // Resize each part
    body->resizeDown();
    roof->resizeDown();
    door->resizeDown();
    sizecounter -= 1;
}
void Home::moveup(double d)
{
    body->moveup(d);
    body->moveup(d);
    roof->moveup(2*d);
    door->moveup(2*d);
}

void Home::movedown(double d)
{
    body->movedown(d);
    body->movedown(d);
    roof->movedown(2*d);
    door->movedown(2*d);
}

void Home::moveright(double d)
{
    body->moveright(d);
    body->moveright(d);
    roof->moveright(2*d);
    door->moveright(2*d);
}

void Home::moveleft(double d)
{
    body->moveleft(d);
    body->moveleft(d);
    roof->moveleft(2*d);
    door->moveleft(2*d);
}

string Home::gettype()
{
    return "Home";
}











#ifndef SHIP_H

#define SHIP_H
#include "oxygine-framework.h"
#include "config.h"
#include "gun.h"
#include "Bullet.h"

using namespace oxygine;


using namespace std;
class Ship : public Actor
{
public:
    Ship(vector<spBullet> &bullets, int team, int x = 0, int y = 0);
    void move(double x , double y);
    void ciber();
    void moveToLine(double x , double y);
    double getSpeed();
    double getVector();
    void hit();
    int team;
    double hp;
    bool AI;

private:
    spSprite ship;
    spGun centralGun;
    spGun leftGun;
    spGun rightGun;
    spColorRectSprite hpSprite;
    double speed;


    void _rotate(double angle);
    void fire();

};
typedef intrusive_ptr<Ship> spShip;
#endif // SHIP_H

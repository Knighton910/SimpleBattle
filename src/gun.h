#ifndef GUN_H

#define GUN_H
#include "oxygine-framework.h"
#include "config.h"
#include "Bullet.h"

using namespace oxygine;


using namespace std;
class Gun : public Actor
{
public:
    Gun(vector<spBullet> &bullets);
    void _rotate(double angle);
    void fire(Vector2 position, double ship_angle, double speed, int team);


private:
    spSprite gun;
    vector<spBullet> &bullets;
};
typedef intrusive_ptr<Gun> spGun;
#endif // SHIP_H

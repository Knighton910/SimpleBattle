#ifndef BULLET_H

#define BULLET_H
#include "oxygine-framework.h"
#include "config.h"

using namespace oxygine;


using namespace std;
class Bullet : public Actor
{
public:
    Bullet(Vector2 position, double angle, double speed, int team);
    void move();
    double speed;
    int team;


private:
    spSprite bullet;
};
typedef intrusive_ptr<Bullet> spBullet;
#endif // BULLET_H

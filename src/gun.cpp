#include "gun.h"


Gun::Gun(vector<spBullet> &_bullets) : bullets(_bullets)
{
    gun = new Sprite();
    gun->setResAnim(config::resources.getResAnim("Gun"));
    this->setSize(gun->getSize());
    this->setAnchor(0.5f, 0.5f);
    addChild(gun);
}

void Gun::_rotate(double angle)
{
    this->setRotationDegrees(getRotationDegrees() + angle);
}

void Gun::fire(Vector2 position, double ship_angle, double speed, int team)
{

    Vector2 ship_position =  position;
    Vector2 myPosition = Vector2(
                getPosition().x ,
                getPosition().y
                );

    //log::messageln(" ----- %f %f" , getPosition().x, getPosition().y);
    spBullet bullet = new Bullet(ship_position + myPosition, getRotationDegrees() + ship_angle, speed , team);
    bullets.push_back(bullet);

}

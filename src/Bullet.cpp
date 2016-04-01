#include "Bullet.h"


Bullet::Bullet(Vector2 _position, double _angle, double _speed, int _team)
{
    bullet = new Sprite();
    bullet->setResAnim(config::resources.getResAnim("Bullet"));
    bullet->setAnchor(0.5, 0.5);
    team = _team;
    setAnchor(0.5,0.5);
    setPosition(_position);
    addChild(bullet);

    speed = _speed;
    setRotationDegrees(_angle);
}

void Bullet::move()
{
    double new_x = getX() + speed*cos(getRotation() + MATH_PI/2);
    double new_y = getY() + speed*sin(getRotation() + MATH_PI/2);
    setPosition(new_x, new_y);
    speed -= 0.02;
    if (speed < 0)
        speed = 0.0;
}


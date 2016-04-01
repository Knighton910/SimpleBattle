#include "ship.h"

Ship::Ship(vector<spBullet> &bullets,  int _team,int x, int y)
{
    speed = -1.0;
    ship = new Sprite();
    ship->setResAnim(config::resources.getResAnim("Ship"));
    hp = 100;
    team = _team;

    AI = true;
    centralGun = new Gun(bullets);
    centralGun->setX(ship->getWidth()/2);
    centralGun->setY(ship->getHeight()*2/3);

    leftGun = new Gun(bullets);
    leftGun->setX(ship->getWidth()/3);
    leftGun->setY(ship->getHeight()/2);
    leftGun->setScale(0.5, 0.5);

    rightGun = new Gun(bullets);
    rightGun->setX(ship->getWidth()*2/3);
    rightGun->setY(ship->getHeight()/2);
    rightGun->setScale(0.5, 0.5);

    hpSprite = new ColorRectSprite();
    //hpSprite->setAnchor(1, 0.5);
    hpSprite->setSize(5,10);
    hpSprite->setScaleX((hp)/10);
    hpSprite->setPosition( 0,  - ship->getHeight()/2);
    hpSprite->setColor(Color::Red);

    this->setPosition(x,y);
    this->setSize(ship->getSize());
    this->setAnchor(0.5f, 0.5f);
    addChild(ship);
    addChild(leftGun);
    addChild(rightGun);
    addChild(centralGun);
    addChild(hpSprite);

}

void Ship::hit()
{
    hp --;
    hpSprite->setScaleX((hp)/10);
}

void Ship::_rotate(double angle)
{
    this->setRotationDegrees(getRotationDegrees() + angle);
}

double Ship::getSpeed()
{
    return this->speed;
}

void Ship::move(double x, double y)
{

    double new_x = getX() + speed*cos(getRotation() + MATH_PI/2);
    double new_y = getY() + speed*sin(getRotation() + MATH_PI/2);
    setPosition(new_x, new_y);
}

double Ship::getVector()
{
    return sqrt(pow(getX(),2) + pow(getY(),2));
}

void Ship::moveToLine(double x, double y)
{


    double new_x = getX() + speed*cos(getRotation() + MATH_PI/2);
    double new_y = getY() + speed*sin(getRotation() + MATH_PI/2);

     double len =  sqrt( pow(new_x - x, 2) + pow(new_y - y, 2) );
    setPosition(new_x, new_y);
    //log::messageln("%d", ship->getRotationDegrees());
    addTween(TweenPosition(Vector2(new_x, new_y)), 1000,1);

    double x1 = getX(), y1 = getY();
    double x2 = x, y2 = y;
    double A = atan2( y2 - y1,  x2 - x1)+ MATH_PI/2 ;
    setRotation(A);
    if (len  < 300)
        fire();

}

void Ship::fire()
{
    centralGun->fire(getPosition() - getSize()/2, getRotationDegrees() + 180, 4.9, team);
    leftGun->fire(getPosition() - getSize()/2, getRotationDegrees() + 180, 3.1, team);
    rightGun->fire(getPosition() - getSize()/2, getRotationDegrees() + 180, 3.1, team);
}

void Ship::ciber()
{
    AI= false;
    Input::instance.addEventListener(Input::event_platform, [this](Event* ev)
        {
            SDL_Event *event = (SDL_Event*)ev->userData;

            if (event->type != SDL_KEYDOWN)
                return;

            switch (event->key.keysym.sym)
            {
                case SDLK_RIGHT:
                    this->_rotate(1.0);
                    break;
                case SDLK_LEFT:
                    this->_rotate(-1.0);
                    break;
                case SDLK_UP:
                    speed -= 0.05;
                    break;
                case SDLK_DOWN:
                    speed += 0.05;
                    break;
                case SDLK_w:
                    fire();
                    break;
                case SDLK_q:
                    leftGun->_rotate(-1);
                    rightGun->_rotate(-1);
                    centralGun->_rotate(-1);
                break;
                case SDLK_e:
                    leftGun->_rotate(1);
                    rightGun->_rotate(1);
                    centralGun->_rotate(1);
                break;
            }
        });
}

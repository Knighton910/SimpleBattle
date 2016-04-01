#include "PlotBet.h"

PlotBet::PlotBet(double _value, Vector2 start, Vector2 finish, double _win, Color color, double _height)
{
    betSprite = new ColorRectSprite();
    betSprite->setColor(color);
    betSprite->setSize(1.0, _height);
    betSprite->setPosition(start);
    betSprite->setAnchor(0.0, 0.5);
    betSprite->setAlpha(75);
    if (_win > 0)
    {
        double angle = atan2( finish.y - start.y,  finish.x - start.x) ;
        double scalex = sqrt(pow(start.x - finish.x, 2) + pow(start.y - finish.y, 2 ));
        betSprite->setScaleX(scalex);
        betSprite->setRotation(angle);

        value = new TextField();
        value->setText(to_string(_value));
        value->setPosition(finish);
        addChild(value);
    }else
    {
        betSprite->setAnchor(0.5, 0.5);
        betSprite->setSize(5,5);
    }
    addChild(betSprite);


}

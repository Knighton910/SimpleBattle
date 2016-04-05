#include "PlotBet.h"
#include "Row.h"

PlotBet::PlotBet(double _value, Vector2 start, Vector2 finish, double _win, TextStyle style, Color color, double _height)
{
    betSprite = new ColorRectSprite();
    betSprite->setColor(color);
    betSprite->setSize(1.0, _height);
    betSprite->setPosition(start);
    betSprite->setAnchor(0.0, 0.5);
    addChild(betSprite);
    if (_win > 0)
    {
        double angle = atan2( finish.y - start.y,  finish.x - start.x) ;
        double scalex = sqrt(pow(start.x - finish.x, 2) + pow(start.y - finish.y, 2 ));
        betSprite->setScaleX(scalex);
        betSprite->setRotation(angle);

        background = new ColorRectSprite();
        background->setColor(Color::WhiteSmoke);
        background->setSize(_height, 20);
        background->setAnchor(0.5, 0);
        background->setPosition(finish.x, 0);
        addChild(background);

        value = new TextField();
        value->setText(cutDouble( _value) );
        value->setStyle(style);
        value->setX(background->getWidth()/2);
        value->setY(background->getHeight()/2);
        background->addChild(value);
    }else
    {
        betSprite->setAnchor(0.5, 0.5);
        betSprite->setSize(5,5);
    }
}

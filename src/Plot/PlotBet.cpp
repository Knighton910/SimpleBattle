#include "PlotBet.h"
#include "Row.h"

PlotBet::PlotBet(double _value, Vector2 start, Vector2 finish, double _win, TextStyle style, Color color, double _heightLine, double _heightBackground)
{
    betSprite = new ColorRectSprite();
    betSprite->setColor(color);
    betSprite->setPosition(start);
    betSprite->setAnchor(0.0, 0.5);

    if (_win > 0)
    {
        double angle = atan2( finish.y - start.y,  finish.x - start.x) ;
        double scalex = sqrt(pow(start.x - finish.x, 2) + pow(start.y - finish.y, 2 ));

        backgroundBetSprite = new ColorRectSprite();
        backgroundBetSprite->setColor(Color::Black);
        backgroundBetSprite->setSize(scalex + 3, _heightLine + 3);
        backgroundBetSprite->setPosition(start);
        backgroundBetSprite->setAnchor(0.0, 0.5);
        backgroundBetSprite->setRotation(angle);
        addChild(backgroundBetSprite);

        betSprite->setRotation(angle);
        betSprite->setSize(scalex, _heightLine);


        littleLine = new ColorRectSprite();
        littleLine->setColor(Color::WhiteSmoke);
        littleLine->setSize(1, _heightBackground);
        littleLine->setAnchor(0.5, 1);
        littleLine->setPosition(finish.x, finish.y);
        addChild(littleLine);

        background = new ColorRectSprite();
        background->setColor(Color::WhiteSmoke);
        background->setSize(_heightLine, _heightBackground);
        background->setAnchor(0.5, 0);
        background->setPosition(finish.x, finish.y - 2*background->getHeight());
        addChild(background);

        value = new TextField();
        value->setText(cutDouble( _value) );
        value->setStyle(style);
        value->setX(background->getWidth()/2);
        value->setY(0);
        background->addChild(value);
    }else
    {
        betSprite->setAnchor(0.5, 0.5);
        betSprite->setSize(5,5);
    }
    addChild(betSprite);

}

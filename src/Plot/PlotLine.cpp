#include "PlotLine.h"

PlotLine::PlotLine(Vector2 start, Vector2 finish, Color color,double _height)
{
    line = new ColorRectSprite();
    line->setColor(color);
    line->setSize(1.0, _height);
    line->setPosition(start);
    line->setAnchor(0.0, 0.5);

    double angle = atan2( finish.y - start.y,  finish.x - start.x) ;
    double scalex = sqrt(pow(start.x - finish.x, 2) + pow(start.y - finish.y, 2 ));

    line->setScaleX(scalex);
    line->setRotation(angle);
    addChild(line);
}

#include "Row.h"

Row::Row(double _value, Vector2 start, Vector2 finish, TextStyle textStyle, Color _colorRow, double height)
{
    line = new PlotLine(start, finish, _colorRow, height);
    addChild(line);

    value = new TextField();
    value->setText(to_string(_value));
    value->setPosition(finish);
    value->setStyle(textStyle);
    value->setColor(_colorRow);
    addChild(value);

}

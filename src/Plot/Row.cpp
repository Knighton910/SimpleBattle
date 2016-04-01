#include "Row.h"

Row::Row(double _value, Vector2 start, Vector2 finish, Color _colorRow)
{
    line = new PlotLine(start, finish, _colorRow);
    addChild(line);

    TextStyle styleTextLoad;

    styleTextLoad.font = config::resources.getResFont("main")->getFont();
    styleTextLoad.vAlign = TextStyle::VALIGN_MIDDLE;

    value = new TextField();
    value->setText(to_string(_value));
    value->setPosition(finish);
    value->setStyle(styleTextLoad);
    value->setScale(1.5);
    value->setColor(_colorRow);
    addChild(value);

}

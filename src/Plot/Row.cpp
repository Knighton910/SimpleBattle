#include "Row.h"

Row::Row(double _value, Vector2 start, Vector2 finish, TextStyle textStyle, Color _colorRow, double height)
{
    line = new PlotLine(start, finish, _colorRow, height);
    addChild(line);

    value = new TextField();
    value->setText(cutDouble(_value));
    value->setPosition(finish);
    value->setStyle(textStyle);
    value->setColor(_colorRow);
    addChild(value);
}

string cutDouble(double a)
{
    string result = "";
    string count = to_string(a);
    for(int i = 0; i < count.length(); i++)
    {
        if(count[i] == '.')
        {
            result += count[i];
            result += count[i + 1];
            result += count[i + 2];
            result += count[i + 3];
            return result;
        }
        else
        {
            result += count[i];
        }
    }
    return result;
}

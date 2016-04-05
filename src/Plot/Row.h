//
//  Row.h
//  slots
//
//  Created by iAppleJack on 24.03.16.
//  Copyright (c) 2016 oxygine. All rights reserved.
//
#include "oxygine-framework.h"
#include "PlotLine.h"

//Специальная линия-строка с показателем коэффициента
using namespace oxygine;
using namespace std;

class Row: public Actor
{
public:
    Row(double _value, Vector2 start, Vector2 finish, TextStyle textStyle, Color colorRow = Color::Gray, double height = 5.0);
private:
    spPlotLine line;
    spTextField value;

};

string cutDouble(double a);
typedef oxygine::intrusive_ptr<Row> spRow;

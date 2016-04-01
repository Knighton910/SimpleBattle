//
//  Row.h
//  slots
//
//  Created by iAppleJack on 24.03.16.
//  Copyright (c) 2016 oxygine. All rights reserved.
//
#include <stdio.h>
#include <math.h>
#include "oxygine-framework.h"
#include "PlotLine.h"
#include "../config.h"
//Специальная линия-строка с показателем коэффициента
using namespace oxygine;
using namespace std;

class Row: public Actor
{
public:
    Row(double _value, Vector2 start, Vector2 finish, Color colorRow = Color::Gray);
private:
    spPlotLine line;
    spTextField value;

};
typedef oxygine::intrusive_ptr<Row> spRow;
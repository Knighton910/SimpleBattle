//
//  PlotLine.h
//  slots
//
//  Created by iAppleJack on 24.03.16.
//  Copyright (c) 2016 oxygine. All rights reserved.
//
#include <stdio.h>
#include <math.h>
#include "oxygine-framework.h"

using namespace oxygine;
using namespace std;
//Любые Линии на графике

class PlotLine: public Actor
{
public:
    PlotLine(Vector2 start, Vector2 finish, Color color = Color::Yellow, double height = 5.0);
private:
    spColorRectSprite line;

};
typedef oxygine::intrusive_ptr<PlotLine> spPlotLine;

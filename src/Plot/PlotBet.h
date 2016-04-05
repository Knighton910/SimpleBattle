//
//  PlotBet.h
//  slots
//
//  Created by iAppleJack on 25.03.16.
//  Copyright (c) 2016 oxygine. All rights reserved.
//
#include <stdio.h>
#include <math.h>
#include "oxygine-framework.h"
//Точка на графике рисует либо Квадратик 5х5 либо широкий график ставки

using namespace oxygine;
using namespace std;

class PlotBet: public Actor
{
public:
    PlotBet(double _value, Vector2 start, Vector2 finish, double _win, TextStyle style ,Color color = Color::Yellow, double height = 5.0);
private:
    spColorRectSprite betSprite;
    spColorRectSprite background;
    spTextField value;


};
typedef oxygine::intrusive_ptr<PlotBet> spPlotBet;

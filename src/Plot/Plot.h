//
//  Plot.h
//  slots
//
//  Created by iAppleJack on 24.03.16.
//  Copyright (c) 2016 oxygine. All rights reserved.
//
// Актер на котором отображается график
//
#include <stdio.h>
#include <math.h>
#include "oxygine-framework.h"
#include "Row.h"
#include "PlotPoint.h"
#include "PlotBet.h"


using namespace oxygine;
using namespace std;

class Plot: public Actor
{
public:
    Plot(int width, int height);
    //Конструктор  принимает 2 параметра ширину и длину Актера на котором отображается график
    void update(vector<spPlotPoint> _sample, int rows_count = 10);
    // Метод принимает выборку точек типа PlotPoint, и количество строк (единиц) на графике
private:
    spActor plotActor;
    vector<spPlotPoint> points;
    int cols;
    int rows_count;
    double min;
    double max;
    double stepX;
    void takeMinMax(vector<spPlotPoint> _sample);
    void takePoints(vector<spPlotPoint> _sample);

};
typedef oxygine::intrusive_ptr<Plot> spPlot;

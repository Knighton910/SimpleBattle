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
    //Конструктор  принимает 2 параметра ширину и длину Актера на котором отображается график
    Plot(int width, int height, TextStyle textStyle, double lineHeight = 3.0);

    // Метод принимает выборку точек типа PlotPoint, и количество строк (единиц) на графике
    void update(vector<spPlotPoint> _sample, int _rows_count = 10);

    template <class IterT>
    void update(IterT begin, IterT end, int _rows_count = 10);

private:
    TextStyle textStyle;

    TextStyle rowRStyle;
    TextStyle rowLStyle;

    double height;
    spActor plotActor;
    vector<spPlotPoint> points;

    vector<spPlotPoint> Bpoints;
    int cols;
    int rows_count;
    double min_open;
    double max_open;

    double min_close;
    double max_close;
    double stepX;

    template <class IterT>
    void takePoints(IterT begin, IterT end);

    template <class IterT>
    void takeMinMax(IterT begin, IterT end);
};
typedef oxygine::intrusive_ptr<Plot> spPlot;

template <class IterT>
void Plot::update(IterT begin, IterT end, int _rows_count)
{
    rows_count = _rows_count;
    plotActor->detach();
    plotActor = new Actor();
    plotActor->setSize(getSize());

    spClipRectActor plotClipActor = new ClipRectActor();
    plotClipActor->setSize(getSize());


    addChild(plotActor);
    points.clear();
    Bpoints.clear();
    takeMinMax(begin, end);
    takePoints(begin, end);
    for (int i = 0; i < rows_count + 1; i++)
    {
        double value = max_open - i*(max_open - min_open)/rows_count;
        TextStyle rowRStyle;
        rowRStyle = textStyle;
        rowRStyle.hAlign = TextStyle::HALIGN_LEFT;

        spRow row = new Row(value, Vector2(0, i*getHeight()/rows_count), Vector2(getWidth(), i*getHeight()/rows_count), rowRStyle, Color::Gray, height);
        plotActor->addChild(row);

        TextStyle rowLStyle;
        rowLStyle = textStyle;
        rowLStyle.hAlign = TextStyle::HALIGN_RIGHT;

        value = max_close - i*(max_close - min_close)/rows_count;

        row = new Row(value , Vector2(getWidth(), i*getHeight()/rows_count), Vector2(0, i*getHeight()/rows_count), rowLStyle, Color::Gray, height);
        plotActor->addChild(row);
    }

    IterT it = begin;
    for (size_t i = 0; i < points.size() - 1;  i++)
    {
        spPlotLine pl = new PlotLine(points[i]->position, points[i+1]->position, Color::Yellow, height + 2);
        plotClipActor->addChild(pl);
    }
    for (size_t i = 0; i < Bpoints.size() - 1; ++it, i++)
    {

        TextStyle betStyle;
        betStyle.color = Color::Black;
        betStyle.hAlign = TextStyle::HALIGN_CENTER;
        betStyle.vAlign = TextStyle::VALIGN_MIDDLE;
        betStyle.font = textStyle.font;

        double ymax = ((*it)->value + (*it)->win - min_close);
        ymax = ymax/(max_close - min_close);
        ymax *= getHeight();
        ymax = getHeight() - ymax;

        double ymin = ((*it)->value - min_close);
        ymin = ymin/(max_close - min_close);
        ymin *= getHeight();
        ymin = getHeight() - ymin;

        spPlotBet pb = new PlotBet((*it)->value +  (*it)->win  ,Vector2(stepX*i, ymin), Vector2(stepX*i, ymax),(*it)->win, betStyle,Color::Red, 5*stepX);
        plotClipActor->addChild(pb);
    }
    plotActor->addChild(plotClipActor);
}

template <class IterT>
void Plot::takeMinMax(IterT begin, IterT end)
{
    if (end - begin > 1)
    {
        min_open = (*begin)->value;
        max_open = (*begin)->value;

        min_close = (*begin)->value;
        max_close = (*begin)->value;
        for (auto it = begin; it != end; ++it)
        {
            if (min_open > (*it)->value)
                min_open = (*it)->value;
            if (max_open < (*it)->value)
                max_open = ((*it)->value);
            if (max_close < (*it)->value + (*it)->win)
                max_close = ((*it)->value + (*it)->win);
            if (min_close > (*it)->value + (*it)->win)
                min_close = ((*it)->value + (*it)->win);
        }

        min_open -= (max_open - min_open)*0.01;
        min_open *= 0.999;
        max_open += (max_open - min_open)*0.01;
        max_open *= 1.001;

        min_close -= (max_close - min_close)*0.01;
        min_close *= 0.999;
        max_close += (max_close - min_close)*0.01;
        max_close *= 1.001;

        if (max_close > max_open)
        {
            max_close *= 1.1;
        }
        stepX = getWidth()/((end - begin) -1);
    }
}

template <class IterT>
void Plot::takePoints(IterT begin, IterT end)
{
    for (auto it = begin; it != end; ++it)
    {
        double xi = (it - begin) * stepX;
        double yi = ((*it)->value - min_open);
        yi = yi/(max_open - min_open);
        yi *= getHeight();
        yi = getHeight() - yi;
        points.push_back(new PlotPoint(yi, 0.0, Vector2(xi,yi)));

        xi = (it - begin) * stepX;
        yi = ((*it)->value + (*it)->win - min_close);
        yi = yi/(max_close - min_close);
        yi *= getHeight();
        yi = getHeight() - yi;
        Bpoints.push_back(new PlotPoint(yi, 0.0, Vector2(xi,yi)));
    }


}

#include "Plot.h"

Plot::Plot(int width, int height, TextStyle textStyle, double lineHeight) :
    textStyle(textStyle),
    height(lineHeight)
{
    setSize(width, height);
    plotActor = new Actor();
    addChild(plotActor);
    max_open = 0.0;
    min_open = 0.0;

    min_close = 0.0;
    max_close = 0.0;

    stepX = 0.0f;
}

void Plot::update(vector<spPlotPoint> _sample, int _rows_count)
{
    update(_sample.begin(), _sample.end(), _rows_count);
}

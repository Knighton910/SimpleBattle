#include "Plot.h"

Plot::Plot(int width, int height)
{
    spColorRectSprite background = new ColorRectSprite();
    background->setColor(Color::Black);
    background->setSize(width, height);
    addChild(background);
    setSize(width, height);
    plotActor = new Actor();
    addChild(plotActor);
    max = 0.0;
    min = 0.0;
    int cols = 0;
    stepX = 0.0f;
}

void Plot::update(vector<spPlotPoint> _sample, int _rows_count)
{
    rows_count = _rows_count;
    plotActor->detach();
    plotActor = new Actor();
    addChild(plotActor);
    points.clear();
    takeMinMax(_sample);
    takePoints(_sample);
    for (int i = 0; i < rows_count + 1; i++)
    {
        double x = 0;
        double value = max - i*(max - min)/rows_count;

        spRow row = new Row(value, Vector2(0, i*getHeight()/rows_count), Vector2(getWidth(), i*getHeight()/rows_count));
        plotActor->addChild(row);        

        value = max - i*(max)/rows_count;

        row = new Row(value , Vector2(getWidth(), i*getHeight()/rows_count), Vector2(0, i*getHeight()/rows_count));
        plotActor->addChild(row);
    }

    double value = _sample.back()->value;

    for (int i = 0; i < points.size() - 1; i++)
    {
        spPlotLine pl = new PlotLine(points[i]->position, points[i+1]->position);
        plotActor->addChild(pl);

        double yi = (_sample[i]->value + _sample[i]->win - min);
        yi = yi/(max - min);
        yi *= getHeight();
        yi = getHeight() - yi;
        spPlotBet pb = new PlotBet(_sample[i]->value + _sample[i]->win ,points[i]->position, Vector2(points[i]->position.x, yi), _sample[i]->win ,Color::Red, stepX);
        plotActor->addChild(pb);


    }


}

void Plot::takeMinMax(vector<spPlotPoint> _sample)
{
    if (_sample.size() != 0)
    {
        min = _sample[0]->value;
        max = _sample[0]->value;
        for (int i = 0; i < _sample.size(); i++)
        {
            if (min > _sample[i]->value)
                min = _sample[i]->value;
            if (max < _sample[i]->value + _sample[i]->win)
                max = (_sample[i]->value + _sample[i]->win);
        }
        stepX = getWidth()/(_sample.size() -1);
    }
}

void Plot::takePoints(vector<spPlotPoint> _sample)
{
    for (int i = 0; i < _sample.size(); i++)
    {
        double xi = i * stepX;
        double yi = (_sample[i]->value - min);
        yi = yi/(max - min);
        yi *= getHeight();
        yi = getHeight() - yi;
        points.push_back(new PlotPoint(yi, 0.0, Vector2(xi,yi)));
    }
}

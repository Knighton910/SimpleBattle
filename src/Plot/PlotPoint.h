#include <stdio.h>
#include <math.h>
#include "oxygine-framework.h"

using namespace oxygine;
using namespace std;

class PlotPoint: public Actor
{
public:
    PlotPoint(double value, double win = 0.0, Vector2 position = Vector2(0,0));
    double value;
    double win;
    Vector2 position;

};
typedef oxygine::intrusive_ptr<PlotPoint> spPlotPoint;

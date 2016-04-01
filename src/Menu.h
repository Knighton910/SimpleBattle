#ifndef MENU_H

#define MENU_H
#include "oxygine-framework.h"
#include "config.h"
#include "ship.h"
#include "Plot/Plot.h"


using namespace oxygine;


using namespace std;
class Menu : public Actor
{
public:
    Menu();
    void update();
    spShip s;

    vector<spShip> enemies;
    int temp = 0;
    spPlot plot;
    vector<spPlotPoint> speed;

    vector<spBullet> bullets;
};
typedef intrusive_ptr<Menu> spMenu;
#endif // MENU_H

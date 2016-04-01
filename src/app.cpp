#include "oxygine-framework.h"
#include "config.h"
#include "Menu.h"
using namespace oxygine;

//it is our resources
//in real project you would have more than one Resources declarations. It is important on mobile devices with limited memory and you would load/unload them


void app_preinit()
{

}
void app_init()
{
    SDL_ShowCursor(1);

    config::init("res.xml");
    log::messageln("Hello world");
    spMenu menu = new Menu();
    getStage()->addChild(menu);

    getStage()->addEventListener(TouchEvent::CLICK,  [] (Event* e)
                {
                    TouchEvent* te = (TouchEvent*) e;
                   // log::messageln("%f %f", te->position.x, te->position.y);

                });
    //spMap map = new Map();
    //getStage()->addChild(map);
}



void app_update()
{

}

void app_destroy()
{
	config::free();
}




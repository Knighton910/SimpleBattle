#include "Menu.h"

Menu::Menu()
{
    TextStyle ts;

    ts.color = Color::Blue;
    ts.hAlign = TextStyle::HALIGN_CENTER;
    ts.vAlign = TextStyle::VALIGN_MIDDLE;
    ts.font = config::resources.getResFont("main")->getFont();

    plot = new Plot(600,400, ts);
    plot->setPosition(150,100);
    addChild(plot);
    s = new Ship(bullets,  0, 200,200);
    addChild(s);
    enemies.push_back(s);
    //enemy = new Ship(bullets,600,200);
    //addChild(enemy);

    for (int i = 0; i < 3; i ++)
    {
        for (int j = 0; j < 0; j ++)
        {
            spShip evil =  new Ship(bullets,  100 , 500 + j*100,200 * i);
            addChild(evil);
            enemies.push_back(evil);

        }
    }

    for (int i = 0; i < 30; i++)
    {
        speed.push_back(new PlotPoint(1.0, 0.0f));
    }
    s->ciber();
    spTween tween = this->addTween(TweenDummy(), 16);
    tween->addEventListener(TweenEvent::DONE, [this](Event* e)
    {
        update();
    }
            );
}

void Menu::update()
{
    temp ++;
    s->move(0,0);


    speed.erase(speed.begin());
    if (temp % 50 == 45)
        speed.push_back(new PlotPoint(s->getVector(), s->getVector()*0.05));
    else
        speed.push_back(new PlotPoint(s->getVector(), 0.0f));
    plot->update(speed);
    spTween tween = this->addTween(TweenDummy(), 200);
    for (int i = 0; i < bullets.size(); i++)
    {
        bullets[i]->move();
        addChild(bullets[i]);


        if (bullets[i]->speed == 0.0)
        {
            bullets[i]->detach();
            bullets.erase(bullets.begin() + i);

        }
    }
    for (int j = 0; j < enemies.size(); j++)
    {
        if (enemies[j]->AI)
            enemies[j]->moveToLine(s->getX(), s->getY());
        for (int i = 0; i < bullets.size(); i++)
        {
            double x = enemies[j]->getX() + enemies[j]->getWidth()/2 - bullets[i]->getX();
            double y = enemies[j]->getY() + enemies[j]->getHeight()/2 - bullets[i]->getY();
            if (enemies[j]->isOn(Vector2(x, y)) && enemies[j]->team != bullets[i]->team)
            {
                bullets[i]->detach();
                bullets.erase(bullets.begin() + i);
                enemies[j]->hit();
                break;
            }
            if (enemies[j]->hp <= 0)
            {
                enemies[j]->detach();
                enemies.erase(enemies.begin() + j);
                break;
            }
        }
    }
    tween->addEventListener(TweenEvent::DONE, [this](Event* e)
    {
        update();
    });
}

#include "config.h"

namespace config
{
    Resources resources;
    
    double screenWidth = 1080;
    double screenHeight = 720;
    
    bool fullscreen = false;
    bool isProfile = true;
    bool isDebug = true;

    void init(string path)
    {
        resources.loadXML(path);
    }
    
    void initOnlyRes(string path)
    {
        resources.loadXML(path);
    }
    
    void update()
    {
    }
    
    void free()
    {
        resources.free();
    }
    
}

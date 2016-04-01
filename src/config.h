#include "oxygine-framework.h"

using namespace oxygine;
using namespace std;

namespace config
{

    extern double screenWidth;
    extern double screenHeight;
    extern bool fullscreen;
    extern bool isProfile;
    extern bool isDebug;

    extern Resources resources;
    
   
    void init(string path);
    void initOnlyRes(string path);
    void update();
    void free();
}



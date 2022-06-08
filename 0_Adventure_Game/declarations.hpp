void Init();
void FetchEvents();
void CheckEvents();
void DrawAndUpdate();
// bool MoveDynamicObject(int,int,int); //Cannot Overload blah blah blah

bool shouldRun = true;
int heroIndex=0;

SDL_Event event;

MyWindow::Window mainWindow;
GSWE::GridSystem mainGrid;

std::string imagesAddress = 
"/home/yolo/Workstation/Graphies/Tiles/Adventure-Game-Jam/";

enum {
    UP,DOWN,
    RIGHT,LEFT,
    RETURN,SPACE
};

bool heldKeys[6];
bool triggeredKeys[4];

std::string imagesPath[] = {
    imagesAddress+"/Tiles1/stone-tbrl.png",
    imagesAddress+"/Tiles1/stone-tbr.png",
    imagesAddress+"/Tiles1/stone-tbl.png",
    imagesAddress+"/Tiles1/stone-tb.png",
    
    imagesAddress+"/Tiles1/stone-trl.png",
    imagesAddress+"/Tiles1/stone-tr.png",
    imagesAddress+"/Tiles1/stone-tl.png",
    imagesAddress+"/Tiles1/stone-t.png",
    
    imagesAddress+"/Tiles1/stone-brl.png",
    imagesAddress+"/Tiles1/stone-br.png",
    imagesAddress+"/Tiles1/stone-bl.png",
    imagesAddress+"/Tiles1/stone-b.png",
    
    imagesAddress+"/Tiles1/stone-rl.png",
    imagesAddress+"/Tiles1/stone-r.png",
    imagesAddress+"/Tiles1/stone-l.png",
    imagesAddress+"/Tiles1/stone.png",

    // 16

    imagesAddress+"/Tiles1/water0.png",
    imagesAddress+"/Tiles1/flower0.png",
    imagesAddress+"/Tiles1/flower1.png",
    imagesAddress+"/Tiles1/flower2.png",

    imagesAddress+"/Tiles1/flower3.png",
    imagesAddress+"/Tiles1/sign0.png",
    imagesAddress+"/Tiles1/sign1.png",
    imagesAddress+"/Tiles1/sign2.png",

    imagesAddress+"/Tiles1/sign3.png",
    imagesAddress+"/Tiles1/door0.png",
    imagesAddress+"/Tiles1/gate0.png",
    imagesAddress+"/Tiles1/lever0.png",

    imagesAddress+"/Tiles1/ladder0.png", //28
    imagesAddress+"/Tiles1/person0.png",
    imagesAddress+"/Tiles1/person1.png",
    imagesAddress+"/Tiles1/person2.png",

    // 32

    imagesAddress+"/Tiles1/person3.png", 
    imagesAddress+"/Tiles1/fish0.png",
    imagesAddress+"/Tiles1/bee0.png",
    imagesAddress+"/Characters/hero.png", //35

    imagesAddress+"/Tiles1/fire0.png",
    imagesAddress+"/Tiles1/chest0.png",
    // imagesAddress+"/Tiles1/trapdoor0.png"
    //37
};



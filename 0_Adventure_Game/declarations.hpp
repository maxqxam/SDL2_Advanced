void Init();
void FetchEvents();
void CheckEvents();
void DrawAndUpdate();
void HandleMovements();
void Interact();
void SocialControl();
void StartAnimation(int,bool);
void HandleAnimation();
// bool MoveDynamicObject(int,int,int); //Cannot Overload blah blah

bool shouldRun = true;
int heroIndex=0;
int level=0;

SDL_Event event;
MyWindow::Window mainWindow;
GSWE::GridSystem mainGrid;
SU::SimpleUi mainUi({"HQ: ","HeadQuarters"},{0,0,1000,750});


std::string imagesAddress = 
"/home/yolo/Workstation/Graphies/Tiles/Adventure-Game-Jam/";

enum {
    UP,DOWN,
    RIGHT,LEFT,
    RETURN
};
enum {
    INSTONE,   
    INWATER,
    INLADDER,
    ISINWATER,
    ISINLADDER,
};

enum {
    FISH=33,
    SIGN0=21,
    FLOWER0=17,
    CHEST0=37,
    GATE0=26,
    FIRE0=36,
    PERSON0=29,
    LEVER=27,
};


bool inWater=false;
bool heldKeys[5];
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
    imagesAddress+"/Tiles1/flower0.png", //17
    imagesAddress+"/Tiles1/flower1.png",
    imagesAddress+"/Tiles1/flower2.png",

    imagesAddress+"/Tiles1/flower3.png",
    imagesAddress+"/Tiles1/sign0.png",   //21
    imagesAddress+"/Tiles1/sign1.png",
    imagesAddress+"/Tiles1/sign2.png",

    imagesAddress+"/Tiles1/sign3.png",
    imagesAddress+"/Tiles1/door0.png",
    imagesAddress+"/Tiles1/gate0.png",  //26
    imagesAddress+"/Tiles1/lever0.png", //27

    imagesAddress+"/Tiles1/ladder0.png", //28
    imagesAddress+"/Tiles1/person0.png",
    imagesAddress+"/Tiles1/person1.png",
    imagesAddress+"/Tiles1/person2.png",

    // 32

    imagesAddress+"/Tiles1/person3.png", 
    imagesAddress+"/Tiles1/fish0.png",   //33
    imagesAddress+"/Tiles1/bee0.png",
    imagesAddress+"/Tiles1/hero0.png", //35

    imagesAddress+"/Tiles1/fire0.png",
    imagesAddress+"/Tiles1/chest0.png",
    imagesAddress+"/Tiles1/gate1.png",//38
    imagesAddress+"/Tiles1/gate2.png",

    imagesAddress+"/Tiles1/gate3.png",
    imagesAddress+"/Tiles1/gate4.png",
    imagesAddress+"/Tiles1/gate5.png",//42
    imagesAddress+"/Tiles1/chest1.png",

    imagesAddress+"/Tiles1/chest2.png",
    imagesAddress+"/Tiles1/chest3.png",
    imagesAddress+"/Tiles1/door1.png",
    imagesAddress+"/Tiles1/door2.png",

    //48
    imagesAddress+"/Tiles1/door3.png",
    imagesAddress+"/Tiles1/door4.png",
    imagesAddress+"/Tiles1/lever0-1.png",
    
    
};


int leverFrames[] = {LEVER,50};
int gateFrames[] = {GATE0,38,39,
                    40,41,42}; //6
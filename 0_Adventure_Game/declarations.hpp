void Init();
void FetchEvents();
void CheckEvents();
void DrawAndUpdate();
void HandleMovements();
void Interact();
void SocialControl();
void StartAnimation(int,bool);
void HandleAnimation();
void StartConversation(int,std::vector<std::string>&);
void HandleConversation();
void HandleObjectCycles();
// bool MoveDynamicObject(int,int,int); //Cannot Overload blah blah
void thing();
bool shouldRun = true;
bool isInConversation = false;
int currentConversationId = 0;

int heroIndex=0;
int level=0;
int totoalKeys=0;
int heroSpeed = 10;
int beeSpeed = 4;
int fishSpeed = 2;
float zoom = 1.3;

// Mix_Chunk* footstep=NULL; 
// Mix_Chunk* ding=NULL;

SDL_Event event;
MyWindow::Window mainWindow;
GSWE::GridSystem mainGrid;
SU::SimpleUi mainUi({"HQ: ","HeadQuarters"},{0,0,1000,750});


std::string imagesAddress = 
".";



enum {
    UP,DOWN,
    RIGHT,LEFT,
    RETURN,
    RSHIFT,
    RCTRL,
    STOP=-1,
    FREEZE=-2,
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
    SIGN1=22,
    SIGN2=23,
    SIGN3=24,
    
    DOOR=25,
    FLOWER0=17,
    FLOWER1=18,
    FLOWER2=19,
    FLOWER3=20,
    CHEST0=37,
    GATE0=26,
    FIRE0=36,
    PERSON0=29,
    LEVER=27,
    HERO=35,
    BEE=34,

};


bool inWater=false;
bool heldKeys[7];
bool triggeredKeys[4];

std::string imagesPath[] = {
    imagesAddress+"/data/images/stone-tbrl.png",
    imagesAddress+"/data/images/stone-tbr.png",
    imagesAddress+"/data/images/stone-tbl.png",
    imagesAddress+"/data/images/stone-tb.png",
    
    imagesAddress+"/data/images/stone-trl.png",
    imagesAddress+"/data/images/stone-tr.png",
    imagesAddress+"/data/images/stone-tl.png",
    imagesAddress+"/data/images/stone-t.png",
    
    imagesAddress+"/data/images/stone-brl.png",
    imagesAddress+"/data/images/stone-br.png",
    imagesAddress+"/data/images/stone-bl.png",
    imagesAddress+"/data/images/stone-b.png",
    
    imagesAddress+"/data/images/stone-rl.png",
    imagesAddress+"/data/images/stone-r.png",
    imagesAddress+"/data/images/stone-l.png",
    imagesAddress+"/data/images/stone.png",

    // 16

    imagesAddress+"/data/images/water0.png",
    imagesAddress+"/data/images/flower0.png", //17
    imagesAddress+"/data/images/flower1.png",
    imagesAddress+"/data/images/flower2.png",

    imagesAddress+"/data/images/flower3.png",
    imagesAddress+"/data/images/sign0.png",   //21
    imagesAddress+"/data/images/sign1.png",  //22
    imagesAddress+"/data/images/sign2.png",  //23

    imagesAddress+"/data/images/sign3.png",   //24
    imagesAddress+"/data/images/door0.png",      //25
    imagesAddress+"/data/images/gate0.png",  //26
    imagesAddress+"/data/images/lever0.png", //27

    imagesAddress+"/data/images/ladder0.png", //28
    imagesAddress+"/data/images/person0.png",
    imagesAddress+"/data/images/person1.png",
    imagesAddress+"/data/images/person2.png",

    // 32

    imagesAddress+"/data/images/person3.png", 
    imagesAddress+"/data/images/fish0.png",   //33
    imagesAddress+"/data/images/bee0.png",   //34
    imagesAddress+"/data/images/hero0.png", //35

    imagesAddress+"/data/images/fire0.png",
    imagesAddress+"/data/images/chest0.png",
    imagesAddress+"/data/images/gate1.png",//38
    imagesAddress+"/data/images/gate2.png",

    imagesAddress+"/data/images/gate3.png",
    imagesAddress+"/data/images/gate4.png",
    imagesAddress+"/data/images/gate5.png",//42
    imagesAddress+"/data/images/chest1.png",

    imagesAddress+"/data/images/chest2.png",
    imagesAddress+"/data/images/chest3.png",
    imagesAddress+"/data/images/door1.png",//46
    imagesAddress+"/data/images/door2.png",//47

    //48
    imagesAddress+"/data/images/door3.png",//48
    imagesAddress+"/data/images/door4.png",//49
    imagesAddress+"/data/images/lever0-1.png",
    imagesAddress+"/data/images/hero1.png",//51
    
    imagesAddress+"/data/images/hero2.png",
    imagesAddress+"/data/images/hero3.png",//53
    imagesAddress+"/data/images/hero4.png",
    imagesAddress+"/data/images/hero5.png",//55

    imagesAddress+"/data/images/hero6.png",
    imagesAddress+"/data/images/bee1.png",//57
    imagesAddress+"/data/images/bee2.png",//58
    imagesAddress+"/data/images/bee3.png",//59
    
    imagesAddress+"/data/images/fish1.png",//60
    imagesAddress+"/data/images/fish2.png",//61
    imagesAddress+"/data/images/fish3.png",//62



       
};
int doorFrames[] = {25,46,47,48,49};
int heroClimbFrames[] = {55,56};
int heroLeftFrames[] = {53,54};
int heroRightFrames[] = {51,52};
int leverFrames[] = {LEVER,50};
int gateFrames[] = {GATE0,38,39,
                    40,41,42}; //6
                    
int chestFrames[] = {37,43,44,45};
int beeFramesRight[] = {34,57};
int beeFramesLeft[]  = {58,59};
int fishFramesLeft[]={33,60};
int fishFramesRight[]={61,62};
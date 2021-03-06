#include "mapdata.hpp"
#include "GSWE.hpp"

bool ValidMove(int p_index,int dircx,int dircy,bool isHero=false)
{
    bool cond[5]={0,0,0,0,0};
    
    for (int i=0;i!=GSWE::DynamicTilesArray.size();i++)
    {
        
        if ((GSWE::DynamicTilesArray[i].imageIndex==gateFrames[0])||
            (GSWE::DynamicTilesArray[i].imageIndex==gateFrames[1])||
            (GSWE::DynamicTilesArray[i].imageIndex==gateFrames[2])||
            (GSWE::DynamicTilesArray[i].imageIndex==gateFrames[3])||
            (GSWE::DynamicTilesArray[i].imageIndex==gateFrames[4])||
            (GSWE::DynamicTilesArray[i].imageIndex==gateFrames[5])||

            (GSWE::DynamicTilesArray[i].imageIndex==PERSON0))
        {
            
        if
        (
        (GSWE::DynamicTilesArray[i].pos.x==GSWE::DynamicTilesArray[p_index].pos.x+dircx)
        &&
        (GSWE::DynamicTilesArray[i].pos.y==GSWE::DynamicTilesArray[p_index].pos.y+dircy)            
        )

        {
            if (GSWE::DynamicTilesArray[i].state==1)
            {
                cond[INSTONE]=true;
            }
        }



            
        }
    }

    for (int i=0;i!=GSWE::StaticTilesArray.size();i++)
    {

        if
        (
            (GSWE::StaticTilesArray[i].pos.x==GSWE::DynamicTilesArray[p_index].pos.x+dircx)
            &&
            (GSWE::StaticTilesArray[i].pos.y==GSWE::DynamicTilesArray[p_index].pos.y+dircy)            
        )
        {
            // if (dircx&&dircy)
            // std::cout<<"Hit\n";
            if (GSWE::StaticTilesArray[i].imageIndex<16)
            {
                cond[INSTONE]=true;
            }
            if (GSWE::StaticTilesArray[i].imageIndex==16)
            {
                cond[INWATER]=true;
            }
            if (GSWE::StaticTilesArray[i].imageIndex==28)
            {
                cond[INLADDER]=true;
            }
        }

        if
        (
            (GSWE::StaticTilesArray[i].pos.x==GSWE::DynamicTilesArray[p_index].pos.x)
            &&
            (GSWE::StaticTilesArray[i].pos.y==GSWE::DynamicTilesArray[p_index].pos.y)            
        )
        {

            // std::cout<<"In\n";   
            if (GSWE::StaticTilesArray[i].imageIndex==28)
            {
                cond[ISINLADDER]=true;
            }
            if (GSWE::StaticTilesArray[i].imageIndex==16)
            {
                cond[ISINWATER]=true;

            }
        }
    }

    // for (int i=0;i!=5;i++)
    // {
    //     std::cout<<std::to_string(cond[i])<<" ";
    // }
    // std::cout<<dircx<<" "<<dircy<<"\n";

    inWater=cond[ISINWATER]||cond[INWATER];

    bool result=true;
    if (cond[INSTONE]){result = false;}
    if (
    ((dircy==-1)||0)    
    &&
    !(cond[ISINLADDER]||cond[INLADDER]||cond[INWATER]||cond[ISINWATER]))
    
    {result = false;}




    if (!result)
    {
        GSWE::DynamicTilesArray[heroIndex].imageIndex=HERO;
        
        return false;
    }

    mainUi.shouldDraw=false;    
    return true;
}

bool MoveDynamicObject(int p_index,int p_dirc,int p_speed,bool moveCamera=false)
{
    if (p_dirc==UP){
        GSWE::DynamicTilesArray[p_index].YRel-=p_speed;
        if (moveCamera)
        {
            mainGrid.cameraYRel+=p_speed;
        }
        
        if ((p_index==heroIndex) &&
            (SDL_GetTicks()>(GSWE::DynamicTilesArray[heroIndex].frameTime+80))
            )
        {
        GSWE::DynamicTilesArray[heroIndex].frameTime=SDL_GetTicks();
        if (GSWE::DynamicTilesArray[heroIndex].imageIndex==heroClimbFrames[0])
        {
            GSWE::DynamicTilesArray[heroIndex].imageIndex=heroClimbFrames[1];
        }
        else
        {
            GSWE::DynamicTilesArray[heroIndex].imageIndex=heroClimbFrames[0];
        }
        }


    }
    else if (p_dirc==DOWN){
        GSWE::DynamicTilesArray[p_index].YRel+=p_speed;
        if (moveCamera)
        {
            mainGrid.cameraYRel-=p_speed;
        }
        
        if ((p_index==heroIndex) &&
            (SDL_GetTicks()>(GSWE::DynamicTilesArray[heroIndex].frameTime+80))
            )
        {
        GSWE::DynamicTilesArray[heroIndex].frameTime=SDL_GetTicks();
        if (GSWE::DynamicTilesArray[heroIndex].imageIndex==heroClimbFrames[0])
        {
            GSWE::DynamicTilesArray[heroIndex].imageIndex=heroClimbFrames[1];
        }
        else
        {
            GSWE::DynamicTilesArray[heroIndex].imageIndex=heroClimbFrames[0];
        }
        }
        

    }
    else if (p_dirc==RIGHT){
        GSWE::DynamicTilesArray[p_index].XRel+=p_speed;
        if (moveCamera)
        {
            mainGrid.cameraXRel-=p_speed;
        }

        if (p_index==heroIndex &&
            (SDL_GetTicks()>(GSWE::DynamicTilesArray[heroIndex].frameTime+250))
            )
        {
        GSWE::DynamicTilesArray[heroIndex].frameTime=SDL_GetTicks();
        if (GSWE::DynamicTilesArray[heroIndex].imageIndex==heroRightFrames[0])
        {
            GSWE::DynamicTilesArray[heroIndex].imageIndex=heroRightFrames[1];
        }
        else
        {
            GSWE::DynamicTilesArray[heroIndex].imageIndex=heroRightFrames[0];
        }
        }
    }
    else if (p_dirc==LEFT){
        GSWE::DynamicTilesArray[p_index].XRel-=p_speed;
        if (moveCamera)
        {
            mainGrid.cameraXRel+=p_speed;
        }
        if (p_index==heroIndex &&
            (SDL_GetTicks()>(GSWE::DynamicTilesArray[heroIndex].frameTime+250))
            )
        {
        GSWE::DynamicTilesArray[heroIndex].frameTime=SDL_GetTicks();
        if (GSWE::DynamicTilesArray[heroIndex].imageIndex==heroLeftFrames[0])
        {
            GSWE::DynamicTilesArray[heroIndex].imageIndex=heroLeftFrames[1];
        }
        else
        {
            GSWE::DynamicTilesArray[heroIndex].imageIndex=heroLeftFrames[0];
        }
        }
    }

    GSWE::DynamicTilesArray[p_index].RelToPos();
    mainGrid.RelToGridRel();

    if (GSWE::DynamicTilesArray[p_index].YRel==0){
    }
    if (
        ((GSWE::DynamicTilesArray[p_index].XRel==0) && ((p_dirc==RIGHT) || (p_dirc==LEFT)))
        ||
        ((GSWE::DynamicTilesArray[p_index].YRel==0) && ((p_dirc==UP) || (p_dirc==DOWN)))
        )
    {
        
        return true;
    }

    return false;
}

void HandleMovements(){
    //Movements<
    if(!triggeredKeys[UP]&&!triggeredKeys[DOWN]&&
            !triggeredKeys[RIGHT]&&!triggeredKeys[LEFT])
    {
        // Up&Down
        if (heldKeys[UP]&&!triggeredKeys[DOWN])
        {
            if (ValidMove(heroIndex,0,-1,1))
            triggeredKeys[UP]=true;
        }
        else if (heldKeys[DOWN]&&!triggeredKeys[UP])
        {
            

            if (ValidMove(heroIndex,0,1,1))
            triggeredKeys[DOWN]=true;
        }

        // Right&Left
        else if (heldKeys[RIGHT]&&!triggeredKeys[LEFT])
        {
            if (ValidMove(heroIndex,1,0,1))
            triggeredKeys[RIGHT]=true;
        }
        else if (heldKeys[LEFT]&&!triggeredKeys[RIGHT])
        {
            if (ValidMove(heroIndex,-1,0,1))
            triggeredKeys[LEFT]=true;
        }
    }
    // Movements >
}


void FetchEvents(){
    while (SDL_PollEvent(&event))
    {
        if (event.type==SDL_WINDOWEVENT)
        {
            mainWindow.FetchWindowEvent(event);
        }
        else if(event.type==SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_UP: if(!heldKeys[UP]) heldKeys[UP]=true;break;
                case SDLK_DOWN: if(!heldKeys[DOWN]) heldKeys[DOWN]=true;break;
                case SDLK_RIGHT: if(!heldKeys[RIGHT]) heldKeys[RIGHT]=true;break;
                case SDLK_LEFT: if(!heldKeys[LEFT]) heldKeys[LEFT]=true;break;

                case SDLK_RETURN: if(!heldKeys[RETURN]) heldKeys[RETURN]=true;break;
                case SDLK_RSHIFT: if(!heldKeys[RSHIFT]) heldKeys[RSHIFT]=true;break;         
                case SDLK_RCTRL: if(!heldKeys[RCTRL]) heldKeys[RCTRL]=true;break;         
                
            }
        }
        else if(event.type==SDL_KEYUP)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE: shouldRun=false; break;
                case SDLK_F1: mainGrid.showGrid=!mainGrid.showGrid; break;

                case SDLK_UP: if(heldKeys[UP]) heldKeys[UP]=0;break;
                case SDLK_DOWN: if(heldKeys[DOWN]) heldKeys[DOWN]=0;break;
                case SDLK_RIGHT: if(heldKeys[RIGHT]) heldKeys[RIGHT]=0;break;
                case SDLK_LEFT: if(heldKeys[LEFT]) heldKeys[LEFT]=0;break;

                case SDLK_RETURN: if(heldKeys[RETURN]) heldKeys[RETURN]=0;break;
                case SDLK_RSHIFT: if(heldKeys[RSHIFT]) heldKeys[RSHIFT]=0;break;
                case SDLK_RCTRL: if(heldKeys[RCTRL]) heldKeys[RCTRL]=0;break;
                
                
            }
        }
    }
}

void Init(){
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    // Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
    TTF_Init();
    std::srand(time(0));
    mainWindow.Init("Adventure Game",1000,750);

    mainGrid.Init(1000,750,10,8);
    mainGrid.showGrid=false;
    // mainGrid.backgroundColor={0,0,0};
    SU::gFont = TTF_OpenFont( "./lazy.ttf", 25 );
    // footstep = Mix_LoadWAV("data/footstep0.wav");
    // ding = Mix_LoadWAV("data/ding.wav");
    
    SDL_SetRenderDrawBlendMode(mainWindow.renderer,
                SDL_BLENDMODE_BLEND);

    SDL_Rect tempRect = {mainWindow.width/5,
                            mainWindow.height/3,
                            (mainWindow.width/5)*3,
                            (mainWindow.height/3)};
    
    mainUi.UpdateTexture(mainWindow.renderer,tempRect);

    SDL_Texture* tempTexture;
    int tempWidth;
    int tempHeight;
    
    
    
    // Mix_PlayChannel(-1,footstep,10);
    
    if (SU::gFont==NULL) {myout(SDL_GetError()) enter}



    for (int i=0;i!=sizeof(imagesPath)/sizeof(imagesPath[i]);i++){
        tempTexture = loadTexture(mainWindow.renderer,
                        imagesPath[i].c_str(),
                        tempWidth,tempHeight);

        GSWE::imageArray.push_back({tempTexture,tempWidth,tempHeight});

    }

    level=0;
    LoadLevel("data/tutorial.map");
    SocialControl();
    mainGrid.cameraZoom=zoom;

    mainGrid.SetZoomFocus(GSWE::DynamicTilesArray[heroIndex].pos,0,0);
}

void Interact(){
    bool shouldInteract=false;
    int i=0;
    for (i=0;i!=GSWE::DynamicTilesArray.size();i++)
    {

        if (GSWE::DynamicTilesArray[i].pos.y==GSWE::DynamicTilesArray[heroIndex].pos.y)
        {

        if (GSWE::DynamicTilesArray[i].pos.x==
                GSWE::DynamicTilesArray[heroIndex].pos.x+1)
        {
            shouldInteract=true;
        }
        
        if (GSWE::DynamicTilesArray[i].pos.x==
                GSWE::DynamicTilesArray[heroIndex].pos.x-1)
        {
            shouldInteract=true;
        }            
        }
        if (shouldInteract){break;}      
    }

    if (shouldInteract)
    {
        // Mix_PlayChannel(-1,ding,0);
        int tempIndex = GSWE::DynamicTilesArray[i].imageIndex; 
        std::vector<std::string> tempTextArray;
        mainUi.shouldDraw=true;
       

        
        if ((tempIndex==doorFrames[0])||(tempIndex==doorFrames[4]))
        {
            if (GSWE::DynamicTilesArray[i].state==1)
            {
                if (totoalKeys==1)
                {
                    StartConversation(i,tempTextArray);
                }
                else
                {
                    
                    tempTextArray.push_back("I already opened a door.");
                    tempTextArray.push_back("I don't have any keys left.");
                }
            }
            else
            {
                StartConversation(i,tempTextArray);
            }
           
        }
        else if((tempIndex==fishFramesLeft[0])||
           (tempIndex==fishFramesLeft[1])||
           (tempIndex==fishFramesRight[0])||
           (tempIndex==fishFramesRight[1])||
           
           (tempIndex==beeFramesLeft[0])||
           (tempIndex==beeFramesLeft[1])||
           (tempIndex==beeFramesRight[0])||
           (tempIndex==beeFramesRight[1]))
        {
        tempTextArray.push_back(GSWE::DynamicTilesArray[i].captions[randint(0,3)]);
        }
        else if((tempIndex==gateFrames[0])|| // Gate
                (tempIndex==gateFrames[5]))
        {
            if (GSWE::DynamicTilesArray[i].state==true)
            {
                tempTextArray.push_back("I cant get past this gate.");
            }
            else
            {
                tempTextArray.push_back("This gate is open.");
            }
        }


        else if((tempIndex==FLOWER0)||
                (tempIndex==FLOWER1)||
                (tempIndex==FLOWER2)||
                (tempIndex==FLOWER3))
        {
            if (GSWE::DynamicTilesArray[i].pointer==0)
            {
                StartConversation(i,tempTextArray);
                if (level==0){GSWE::DynamicTilesArray[i].pointer=1;}
            }
            else
            {
                if (level==0){tempTextArray.push_back("Find the bald wise guy.");}

            }
        }
        else if(tempIndex==PERSON0)
        {
            if (GSWE::DynamicTilesArray[i].pointer==0)
            {
                StartConversation(i,tempTextArray);
                GSWE::DynamicTilesArray[i].pointer=1;
            }
            else
            {
                if (totoalKeys==0)
                {tempTextArray.push_back("Go grab the key.");}
                else
                {tempTextArray.push_back("Be careful in your journy!");
                GSWE::DynamicTilesArray[i].state=0;}

    
            }
           
        }
        else if (tempIndex==leverFrames[0])
        {
            tempTextArray.push_back("I pushed the lever.");
            tempTextArray.push_back("The gate is opening...");

            // StartConversation(i,tempTextArray);
        }
        else if(tempIndex==leverFrames[1])
        {
            tempTextArray.push_back("I pulled the lever.");
            tempTextArray.push_back("The gate is closing...");
            

            // StartConversation(i,tempTextArray);
            
        }
        else if((tempIndex==SIGN0)||(tempIndex==FIRE0)||
                (tempIndex==SIGN1)||(tempIndex==SIGN2)||
                (tempIndex==SIGN3))
        {
            StartConversation(i,tempTextArray);
        }
        else if((tempIndex==chestFrames[0]))
        {
            StartConversation(i,tempTextArray);
            totoalKeys++;
        }
        else if(tempIndex==chestFrames[3])
        {
            tempTextArray.push_back("I already opened this chest.");
        }


        SDL_Rect tempRect = {mainWindow.width/5,
                            mainWindow.height/3,
                            (mainWindow.width/5)*3,
                            (mainWindow.height/3)};
    
       
        
        mainUi.textArray=tempTextArray;

        mainUi.UpdateTexture(mainWindow.renderer,tempRect);        

      
        
        if (tempIndex==chestFrames[0])
        {
            // StartAnimation(i,false)
            GSWE::DynamicTilesArray[i].imageIndex=chestFrames[1];
            GSWE::DynamicTilesArray[i].state = false;

        }
        else if(tempIndex==chestFrames[3])
        {
            // StartAnimation(i,true);
            // GSWE::DynamicTilesArray[i].imageIndex=chestFrames[2];
            // GSWE::DynamicTilesArray[i].state=true;
        }
        else if (tempIndex==leverFrames[0]){

            GSWE::DynamicTilesArray[
            GSWE::DynamicTilesArray[i].pointer
            ].state=false;

            GSWE::DynamicTilesArray[
            GSWE::DynamicTilesArray[i].pointer
            ].imageIndex=gateFrames[1];

            GSWE::DynamicTilesArray[i].imageIndex=leverFrames[1];
        }
        else if (tempIndex==leverFrames[1]){

            GSWE::DynamicTilesArray[
            GSWE::DynamicTilesArray[i].pointer
            ].state=true;
            
            GSWE::DynamicTilesArray[
                GSWE::DynamicTilesArray[i].pointer
                ].imageIndex=gateFrames[4];
            
            // StartAnimation(GSWE::DynamicTilesArray[i].pointer,true);

            GSWE::DynamicTilesArray[i].imageIndex=leverFrames[0];
        }   
    }

}




void HandleAnimation()
{
    SDL_Rect tempRect = {mainWindow.width/5,
                            mainWindow.height/3,
                            (mainWindow.width/5)*3,
                            (mainWindow.height/3)};

    for (int i=0;i!=GSWE::DynamicTilesArray.size();i++)
    {

        if ((SDL_GetTicks()-GSWE::DynamicTilesArray[i].frameTime)>100)
        { //only if the timing is right
        if (
            (i!=heroIndex)&&
            (GSWE::DynamicTilesArray[i].imageIndex!=beeFramesLeft[0])&&
            (GSWE::DynamicTilesArray[i].imageIndex!=beeFramesLeft[1])&&
            (GSWE::DynamicTilesArray[i].imageIndex!=beeFramesRight[0])&&
            (GSWE::DynamicTilesArray[i].imageIndex!=beeFramesRight[1])&&
            (GSWE::DynamicTilesArray[i].imageIndex!=fishFramesLeft[0])&&
            (GSWE::DynamicTilesArray[i].imageIndex!=fishFramesLeft[1])&&
            (GSWE::DynamicTilesArray[i].imageIndex!=fishFramesRight[0])&&
            (GSWE::DynamicTilesArray[i].imageIndex!=fishFramesRight[1])
        )
        {
            GSWE::DynamicTilesArray[i].frameTime=SDL_GetTicks();
        }        
        if (GSWE::DynamicTilesArray[i].state==true) //means if blocked , opening
        {
            

            for (int c=4;c!=0;c--) // This is for Gates
            {
                if (GSWE::DynamicTilesArray[i].imageIndex == 
                    gateFrames[c])
                {                    
                    GSWE::DynamicTilesArray[i].imageIndex=gateFrames[c-1];
                    if (c==1){
                        mainUi.textArray.push_back("The gate is now closed.");
                        mainUi.UpdateTexture(mainWindow.renderer,
                                tempRect);                        
                    }
                    break;
                }
            }

            for (int c=2;c!=0;c--) // This is for Chests
            {
                if (GSWE::DynamicTilesArray[i].imageIndex == 
                    chestFrames[c])
                {                    
                    GSWE::DynamicTilesArray[i].imageIndex=chestFrames[c-1];
                    if (c==1){
                        mainUi.textArray.push_back("The chest is now closed.");
                        mainUi.UpdateTexture(mainWindow.renderer,
                                tempRect);                        
                    }
                    break;
                }
            }

        }
        else // means if not blocked, closing
        {
            for (int c=1;c!=4;c++) // For door its the case for opening
            {
                if (GSWE::DynamicTilesArray[i].imageIndex==
                    doorFrames[c])
                {                    
                
                    GSWE::DynamicTilesArray[i].imageIndex=doorFrames[c+1];
                    break;
                }
            }

            for (int c=0;c!=5;c++) // This is for Gates
            {
                if (GSWE::DynamicTilesArray[i].imageIndex == 
                    gateFrames[c])
                { 
                    GSWE::DynamicTilesArray[i].imageIndex=gateFrames[c+1];
                    if (c==4){
                        mainUi.textArray.push_back("The gate is now opened.");                      
                        mainUi.UpdateTexture(mainWindow.renderer,
                                tempRect);
                    }
                    break;
                }

            }

            for (int c=1;c!=3;c++) // This is for Chests
            {
                if (GSWE::DynamicTilesArray[i].imageIndex == 
                    chestFrames[c])
                {                    
                    GSWE::DynamicTilesArray[i].imageIndex=chestFrames[c+1];
                    if (c==1){
                        mainUi.textArray.push_back("The chest is now opened.");
                        mainUi.UpdateTexture(mainWindow.renderer,
                                tempRect);                        
                    }
                    break;
                }
            }
        }

        }// only if the timing is right

    }
}

void FishAnimate(int p_index)
{
    if ((GSWE::DynamicTilesArray[p_index].imageIndex==fishFramesLeft[0]) ||
        (GSWE::DynamicTilesArray[p_index].imageIndex==fishFramesLeft[1]) ||
        (GSWE::DynamicTilesArray[p_index].imageIndex==fishFramesRight[0]) ||
        (GSWE::DynamicTilesArray[p_index].imageIndex==fishFramesRight[1]))
    {    

    if ((GSWE::DynamicTilesArray[p_index].moveArray
        [GSWE::DynamicTilesArray[p_index].moveIndex]==RIGHT)
        &&
        ((GSWE::DynamicTilesArray[p_index].imageIndex!=fishFramesRight[0])&&
         (GSWE::DynamicTilesArray[p_index].imageIndex!=fishFramesRight[1])))

    {GSWE::DynamicTilesArray[p_index].imageIndex=fishFramesRight[0];}

    else if((GSWE::DynamicTilesArray[p_index].moveArray
        [GSWE::DynamicTilesArray[p_index].moveIndex]==LEFT)
        &&
        ((GSWE::DynamicTilesArray[p_index].imageIndex!=fishFramesLeft[0])&&
         (GSWE::DynamicTilesArray[p_index].imageIndex!=fishFramesLeft[1])))

    {
    {GSWE::DynamicTilesArray[p_index].imageIndex=fishFramesLeft[0];}
    }
    

    if ((GSWE::DynamicTilesArray[p_index].frameTime2 + 250
       < SDL_GetTicks()) &&(GSWE::DynamicTilesArray[p_index].moveArray
        [GSWE::DynamicTilesArray[p_index].moveIndex]!=FREEZE)    
       )
    {
        GSWE::DynamicTilesArray[p_index].frameTime2 = SDL_GetTicks();
        if (GSWE::DynamicTilesArray[p_index].imageIndex==fishFramesLeft[0])
        {GSWE::DynamicTilesArray[p_index].imageIndex=fishFramesLeft[1];}

        else if (GSWE::DynamicTilesArray[p_index].imageIndex==fishFramesLeft[1])
        {GSWE::DynamicTilesArray[p_index].imageIndex=fishFramesLeft[0];}

        else if (GSWE::DynamicTilesArray[p_index].imageIndex==fishFramesRight[0])
        {GSWE::DynamicTilesArray[p_index].imageIndex=fishFramesRight[1];}

        else if (GSWE::DynamicTilesArray[p_index].imageIndex==fishFramesRight[1])
        {GSWE::DynamicTilesArray[p_index].imageIndex=fishFramesRight[0];} 
        }
    }
}


void BeeAnimate(int p_index)
{
    
    if ((GSWE::DynamicTilesArray[p_index].imageIndex==beeFramesLeft[0]) ||
        (GSWE::DynamicTilesArray[p_index].imageIndex==beeFramesLeft[1]) ||
        (GSWE::DynamicTilesArray[p_index].imageIndex==beeFramesRight[0]) ||
        (GSWE::DynamicTilesArray[p_index].imageIndex==beeFramesRight[1]))
    {

    

    if ((GSWE::DynamicTilesArray[p_index].moveArray
        [GSWE::DynamicTilesArray[p_index].moveIndex]==RIGHT)
        &&
        ((GSWE::DynamicTilesArray[p_index].imageIndex!=beeFramesRight[0])&&
         (GSWE::DynamicTilesArray[p_index].imageIndex!=beeFramesRight[1])))

    {GSWE::DynamicTilesArray[p_index].imageIndex=beeFramesRight[0];}

    else if((GSWE::DynamicTilesArray[p_index].moveArray
        [GSWE::DynamicTilesArray[p_index].moveIndex]==LEFT)
        &&
        ((GSWE::DynamicTilesArray[p_index].imageIndex!=beeFramesLeft[0])&&
         (GSWE::DynamicTilesArray[p_index].imageIndex!=beeFramesLeft[1])))

    {
    {GSWE::DynamicTilesArray[p_index].imageIndex=beeFramesLeft[0];}
    }
    

    if ((GSWE::DynamicTilesArray[p_index].frameTime2 + 250
       < SDL_GetTicks()) &&(GSWE::DynamicTilesArray[p_index].moveArray
        [GSWE::DynamicTilesArray[p_index].moveIndex]!=FREEZE)    
       )
    {
        GSWE::DynamicTilesArray[p_index].frameTime2 = SDL_GetTicks();
        if (GSWE::DynamicTilesArray[p_index].imageIndex==beeFramesLeft[0])
        {GSWE::DynamicTilesArray[p_index].imageIndex=beeFramesLeft[1];}

        else if (GSWE::DynamicTilesArray[p_index].imageIndex==beeFramesLeft[1])
        {GSWE::DynamicTilesArray[p_index].imageIndex=beeFramesLeft[0];}

        else if (GSWE::DynamicTilesArray[p_index].imageIndex==beeFramesRight[0])
        {GSWE::DynamicTilesArray[p_index].imageIndex=beeFramesRight[1];}

        else if (GSWE::DynamicTilesArray[p_index].imageIndex==beeFramesRight[1])
        {GSWE::DynamicTilesArray[p_index].imageIndex=beeFramesRight[0];} 
        }
    }
    
}
void HandleObjectCycles(){
    for (int i=0;i!=GSWE::DynamicTilesArray.size();i++)
    {
    
    if (GSWE::DynamicTilesArray[i].moveArray.size()!=0)
    {

    int speed = beeSpeed;
    if ((GSWE::DynamicTilesArray[i].imageIndex==beeFramesLeft[0]) ||
        (GSWE::DynamicTilesArray[i].imageIndex==beeFramesLeft[1]) ||
        (GSWE::DynamicTilesArray[i].imageIndex==beeFramesRight[0]) ||
        (GSWE::DynamicTilesArray[i].imageIndex==beeFramesRight[1]) ||

        (GSWE::DynamicTilesArray[i].imageIndex==fishFramesLeft[0]) ||
        (GSWE::DynamicTilesArray[i].imageIndex==fishFramesLeft[1]) ||
        (GSWE::DynamicTilesArray[i].imageIndex==fishFramesRight[0]) ||
        (GSWE::DynamicTilesArray[i].imageIndex==fishFramesRight[1])
        )
    {
       
       BeeAnimate(i);
       FishAnimate(i);

       if ((GSWE::DynamicTilesArray[i].moveArray[
           GSWE::DynamicTilesArray[i].moveIndex]!=STOP) && 
           (GSWE::DynamicTilesArray[i].moveArray[
           GSWE::DynamicTilesArray[i].moveIndex]!=FREEZE))
       {
            if ((GSWE::DynamicTilesArray[i].imageIndex==fishFramesLeft[0]) ||
                (GSWE::DynamicTilesArray[i].imageIndex==fishFramesLeft[1]) ||
                (GSWE::DynamicTilesArray[i].imageIndex==fishFramesRight[0]) ||
                (GSWE::DynamicTilesArray[i].imageIndex==fishFramesRight[1]))
            {
                speed=fishSpeed;
                if (GSWE::DynamicTilesArray[i].state==1)
                {
                    speed*=2;
                }
            }

            
            if 
            (        
            MoveDynamicObject(i,GSWE::DynamicTilesArray[i].moveArray
                                [GSWE::DynamicTilesArray[i].moveIndex]
                                ,speed,0)
            )
            {
                GSWE::DynamicTilesArray[i].moveIndex++;
                if (GSWE::DynamicTilesArray[i].moveIndex>
                        GSWE::DynamicTilesArray[i].moveArray.size()-1)
                {
                    GSWE::DynamicTilesArray[i].moveIndex=0;
                }
            }      
       }
       else 
       {

           if (SDL_GetTicks()>GSWE::DynamicTilesArray[i].frameTime+2500)
           {
           
               GSWE::DynamicTilesArray[i].frameTime=SDL_GetTicks();
               GSWE::DynamicTilesArray[i].moveIndex++;
               if (GSWE::DynamicTilesArray[i].moveIndex >
                    GSWE::DynamicTilesArray[i].moveArray.size())
               {
                   GSWE::DynamicTilesArray[i].moveIndex=0;
               }
           }
       }                                                                
    }
    



    }


    }
}
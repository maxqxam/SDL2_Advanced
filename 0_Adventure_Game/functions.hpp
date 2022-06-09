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


    if (cond[INSTONE]){return false;}
    if (
    ((dircy==-1)||0)    
    &&
    !(cond[ISINLADDER]||cond[INLADDER]||cond[INWATER]||cond[ISINWATER]))
    
    {return false;}

    



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
    }
    else if (p_dirc==DOWN){
        GSWE::DynamicTilesArray[p_index].YRel+=p_speed;
        if (moveCamera)
        {
            mainGrid.cameraYRel-=p_speed;
        }
    }
    else if (p_dirc==RIGHT){
        GSWE::DynamicTilesArray[p_index].XRel+=p_speed;
        if (moveCamera)
        {
            mainGrid.cameraXRel-=p_speed;
        }
    }
    else if (p_dirc==LEFT){
        GSWE::DynamicTilesArray[p_index].XRel-=p_speed;
        if (moveCamera)
        {
            mainGrid.cameraXRel+=p_speed;
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

    int tempSpeed=25;
    for (int i=0;i!=4;i++)
    {
        if (triggeredKeys[i])
        {
            if(MoveDynamicObject(heroIndex,i,tempSpeed,true))
            {
                triggeredKeys[i]=false;
            }
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
                
                
            }
        }
    }
}

void Init(){
    mainWindow.Init("Adventure Game",1000,750);
    mainGrid.Init(1000,750,10,8);

    SDL_Texture* tempTexture;
    int tempWidth;
    int tempHeight;

    for (int i=0;i!=sizeof(imagesPath)/sizeof(imagesPath[i]);i++){
        tempTexture = loadTexture(mainWindow.renderer,
                        imagesPath[i].c_str(),
                        tempWidth,tempHeight);

        GSWE::imageArray.push_back({tempTexture,tempWidth,tempHeight});

    }

    LoadLevel("data/tutorial.map");
    SocialControl();

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
        myout("Id : ")
        myout(i) myout(" Type : ")
        myout(GSWE::DynamicTilesArray[i].imageIndex)
        space 
        if (GSWE::DynamicTilesArray[i].captions.size()!=0){
            myout(GSWE::DynamicTilesArray[i].captions[0])
        }else{
            myout("Nothing to show")
        }
        enter 

        int tempIndex = GSWE::DynamicTilesArray[i].imageIndex; 
       
        if (tempIndex==leverFrames[0]){
                GSWE::DynamicTilesArray[
                GSWE::DynamicTilesArray[i].pointer
                ].state=false;

            StartAnimation(GSWE::DynamicTilesArray[i].pointer,false);

            GSWE::DynamicTilesArray[i].imageIndex=leverFrames[1];
        }
        else if (tempIndex==leverFrames[1]){
                GSWE::DynamicTilesArray[
                GSWE::DynamicTilesArray[i].pointer
                ].state=true;
            
            StartAnimation(GSWE::DynamicTilesArray[i].pointer,true);

            GSWE::DynamicTilesArray[i].imageIndex=leverFrames[0];
        }
                
           
        
    }
}


void StartAnimation(int p_index,bool ifClosing)
{

    if (!ifClosing)
    {
    GSWE::DynamicTilesArray[p_index].imageIndex=gateFrames[1];
    }
    else
    {
    GSWE::DynamicTilesArray[p_index].imageIndex=gateFrames[4];
    }
}

void HandleAnimation()
{
    for (int i=0;i!=GSWE::DynamicTilesArray.size();i++)
    {
        if ((SDL_GetTicks()-GSWE::DynamicTilesArray[i].frameTime)>50)
        { //only if the timing is right
        GSWE::DynamicTilesArray[i].frameTime=SDL_GetTicks()+50;
        
        if (GSWE::DynamicTilesArray[i].state==true) //means if blocked
        {
            for (int c=4;c!=0;c--) // This is for Gates
            {
                if (GSWE::DynamicTilesArray[i].imageIndex == 
                    gateFrames[c])
                {                    
                    GSWE::DynamicTilesArray[i].imageIndex=gateFrames[c-1];
                    break;
                }

            }
        }
        else // means if not blocked
        {
            for (int c=0;c!=5;c++) // This is for Gates
            {
                if (GSWE::DynamicTilesArray[i].imageIndex == 
                    gateFrames[c])
                { 
                    GSWE::DynamicTilesArray[i].imageIndex=gateFrames[c+1];
                    break;
                }

            }
        }

        }// only if the timing is right

    }
}

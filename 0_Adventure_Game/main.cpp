#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <fstream>

#include "GSWE.hpp"
#include "MyWindow.hpp"
#include "definitions.hpp"
#include "declarations.hpp"
#include "structures.hpp"
#include "snippets.hpp"

enum {
    INSTONE,
    INWATER,
    INLADDER,
    ISINWATER,
    ISINLADDER,
};

bool ValidMove(int p_index,int dircx,int dircy,bool isHero=false,bool isJump=false)
{
    bool cond[5]={0,0,0,0,0};

    for (int i=0;i!=GSWE::StaticTilesArray.size();i++)
    {

        if
        (
            (GSWE::StaticTilesArray[i].pos.x==GSWE::DynamicTilesArray[p_index].pos.x+dircx)
            &&
            (GSWE::StaticTilesArray[i].pos.y==GSWE::DynamicTilesArray[p_index].pos.y+dircy)            
        )
        {
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

    if (dircy==1){
        if (cond[INSTONE]||cond[INLADDER]||cond[INWATER]){
            totalJump=4;
        }
    }

    if (cond[INSTONE]){return false;}

    if (((dircy==-1)&&(isJump))&&!cond[ISINLADDER]){
        return true;
    }
    if (
    ((dircy==-1)||0)    
    &&
    !(cond[ISINLADDER]||cond[INLADDER]||cond[INWATER]||cond[ISINWATER]))
    
    {return false;}

    



    return true;
}
bool MoveDynamicObject(int p_index,int p_dirc,int p_speed,bool moveCamera=false)
{
    int lp_dirc=p_dirc;
    if (p_dirc==SPACE){
        p_dirc=UP;
    }
    if (p_dirc==5){
        p_dirc=DOWN;
    }
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
        if (lp_dirc==SPACE)
        {
            totalJump--;
            if (totalJump==0)
            {
                triggeredKeys[SPACE]=0;
                heldKeys[SPACE]=0;                   
            }
        }
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

    mainGrid.SetZoomFocus(GSWE::DynamicTilesArray[heroIndex].pos,0,0);
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
                case SDLK_SPACE: if(!heldKeys[SPACE]) 
                myout("SPACE\n") heldKeys[SPACE]=true;break;
                
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
                case SDLK_SPACE: if(heldKeys[SPACE]) heldKeys[SPACE]=0;break;
                
            }
        }
    }
}

void CheckEvents(){
    
    myout(totalJump) enter
    if (mainWindow.isClosed){shouldRun=false;}
    if (mainWindow.sizeChanged){
        mainGrid.Update(mainWindow.width,mainWindow.height);
    }

    int tempX=0;
    int tempY=0;

    std::to_string(GSWE::DynamicTilesArray.size());

    // std::cout<<GSWE::DynamicTilesArray.size();
    GSWE::DynamicTilesArray[0];
    
    if (triggeredKeys[5]){heldKeys[SPACE]=false;}
    
    if (!triggeredKeys[5]){
    if (heldKeys[SPACE]&&!triggeredKeys[DOWN]&&!triggeredKeys[UP]&&(totalJump!=0))
    {
        
        tempX=0; tempY=-1;
        
        if (triggeredKeys[RIGHT]){tempX=1;}
        else if(triggeredKeys[LEFT]){tempX=-1;}

        if ((tempX==-1)&&(GSWE::DynamicTilesArray[heroIndex].XRel!=0)){
            tempX=0;
        }

        if (ValidMove(heroIndex,tempX,tempY,1,1)){
        triggeredKeys[SPACE]=true;
        }
        tempX=0;tempY=0;
    }

    else if (heldKeys[UP]&&!triggeredKeys[DOWN])
    {
        tempX=0; tempY=-1;
        
        if (triggeredKeys[RIGHT]){tempX=1;}
        else if(triggeredKeys[LEFT]){tempX=-1;}

        if ((tempX==-1)&&(GSWE::DynamicTilesArray[heroIndex].XRel!=0)){
            tempX=0;
        }

        if (ValidMove(heroIndex,tempX,tempY,1))
        triggeredKeys[UP]=true;

        tempX=0;tempY=0;
    }

    else if (heldKeys[DOWN]&&!triggeredKeys[UP])
    {
        tempY=1;
        if (triggeredKeys[RIGHT]){tempX=1;}
        else if(triggeredKeys[LEFT]){tempX=-1;}

        if ((tempX==-1)&&(GSWE::DynamicTilesArray[heroIndex].XRel!=0)){
            tempX=0;
        }

        if (ValidMove(heroIndex,tempX,tempY,1))
        triggeredKeys[DOWN]=true;

        tempX=0;tempY=0;
    }
    else if (!triggeredKeys[UP]&&!triggeredKeys[SPACE]&&!triggeredKeys[DOWN])
    {
        tempY=1;
        if (triggeredKeys[RIGHT]){tempX=1;}
        else if(triggeredKeys[LEFT]){tempX=-1;}

        if ((tempX==-1)&&(GSWE::DynamicTilesArray[heroIndex].XRel!=0)){
            tempX=0;
        }

        if (ValidMove(heroIndex,tempX,tempY,1))
        triggeredKeys[5]=true;

        tempX=0;tempY=0;
    }
    }




    if (heldKeys[RIGHT]&&!triggeredKeys[LEFT])
    {
        tempX=1;
        if (triggeredKeys[UP]||triggeredKeys[SPACE]){tempY=-1;}
        else if(triggeredKeys[DOWN]){tempY=1;}

        if ((tempY==-1)&&(GSWE::DynamicTilesArray[heroIndex].YRel!=0)){
            tempY=0;
        }

        if (ValidMove(heroIndex,tempX,tempY,1))
        triggeredKeys[RIGHT]=true;

        tempX=0;tempY=0;
    }

    else if (heldKeys[LEFT]&&!triggeredKeys[RIGHT])
    {
        tempX=-1;
        if (triggeredKeys[UP]||triggeredKeys[SPACE]){tempY=-1;}
        else if(triggeredKeys[DOWN]){tempY=1;}
       
        if ((tempY==-1)&&(GSWE::DynamicTilesArray[heroIndex].YRel!=0)){
            tempY=0;
        }
        if (ValidMove(heroIndex,tempX,tempY,1))
        triggeredKeys[LEFT]=true;

        tempX=0;tempY=0;
    }


    int tempSpeed=10;
    for (int i=0;i!=6;i++)
    {
        // myout(int(triggeredKeys[i])) space

        if (triggeredKeys[i])
        {
            if (i==4){tempSpeed=20;}
            if (i==5){tempSpeed=20;if(inWater)tempSpeed=5;}
            if(MoveDynamicObject(heroIndex,i,tempSpeed,true))
            {
                triggeredKeys[i]=false;
            }
        }
    }
    // enter

}

void DrawAndUpdate(){

    mainGrid.Draw(mainWindow.renderer);

    SDL_RenderPresent(mainWindow.renderer);
}

int main(){
    Init();

    while (shouldRun)
    {
        FetchEvents();
        CheckEvents();
        DrawAndUpdate();
        SDL_Delay(50);
    }
    return 0;
}

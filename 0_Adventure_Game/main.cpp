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

bool ValidMove(int p_index,int p_dirc,bool isHero=false)
{
    bool cond[5]={0,0,0,0};

    GSWE::Pos dirc = {0,0};   
    if (p_dirc==UP) dirc.y=-1;
    if (p_dirc==DOWN) dirc.y=1;
    if (p_dirc==RIGHT) dirc.x=1;
    if (p_dirc==LEFT) dirc.x=-1;

    for (int i=0;i!=GSWE::StaticTilesArray.size();i++)
    {

        if
        (
            (GSWE::StaticTilesArray[i].pos.x==(GSWE::DynamicTilesArray[p_index].pos.x+dirc.x))
            &&
            (GSWE::StaticTilesArray[i].pos.y==(GSWE::DynamicTilesArray[p_index].pos.y+dirc.y))            
        )
        {
            
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

    if (cond[INSTONE]){return false;}
    if (((p_dirc==UP)||0)&&!(cond[ISINLADDER]||cond[INLADDER]
                            ||cond[INWATER]||cond[ISINWATER])){return false;}



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
                case SDLK_SPACE: if(!heldKeys[SPACE]) heldKeys[SPACE]=true;break;
                
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
    
    if (mainWindow.isClosed){shouldRun=false;}
    if (mainWindow.sizeChanged){
        mainGrid.Update(mainWindow.width,mainWindow.height);
    }

    if (heldKeys[UP]&&!triggeredKeys[DOWN]&&
        ValidMove(heroIndex,UP,1)){triggeredKeys[UP]=true;}

    if (heldKeys[DOWN]&&!triggeredKeys[UP]&&
        ValidMove(heroIndex,DOWN,1)){triggeredKeys[DOWN]=true;}

    if (heldKeys[RIGHT]&&!triggeredKeys[LEFT]&&
        ValidMove(heroIndex,RIGHT,1)){triggeredKeys[RIGHT]=true;}

    if (heldKeys[LEFT]&&!triggeredKeys[RIGHT]&&
        ValidMove(heroIndex,LEFT,1)){triggeredKeys[LEFT]=true;}


    for (int i=0;i!=4;i++)
    {
        if (triggeredKeys[i])
        {
            if(MoveDynamicObject(heroIndex,i,10,true))
            {
                triggeredKeys[i]=false;
            }
        }
    }
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

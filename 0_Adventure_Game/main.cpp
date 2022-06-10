#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <fstream>

#include "GSWE.hpp"
#include "MyWindow.hpp"
#include "simpleui.hpp"
#include "definitions.hpp"

#include "declarations.hpp"
#include "structures.hpp"
#include "gameflow.hpp"
#include "snippets.hpp"
#include "functions.hpp"


void CheckEvents(){
      
    if (mainWindow.isClosed){shouldRun=false;}
    if (mainWindow.sizeChanged){
        mainGrid.Update(mainWindow.width,mainWindow.height);
        
        SDL_Rect tempRect = {mainWindow.width/5,
                            mainWindow.height/3,
                            (mainWindow.width/5)*3,
                            (mainWindow.height/3)};
        
        mainUi.UpdateTexture(mainWindow.renderer,tempRect);
        
        mainWindow.sizeChanged=false;
    }

    if (!isInConversation){
        HandleMovements();
    }
    
    int tempI=0;
    for (tempI=-1;tempI!=4;tempI++)
    {if (heldKeys[tempI+1]) break;}
    if (tempI==4){GSWE::DynamicTilesArray[heroIndex].imageIndex=HERO;}
    //Fixing hero animation

    int tempSpeed=5;
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


    HandleAnimation();

    if (heldKeys[RETURN]){
        if (isInConversation){HandleConversation();}
        else{Interact();}
        heldKeys[RETURN]=0;
    }

}

void DrawAndUpdate(){

    mainGrid.Draw(mainWindow.renderer);
    if (mainUi.shouldDraw){
        mainUi.Draw(mainWindow.renderer);
    }
    SDL_RenderPresent(mainWindow.renderer);
}

int main(){
    Init();

    while (shouldRun)
    {
        FetchEvents();
        CheckEvents();
        DrawAndUpdate();
        SDL_Delay(15);
    }
    return 0;
}

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

    HandleMovements();
    HandleAnimation();

    if (heldKeys[RETURN]){
        Interact();
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
        SDL_Delay(25);
    }
    return 0;
}

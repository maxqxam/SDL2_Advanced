#include "GSWE.hpp"
void MakeLevel0();


void SocialControl(){
    MakeLevel0();    
}


void MakeLevel0(){
    int Type=0;
    if (level==0){
    for (int i=0;i!=GSWE::DynamicTilesArray.size();i++)
    {
    Type=GSWE::DynamicTilesArray[i].imageIndex; 


    if (Type==FIRE0)
    {
        if (i==4)
        {
           GSWE::DynamicTilesArray[i].Socialize(
            {"This feature is still unavailable.",
            "You can still re-open the game,",
            "If you like to play it so much."}
            ,0,1); 
        }
    }
    if (Type==PERSON0)
    {
        if (i==13)
        {
           GSWE::DynamicTilesArray[i].Socialize(
            {"You Shall not pass,",
            "You Shall pass"}
            ,0,1); 
        }
    }

    if (Type==LEVER)
    {
        if (i==3)
        {

        GSWE::DynamicTilesArray[i].Socialize(
        {"Opening Gate",
         "Closing Gate"}
        ,2,0);
        } 

        if (i==14)
        {

        GSWE::DynamicTilesArray[i].Socialize(
        {"Opening Gate",
         "Closing Gate"}
        ,12,0);
        } 

        
    }

    if (Type==GATE0)
    {
        if (i==2)
        {
        GSWE::DynamicTilesArray[i].Socialize(
        {"I cant get past the bars.",
         "This gate is opened"}
        ,0,1);
        }   

        if (i==12)
        {
        GSWE::DynamicTilesArray[i].Socialize(
        {"I cant get past the bars.",
         "This gate is opened"}
        ,0,1);
        }   
    }


    if (Type==FLOWER0)
    {
        if (i==15)
        {
        GSWE::DynamicTilesArray[i].Socialize(
        {"Hello There!",
         "Watz up!"}
        ,0,0); 
        }   
    }

    if (Type==FISH)
    {
        if (i==8)
        {
        GSWE::DynamicTilesArray[i].Socialize({"Blob","Blob There",
                                            "Blob Blob"},0,0);
        }
    }

    if (Type==SIGN0)
    {
        if (i==5)
        {
        GSWE::DynamicTilesArray[i].Socialize(
             {"You can talk with flowers,","Yellow flowers ALWAYS tell the truth."}
            ,0,0);
        }

        else if(i==6)
        {
        GSWE::DynamicTilesArray[i].Socialize(
            {"Use keys to open chests and doors,","You lose a key if you use it."}
            ,0,0);
        }

        else if(i==1)
        {
        GSWE::DynamicTilesArray[i].Socialize(
            {"Use levers to open Gates."}
            ,0,0);
        }

        else if(i==0)
        {
        GSWE::DynamicTilesArray[i].Socialize(
            {"Save your progress on campfires."}
            ,0,0);
        }            
    }    


    }

    }
}
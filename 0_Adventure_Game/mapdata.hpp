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

    if (Type==CHEST0)
    {
        if (i==7)
        {
        GSWE::DynamicTilesArray[i].Socialize(
            {"Opening the chest...",
            "Silver key obtained!"
            }
            ,0,1);
        }
    }
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
            {">This must be the bald wise guy",
             "> whom that flower mentioned,",
             "Hello!",
             ": How can i help you young soul?",
             "> young soul? what is he talking about!",
             "I want to know who I am, and where am I.",
             ": Don't you know that already?",
             "I don't remember.",
             ": ...",
             ": It seems that you are a skeleton.",
             "Ha Ha.",
             ": Im serious, look at your hands.",
             "...",
             "How can this be??",
             ": Why are you surprised?",
             "It means that I'm ... dead?",
             ": Isn't that obvious?",
             ": You are dead. and this is afterlife.",
             ": You'r memories are taken away",
             ": from you. because we are testing you.",
             "It seems... so unreal!",
             ": There are various tests wating for you,",
             ": Pass them and you shall travel back",
             ": to the living land.",
             ": Fail them and you shall get,",
             ": United with NOTHINGLESS.",
             "But...",
             "What are the tests?",
             ": You'll soon find out, ",
             ": Do not trust anything you hear or see.",
             ": You'r objective is to find the truth!"}
            ,0,1); 
        }
    }

    if (Type==LEVER)
    {
        if (i==3)
        {

        GSWE::DynamicTilesArray[i].Socialize(
        {}
        ,2,0);
        } 

        if (i==14)
        {

        GSWE::DynamicTilesArray[i].Socialize(
        {}
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
        {"Hello?",
         ": Hello there how can I Help you?",
         "...",
         "S**t it can ACTUALLY talk :/",
         ": :] ...",

         ": How can i Help you?",
         "I want to know who I am",
         ": You don't know that already?",
         "I don't remember...",
         ": ...",

         ": There is a bald wise guy,",
         ": around here.",
         ": FIND HIM, and you shall get",
         ": your answers."}
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
             {"You can talk with flowers,",
             "Yellow flowers ALWAYS tell the truth.",
             "...",
             "Flowers Can talk?",
             "What a lame prank...",
             "What is this Odd sign anyway?"}
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
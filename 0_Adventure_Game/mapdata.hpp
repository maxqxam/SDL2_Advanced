#include "GSWE.hpp"
void MakeLevel0();
void MakeLevel1();

void SocialControl(){
    MakeLevel0(); 
    MakeLevel1();   
}

void MakeLevel1()
{
    int Type=0;
    if (level==1){
    for (int i=0;i!=GSWE::DynamicTilesArray.size();i++)
    {
    Type=GSWE::DynamicTilesArray[i].imageIndex;


    if (Type==DOOR)
    {
        
        if (i==8)
        {
            GSWE::DynamicTilesArray[i].Socialize(
            {"This is the door behind the green sign",
            "The sign said it is supposed to-",
            "Lead me to the LIVING LAND.",
            "...",
            "Are you sure you want to use your key on this?",
            "Press Right Shift to leave it open.",
            "Press Right Ctrl to open the door."}
            ,0,1);
        }
        else if(i==9)
        {
            GSWE::DynamicTilesArray[i].Socialize(
            {"This is the door behind the red sign.",
            "The sign said it is supposed to-",
            "Lead me to NOTHINGNESS.",
            "...",
            "Are you sure you want to use your key on this?",
            "Press Right Shift to leave it open.",
            "Press Right Ctrl to open the door."}
            ,0,1);
        }
        else if(i==10)
        {
            GSWE::DynamicTilesArray[i].Socialize(
            {"This is the door behind the blue sign.",
            "The sign said it is supposed to-",
            "Lead me to NOTHINGNESS.",
            "...",
            "Are you sure you want use your key on this?",
            "Press Right Shift to leave it open.",
            "Press Right Ctrl to open the door."}
            ,0,1);
        }
    }
    else if (Type==GATE0)
    {     

        //30 and 2
        GSWE::DynamicTilesArray[i].Socialize(
        {"I cant get past the bars.",
         "This gate is opened"}
        ,0,1);
          
    }
    else if (Type==LEVER)
    {
        if (i==25)
        {
        GSWE::DynamicTilesArray[i].Socialize(
        {}
        ,2,0);
        
        }    
    }
    else if (Type==SIGN0)
    {
        if (i==16)
        {
        GSWE::DynamicTilesArray[i].Socialize(
             {"The flowers and signs are-",
             "of three main colors.",
             "Red, Green and Blue.",
             "One color NEVER lies.",
             "One color SOMETIMES lies.",
             "One color ALWAYS lies.",
             "Your job is to find the-",
             "door that will lead you to the-",
             "Living land. using the info they-",
             "Provide you. ",
             "...",
             "- I honestly believed the test-",
             "- is about killing dungeon dragons.",
             "- What a relief...",
             "..."
             }
            ,0,0);
        }
    }
    else if (Type==SIGN1)
    {
        if (i==6)
        {
        GSWE::DynamicTilesArray[i].Socialize(
             {
             "The door behind me leads you to-",
             "NOTHING."}
            ,0,0);
        }
        if (i==28)
        {
        GSWE::DynamicTilesArray[i].Socialize(
             {
             "Every flower here is lying."
             }
            ,0,0);
        }
    }
    else if (Type==SIGN2)
    {
        if (i==5)
        {
        GSWE::DynamicTilesArray[i].Socialize(
             {
             "The door behind me leads you to-",
             "NOTHING."}
            ,0,0);
        }
        if (i==3)
        {
        GSWE::DynamicTilesArray[i].Socialize(
             {
             "The fishes below me eat people."}
            ,0,0);
        }
    }
    else if (Type==SIGN3)
    {
        if (i==7)
        {
        GSWE::DynamicTilesArray[i].Socialize(
             {
             "The door behind me leads you to-",
             "the LIVING LAND."
             }
            ,0,0);
        }
        if (i==4)
        {
        GSWE::DynamicTilesArray[i].Socialize(
             {
             "There are 3 Bees in this level."
             }
            ,0,0);
        }
    }
    else if(Type==FLOWER0)
    {
        if (i==13)
        {
            GSWE::DynamicTilesArray[i].Socialize(
            {
            "The one who always lies is not here.",
            "...",
            ": JACKPOT"
            }
            ,0,0);
        }
    }
    else if(Type==FLOWER1)
    {
        if (i==11)
        {
        GSWE::DynamicTilesArray[i].Socialize(
             {
             "There is a secret garden around here.",
             "I always tell the truth."}
            ,0,0);
        }
        if (i==22)
        {
        GSWE::DynamicTilesArray[i].Socialize(
             {
             "There are 5 bees in this level.",
             "...",
             ": am I supposed to count the bees now?"
             }
            ,0,0);
        }
        if (i==24)
        {
        GSWE::DynamicTilesArray[i].Socialize(
             {
             "Only 2 bees feed from flowers.",
             "...",
             ": How do you know :/"
             }
            ,0,0);
        }
        if (i==14)
        {
        GSWE::DynamicTilesArray[i].Socialize(
             {
             "The flower on my left lies sometimes.",
             "...",
             ": Makes sense...",
             ": Since those fishes don't eat me"
             }
            ,0,0);
        }
    }
    else if(Type==FLOWER2)
    {
        if (i==12)
        {
        GSWE::DynamicTilesArray[i].Socialize(
             {
             "Skeletons can't breath under water."}
            ,0,0);
        }
        if (i==23)
        {
        GSWE::DynamicTilesArray[i].Socialize(
             {
             "One of the fishes is depressed.",
             "...",
             ": How can I make sure that it is depressed?",
             "...",
             "Good question,",
             "ASK THE HYPE ONE"}
            ,0,0);
        }
        if (i==15)
        {
        GSWE::DynamicTilesArray[i].Socialize(
             {
             "The flower on my right lies sometimes.",
             "...",
             ": He says the same thing!",

             "it's because hes a lier."}
            ,0,0);
        }
    }
    else if(Type==FLOWER3)
    {
        if (i==27)
        {
        GSWE::DynamicTilesArray[i].Socialize(
             {
             "Bees feed from honest flowers.",
             "...",
             ": How are you so sure?",
             "Look up"}
            ,0,0);
        }
        if (i==26)
        {
        GSWE::DynamicTilesArray[i].Socialize(
             {
             "The content written on the sign-",
             "on my left are a bunch of lies."}
            ,0,0);
        }
    }
    else if(Type==FISH)
    {
        if (i==0)
        {
        GSWE::DynamicTilesArray[i].Socialize({"BLOB!!","BLOB THEEERE!",
                                            "BLLllooOOoOBBb!!"},0,0);
        GSWE::DynamicTilesArray[i].state=1;
        GSWE::DynamicTilesArray[i].moveArray=
        {
            UP,RIGHT,
            DOWN,RIGHT,
            UP,RIGHT,
            DOWN,DOWN,RIGHT,
            UP,UP,RIGHT,
            DOWN,DOWN,DOWN,RIGHT,
            STOP,
            UP,UP,
            LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,
        };
        }
        if (i==1)
        {
        GSWE::DynamicTilesArray[i].Socialize({"...","blob...",
                                            "blob blob"},0,0);
        GSWE::DynamicTilesArray[i].moveArray=
        {RIGHT,RIGHT,
        UP,RIGHT,RIGHT,RIGHT,RIGHT,
        STOP,STOP,STOP,
        LEFT,
        UP,UP,
        STOP,STOP,STOP,
        DOWN,DOWN,
        RIGHT,
        STOP,
        LEFT,LEFT,LEFT,LEFT,LEFT,LEFT,
        DOWN,
        };
        }
       
    }
    else if(Type==BEE)
    {
        GSWE::DynamicTilesArray[i].Socialize({"BIzz"," BIiiiIzZZz",
                                            "Bizzzz"},0,0);
        
        if (i==17) // Liers garden
        {
        GSWE::DynamicTilesArray[i].moveArray=
        {DOWN,DOWN,DOWN,
        FREEZE,FREEZE,FREEZE,
        UP,
        RIGHT,RIGHT,RIGHT,
        STOP,
        RIGHT,RIGHT,RIGHT,
        DOWN,FREEZE,FREEZE,
        UP,RIGHT,
        STOP,
        LEFT,LEFT,LEFT,
        STOP,LEFT,LEFT,LEFT,LEFT,
        STOP,STOP,
        UP,UP
        
        };
        }
        if (i==18) // First bee
        {
          GSWE::DynamicTilesArray[i].moveArray=
        {
        DOWN,
        STOP,
        LEFT,LEFT,
        STOP,
        RIGHT,RIGHT,UP,
        FREEZE,
        LEFT,LEFT,LEFT,
        STOP,
        LEFT,LEFT,LEFT,LEFT,
        STOP,
        UP,
        RIGHT,RIGHT,RIGHT,
        STOP,
        DOWN,
        RIGHT,RIGHT,RIGHT,RIGHT
        };  
        }
        if (i==19) //End game
        {
          GSWE::DynamicTilesArray[i].moveArray=
        {
        LEFT,LEFT,LEFT,LEFT,
        LEFT,LEFT,LEFT,LEFT,
        LEFT,LEFT,LEFT,LEFT,

        DOWN,DOWN,DOWN,DOWN,
        DOWN,DOWN,DOWN,
        FREEZE,FREEZE,FREEZE, //Landing
        UP,UP,UP,
        STOP,STOP,STOP,
        STOP,
        UP,UP,UP,
        UP,
        RIGHT,RIGHT,RIGHT,RIGHT,
        RIGHT,RIGHT,RIGHT,RIGHT,
        RIGHT,RIGHT,RIGHT,RIGHT,

        };  
        }
        if (i==20)//Secret Garden
        {
          GSWE::DynamicTilesArray[i].moveArray=
        {
        UP,UP,UP,UP,
        RIGHT,RIGHT,RIGHT,RIGHT,
        RIGHT,RIGHT,RIGHT,RIGHT,
        RIGHT,RIGHT,RIGHT,RIGHT,
        DOWN,DOWN,DOWN,
        STOP,STOP,STOP,
        UP,UP,UP,
        LEFT,LEFT,LEFT,LEFT,
        LEFT,LEFT,LEFT,LEFT,
        DOWN,DOWN,DOWN,
        LEFT,LEFT,LEFT,LEFT,
        STOP,STOP,
        DOWN,DOWN,DOWN,DOWN,
        FREEZE,FREEZE,FREEZE, // Landing
        UP,UP,UP
        };  
        }
        if (i==21) //Secret garden
        {
          GSWE::DynamicTilesArray[i].moveArray=
        {
        DOWN,DOWN,
        RIGHT,RIGHT,
        STOP,STOP,
        RIGHT,RIGHT,
        RIGHT,RIGHT,
        STOP,
        LEFT,LEFT,LEFT,LEFT,
        STOP,STOP,
        LEFT,LEFT,LEFT,
        DOWN,
        STOP,
        RIGHT,RIGHT,
        STOP,
        RIGHT,RIGHT,
        STOP,
        RIGHT,RIGHT,
        STOP,
        LEFT,LEFT,LEFT,LEFT,
        UP,
        LEFT,LEFT,
        UP,UP,RIGHT
        };  
        }
    }






    }
    }
}

void MakeLevel0()
{
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
            "..."
            }
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
             ": from you. ",             
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
        GSWE::DynamicTilesArray[i].moveArray=
        {
           RIGHT,DOWN,RIGHT,RIGHT,
           UP,RIGHT,UP,RIGHT,
           LEFT,DOWN,LEFT,DOWN,
           LEFT,LEFT,UP,LEFT,STOP,
           LEFT,LEFT,LEFT,
           STOP,
           RIGHT,RIGHT,RIGHT
        };
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
            {"Use keys to open doors,","You lose a key when you use it."}
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
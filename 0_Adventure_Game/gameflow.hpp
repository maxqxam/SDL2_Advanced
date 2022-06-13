void StartConversation(int p_index,std::vector<std::string> & p_text_array)
{
    p_text_array.push_back(GSWE::DynamicTilesArray[p_index].captions[0]);
    GSWE::DynamicTilesArray[p_index].textIndex=1;
    currentConversationId = p_index;
    isInConversation=true;
    
}


void HandleConversation(int inputType)
{
    // Mix_PlayChannel(-1,ding,0);
    if ((level==1)&&(totoalKeys==0)&&
        (GSWE::DynamicTilesArray[currentConversationId].imageIndex==doorFrames[4]))
    {
        inputType=RETURN;
    }

    if (GSWE::DynamicTilesArray[currentConversationId].captions.size()
       > 
       GSWE::DynamicTilesArray[currentConversationId].textIndex
       )
    {
    
    if (((GSWE::DynamicTilesArray[currentConversationId].textIndex)%6)==0)
    {
        mainUi.textArray.clear();
    }

    mainUi.textArray.push_back(GSWE::DynamicTilesArray[currentConversationId].captions[
        GSWE::DynamicTilesArray[currentConversationId].textIndex
    ]);
    
    GSWE::DynamicTilesArray[currentConversationId].textIndex+=1;

    SDL_Rect tempRect = {mainWindow.width/5,
                            mainWindow.height/3,
                            (mainWindow.width/5)*3,
                            (mainWindow.height/3)};


    if (inputType==RSHIFT)
    {
        GSWE::DynamicTilesArray[currentConversationId].textIndex=0;
        mainUi.textArray.clear();
        currentConversationId=0;
        mainUi.shouldDraw=false;
        isInConversation=false;
    }

    mainUi.UpdateTexture(mainWindow.renderer,tempRect);
    
    }
    else
    {
        if ((level==1)&&(totoalKeys==0)&&
        (GSWE::DynamicTilesArray[currentConversationId].imageIndex==doorFrames[4]))
        {
            if (currentConversationId==10)
            {
                
                
                myout("I was planning to work on this way more, but \n")
                myout("Unfortunatly the deadline was near the begining of my\n")
                myout("Semester exams and I had to let it go!\n")
                myout("Anyways, Thank you for playing!\n")
                shouldRun=false;

            }
            if (currentConversationId==8)
            {
               
                myout("I was planning to work on this way more, but \n")
                myout("Unfortunatly the deadline was near the begining of my\n")
                myout("Semester exams and I had to let it go!\n")
                myout("Anyways, Thank you for playing!\n")
                shouldRun=false;

            }
            if (currentConversationId==9)
            {
                
                myout("I was planning to work on this way more, but \n")
                myout("Unfortunatly the deadline was near the begining of my\n")
                myout("Semester exams and I had to let it go!\n")
                myout("Anyways, Thank you for playing!\n")
                shouldRun=false;

            }
        }
        if ((inputType==RSHIFT) &&
            (GSWE::DynamicTilesArray[currentConversationId].imageIndex==DOOR))
        {
            // myout("Canceled!\n")
        }
        else if((inputType==RCTRL) &&
            (GSWE::DynamicTilesArray[currentConversationId].imageIndex==doorFrames[0]))
        {
            totoalKeys=0;   // ACCEPT
            GSWE::DynamicTilesArray[currentConversationId].imageIndex=doorFrames[1];
            GSWE::DynamicTilesArray[currentConversationId].state=0;

            
            if (currentConversationId==8)
            {
                GSWE::DynamicTilesArray[currentConversationId].captions=
                                                            {"The door is open.",
                                                            "...",
                                                            "I am going inside.",
                    "...",
                    "Wrong choice!",
                    "Green is the one who always lies!!",
                    "Prepare to get destroyed!!",
                    "3...",
                    "2..",
                    "1.",
                    "Thanks for playing"};
            }
            if (currentConversationId==9)
            {
                GSWE::DynamicTilesArray[currentConversationId].captions=
                                                            {"The door is open.",
                                                            "...",
                                                            "I am going inside.",
                    "...",
                    "Congrats!",
                    "You have made the most reasonable choice!",
                    "Red is the one who sometimes lies!",
                    "Are you praying that red didn't lie?",
                    "You think he lied that 'the door behind me,",
                    "leads you to Nothing?'",
                    "Well...",
                    "he didn't...",
                    "prepare to get destroyed!!",
                    "3...  ",
                    "2..",
                    "1.",
                    "Thanks for playing"

                    };
            }
            if (currentConversationId==10)
            {
                GSWE::DynamicTilesArray[currentConversationId].captions=
                                                            {"The door is open.",
                                                            "...",
                                                            "I am going inside.",
                    "...",
                    "Wrong choice!",
                    "Blue is the one who never lies!!",
                    "Prepare to get destroyed!!",
                    "3...",
                    "2..",
                    "1.",
                    "Thanks for playing"};
            }
            
        }
        isInConversation=false;
        currentConversationId=0;
        mainUi.shouldDraw=false;
    }
}
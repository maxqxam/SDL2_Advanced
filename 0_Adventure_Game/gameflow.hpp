void StartConversation(int p_index,std::vector<std::string> & p_text_array)
{
    p_text_array.push_back(GSWE::DynamicTilesArray[p_index].captions[0]);
    GSWE::DynamicTilesArray[p_index].textIndex=1;
    currentConversationId = p_index;
    isInConversation=true;
    
}


void HandleConversation()
{
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

    mainUi.UpdateTexture(mainWindow.renderer,tempRect);
    
    }
    else
    {
        isInConversation=false;
        currentConversationId=0;
        mainUi.shouldDraw=false;
    }
}
SDL_Texture* loadTexture(SDL_Renderer* p_renderer,
                std::string path,int &p_width,
                                 int &p_height){
    
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface==NULL){
        std::cout<<path<<'\n'<<'\t';
        std::cout<<SDL_GetError()<<std::endl;
        return NULL;
    }
    newTexture = SDL_CreateTextureFromSurface(p_renderer,loadedSurface);
    if (newTexture==NULL){
        std::cout<<path<<'\n'<<'\t';
        std::cout<<SDL_GetError()<<std::endl;
        return NULL;
    }
    p_width = loadedSurface->w;
    p_height = loadedSurface->h;
    SDL_FreeSurface(loadedSurface);
    
    return newTexture;
}

void LoadLevel(std::string p_path){
        std::ifstream inputFile(p_path);

        int posx  = 0;
        int posy  = 0;
        int index = 0;

        int counter = 0;
        std::string text="";
        std::string tempString = "";
        int totalLines = 0;
        while (std::getline(inputFile,text))
        {
            totalLines ++;
            for (int i=0;i!=text.length();i++){
                if (text[i]=='_'){
                    // myout("tempString: ") myout(tempString) enter
                    if (counter==0){
                        index = std::stoi(tempString);
                    }else if(counter==1){
                        posx = std::stoi(tempString);
                    }
                    counter++;
                    tempString="";
                }else{
                    tempString+=text[i];
                }
            }
            posy=std::stoi(tempString);

            if ((index<17)||(index==28))
            {
                GSWE::StaticTilesArray.push_back({{posx,posy},index});
            }
            else {
                if (index==35)
                {
                    heroIndex=GSWE::DynamicTilesArray.size();
                }
                GSWE::DynamicTilesArray.push_back({{posx,posy},index,0,0});
            }

            counter = 0;
            tempString = "";
        }

        myout(totalLines) myout(" Loaded from ")
        myout(p_path) enter
}
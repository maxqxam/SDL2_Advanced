#include "SDL2/SDL_ttf.h"
namespace SU{
    TTF_Font* gFont=NULL;
    struct SimpleUi{  


        bool shouldDraw=false;
        std::vector<std::string> textArray;
        SDL_Color textColor = {0,0,0,255};
        SDL_Color backgroundColor = {180,180,180,200};

        std::vector<SDL_Rect> textRectArray;
        SDL_Rect backgroundRect;
        std::vector<SDL_Texture*> textureArray;
        bool shouldDrawRect=false;

        int maxLines = 6;
        












        SimpleUi(std::vector<std::string> p_textArray
                        ,SDL_Rect p_rect)
        {
            textArray=p_textArray;
            backgroundRect=p_rect;
        }




        void UpdateTexture(SDL_Renderer* p_renderer,
                SDL_Rect p_rect)
        {
            backgroundRect=p_rect;

            if (textRectArray.size()!=0)textRectArray.clear();
            if (textureArray.size()!=0)textureArray.clear();
            for (int i=0;i!=textArray.size();i++)
            {
                textRectArray.push_back({0,0,0,0});
                textureArray.push_back((SDL_Texture*) NULL);
            }

            GetTexture(p_renderer);
        }



        void Draw(SDL_Renderer* p_renderer)
        {
            SDL_SetRenderDrawColor(p_renderer,
                                backgroundColor.r,
                                backgroundColor.g,
                                backgroundColor.b,
                                backgroundColor.a);
            
            SDL_RenderFillRect(p_renderer,&backgroundRect);

            for (int i=0;i!=textureArray.size();i++)
            {
                SDL_Rect tempRect=textRectArray[i];
                tempRect.x+=backgroundRect.x;
                tempRect.y+=backgroundRect.y+(tempRect.h*i);

                SDL_RenderCopy(p_renderer,textureArray[i],
                                NULL,&tempRect);
            }
        }

        void GetTexture(SDL_Renderer* p_renderer){
            
            SDL_Surface* tempSurf;
            // std::cout<<textArray.size()<<"\n";
            for (int i=0;i!=textArray.size();i++)
            {

                tempSurf = TTF_RenderText_Solid(gFont,textArray[i].c_str()
                            ,textColor);
                textureArray[i] = SDL_CreateTextureFromSurface(p_renderer,tempSurf);
                
                textRectArray[i].w = (backgroundRect.h/maxLines)*(tempSurf->w/tempSurf->h);
                textRectArray[i].h = backgroundRect.h/maxLines;
                if (textRectArray[i].w>backgroundRect.w)
                {textRectArray[i].w=backgroundRect.w;}


            }

            SDL_FreeSurface(tempSurf);           
        }

















    };
}
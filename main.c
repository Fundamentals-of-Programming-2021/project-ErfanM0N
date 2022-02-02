#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "NameMenu.h"
#include "GameGraphic.h"





int main() {
    char name[20] = "";

    if (!init())
    {
        return 0 ;
    }
    
    SDL_Window *Window = SDL_CreateWindow("FOP project",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_OPENGL);
    SDL_Renderer *Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    //Set Background Image
    if (!init_IMG())
    {
        return 0 ;
    }

    //Set text and font
    if (!init_TTF())
    {
        return 0 ;
    }

    //set Name
    SDL_Texture *TextureFirst = IMG_LoadTexture(Renderer, "../IMG/FirstPage.jpg");
    SDL_Rect FullPic = {.x=0, .y=0, .w=SCREEN_WIDTH, .h=SCREEN_HEIGHT};

    //if (!getName(Window,Renderer,TextureFirst,FullPic,name))
    //{
    //    return 0;
    //}
    SDL_DestroyTexture(TextureFirst);

    //set Menu
    SDL_Texture *TextureMenu = IMG_LoadTexture(Renderer, "../IMG/MenuPage.jpg");

    //if (!Menu(Window,Renderer,TextureMenu,FullPic))
    //{
    //    return 0;
    //}
    SDL_DestroyTexture(TextureMenu);

    //start Game
    SDL_Texture *TextureBG = IMG_LoadTexture(Renderer, "../IMG/GameBG.jpg");

    int t = 10 ;
    state object[t];
    CreateState(Renderer,t,object);

    int p = 5;
    play Player[p];
    CreatePlayer(Renderer,p,Player);

    SetStateOwner(t,object,p,Player);
    SDL_Texture *TextureSol = IMG_LoadTexture(Renderer, "../IMG/SoldierIcon.png");

    
    SDL_Texture *BoardT = GetText(Renderer,45,"Arial.ttf",0,0,30,"LEADERBOARD");
    
    int j = -1;
    int w = 0 ,w1,w2 ;
    int x = 0 ;
    SDL_Event sdlEvent;
    SDL_bool Exit = SDL_FALSE;
    while (Exit == SDL_FALSE) 
    {
        SDL_SetRenderDrawColor(Renderer, 0 , 0 , 0 , 255);
        SDL_RenderClear(Renderer);
        SDL_RenderCopy(Renderer, TextureBG, NULL, &FullPic);
        

        for (int i = 0; i < t; i++)
        {
            
            if (object[i].shape)
            {
                filledCircleRGBA(Renderer,object[i].x,object[i].y,object[i].size,object[i].owner.R,object[i].owner.G,object[i].owner.B,0.5*object[i].soldier + 120);
            }
            else
            {
                boxRGBA(Renderer, object[i].x - object[i].size , object[i].y - object[i].size ,
                object[i].x + object[i].size, object[i].y + object[i].size,object[i].owner.R,object[i].owner.G,object[i].owner.B,0.5*object[i].soldier + 120);
            }
         
        }
        
        SoldierIcon(Renderer,t,object,TextureSol);
        x++ ;
        if (x == FPS/5)
        {
            IncreaseSoldier(t,object,p,Player);
            x = 0 ;
        }
        ShowNumberOfSoldiers(Renderer,t,object);

        Getscore(t,object,p,Player);

        SetRank(p,Player);

        RenderLeaderBoard(Renderer,BoardT,p,Player);

        if (j > -1)
        {
            SDL_SetRenderDrawColor(Renderer, 255 , 0 , 0 , 255);
            SDL_Rect choice = {.x = object[j].x - 26 ,.y = object[j].y - 26 , .w = 52 ,.h = 52};
            Render_border(Renderer,choice,3);
        }
        
        if (w)
        {
            thickLineRGBA(Renderer,object[j].x,object[j].y,w1,w2,3,255,0,0,255);
        }
        

        SDL_RenderPresent(Renderer);
        
        
        SDL_PollEvent(&sdlEvent) ;
        if (sdlEvent.type == SDL_QUIT)
        {
            Exit = SDL_TRUE;
            return 0 ;
        }
        else if (sdlEvent.type == SDL_MOUSEBUTTONDOWN)
        {
            for (int i = 0; i < t; i++)
            {
                if (sdlEvent.button.x >= object[i].x - 24 && sdlEvent.button.x <= object[i].x + 24 && 
                sdlEvent.button.y >= object[i].y - 24 && sdlEvent.button.y <= object[i].y + 24)
                {
                    j = i ;
                    SDL_Delay(1000 / FPS);
                    SDL_SetRenderDrawColor(Renderer, 255 , 0 , 0 , 255);
                    SDL_Rect choice = {.x = object[j].x - 26 ,.y = object[j].y - 26 , .w = 52 ,.h = 52};
                    Render_border(Renderer,choice,3);
                    SDL_RenderPresent(Renderer);
                    w = 0;
                }
                
            }
            
        }
        else if (sdlEvent.type == SDL_MOUSEMOTION && j > 0)
        {
            w = 1;
            w1 = sdlEvent.button.x;
            w2 = sdlEvent.button.y;
               
        }      
        
        SDL_Delay(1000 / FPS);
    }
    
    
    SDL_DestroyWindow(Window);
    return 0;

}
#ifndef _HEADER_Gamelogic_H

#define _HEADER_Gamelogic_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "Functions.h"


const int vCursor = 10;
const float v = 1.5 ;

int AmountOfPlayers;

int WinOrLost(int p,play Player[p]){

    
    
    //SDL_Rect end = {.x = 200 , .y = 500 , .w = 400 , .h = 100 };
    //SDL_Texture *TextEnd = GetText(Renderer,100,"Arial.ttf",0,0,0,"GAME OVER");
    if (Player[1].score == 0)
    {
        SDL_Window *ExitWindow = SDL_CreateWindow("GameOver",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,500,300,SDL_WINDOW_OPENGL);
        SDL_Renderer *ExitRenderer = SDL_CreateRenderer(ExitWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
        SDL_Event Event;

        SDL_bool Exit = SDL_FALSE;
        while (Exit == SDL_FALSE) 
        {
            SDL_SetRenderDrawColor(ExitRenderer, 255, 255, 255, 255);
            SDL_RenderClear(ExitRenderer);
        
        
            SDL_RenderPresent(ExitRenderer);
        
            while (SDL_PollEvent(&Event))
            {
                if (Event.type == SDL_QUIT)
                {
                    Exit = SDL_TRUE;
                    return 0 ;
                }
            }
        
            SDL_Delay(1000 / /*FPS*/ 60);
        }
    
    
    }

    
    return 0 ;

}










#endif
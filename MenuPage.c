#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "Functions.h"

extern const int FPS ;

void Render_border(SDL_Renderer *Renderer,SDL_Rect border,int size){
    for (int j = 1; j <= size; j++)
    {
        SDL_RenderDrawRect(Renderer,&border);

        border.x -= 1,border.y -= 1;
        border.w += 2,border.h += 2;
    }
}

int Menu(SDL_Window *Window,SDL_Renderer *Renderer,SDL_Texture *TextureMenu,SDL_Rect FullPic,SDL_Texture *TextureBack,SDL_Rect Back){
    
    SDL_Rect border[3];

    border[0].x = 90 , border[0].y = 335, border[0].w = 640 ,border[0].h = 110 ;
    border[1].x = 60 , border[1].y = 510, border[1].w = 840 ,border[1].h = 110 ;
    border[2].x = 240 , border[2].y = 670, border[2].w = 440 ,border[2].h = 110 ;

    SDL_Event sdlEvent;
    SDL_bool Exit = SDL_FALSE;

    static int i = 1 ;

    while (Exit == SDL_FALSE) 
    {
        SDL_SetRenderDrawColor(Renderer, 0 , 0 , 0 , 255);
        SDL_RenderClear(Renderer);

        SDL_RenderCopy(Renderer, TextureMenu, NULL, &FullPic);
        SDL_RenderCopy(Renderer, TextureBack, NULL, &Back);

        
        Render_border(Renderer,border[0],5);
        Render_border(Renderer,border[1],5);
        Render_border(Renderer,border[2],5);
        
        SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
        
        Render_border(Renderer,border[i-1],5); 

        SDL_RenderPresent(Renderer);
        

        while (SDL_PollEvent(&sdlEvent))
        {

            if (sdlEvent.type == SDL_QUIT)
            {
                Exit = SDL_TRUE;
                return 0 ;
            }

            else if (sdlEvent.type == SDL_KEYDOWN)
            {

                if (sdlEvent.key.keysym.sym == SDLK_DOWN)
                {
                    i++ ;
                    if (i == 4)
                    {
                        i = 1;
                    }
                    
                }

                else if (sdlEvent.key.keysym.sym == SDLK_UP)
                {
                    i--;
                    if (i == 0)
                    {
                        i = 3;
                    }
    
                }
             
                else if (sdlEvent.key.keysym.sym == SDLK_RETURN)
                {
                         
                    return i;
                    
                }

            }

            else if (sdlEvent.type == SDL_MOUSEBUTTONDOWN)
            {

                if (sdlEvent.button.x >= 90 && sdlEvent.button.x <= 90 + 640 && sdlEvent.button.y >= 335 && sdlEvent.button.y <= 335 + 110)
                {
                    i = 1;
                    return 1;
                }

                else if (sdlEvent.button.x >= 60 && sdlEvent.button.x <= 60 + 840 && sdlEvent.button.y >= 510 && sdlEvent.button.y <= 510 + 110)
                {
                    i = 2;
                    return 2;
                }

                else if (sdlEvent.button.x >= 240 && sdlEvent.button.x <= 240 + 440 && sdlEvent.button.y >= 670 && sdlEvent.button.y <= 670 + 100)
                {
                    i = 3;
                    return 3 ;
                }

                else if (sdlEvent.button.x >= 10 && sdlEvent.button.x <= 10 + 100 && sdlEvent.button.y >= 10 && sdlEvent.button.y <= 10 + 70)
                {
                    return -1 ;
                }
            
            }
        }    
                
        SDL_Delay(1000 / FPS);
    }

    return 4;

}


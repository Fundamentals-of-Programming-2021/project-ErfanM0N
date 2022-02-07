#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "Functions.h"
#include "Structs.h"
#include <math.h>


const int SCREEN_WIDTH = 1270;
const int SCREEN_HEIGHT = 850;
const int FPS = 60;



int main() {

    char name[20] = "";

    if (!init())
    {
        return 0 ;
    }
    
    SDL_Window *Window = SDL_CreateWindow("FOP project",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_OPENGL);
    SDL_Renderer *Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    if (!init_IMG())
    {
        return 0 ;
    }

    if (!init_TTF())
    {
        return 0 ;
    }


    SDL_Rect FullPic = {.x = 0, .y = 0, .w = SCREEN_WIDTH, .h = SCREEN_HEIGHT};
    SDL_Rect Back = {.x = 10, .y = 10, .w = 100, .h = 70};

    
    int i = 0;
    
    while (1)
    {
        if (i < 1)
        {
            SDL_Texture *TextureFirst = IMG_LoadTexture(Renderer, "../IMG/FirstPage.jpg");
   
            if (!getName(Window,Renderer,TextureFirst,FullPic,name))
            {
                break;
            }
            SDL_DestroyTexture(TextureFirst);
            i++;
        }
        


        int j = 0;

        if (i < 2)
        {
            SDL_Texture *TextureMenu = IMG_LoadTexture(Renderer, "../IMG/MenuPage.jpg");
            SDL_Texture *TextureBack = IMG_LoadTexture(Renderer, "../IMG/Back.png");

            j = Menu(Window,Renderer,TextureMenu,FullPic,TextureBack,Back) ;
        
            SDL_DestroyTexture(TextureMenu);
            SDL_DestroyTexture(TextureBack);

            if (j == -1)
            {
                i--;
                continue;
            }

            else if (j == 0)
            {
                break;
            }

            else
            {
                i++;
            }

        }

        
        int j1 = 0;


        if (i < 3)
        {
            if (j > 0)
            {
                SDL_Texture *TextureGameFirstPage = IMG_LoadTexture(Renderer, "../IMG/GameFirstPage.jpg");
                SDL_Texture *TextureBack = IMG_LoadTexture(Renderer, "../IMG/Back.png");

                j1 = StartGame(Window,Renderer,TextureGameFirstPage,FullPic,TextureBack,Back) ;
        
                SDL_DestroyTexture(TextureGameFirstPage);
                SDL_DestroyTexture(TextureBack);

                if (j1 == -1)
                {
                    i--;
                    continue;
                }

                else if (j1 == 0)
                {
                    break;
                }

                else
                {
                    i++;
                }
            }

            //else
            //{
            //    break;
            //}
            

        }


        int j2 = 0 ;


        if (i < 4)
        {
            if (j1 == 1)
            {
                SDL_Texture *TextureBG = IMG_LoadTexture(Renderer, "../IMG/GameBG.jpg");
                SDL_Texture *TextureBack = IMG_LoadTexture(Renderer, "../IMG/Back.png");

                int t = 10 ;
                state object[t];
                CreateState(Renderer,t,object);

                int p = 5;
                play Player[p];
                CreatePlayer(Renderer,p,Player);
                SetStateOwner(t,object,p,Player);
                

                j2 = Game(Window,Renderer,TextureBG,FullPic,t,object,p,Player) ;
        
                SDL_DestroyTexture(TextureBG);
                SDL_DestroyTexture(TextureBack);

                if (j2 == -1)
                {
                    i--;
                    continue;
                }

                else if (j2 == 0)
                {
                    break;
                }

                else
                {
                    i++;
                    break;
                }
            }

            else
            {
                break;
            }
            

        }
        
        
        
        
        
        
    


        //SDL_Texture *TextureBG = IMG_LoadTexture(Renderer, "../IMG/GameBG.jpg");
        //SDL_Texture *TextureGameFirstPage = IMG_LoadTexture(Renderer, "../IMG/GameFirstPage.jpg");

    


    

    
    }


    
    SDL_DestroyWindow(Window);
    return 0;

}
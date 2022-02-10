#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string.h>
#include "Functions.h"
#include "Structs.h"


const int SCREEN_WIDTH = 1270;
const int SCREEN_HEIGHT = 850;
const int FPS = 60;
int AmountOfPlayers;



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

    int j = 0;
    int j1 = 0;
    int j2 = 0;
    int j3 = 0;

    int number = -1;


    int n0 ;


    FILE* fp = fopen("ScoreBoard.txt","r");

    fscanf(fp,"%d",&n0);

    PlayerName N[n0+1];

    for (int i = 0; i < n0; i++)
    {
        fscanf(fp,"%s %d %d",N[i].Name,&N[i].rank,&N[i].Score);
    }

    fclose(fp);



    int p = 5;
    play Player[p];
    CreatePlayer(Renderer,p,Player);

    int t = 10 ;
    state object[t];
    


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



        if (i < 3)
        {
            if (j == 1)
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

            else if (j == 2)
            {
                i++;
                j3 = 2;
                j1 = 1 ;
            }
            

            else
            {
                SDL_Texture *TextureScoreBoard = IMG_LoadTexture(Renderer, "../IMG/ScoreBoard.jpg");
                SDL_Texture *TextureBack = IMG_LoadTexture(Renderer, "../IMG/Back.png");

                j1 = ScoreBoard(Window,Renderer,TextureScoreBoard,FullPic,TextureBack,Back,n0,N,number) ;
        
                SDL_DestroyTexture(TextureScoreBoard);
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

            }
            

        }


        if (i < 4)
        {

            if (j1 == 1)
            {

                for (int i = 0; i < n0; i++)
                {
                    if (!(strcmp(name,N[i].Name)) )
                    {
                        number = i ;
                        break;
                    }
                    
                }

                if (number == -1)
                {
                    number = n0 ;
                    strcpy(N[n0].Name,name);
                    N[n0].Score = 0;
                    N[n0].rank = n0 + 1 ;
                }
                

                SDL_Texture *TextureBG = IMG_LoadTexture(Renderer, "../IMG/GameBG.jpg");
                SDL_Texture *TextureBack = IMG_LoadTexture(Renderer, "../IMG/Back.png");

                if (j3 == 0)
                {
                    CreateState(Renderer,t,object);
            
                    SetStateOwner(t,object,p,Player);
                
                }

                if (j3 == 2)
                {
                    j2 = Game(Window,Renderer,TextureBG,FullPic,t,object,p,Player,n0,N,number,1) ;
                }

                else
                {
                    j2 = Game(Window,Renderer,TextureBG,FullPic,t,object,p,Player,n0,N,number,0) ;
                }
                

                SDL_DestroyTexture(TextureBG);
                SDL_DestroyTexture(TextureBack);

                break;
            }



            else
            {
                SDL_Texture *TextureMap = IMG_LoadTexture(Renderer, "../IMG/ChooseMap.jpg");
                SDL_Texture *TextureBack = IMG_LoadTexture(Renderer, "../IMG/Back.png");

                j2 = ChooseM(Window,Renderer,TextureMap,FullPic,TextureBack,Back) ;
        
                SDL_DestroyTexture(TextureMap);
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

                else if (j2 == 1)
                {
                    FILE* fp = fopen("MAPS/MAP1.txt","r");

                    ReadMap(fp,t,object,p,Player);

                    fclose(fp);

                    j3 = 1 ;
                    j1 = 1 ;
            
                }

                else if (j2 == 2)
                {
                    FILE* fp = fopen("MAPS/MAP2.txt","r");

                    ReadMap(fp,t,object,p,Player);

                    fclose(fp);

                    j3 = 1 ;
                    j1 = 1 ;
            
                }

                else if (j2 == 3)
                {
                    FILE* fp = fopen("MAPS/MAP3.txt","r");

                    ReadMap(fp,t,object,p,Player);

                    fclose(fp);

                    j3 = 1 ;
                    j1 = 1 ;
            
                }

                else if (j2 == 4)
                {
                    FILE* fp = fopen("MAPS/MAP4.txt","r");

                    ReadMap(fp,t,object,p,Player);

                    fclose(fp);

                    j3 = 1 ;
                    j1 = 1 ;
            
                }

                else if (j2 == 5)
                {
                    FILE* fp = fopen("MAPS/MAP5.txt","r");

                    ReadMap(fp,t,object,p,Player);

                    fclose(fp);

                    j3 = 1 ;
                    j1 = 1 ;
            
                }
                
            }
            

        }
        
    
    }


    
    SDL_DestroyWindow(Window);
    return 0;

}
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
#include <math.h>


const int vCursor = 10;
const int v = 5 ;
int AmountOfSoldier = 0 ;

typedef struct sol{
    int R ;
    int G ;
    int B ;
    int x,y ;
    int x1,y1 ;
    float dx,dy,d;
    int active ;
}sol;



void ShowSoldier(SDL_Renderer *Renderer,sol *Soldier,int t){
    if (t % 10 == 0)
    {
        Soldier[t/10].active = 1;
        Soldier[t/10 - 1].active = 1 ;
    }

    for (int i = 0; i < AmountOfSoldier; i++)
    {
        if (Soldier[i].active == 1)
        {
            if (Soldier[i].dx > 0 && Soldier[i].x > Soldier[i].x1 )
            {
                Soldier[i].x -= (Soldier[i].dx / Soldier[i].d) * v ;
                Soldier[i].y -= (Soldier[i].dy / Soldier[i].d) * v ;
            }
            else if (Soldier[i].dx < 0 && Soldier[i].x < Soldier[i].x1)
            {
                Soldier[i].x -= (Soldier[i].dx / Soldier[i].d) * v ;
                Soldier[i].y -= (Soldier[i].dy / Soldier[i].d) * v ;
            }
            
            filledCircleRGBA(Renderer,Soldier[i].x,Soldier[i].y,5,Soldier[i].R,Soldier[i].G,Soldier[i].B,200);
        }
        
    }
    
}

void CreateSoldier(state i,state j,sol *Soldier,int p , play Player[p]){

    float dx = i.x - j.x ;
    float dy = i.y - j.y ;
    float d = sqrt(dx * dx +  dy * dy);
    
    if (Isequal(i.owner,Player[1]))
    {
        for (int q = 0; q < i.soldier ; q++)
        {
            Soldier[q+AmountOfSoldier].R = 190 ;
            Soldier[q+AmountOfSoldier].G = 80 ;
            Soldier[q+AmountOfSoldier].B = 140 ;

        }
    }
    else if (Isequal(i.owner,Player[2]))
    {
        for (int q = 0; q < i.soldier ; q++)
        {
            Soldier[q+AmountOfSoldier].R = 63 ;
            Soldier[q+AmountOfSoldier].G = 81 ;
            Soldier[q+AmountOfSoldier].B = 250 ;

        }
    }
    else if (Isequal(i.owner,Player[3]))
    {
        for (int q = 0; q < i.soldier ; q++)
        {
            Soldier[q+AmountOfSoldier].R = 50 ;
            Soldier[q+AmountOfSoldier].G = 160 ;
            Soldier[q+AmountOfSoldier].B = 30 ;
        }
    }
    else
    {
        for (int q = 0; q < i.soldier ; q++)
        {
            Soldier[q+AmountOfSoldier].R = 255 ;
            Soldier[q+AmountOfSoldier].G = 111 ;
            Soldier[q+AmountOfSoldier].B = 40 ;
        }
    }
    
    for (int q = 0; q < i.soldier ; q++)
    {
        Soldier[q+AmountOfSoldier].active = 0 ;
        if (q % 2)
        {
            Soldier[q+AmountOfSoldier].x = i.x + (10 * (dy/d));
            Soldier[q+AmountOfSoldier].y = i.y - (10 * (dx/d));
            Soldier[q+AmountOfSoldier].x1 = j.x + (10 * (dy/d));
            Soldier[q+AmountOfSoldier].y1 = j.y - (10 * (dx/d));

        }
        else
        {
            Soldier[q+AmountOfSoldier].x = i.x - (10 * (dy/d));
            Soldier[q+AmountOfSoldier].y = i.y + (10 * (dx/d));
            Soldier[q+AmountOfSoldier].x1 = j.x - (10 * (dy/d));
            Soldier[q+AmountOfSoldier].y1 = j.y + (10 * (dx/d));
        }
        
        Soldier[q+AmountOfSoldier].dx = dx;
        Soldier[q+AmountOfSoldier].dy = dy ;
         Soldier[q+AmountOfSoldier].d = d ;
    }
    
    AmountOfSoldier += i.soldier ;
    
}

//filledCircleRGBA(Renderer,object[j].x + (e * (dx/d) * v) + (8 * (dy/d)),object[j].y + (e * (dy/d) * v) - (8 * (dx/d)),5,0,100,200,225);
//filledCircleRGBA(Renderer,object[j].x + (e * (dx/d) * v)  - (8 * (dy/d)),object[j].y + (e * (dy/d) * v) + (8 * (dx/d)),5,25,25,25,255);

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

    if (!getName(Window,Renderer,TextureFirst,FullPic,name))
    {
        return 0;
    }
    SDL_DestroyTexture(TextureFirst);

    //set Menu
    SDL_Texture *TextureMenu = IMG_LoadTexture(Renderer, "../IMG/MenuPage.jpg");

    if (!Menu(Window,Renderer,TextureMenu,FullPic))
    {
        return 0;
    }
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
    
    int j[3] = {-1};
    int w[3] = {0} ;
    
    int x = 0 ;

    sol *Soldier = (sol*)malloc(sizeof(sol) * 1000) ;

    int a = 1 ;
    SDL_Event sdlEvent;
    SDL_bool Exit = SDL_FALSE;
    while (Exit == SDL_FALSE) 
    {
        SDL_SetRenderDrawColor(Renderer, 0 , 0 , 0 , 255);
        SDL_RenderClear(Renderer);
        SDL_RenderCopy(Renderer, TextureBG, NULL, &FullPic);
        

        for (int i = 0; i < t; i++)
        {
            int brightness = 0.7*object[i].soldier + 130 ;
            if (brightness > 255)
            {
                brightness = 255 ;
            }
            
            if (object[i].shape)
            {
                filledCircleRGBA(Renderer,object[i].x,object[i].y,object[i].size,object[i].owner.R,object[i].owner.G,object[i].owner.B,brightness);
            }
            else
            {
                boxRGBA(Renderer, object[i].x - object[i].size , object[i].y - object[i].size ,
                object[i].x + object[i].size, object[i].y + object[i].size,object[i].owner.R,object[i].owner.G,object[i].owner.B,brightness);
            }
         
        }
        
        SoldierIcon(Renderer,t,object,TextureSol);
        x++ ;
        if (x == FPS/2)
        {
            IncreaseSoldier(t,object,p,Player);
            x = 0 ;
        }
        ShowNumberOfSoldiers(Renderer,t,object);

        Getscore(t,object,p,Player);

        SetRank(p,Player);

        RenderLeaderBoard(Renderer,BoardT,p,Player);

        if (j[0] > -1)
        {
            SDL_SetRenderDrawColor(Renderer, 255 , 0 , 0 , 230);
            SDL_Rect choice = {.x = object[j[0]].x - 26 ,.y = object[j[0]].y - 26 , .w = 52 ,.h = 52};
            Render_border(Renderer,choice,3);

            if (w[0])
            {
                float dx = (w[1] - object[j[0]].x) ;
                float dy = (w[2] - object[j[0]].y) ;
                float d = sqrt(dx * dx +  dy * dy);
                int e = 1;
                if (dx > 0)
                {
                    while (object[j[0]].x + (e * (dx/d) * vCursor) < w[1])
                    {
                        filledCircleRGBA(Renderer,object[j[0]].x + (e * (dx/d) * vCursor),object[j[0]].y + (e * (dy/d) * vCursor),2,25,25,25,255);
                        e++;
                    }
                }
                else
                {
                    while (object[j[0]].x + (e * (dx/d) * vCursor) > w[1] )
                    {
                        filledCircleRGBA(Renderer,object[j[0]].x + (e * (dx/d) * vCursor),object[j[0]].y + (e * (dy/d) * vCursor),2,25,25,25,255);
                        e++;
                    }
                }
                
                
            }
            
        }
        
        ShowSoldier(Renderer,Soldier,a);
        a++ ;
        if (a > 10000)
        {
            a = 1 ;
        }
        

        SDL_RenderPresent(Renderer);
        
        
        while (SDL_PollEvent(&sdlEvent))
        {
            if (sdlEvent.type == SDL_QUIT)
            {
                Exit = SDL_TRUE;
                return 0 ;
            }
            else if (sdlEvent.type == SDL_MOUSEBUTTONDOWN)
            {
                j[2] = 0;

                if (j[0] < 0)
                {
                    for (int i = 0; i < t; i++)
                    {
                        if (sdlEvent.button.x >= object[i].x - 30 && sdlEvent.button.x <= object[i].x + 30 && 
                        sdlEvent.button.y >= object[i].y - 30 && sdlEvent.button.y <= object[i].y + 30 && Isequal(Player[1],object[i].owner))
                        {
                            j[0] = i ;
                            w[0] = 0;
                            j[2] = 1;
                            break ;
                        }

                    }
                }
                else
                {
                    for (int i = 0; i < t; i++)
                    {
                        if (i != j[0] && sdlEvent.button.x >= object[i].x - 30 && sdlEvent.button.x <= object[i].x + 30 && 
                        sdlEvent.button.y >= object[i].y - 30 && sdlEvent.button.y <= object[i].y + 30)
                        {
                            j[1] = i ;
                            w[0] = 0;
                            j[2] = 0;
                            CreateSoldier(object[j[0]],object[j[1]],Soldier,p,Player);
                            break ;
                        }

                    }
                }
    
                
                if (!j[2])
                {
                    j[0] = -1;
                }
                
                
            
            }
            if (sdlEvent.type == SDL_MOUSEMOTION && j[0] > -1)
            {
                w[0] = 1;
                w[1] = sdlEvent.button.x;
                w[2] = sdlEvent.button.y;
               
            }      
        }
        
        
        SDL_Delay(1000 / FPS);
    }
    
    
    SDL_DestroyWindow(Window);
    return 0;

}
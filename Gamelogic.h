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
#include "NameMenu.h"
#include "GameGraphic.h"
#include <math.h>


const int vCursor = 10;
const int v = 2 ;


typedef struct sol{
    int R ;
    int G ;
    int B ;
    float x,y ;
    float x1,y1 ;
    float dx,dy;
    int active ;
    int owner ;
    int Playerowner;
    int dest ;
}sol;


int getOwner(int p , play Player[p],state j){
    for (int i = 0; i < p; i++)
    {
        if (Isequal(j.owner,Player[i]))
        {
            return i ;
            break;
        }
        
    }
    return 0 ;
}

void ShowSoldier(SDL_Renderer *Renderer,sol *Soldier,int p , play Player[p],int t ,state object[t]){
    for (int i = 0; i < 1000; i++)
    {
        if (Soldier[i].active > 2)
        {
            Soldier[i].active--;
        }
        else if (Soldier[i].active == 2)
        {
            object[Soldier[i].owner].soldier--;
            Player[Soldier[i].Playerowner].SoldierOnSurface++;
            Soldier[i].active--;
            Soldier[i].x += 7 * Soldier[i].dx * v ;
            Soldier[i].y += 7 * Soldier[i].dy * v ;
        }
        
        else if (Soldier[i].active == 1)
        {
        
            if ( ((Soldier[i].dx > 0 && (Soldier[i].x + 7 * Soldier[i].dx * v <= Soldier[i].x1)) || 
            (Soldier[i].dx < 0 && (Soldier[i].x + 7 * Soldier[i].dx * v >= Soldier[i].x1) )) && 
            ((Soldier[i].dy > 0 && (Soldier[i].y + 7 * Soldier[i].dy * v <= Soldier[i].y1)) || 
            (Soldier[i].dy < 0 && (Soldier[i].y + 7 * Soldier[i].dy * v >= Soldier[i].y1) )))
            {
                Soldier[i].x += Soldier[i].dx * v ;
                Soldier[i].y += Soldier[i].dy * v ;
            }
            else
            {
                int q1 = getOwner(p,Player,object[Soldier[i].dest]);
                if (Soldier[i].Playerowner == q1)
                {
                    object[Soldier[i].dest].soldier++ ;
                    object[Soldier[i].dest].ReadySoldier++ ;
                }
                else
                {
                    object[Soldier[i].dest].soldier-- ;
                    object[Soldier[i].dest].ReadySoldier-- ;
                    if (object[Soldier[i].dest].soldier < 0)
                    {
                        object[Soldier[i].dest].owner = Player[Soldier[i].Playerowner];
                        object[Soldier[i].dest].soldier = 1 ; 
                        object[Soldier[i].dest].ReadySoldier = 1 ;
                        Player[Soldier[i].Playerowner].Amount_of_state++ ;
                        Player[q1].Amount_of_state-- ;
                    }
                    else if (object[Soldier[i].dest].ReadySoldier < 0)
                    {
                        object[Soldier[i].dest].ReadySoldier = 0 ;
                        for (int j = 999; j >= 0; j--)
                        {
                            if (Soldier[j].owner == Soldier[i].dest && Soldier[j].active > 2)
                            {
                                Soldier[j].active = -1 ;
                                break ;
                            }
                        }
                            
                    }
                }
                Player[Soldier[i].Playerowner].SoldierOnSurface-- ;
                Soldier[i].active = -1 ;
            }
            
        }
            
    }
    
    for (int i = 0; i < 1000; i++)
    {
        if (Soldier[i].active == 1)
        {
            for (int j = 0; j < 1000; j++)
            {
                if (Soldier[j].active == 1 && (Soldier[i].x - Soldier[j].x < 8 && Soldier[i].x - Soldier[j].x > -8 ) 
                && (Soldier[i].y - Soldier[j].y < 8 && Soldier[i].y - Soldier[j].y > -8 )&& Soldier[i].Playerowner != Soldier[j].Playerowner)
                {
                    Soldier[i].active = -1 ;
                    Soldier[j].active = -1 ;
                    Player[Soldier[i].Playerowner].SoldierOnSurface-- ;
                    Player[Soldier[j].Playerowner].SoldierOnSurface-- ;
                    break ;
                }
                
            }
            if (Soldier[i].active == 1)
            {
                filledCircleRGBA(Renderer,Soldier[i].x,Soldier[i].y,4,Soldier[i].R,Soldier[i].G,Soldier[i].B,200);
            }
            
        }
    }
    
}
 

void CreateSoldier(state i,state j,sol *Soldier,int p , play Player[p],int stateNumber,int destSatate){
    int t = 0 ;
    float dx = j.x - i.x ;
    float dy = j.y - i.y ;
    float d = sqrt(dx * dx +  dy * dy);
    int q0 = getOwner(p,Player,i);
    
    if (q0 == 1)
    {
        for (int q = 0; q < i.ReadySoldier ; t++)
        {
            if (Soldier[t].active == -1)
            {
                Soldier[t].R = 190 ;
                Soldier[t].G = 80 ;
                Soldier[t].B = 140 ;
                q++ ;
            }
            
        }
    }
    else if (q0 == 2)
    {
        for (int q = 0; q < i.ReadySoldier ; t++)
        {
            if (Soldier[t].active == -1)
            {
                Soldier[t].R = 63 ;
                Soldier[t].G = 81 ;
                Soldier[t].B = 250 ;
                q++ ;
            }   
        }

    }
    else if (q0 == 3)
    {
        for (int q = 0; q < i.ReadySoldier ; t++)
        {
            if (Soldier[t].active == -1)
            {
                Soldier[t].R = 50 ;
                Soldier[t].G = 160 ;
                Soldier[t].B = 30 ;
                q++ ;
            }
            
        }
    }
    else if (q0 == 4)
    {
        for (int q = 0; q < i.ReadySoldier ; t++)
        {
            if (Soldier[t].active == -1)
            {
                Soldier[t].R = 255 ;
                Soldier[t].G = 111 ;
                Soldier[t].B = 40 ;
                q++ ;
            }
            
        }
    }
    
    t = 0 ;
    int distanceBetweenLines = 12;

    for (int q = 0; q < i.ReadySoldier ; t++)
    {

        if (Soldier[t].active == -1)
        {
            Soldier[t].active = 7 * (q/3) + 2;
            if (q % 3 == 2)
            {
                Soldier[t].x = i.x + (distanceBetweenLines * (dy/d));
                Soldier[t].y = i.y - (distanceBetweenLines * (dx/d));
                Soldier[t].x1 = j.x + (distanceBetweenLines * (dy/d));
                Soldier[t].y1 = j.y - (distanceBetweenLines * (dx/d));
            }
            else if (q % 3 == 1)
            {
                Soldier[t].x = i.x - (distanceBetweenLines * (dy/d));
                Soldier[t].y = i.y + (distanceBetweenLines * (dx/d));
                Soldier[t].x1 = j.x - (distanceBetweenLines * (dy/d));
                Soldier[t].y1 = j.y + (distanceBetweenLines * (dx/d));
            }
            else
            {
                Soldier[t].x = i.x ;
                Soldier[t].y = i.y ;
                Soldier[t].x1 = j.x;
                Soldier[t].y1 = j.y ;
            }
            Soldier[t].dx = dx/d;
            Soldier[t].dy = dy/d ;
            Soldier[t].owner =  stateNumber;
            Soldier[t].dest = destSatate ;
            Soldier[t].Playerowner = q0 ; 
            q++ ;
        }
            
    }
    i.ReadySoldier = 0 ;
    
}

void SmartAttack(sol *Soldier,int p , play Player[p],int t , state object[t]){
    int a[t+1];
    a[0] = 0 ;
    int j = 1;

    for (int i = 0; i < t; i++)
    {
        if (!Isequal(object[i].owner,Player[0]) && !Isequal(object[i].owner,Player[1]))
        {
            a[j] = i ;
            a[0]++ ;
            j++ ;
        }
        
    }

    if (a[0] != 0)
    {
        int x = rand() % a[0] + 1 ;
        j = a[x] ;

        int y1 = 200 ;
        int y2 ;

        int w ;
        for (int i = 0; i < t ; i++)
        {
            if (!Isequal(object[j].owner,object[i].owner))
            {
                w = object[i].ReadySoldier + (sqrt( (object[i].x - object[j].x) * (object[i].x - object[j].x) + (object[i].y - object[j].y) * (object[i].y - object[j].y) ) 
                / (FPS * v));
                if ( w < y1 )
                {
                    y1 = w ;
                    y2 = i ;
                }
            
            }
        }
        if (object[j].ReadySoldier > w + 10)
        {
            CreateSoldier(object[j],object[y2],Soldier,p,Player,j,y2);
            object[j].ReadySoldier = 0 ;
        }
        
    }
    
    
    
}


int Game(SDL_Window *Window,SDL_Renderer *Renderer,SDL_Texture *TextureBG,SDL_Rect FullPic){
    
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

    sol *Soldier = (sol*)malloc(sizeof(sol) * 1500) ;
    for (int i = 0; i < 1000; i++)
    {
        Soldier[i].active = -1 ;
    }
    
    int x1 = 0 ;

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
        if (x == FPS/5)
        {
            IncreaseSoldier(t,object,p,Player);
            x = 0 ;
        }
        x1++ ;
        if (x1 == FPS * 3)
        {
            SmartAttack(Soldier,p,Player,t,object);
            x1 = 0 ;
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
        
        ShowSoldier(Renderer,Soldier,p,Player,t,object);
        

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
                            CreateSoldier(object[j[0]],object[j[1]],Soldier,p,Player,j[0],j[1]);
                            object[j[0]].ReadySoldier = 0 ;
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
    return 1 ;
    

}


#endif
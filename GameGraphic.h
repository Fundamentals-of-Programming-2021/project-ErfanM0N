#ifndef _HEADER_GameGraphic_H
#define _HEADER_GameGraphic_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "NameMenu.h"


int AmountOfPlayers;

typedef struct play{
    int R ;
    int G ;
    int B ;
    int score;
    int Amount_of_state;
    int rank;
    int SoldierOnSurface;
}play ;

typedef struct state{
    play owner ;
    int soldier ;
    int ReadySoldier ;
    int x ,y ;
    int shape;
    int size ;
}state ;


void RenderLeaderBoard(SDL_Renderer *Renderer,SDL_Texture *BoardT,int p ,play Player[p]){   
    SDL_Rect LeaderBoard = {.x = 10 ,.y = 10 ,.h = 260 ,.w = 200};
    SDL_Rect Board = {.x = 30 ,.y = 30 ,.h = 20 ,.w = 155};
    SDL_Rect Score = {.x = 125 ,.y = 80 ,.h = 30 ,.w = 55};
    SDL_Rect State = {.x = 65 ,.y = 80 ,.h = 30 ,.w = 55};

    if (AmountOfPlayers == 3)
    {
        LeaderBoard.h -= 50 ;
    }
    if (AmountOfPlayers == 2)
    {
        LeaderBoard.h -= 100 ;
    }
    
    int x = 40 ;
    int y = 95 ;
    
    SDL_SetRenderDrawColor(Renderer,0,0,0,255);
    Render_border(Renderer,LeaderBoard,5);
    SDL_RenderCopy(Renderer,BoardT,NULL,&Board);

    thickLineRGBA(Renderer,10,65,210,65,5,0,0,0,255);
    

    for (int i = 1; i <= AmountOfPlayers; i++)
    {
        char str[20],str1[20];
        filledCircleRGBA(Renderer,x,y + (50 * (Player[i].rank - 1)),18,Player[i].R,Player[i].G,Player[i].B,240);
        
        Score.y = 80;
        State.y = 80;

        sprintf(str,"%8d",Player[i].score);
        SDL_Texture *TextScore = GetText(Renderer,35,"Arial.ttf",0,0,0,str);
        Score.y += (50 * (Player[i].rank - 1)) ;
        SDL_RenderCopy(Renderer,TextScore,NULL,&Score);
        SDL_DestroyTexture(TextScore);

        sprintf(str1,"%8d",Player[i].Amount_of_state);
        SDL_Texture *TextState = GetText(Renderer,35,"Arial.ttf",0,0,0,str1);
        State.y += (50 * (Player[i].rank - 1)) ;
        SDL_RenderCopy(Renderer,TextState,NULL,&State);
        SDL_DestroyTexture(TextState);

        thickLineRGBA(Renderer,10,y + (50 * (Player[i].rank - 1))+25,210,y + (50 * (Player[i].rank - 1))+25,3,0,0,0,255);
    }
    

}

void SetRank(int p ,play Player[p]){
    int w = 0 ;

    for (int i = AmountOfPlayers; i > 0; i--)
    {
        for (int j = AmountOfPlayers; j > 0; j--)
        {
            if (Player[j].score > Player[i].score && Player[j].rank > Player[i].rank )
            {
                w = Player[i].rank;
                Player[i].rank = Player[j].rank;
                Player[j].rank = w ;
            }
            
        }
        
    }
    
}

int Isequal(play x,play y){
    if (x.R == y.R && x.G == y.G && x.B == y.B)
    {
        return 1;
    }
    return 0;
}

void Getscore(int t ,state object[t],int p ,play Player[p]){
    for (int i = 1; i < p; i++)
    {
        Player[i].score = 0;
        for (int j = 0; j < t; j++)
        {
            if (Isequal(Player[i],object[j].owner))
            {
                Player[i].score += object[j].soldier;
            }
            
        }
        Player[i].score +=  Player[i].SoldierOnSurface ;
        
        
    }
    
    
}

void ShowNumberOfSoldiers(SDL_Renderer *Renderer,int t ,state object[t]){
    SDL_Rect rect ;
    rect.h = 18 ;
    int e = 0;
    for (int i = 0; i < t; i++)
    {
        e = 0 ;
        char str[20];
        sprintf(str,"%8d",object[i].soldier);
        rect.w = strlen(str) * 10 ;
        if (object[i].soldier > 99)
        {
            e = 5 ;
        }
        else if (object[i].soldier < 10)
        {
            e = -8;
        }
        
        SDL_Texture *TextM = GetText(Renderer,18,"Arial.ttf",0,0,0,str);
        rect.x = object[i].x - (rect.w/2) - 22 + e;
        rect.y = object[i].y + 30 ;

        SDL_RenderCopy(Renderer,TextM,NULL,&rect);
        SDL_DestroyTexture(TextM);

    }
    
}

void IncreaseSoldier(int t ,state object[t],int p ,play Player[p]){
    for (int i = 0; i < t; i++)
    {
        if (!Isequal(object[i].owner,Player[0]))
        {
            if (object[i].soldier < 120)
            {
                object[i].soldier++;
                object[i].ReadySoldier++ ;
            }
        }
    }
}

void SoldierIcon(SDL_Renderer *Renderer,int t ,state object[t],SDL_Texture *TextureSol){
    SDL_Rect rect;
    rect.w = 48,rect.h = 48 ;
    for (int i = 0; i < t; i++)
    {
        rect. x = object[i].x - 24 ;
        rect. y = object[i].y - 24 ; 

        SDL_RenderCopy(Renderer,TextureSol,NULL,&rect);
    }
    
}

int SetStateOwner(int t ,state object[t],int p ,play Player[p]){
    srand(time(NULL));
    int x ;
    
    for (int i = 0; i < 2; i++)
    {
        object[i].owner = Player[i+1];
        Player[i+1].Amount_of_state = 1;
    }
    
    x = rand () % 3;
    if (x == 2)
    {
        object[2].owner = Player[3];
        Player[3].Amount_of_state = 1;

        object[3].owner = Player[4];
        Player[4].Amount_of_state = 1;
        for (int i = 4; i < t; i++)
        {
            object[i].owner = Player[0];
            Player[0].Amount_of_state += 1;
            object[i].soldier = 70 ;
            object[i].ReadySoldier = 70 ;
        }
        AmountOfPlayers = 4;
    }
    else if (x == 1)
    {
        object[2].owner = Player[3];
        Player[3].Amount_of_state = 1;
        for (int i = 3; i < t; i++)
        {
            object[i].owner = Player[0];
            Player[0].Amount_of_state += 1;
            object[i].soldier = 70 ;
            object[i].ReadySoldier = 70 ;
        }
        AmountOfPlayers = 3;
    }
    else
    {
        for (int i = 2; i < t; i++)
        {
            object[i].owner = Player[0];
            Player[0].Amount_of_state += 1;
            object[i].soldier = 70 ;
            object[i].ReadySoldier = 70 ;
        }
        AmountOfPlayers = 2;
    }
      
}


void CreatePlayer(SDL_Renderer *Renderer,int p ,play Player[p]){
    Player[0].R = 255 ,Player[0].G = 255 ,Player[0].B = 255,Player[0].Amount_of_state = 0 , Player[0].score = 0 ,Player[0].rank = 0;
    Player[1].R = 200 ,Player[1].G = 100 ,Player[1].B = 200 ,Player[1].Amount_of_state = 0 , Player[1].score = 0 ,Player[1].rank = 1 ,Player[1].SoldierOnSurface = 0;
    Player[2].R = 3 ,Player[2].G = 169 ,Player[2].B = 244 ,Player[2].Amount_of_state = 0 , Player[2].score = 0 ,Player[2].rank = 2 ,Player[2].SoldierOnSurface = 0;
    Player[3].R = 51 ,Player[3].G = 230 ,Player[3].B = 0 ,Player[3].Amount_of_state = 0 , Player[3].score = 0 ,Player[3].rank = 3 ,Player[3].SoldierOnSurface = 0;
    Player[4].R = 240 ,Player[4].G = 160 ,Player[4].B = 0 ,Player[4].Amount_of_state = 0 , Player[4].score = 0 ,Player[4].rank = 4 ,Player[4].SoldierOnSurface = 0;
}


void CreateState(SDL_Renderer *Renderer,int t ,state object[t]){
    int a ;
    int Distance = 60 ;
    int DistanceFromBorder = 80 ;
    srand(time(NULL));

    for (int i = 0; i < t; i++)
    {
        a = 0;
       
        object[i].x = (rand() % (SCREEN_WIDTH - 2*DistanceFromBorder - 60)) + (2*DistanceFromBorder + 60) / 2 ;
        object[i].y = (rand() % (SCREEN_HEIGHT - 2*DistanceFromBorder - 60)) + (2*DistanceFromBorder + 60) / 2 ;
        object[i].size = (rand () % 20) + 60 ;

        if ((object[i].x - object[i].size) < 230 && (object[i].y - object[i].size) < 290)
        {
            i-- ;
            a = 1 ;
            continue;
        }
        
        for (int j = 0; j < i; j++)
        {
            if (((object[i].x - object[j].x) <  ((object[i].size + object[j].size) + Distance) 
            && (object[i].x - object[j].x) >  -((object[i].size + object[j].size) + Distance)) 
            && ((object[i].y - object[j].y) <  ((object[i].size + object[j].size) + Distance) 
            && (object[i].y - object[j].y) >  -((object[i].size + object[j].size) + Distance)))
            {
                i-- ;
                a = 1 ;
                break;
            }
        }
                
        if (!a)
        {
            object[i].shape = rand() % 2 ;
            object[i].soldier = rand () % 15 + 40 ;
            object[i].ReadySoldier = object[i].soldier ;
        }
        
    }
    
}


#endif 

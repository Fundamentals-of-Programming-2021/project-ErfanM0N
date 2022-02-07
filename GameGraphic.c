#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdio.h>
#include "Functions.h"


extern int AmountOfPlayers;


int Isequal(play x,play y){
    if (x.R == y.R && x.G == y.G && x.B == y.B)
    {
        return 1;
    }
    return 0;
}


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



void RenderLeaderBoard(SDL_Renderer *Renderer,SDL_Texture *BoardT,int p ,play Player[p],mixture Potion[4]){   
    
    SDL_Rect LeaderBoard = {.x = 10 ,.y = 10 ,.h = 260 ,.w = 200};
    SDL_Rect Board = {.x = 30 ,.y = 30 ,.h = 20 ,.w = 155};
    SDL_Rect Score = {.x = 105 ,.y = 80 ,.h = 30 ,.w = 55};
    SDL_Rect State = {.x = 55 ,.y = 80 ,.h = 30 ,.w = 55};
    SDL_Rect potion = {.x = 175 ,.y = 80 ,.h = 30 ,.w = 30};

    if (AmountOfPlayers == 3)
    {
        LeaderBoard.h -= 50 ;
    }

    else if (AmountOfPlayers == 2)
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
        potion.y = 80;

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

        if (Player[i].Potion > -1)
        {
            potion.y += (50 * (Player[i].rank - 1)) ;
            SDL_RenderCopy(Renderer,Potion[Player[i].Potion].PotionPic,NULL,&potion);
        }
        
        thickLineRGBA(Renderer,10,y + (50 * (Player[i].rank - 1))+25,210,y + (50 * (Player[i].rank - 1))+25,3,0,0,0,255);
    }

    SDL_Texture *TextYou = GetText(Renderer,25,"Arial.ttf",100,20,0,"YOU");
    SDL_Rect you = {.x = 27 ,.y = 82 + (50 * (Player[1].rank - 1)) ,.w = 26,.h = 26};
    
    SDL_RenderCopy(Renderer,TextYou,NULL,&you);
    SDL_DestroyTexture(TextYou);
    

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
            int q = getOwner(p,Player,object[i]);

            if (object[i].soldier < 100)
            {   
                object[i].soldier++;
                object[i].ReadySoldier++ ;
            }

            else if (Player[q].Potion == 0)
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

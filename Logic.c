#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <math.h>
#include "Functions.h"


const int vCursor = 10;
const float v = 1.5 ;

extern const int FPS ;


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
                w = object[i].ReadySoldier + (sqrt( (object[i].x - object[j].x) * (object[i].x - object[j].x) + 
                (object[i].y - object[j].y) * (object[i].y - object[j].y) ) / (FPS * v));
                if ( w < y1 )
                {
                    y1 = w ;
                    y2 = i ;
                }
            
            }
        }

        if (object[j].ReadySoldier > y1 + 20 || object[j].ReadySoldier > 99)
        {
            CreateSoldier(object[j],object[y2],Soldier,p,Player,j,y2);
            object[j].ReadySoldier = 0 ;
        }

        
    }
     
    
}


void RenderHinter(SDL_Renderer *Renderer,int t ,state object[t],int Source[3],int Point[3]){
    
    SDL_SetRenderDrawColor(Renderer, 255 , 0 , 0 , 230);

    SDL_Rect choice = {.x = object[Source[0]].x - 26 ,.y = object[Source[0]].y - 26 , .w = 52 ,.h = 52};
            
    Render_border(Renderer,choice,3);

    if (Point[0])
    {
        float dx = (Point[1] - object[Source[0]].x) ;
        float dy = (Point[2] - object[Source[0]].y) ;
                
        float d = sqrt(dx * dx +  dy * dy);

        int count = 1;
                
        if (dx > 0)
        {
            while (object[Source[0]].x + (count * (dx/d) * vCursor) < Point[1])
            {
                filledCircleRGBA(Renderer,object[Source[0]].x + (count * (dx/d) * vCursor),object[Source[0]].y + 
                (count * (dy/d) * vCursor),2,25,25,25,255);
                        
                count++;
            }
        }

        else
        {
            while (object[Source[0]].x + (count * (dx/d) * vCursor) > Point[1] )
            {
                filledCircleRGBA(Renderer,object[Source[0]].x + (count * (dx/d) * vCursor),object[Source[0]].y + 
                (count * (dy/d) * vCursor),2,25,25,25,255);
                    
                count++;
            }
        }
                
                
    }

}

void SetAttack(SDL_Event sdlEvent,int t ,state object[t],int Source[3],int Point[3],int p ,play Player[p],sol *Soldier){

    Source[2] = 0;

    if (Source[0] < 0)
    {
        for (int i = 0; i < t; i++)
        {
            if (sdlEvent.button.x >= object[i].x - 30 && sdlEvent.button.x <= object[i].x + 30 && 
            sdlEvent.button.y >= object[i].y - 30 && sdlEvent.button.y <= object[i].y + 30  && Isequal(Player[1],object[i].owner))
            {
                Source[0] = i ;
                Point[0] = 0;
                Source[2] = 1;

                break ;

            }

        }
    }

    else
    {
        for (int i = 0; i < t; i++)
        {
            if (i != Source[0] && sdlEvent.button.x >= object[i].x - 30 && sdlEvent.button.x <= object[i].x + 30 && 
            sdlEvent.button.y >= object[i].y - 30 && sdlEvent.button.y <= object[i].y + 30)
            {
                Source[1] = i ;
                Point[0] = 0;
                Source[2] = 0;

                CreateSoldier(object[Source[0]],object[Source[1]],Soldier,p,Player,Source[0],Source[1]);
                            
                object[Source[0]].ReadySoldier = 0 ;

                break ;

            }

        }

    }
                
    if (!Source[2])
    {
        Source[0] = -1;
    }
    
}

void RenderStates(SDL_Renderer *Renderer,int t ,state object[t]){
    
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

}

int Game(SDL_Window *Window,SDL_Renderer *Renderer,SDL_Texture *TextureBG,SDL_Rect FullPic,int t ,state object[t],int p ,play Player[p]
,int n0,PlayerName N[n0+1],int number,int condition){
    
    SDL_Texture *TextureSol = IMG_LoadTexture(Renderer, "../IMG/SoldierIcon.png");
    
    SDL_Texture *BoardT = GetText(Renderer,45,"Arial.ttf",0,0,30,"LEADERBOARD");


    sol *Soldier = (sol*)malloc(sizeof(sol) * 1000) ;

    mixture Potion[4];

    if (condition == 0)
    {
        for (int i = 0; i < 1000; i++)
        {
            Soldier[i].active = -1 ;
        }

        for (int i = 0; i < 4; i++)
        {
            Potion[i].active = -1 ;
        }

    }

    else
    {
        ReadFromSavedMap(t,object,p,Player,Soldier,Potion);
    }

    initPotion(Renderer,Potion);
    
    
    
    
    
    int Source[3] = {-1,0,0};
    int Point[3] = {0,0,0} ;
    

    int x = 0 ;
    int x1 = 0;

    SDL_Rect BorderSaveAndExit = {.x = 1080 , .y = 5 ,.w = 180 , .h = 40 };

    SDL_Rect SaveAndExit = {.x = 1090 , .y = 5 ,.w = 160 , .h = 40 };
    SDL_Texture *TextSave = GetText(Renderer,45,"Arial.ttf",0,0,30,"Save And Exit");

    SDL_Event sdlEvent;
    SDL_bool Exit = SDL_FALSE;

    while (Exit == SDL_FALSE) 
    {
        SDL_SetRenderDrawColor(Renderer, 0 , 0 , 0 , 255);
        SDL_RenderClear(Renderer);
        SDL_RenderCopy(Renderer, TextureBG, NULL, &FullPic);
        
        RenderStates(Renderer,t,object);
        
        SoldierIcon(Renderer,t,object,TextureSol);


        x++ ;

        if (!(x % (FPS/4)))
        {
            IncreaseSoldier(t,object,p,Player);
            
            if (!(x % FPS))
            {
                setPotionTime(Potion,p,Player);

                AddPotion(t,object,Potion);

                if (x == FPS * 2)
                {
                    SmartAttack(Soldier,p,Player,t,object);
                    x = 0 ;
                }
                      
            }
            
        }
        
        
        ShowNumberOfSoldiers(Renderer,t,object);

        Getscore(t,object,p,Player);

        SetRank(p,Player);

        RenderLeaderBoard(Renderer,BoardT,p,Player,Potion);


        if (Source[0] > -1)
        {
            RenderHinter(Renderer,t,object,Source,Point);
        }
        

        ShowSoldier(Renderer,Soldier,p,Player,t,object);
        
        ShowPotion(Renderer,Potion);

        SoldierEatPotion(Potion,t,object,p,Player,Soldier);

        SDL_SetRenderDrawColor(Renderer, 0 , 0 , 0 , 255);
        Render_border(Renderer,BorderSaveAndExit,2);

        SDL_RenderCopy(Renderer, TextSave, NULL, &SaveAndExit);

        SDL_RenderPresent(Renderer);


        if ((Player[1].score == 0 || (Player[2].score == 0 && Player[3].score == 0 && Player[4].score == 0)) && x1 <= FPS/5)
        {
            x1++ ;
        }
        
        if (x1 == FPS/5 )
        {
            WinOrLost(p,Player,n0,N,number);
            return 0;
        }
        
        
        while (SDL_PollEvent(&sdlEvent))
        {
            if (sdlEvent.type == SDL_QUIT)
            {
                Exit = SDL_TRUE;
                return 0 ;
            }

            else if (sdlEvent.type == SDL_MOUSEBUTTONDOWN)
            {
                if (sdlEvent.button.x >= 1080 && sdlEvent.button.x <= 1080 + 180 && sdlEvent.button.y >= 5 && sdlEvent.button.y <= 5 + 45)
                {
                    WriteMaptoSave(t,object,p,Player,Soldier,Potion);
                    SDL_DestroyTexture(TextSave);
                    return 0 ;
                }

                else
                {
                    SetAttack(sdlEvent,t,object,Source,Point,p,Player,Soldier);
                }
                
            }

            if (sdlEvent.type == SDL_MOUSEMOTION && Source[0] > -1)
            {
                Point[0] = 1;
                Point[1] = sdlEvent.button.x;
                Point[2] = sdlEvent.button.y;
               
            }   

        }
        
        SDL_Delay(1000 / FPS);

    }

    return 1 ;
    

}
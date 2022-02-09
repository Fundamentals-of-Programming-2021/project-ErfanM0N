#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdio.h>
#include <time.h>
#include "Functions.h"
#include "Structs.h"

extern int AmountOfPlayers;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int FPS ;


void ReadMap(FILE* fp,int t ,state object[t],int p ,play Player[p]){
    int q = -1;
    
    for (int i = 0; i < t; i++)
    {
        fscanf(fp,"%d %d %d %d %d %d %d",&object[i].x,&object[i].y,&object[i].soldier,&object[i].ReadySoldier,&object[i].shape
        ,&object[i].size,&q);

        object[i].owner = Player[q];
        Player[q].Amount_of_state++ ;
    }

    fscanf(fp,"%d\n",&AmountOfPlayers);
    

}

int SetStateOwner(int t ,state object[t],int p ,play Player[p]){
    
    srand(time(NULL));
    int x ;
    
    for (int i = 0; i < 2; i++)
    {
        object[i].owner = Player[i+1];
        Player[i+1].Amount_of_state = 1;
    }
    
    x =  rand () % 3;

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
            object[i].soldier = 65 ;
            object[i].ReadySoldier = 65 ;
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
            object[i].soldier = 65 ;
            object[i].ReadySoldier = 65 ;
        }

        AmountOfPlayers = 3;
    }

    else
    {
        for (int i = 2; i < t; i++)
        {
            object[i].owner = Player[0];
            Player[0].Amount_of_state += 1;
            object[i].soldier = 65 ;
            object[i].ReadySoldier = 65 ;
        }
        
        AmountOfPlayers = 2;
    }
      
}


void CreatePlayer(SDL_Renderer *Renderer,int p ,play Player[p]){
    Player[0].R = 255 ,Player[0].G = 255 ,Player[0].B = 255,Player[0].Amount_of_state = 0 , Player[0].score = 0 ,Player[0].rank = 0;

    Player[1].R = 200 ,Player[1].G = 100 ,Player[1].B = 200 ,Player[1].Amount_of_state = 0 , Player[1].score = 0 ,Player[1].rank = 1 
    ,Player[1].SoldierOnSurface = 0 ,Player[1].Potion = -1;

    Player[2].R = 3 ,Player[2].G = 169 ,Player[2].B = 244 ,Player[2].Amount_of_state = 0 , Player[2].score = 0 ,Player[2].rank = 2 
    ,Player[2].SoldierOnSurface = 0 ,Player[2].Potion = -1;

    Player[3].R = 51 ,Player[3].G = 230 ,Player[3].B = 0 ,Player[3].Amount_of_state = 0 , Player[3].score = 0 ,Player[3].rank = 3 
    ,Player[3].SoldierOnSurface = 0 ,Player[3].Potion = -1;

    Player[4].R = 240 ,Player[4].G = 160 ,Player[4].B = 0 ,Player[4].Amount_of_state = 0 , Player[4].score = 0 ,Player[4].rank = 4 
    ,Player[4].SoldierOnSurface = 0 ,Player[4].Potion = -1;
}


void CreateState(SDL_Renderer *Renderer,int t ,state object[t]){

    int a ;
    int Distance = 60 ;
    int DistanceFromBorder = 80 ;
    srand(time(NULL));

    for (int i = 0; i < t; i++)
    {
        a = 0;
       
        object[i].x = (rand() % (SCREEN_WIDTH - 2 * DistanceFromBorder - 60)) + (2 * DistanceFromBorder + 60) / 2 ;
        object[i].y = (rand() % (SCREEN_HEIGHT - 2 * DistanceFromBorder - 60)) + (2 * DistanceFromBorder + 60) / 2 ;
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

int ChooseM(SDL_Window *Window,SDL_Renderer *Renderer,SDL_Texture *TextureMap,SDL_Rect FullPic,SDL_Texture *TextureBack,SDL_Rect Back){

    SDL_Rect border[5];

    border[0].x = 155 , border[0].y = 260, border[0].w = 295 ,border[0].h = 130 ;
    border[1].x = 155 , border[1].y = 452, border[1].w = 295 ,border[1].h = 130 ;
    border[2].x = 155 , border[2].y = 640, border[2].w = 295 ,border[2].h = 130 ;
    border[3].x = 560 , border[3].y = 452, border[3].w = 295 ,border[3].h = 130 ;
    border[4].x = 560 , border[4].y = 640, border[4].w = 295 ,border[4].h = 130 ;


    SDL_Event sdlEvent;
    SDL_bool Exit = SDL_FALSE;

    static int i = 1 ;

    while (Exit == SDL_FALSE) 
    {
        SDL_SetRenderDrawColor(Renderer, 0 , 0 , 0 , 255);
        SDL_RenderClear(Renderer);

        SDL_RenderCopy(Renderer, TextureMap, NULL, &FullPic);
        SDL_RenderCopy(Renderer, TextureBack, NULL, &Back);

        
        Render_border(Renderer,border[0],5);
        Render_border(Renderer,border[1],5);
        Render_border(Renderer,border[2],5);
        Render_border(Renderer,border[3],5);
        Render_border(Renderer,border[4],5);
        
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
                    if (i == 6)
                    {
                        i = 1;
                    }
                    
                }

                else if (sdlEvent.key.keysym.sym == SDLK_UP)
                {
                    i--;
                    if (i == 0)
                    {
                        i = 5;
                    }
    
                }
             
                else if (sdlEvent.key.keysym.sym == SDLK_RETURN)
                {
                         
                    return i;
                    
                }

            }

            else if (sdlEvent.type == SDL_MOUSEBUTTONDOWN)
            {

                if (sdlEvent.button.x >= 155 && sdlEvent.button.x <= 155 + 295 && sdlEvent.button.y >= 260 && sdlEvent.button.y <= 260 + 130)
                {
                    i = 1 ;
                    return 1;
                }

                else if (sdlEvent.button.x >= 155 && sdlEvent.button.x <= 155 + 295 && sdlEvent.button.y >= 452 && sdlEvent.button.y <= 452 + 130)
                {
                    i = 2 ;
                    return 2;
                }

                else if (sdlEvent.button.x >= 155 && sdlEvent.button.x <= 155 + 295 && sdlEvent.button.y >= 640 && sdlEvent.button.y <= 640 + 130)
                {
                    i = 3 ;
                    return 3;
                }

                else if (sdlEvent.button.x >= 560 && sdlEvent.button.x <= 560 + 295 && sdlEvent.button.y >= 452 && sdlEvent.button.y <= 452 + 130)
                {
                    i = 4 ;
                    return 4;
                }

                else if (sdlEvent.button.x >= 560 && sdlEvent.button.x <= 560 + 295 && sdlEvent.button.y >= 640 && sdlEvent.button.y <= 640 + 130)
                {
                    i = 5 ;
                    return 5;
                }
                else if (sdlEvent.button.x >= 10 && sdlEvent.button.x <= 10 + 100 && sdlEvent.button.y >= 10 && sdlEvent.button.y <= 10 + 70)
                {
                    return -1 ;
                }
            

            }
            
        }    
                
        SDL_Delay(1000 / FPS);
    }


}

int StartGame(SDL_Window *Window,SDL_Renderer *Renderer,SDL_Texture *TextureGameFirstPage,SDL_Rect FullPic,SDL_Texture *TextureBack,SDL_Rect Back){
    
    SDL_Rect border[2];

    border[0].x = 50 , border[0].y = 462, border[0].w = 790 ,border[0].h = 110 ;
    border[1].x = 95 , border[1].y = 650, border[1].w = 730 ,border[1].h = 110 ;

    SDL_Event sdlEvent;
    SDL_bool Exit = SDL_FALSE;

    static int i = 1 ;

    while (Exit == SDL_FALSE) 
    {
        SDL_SetRenderDrawColor(Renderer, 0 , 0 , 0 , 255);
        SDL_RenderClear(Renderer);

        SDL_RenderCopy(Renderer, TextureGameFirstPage, NULL, &FullPic);
        SDL_RenderCopy(Renderer, TextureBack, NULL, &Back);

        
        Render_border(Renderer,border[0],5);
        Render_border(Renderer,border[1],5);
        
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
                    if (i == 3)
                    {
                        i = 1;
                    }
                    
                }

                else if (sdlEvent.key.keysym.sym == SDLK_UP)
                {
                    i--;
                    if (i == 0)
                    {
                        i = 2;
                    }
    
                }
             
                else if (sdlEvent.key.keysym.sym == SDLK_RETURN)
                {
                         
                    return i;
                    
                }

            }

            else if (sdlEvent.type == SDL_MOUSEBUTTONDOWN)
            {

                if (sdlEvent.button.x >= 50 && sdlEvent.button.x <= 50 + 790 && sdlEvent.button.y >= 462 && sdlEvent.button.y <= 462 + 110)
                {
                    i = 1;
                    return 1;
                }

                else if (sdlEvent.button.x >= 95 && sdlEvent.button.x <= 95 + 730 && sdlEvent.button.y >= 650 && sdlEvent.button.y <= 650 + 110)
                {
                    i = 2;
                    return 2;
                }

                else if (sdlEvent.button.x >= 10 && sdlEvent.button.x <= 10 + 100 && sdlEvent.button.y >= 10 && sdlEvent.button.y <= 10 + 70)
                {
                    return -1 ;
                }
            

            }
        }    
                
        SDL_Delay(1000 / FPS);
    }

    return 3;

}
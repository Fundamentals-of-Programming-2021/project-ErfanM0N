#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "Functions.h"


void SoldierEatPotion(mixture Potion[4],int t ,state object[t],int p ,play Player[p],sol *Soldier){
    
    for (int i = 0; i < 4; i++)
    {
        if (Potion[i].active == 1)
        {
            
            for (int j = 0; j < 1000; j++)
            {
                if (Potion[i].x - Soldier[j].x < 18 && Potion[i].x - Soldier[j].x > -18 && 
                Potion[i].y - Soldier[j].y < 18 && Potion[i].y - Soldier[j].y > -18 && Player[Soldier[j].Playerowner].Potion < 0)
                {
                    Potion[i].time = 0 ;
                    Potion[i].active = -1;
                    Player[Soldier[j].Playerowner].Potion = i ;
                    Player[Soldier[j].Playerowner].PotionActiveTime = Potion[i].activeTime ;
                    break;
                }
            
            }
        }
        
        
    }
    
}

void setPotionTime(mixture Potion[4],int p ,play Player[p]){
    
    for (int i = 0; i < 4; i++)
    {
        if ( Potion[i].active == 1)
        {
            if (Potion[i].time > 0 )
            {
                Potion[i].time-- ;
            }
            else
            {
               Potion[i].active = -1 ;
            }
            
        }
         
    }

    for (int i = 0; i < p; i++)
    {
        if (Player[i].Potion > -1)
        {
            Player[i].PotionActiveTime--;
        }
        if (Player[i].PotionActiveTime == 0)
        {
            Player[i].Potion = -1;
        }
        
    }
    
}

void ShowPotion(SDL_Renderer *Renderer,mixture Potion[4]){
    
    for (int i = 0; i < 4; i++)
    {
        if (Potion[i].active == 1)
        {
            SDL_Rect potion = {.x = Potion[i].x - 15 ,.y = Potion[i].y - 15,.w = 30 ,.h = 30 };
            SDL_RenderCopy(Renderer, Potion[i].PotionPic, NULL, &potion);
        }
        
    }

    
}

void AddPotion(int t ,state object[t],mixture Potion[4]){
        
    int a[5];
    a[0] = 0 ;
    int j = 1 ;

    for (int i = 0; i < 4; i++)
    {
        if (Potion[i].active == -1)
        {
            a[j] = i ;
            a[0]++;
            j++ ;
        }   
    }
    
    int x = rand () % t ;
    int y = rand () % (t-1) + 1; 
    y = (x + y) % t ;

    int domain = rand () % 6 + 2 ;

    if (a[0] > 2 && !(x % 4))
    {
        int P = rand () % a[0] + 1;
        P = a[P] ;

        Potion[P].active = 1 ;
        Potion[P].time = 12 ;

        Potion[P].x = (object[x].x * domain  +  object[y].x * (10 - domain)) / 10 ;
        Potion[P].y = (object[x].y * domain  +  object[y].y * (10 - domain)) / 10 ;
    }
    
}

void initPotion(SDL_Renderer *Renderer,mixture Potion[4]){
    
    for (int i = 0; i < 4; i++)
    {
        Potion[i].active = -1 ;
    }

    Potion[0].PotionPic = IMG_LoadTexture(Renderer, "../IMG/potion1.png");
    Potion[1].PotionPic = IMG_LoadTexture(Renderer, "../IMG/potion2.png");
    Potion[2].PotionPic = IMG_LoadTexture(Renderer, "../IMG/potion3.png");
    Potion[3].PotionPic = IMG_LoadTexture(Renderer, "../IMG/potion4.png");

    Potion[0].activeTime = 18 /*Increse Soldiers Unlimited */  ;
    Potion[1].activeTime = 15 /* change enemy soldiers to friend*/;
    Potion[2].activeTime = 9  /* stop other Players Soldiers*/;
    Potion[3].activeTime = 15 /* 2X friend Soldiers' speed*/;
}

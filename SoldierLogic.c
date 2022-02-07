#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdio.h>
#include "Functions.h"

extern const float v ;

void RenderSoldiers(SDL_Renderer *Renderer,sol *Soldier,int p , play Player[p],int t ,state object[t]){

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

void ShowSoldier(SDL_Renderer *Renderer,sol *Soldier,int p , play Player[p],int t ,state object[t]){
    int q = -1 ;
    
    for (int i = 0; i < p; i++)
    {
        if (Player[i].Potion == 2)
        {
            q = i ;
            break ;
        }
        
    }
    

    for (int i = 0; i < 1000; i++)
    {
        if (Soldier[i].active > 0 && (q == -1 || (q > -1 && Soldier[i].Playerowner == q ) ) )
        {
            if (Soldier[i].active > 2)
            {

                Soldier[i].active--;

                if (Player[Soldier[i].Playerowner].Potion == 3)
                {
                    Soldier[i].active--;
                }

                if (Soldier[i].active == 1)
                {
                    Soldier[i].x += 7 * Soldier[i].dx * v ;
                    Soldier[i].y += 7 * Soldier[i].dy * v ;

                    object[Soldier[i].owner].soldier--;
                    Player[Soldier[i].Playerowner].SoldierOnSurface++;
                }
                
            }

            else if (Soldier[i].active == 2)
            {
                object[Soldier[i].owner].soldier--;
                Player[Soldier[i].Playerowner].SoldierOnSurface++;
                Soldier[i].active--;

                Soldier[i].x += 7 * Soldier[i].dx * v ;
                Soldier[i].y += 7 * Soldier[i].dy * v ;
                
                if (Player[Soldier[i].Playerowner].Potion == 3)
                {
                    Soldier[i].x += Soldier[i].dx * v ;
                    Soldier[i].y += Soldier[i].dy * v ;
                }
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

                    if (Player[Soldier[i].Playerowner].Potion == 3)
                    {
                        Soldier[i].x += Soldier[i].dx * v ;
                        Soldier[i].y += Soldier[i].dy * v ;
                    }
                }

                else
                {
                    int q1 = getOwner(p,Player,object[Soldier[i].dest]);

                    if (Soldier[i].Playerowner == q1 || Player[q1].Potion == 1)
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

                                if (Soldier[j].owner == Soldier[i].dest && Soldier[j].active > 1)
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

    }
        
    RenderSoldiers(Renderer,Soldier,p,Player,t,object);

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

    int q1 = 2 ;

    for (int i = 999; i > -1; i--)
    {
        if (Soldier[i].active > 0 && Soldier[i].owner == stateNumber && Soldier[i].dest == destSatate && q1 < Soldier[i].active) 
        {
            q1 = Soldier[i].active ;
        }
        
    }


    for (int q = 0; q < i.ReadySoldier ; t++)
    {

        if (Soldier[t].active == -1)
        {
            Soldier[t].active = 8 * (q/3) + q1;
            
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
    
}

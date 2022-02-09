#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "Functions.h"

extern const int FPS;

extern int AmountOfPlayers;

void WriteScoreBoard(int n0,PlayerName N[n0+1],int number,int score){
    int value ;
    N[number].Score += score;

    FILE* fp = fopen("ScoreBoard.txt","w");

    if (number > n0 - 1)
    {
        n0++ ; 
    }

    for (int i = 0; i < n0 ; i++)
    {
        for (int j = 0; j < n0 ; j++)
        {
            if (N[i].Score > N[j].Score && N[i].rank > N[j].rank)
            {
                value = N[i].rank;
                N[i].rank = N[j].rank ;
                N[j].rank = value;
            }
            
        }
        
    }
    
        
    fprintf(fp,"%d\n",n0);

    for (int i = 0; i < n0; i++)
    {
        fprintf(fp,"%s \n%d %d\n",N[i].Name,N[i].rank,N[i].Score);
    }

    fclose(fp);

}

int SetScore(int count){

    if (AmountOfPlayers == 2)
    {
        switch (count)
        {

        case 1:

            return 50 ;  
            break;
        
        case 2:

            return -20 ;  
            break;
        }
    }

    else if (AmountOfPlayers == 3)
    {
        switch (count)
        {
            
        case 1:

            return 70 ;  
            break;
        
        case 2:

            return -10 ;  
            break;
        
        case 3:

            return -30 ;  
            break;
        }

    }
    
    else if (AmountOfPlayers == 4)
    {
        switch (count)
        {
            
        case 1:

            return 95 ;  
            break;
        
        case 2:

            return 10;  
            break;
        
        case 3:

            return -20 ;  
            break;
       
        case 4:

            return -50 ;  
            break;
        }
    }

    
}

int WinOrLost(int p,play Player[p],int n0,PlayerName N[n0+1],int number){

    SDL_Window *ExitWindow = SDL_CreateWindow("END",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,500,300,SDL_WINDOW_OPENGL);
    SDL_Renderer *ExitRenderer = SDL_CreateRenderer(ExitWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    
    SDL_Texture *TextureEnd = IMG_LoadTexture(ExitRenderer, "../IMG/End.jpg");
    SDL_Rect End = {.x = 0 , .y = 0 , .w = 500 , .h = 300 };



    if (Player[1].score == 0)
    {
        int count = 1 ;
        char place[10] = "";
        char Score[10] = "";


        SDL_Texture *TextEnd = GetText(ExitRenderer,100,"Arial.ttf",0,0,0,"You Had Lost At   th Place");
        SDL_Rect EndText = {.x = 50 , .y = 120 , .w = 400 , .h = 50 };

        SDL_Texture *TextS = GetText(ExitRenderer,80,"Arial.ttf",0,0,0,"And You Got     Points");
        SDL_Rect SText = {.x = 25 , .y = 200 , .w = 450 , .h = 50 };


        for (int i = 1; i < p; i++)
        {
            if (Player[i].score > 0)
            {
                count++;
            }
            
        }
        
        sprintf(place,"%8d",count);
        SDL_Texture *TextPlace = GetText(ExitRenderer,100,"Arial.ttf",0,0,0,place);
        SDL_Rect EndPlace = {.x = 255 , .y = 120 , .w = 70 , .h = 50 };

        
        int score = SetScore(count);
        WriteScoreBoard(n0,N,number,score);
        

        sprintf(Score,"%8d",score);
        SDL_Texture *TextScore = GetText(ExitRenderer,80,"Arial.ttf",0,0,0,Score);
        SDL_Rect EndScore = {.x = 250 , .y = 200 , .w = 90 , .h = 50 };
        
        
        SDL_Event Event;

        SDL_bool Exit = SDL_FALSE;
        while (Exit == SDL_FALSE) 
        {
            SDL_SetRenderDrawColor(ExitRenderer, 255, 255, 255, 255);
            SDL_RenderClear(ExitRenderer);

            SDL_RenderCopy(ExitRenderer, TextureEnd, NULL, &End);

            SDL_RenderCopy(ExitRenderer, TextEnd, NULL, &EndText);
            SDL_RenderCopy(ExitRenderer, TextPlace, NULL, &EndPlace);

            SDL_RenderCopy(ExitRenderer, TextS, NULL, &SText);
            SDL_RenderCopy(ExitRenderer, TextScore, NULL, &EndScore);
        
        
            SDL_RenderPresent(ExitRenderer);
        
            while (SDL_PollEvent(&Event))
            {
                if (Event.window.event == SDL_WINDOWEVENT_CLOSE)
                {
                    Exit = SDL_TRUE;

                    SDL_DestroyTexture(TextEnd);
                    SDL_DestroyTexture(TextS);
                    SDL_DestroyTexture(TextPlace);
                    SDL_DestroyTexture(TextScore);

                    return 0 ;
                }
            }
        
            SDL_Delay(1000 / FPS );
        }
    
        SDL_DestroyTexture(TextEnd);
        SDL_DestroyTexture(TextS);
        SDL_DestroyTexture(TextPlace);
        SDL_DestroyTexture(TextScore);

    
    }

    else
    {
        char Score[10] = "";


        SDL_Texture *TextEnd = GetText(ExitRenderer,150,"Arial.ttf",0,0,0,"You Had Won");
        SDL_Rect EndText = {.x = 100 , .y = 120 , .w = 300 , .h = 75 };

        SDL_Texture *TextS = GetText(ExitRenderer,80,"Arial.ttf",0,0,0,"And You Got    Points");
        SDL_Rect SText = {.x = 25 , .y = 220 , .w = 450 , .h = 50 };


        int score = SetScore(1);
        WriteScoreBoard(n0,N,number,score);

        sprintf(Score,"%8d",score);
        SDL_Texture *TextScore = GetText(ExitRenderer,80,"Arial.ttf",0,0,0,Score);
        SDL_Rect EndScore = {.x = 245 , .y = 220 , .w = 90 , .h = 50 };


        SDL_Event Event;
        SDL_bool Exit = SDL_FALSE;
        while (Exit == SDL_FALSE) 
        {
            SDL_SetRenderDrawColor(ExitRenderer, 255, 255, 255, 255);
            SDL_RenderClear(ExitRenderer);

            SDL_RenderCopy(ExitRenderer, TextureEnd, NULL, &End);

            SDL_RenderCopy(ExitRenderer, TextEnd, NULL, &EndText);

            SDL_RenderCopy(ExitRenderer, TextS, NULL, &SText);
            SDL_RenderCopy(ExitRenderer, TextScore, NULL, &EndScore);

        
        
            SDL_RenderPresent(ExitRenderer);
        
            while (SDL_PollEvent(&Event))
            {
                if (Event.window.event == SDL_WINDOWEVENT_CLOSE)
                {
                    Exit = SDL_TRUE;

                    SDL_DestroyTexture(TextEnd);
                    SDL_DestroyTexture(TextS);
                    SDL_DestroyTexture(TextScore);

                    return 0 ;
                }
            }
        
            SDL_Delay(1000 / FPS );
        }

        SDL_DestroyTexture(TextEnd);
        SDL_DestroyTexture(TextS);
        SDL_DestroyTexture(TextScore);

    }

    SDL_DestroyWindow(ExitWindow);
    return 0 ;

}
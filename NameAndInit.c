#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Functions.h"

extern const int FPS ;



SDL_Texture* GetText(SDL_Renderer *Renderer,int size,char* Fontname,int R,int G,int B,char* str) {
    
    char string[100] = "../FONT/";
    strcat(string,Fontname);

    TTF_Font* font = TTF_OpenFont(string, size);
    if (!font) 
    {
        printf("Failed to load font: %s\n", TTF_GetError());
    }
    
    SDL_Color color = {R, G, B};

    SDL_Surface* text = TTF_RenderText_Solid(font, str, color);
    
    SDL_Texture* text_texture = SDL_CreateTextureFromSurface( Renderer, text );

    SDL_FreeSurface(text);
    TTF_CloseFont(font);
    
    return text_texture ;
}

int getName(SDL_Window *Window,SDL_Renderer *Renderer,SDL_Texture *TextureFirst,SDL_Rect FullPic,char name[20]){
    
    int i = 0 ;

    SDL_Texture *TextH = GetText(Renderer,20,"Arial.ttf",0,0,0,"|");
    
    SDL_Rect text_rect = {.x = 440 - 20 * strlen(name), .y = 600, .w = 40 * strlen(name), .h = 95};
    SDL_Rect textHint_rect = {.x = 440 + 20 * strlen(name), .y = 595, .w = 20, .h = 90};
    
    SDL_StartTextInput();
    
    SDL_Event Event;
    SDL_bool Exit = SDL_FALSE;

    while (Exit == SDL_FALSE) 
    {
        SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
        SDL_RenderClear(Renderer);

        SDL_RenderCopy(Renderer, TextureFirst, NULL, &FullPic);

        SDL_Texture *TextName = GetText(Renderer,40,"Arial.ttf",255,100,0,name);
        SDL_RenderCopy(Renderer, TextName, NULL, &text_rect);

        
        if ((i % 40) < 20)
        {
            SDL_RenderCopy(Renderer, TextH, NULL, &textHint_rect);
        }
        
       
        SDL_RenderPresent(Renderer);
        
        while (SDL_PollEvent(&Event))
        {
            if (Event.type == SDL_QUIT)
            {
                Exit = SDL_TRUE;

                SDL_DestroyTexture(TextH);
                SDL_DestroyTexture(TextName);
                SDL_StopTextInput();
    
                return 0 ;
            }

            else if (Event.type == SDL_TEXTINPUT && text_rect.w < 680)
            {
                if (*Event.text.text < 128 && *Event.text.text > 0 && *Event.text.text != 32)
                {
                    strcat(name,Event.text.text);

                    text_rect.x -= 20;
                    text_rect.w += 40 ;
                    textHint_rect.x += 20 ;
                }
            
            }

            else if (Event.type == SDL_KEYDOWN && Event.key.keysym.sym == SDLK_RETURN && name[0] != '\0')
            {
                SDL_DestroyTexture(TextH);
                SDL_DestroyTexture(TextName);
                SDL_StopTextInput();
    
                return 1;
            }

            else if (Event.type == SDL_KEYDOWN && Event.key.keysym.sym == SDLK_BACKSPACE && text_rect.w > 39)
            {
                name[strlen(name)-1] = '\0';

                text_rect.x += 20;
                text_rect.w -= 40 ;
                textHint_rect.x -= 20 ;
            }

        }
        
        SDL_Delay(1000 / FPS);

        i %= 40 ;
        i++ ;

        SDL_DestroyTexture(TextName);

    }

    SDL_DestroyTexture(TextH);
    SDL_StopTextInput();

    return 1 ;

}


SDL_bool init_TTF(){
    if (TTF_Init() < 0)
    {
        printf("Unable to initialize SDL_tff: %s\n", TTF_GetError());
        return false ;
    }
    return true ;
}

SDL_bool init_IMG(){
    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG ) < 0) 
    {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }
    return true ;
}

SDL_bool init(){
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) 
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    return true ;
}

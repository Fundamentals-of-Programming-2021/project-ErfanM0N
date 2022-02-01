#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


const int SCREEN_WIDTH = 1270;
const int SCREEN_HEIGHT = 850;
const int FPS = 60;


void Render_border(SDL_Renderer *Renderer,SDL_Rect border){
    for (int j = 1; j < 6; j++)
    {
        SDL_RenderDrawRect(Renderer,&border);
        border.x -= 1,border.y -= 1;
        border.w += 2,border.h += 2;
    }
}

int Menu(SDL_Window *Window,SDL_Renderer *Renderer,SDL_Texture *TextureMenu,SDL_Rect FullPic){
    
    SDL_Rect border[3];
    border[0].x = 90 , border[0].y = 335, border[0].w = 640 ,border[0].h = 110 ;
    border[1].x = 60 , border[1].y = 510, border[1].w = 840 ,border[1].h = 110 ;
    border[2].x = 240 , border[2].y = 670, border[2].w = 440 ,border[2].h = 110 ;

    SDL_Event sdlEvent;
    SDL_bool Exit = SDL_FALSE;
    int i = 1 ;
    while (Exit == SDL_FALSE) 
    {
        SDL_SetRenderDrawColor(Renderer, 0 , 0 , 0 , 255);
        SDL_RenderClear(Renderer);
        SDL_RenderCopy(Renderer, TextureMenu, NULL, &FullPic);
        
        Render_border(Renderer,border[0]);
        Render_border(Renderer,border[1]);
        Render_border(Renderer,border[2]);
        
        SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
        
        Render_border(Renderer,border[i-1]); 

        SDL_RenderPresent(Renderer);
        

        SDL_PollEvent(&sdlEvent) ;
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
                if (i == 4)
                {
                    i = 1;
                }
                SDL_Delay(8000 / FPS);
            }
            if (sdlEvent.key.keysym.sym == SDLK_UP)
            {
                i--;
                if (i == 0)
                {
                    i = 3;
                }
                SDL_Delay(8000 / FPS);
            }
            
            if (sdlEvent.key.keysym.sym == SDLK_RETURN)
            {
                return i;
            }
        }
        else if (sdlEvent.type == SDL_MOUSEBUTTONDOWN)
        {
            if (sdlEvent.button.x >= 90 && sdlEvent.button.x <= 90 + 640 && sdlEvent.button.y >= 335 && sdlEvent.button.y <= 335 + 110)
            {
                return 1;
            }
            if (sdlEvent.button.x >= 60 && sdlEvent.button.x <= 60 + 840 && sdlEvent.button.y >= 510 && sdlEvent.button.y <= 510 + 110)
            {
                return 2;
            }
            if (sdlEvent.button.x >= 240 && sdlEvent.button.x <= 240 + 440 && sdlEvent.button.y >= 670 && sdlEvent.button.y <= 670 + 100)
            {
                return 3 ;
            }
            
        }
                

        SDL_Delay(1000 / FPS);
    }
    return 4;

}

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
    
    SDL_Texture *TextM = GetText(Renderer,20,"arial.ttf",0,0,0,"|");
    SDL_Texture *Textlanguage = GetText(Renderer,20,"arial.ttf",0,0,0,"Use English Characters");
    
    SDL_Rect text_rect = {.x=100, .y=600, .w=0, .h=95};
    SDL_Rect text2_rect = {.x=100+3, .y=595, .w=20, .h=90};
    SDL_Rect language = {.x=200, .y=720, .w=500, .h=95};
    
    SDL_StartTextInput();

    
    SDL_Event Event;
    SDL_bool Exit = SDL_FALSE;
    while (Exit == SDL_FALSE) 
    {
        SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
        SDL_RenderClear(Renderer);
        SDL_RenderCopy(Renderer, TextureFirst, NULL, &FullPic);
        SDL_Texture *TextName = GetText(Renderer,40,"arial.ttf",0,0,0,name);
        SDL_RenderCopy(Renderer, TextName, NULL, &text_rect);
        SDL_RenderCopy(Renderer, Textlanguage, NULL, &language);
        
        if ((i % 40) < 21)
        {
            SDL_RenderCopy(Renderer, TextM, NULL, &text2_rect);
        }
        
        SDL_RenderPresent(Renderer);
        
        SDL_PollEvent(&Event) ;
        if (Event.type == SDL_QUIT)
        {
            Exit = SDL_TRUE;
            return 0 ;
        }
        else if (Event.type == SDL_TEXTINPUT && text_rect.w < 680)
        {
            if (*Event.text.text < 128 && *Event.text.text >0)
            {
                strcat(name,Event.text.text);
                text_rect.w += 40 ;
                text2_rect.x += 40 ;
                SDL_Delay(8000/FPS);
            }
            
        }
        else if (Event.type == SDL_KEYDOWN && Event.key.keysym.sym == SDLK_RETURN)
        {
            SDL_Delay(8000/FPS);
            return 1;
        }
        else if (Event.type == SDL_KEYDOWN && Event.key.keysym.sym == SDLK_BACKSPACE && text_rect.w > 39)
        {
            name[strlen(name)-1] = '\0';
            text_rect.w -= 40 ;
            text2_rect.x -= 40 ;
            SDL_Delay(8000/FPS);
        }
        
        
        SDL_Delay(1000 / FPS);
        i %= 40 ;
        i++ ;
        SDL_DestroyTexture(TextName);
    }
    SDL_DestroyTexture(TextM);
    SDL_DestroyTexture(Textlanguage);
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


    SDL_Event sdlEvent;
    SDL_bool Exit = SDL_FALSE;
    int i = 1 ;
    while (Exit == SDL_FALSE) 
    {
        SDL_SetRenderDrawColor(Renderer, 0 , 0 , 0 , 255);
        SDL_RenderClear(Renderer);
        SDL_RenderCopy(Renderer, TextureBG, NULL, &FullPic);
        
        
        
        SDL_RenderPresent(Renderer);
        

        SDL_PollEvent(&sdlEvent) ;
        if (sdlEvent.type == SDL_QUIT)
        {
            Exit = SDL_TRUE;
            return 0 ;
        }
        
        SDL_Delay(1000 / FPS);
    }
    return 4;
    
    
    SDL_DestroyWindow(Window);
    return 0;

}
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
#include "Gamelogic.h"


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

    if (!Game(Window,Renderer,TextureBG,FullPic))
    {
        return 0;
    }
    SDL_DestroyTexture(TextureBG);


    
    SDL_DestroyWindow(Window);
    return 0;

}
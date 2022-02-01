#include <iostream>

int main(int, char**) {
    std::cout << "Hello, world!\n";
}


Uint32 color = 0xffffff00;
        Sint16 x1 = 60, x2 = 280;
        Sint16 y1 = 160, y2 = 320;
        boxColor(sdlRenderer, x1, y1, x2, y2, color);
       
        Uint32 color2 = 0xff0000ff;
        Sint16 x = 480, y = 240, r = 100;
        filledCircleColor(sdlRenderer, x, y, r, color2);
    


    Uint32 color = 0xffffff00;
        Sint16 x1 = 60, x2 = 580;
        Sint16 y1 = 50, y2 = 130;
        boxColor(sdlRenderer, x1, y1, x2, y2, color);
       
        Uint32 color2 = 0xffffff00;
        Sint16 x12 = 60, x22 = 580;
        Sint16 y12 = 180, y22 = 260;
        boxColor(sdlRenderer, x12, y12, x22, y22, color2);

        Uint32 color3 = 0xffffff00;
        Sint16 x13 = 60, x23 = 580;
        Sint16 y13 = 300, y23 = 380;
        boxColor(sdlRenderer, x13, y13, x23, y23, color3);








        #include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdio.h>
#include <stdbool.h>


const int SCREEN_WIDTH = 840;
const int SCREEN_HEIGHT = 630;
const int FPS = 60;

SDL_Texture *getImageTexture(SDL_Renderer *sdlRenderer, char *image_path) {
    SDL_Surface *image = SDL_LoadBMP(image_path);

    if (!image) {
        printf("Failed to load image at %s: %s\n", image_path, SDL_GetError());
        return 0;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(sdlRenderer, image);

    SDL_FreeSurface(image);
    image = NULL;

    return texture;
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) 
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }
  
    SDL_Window *sdlWindow = SDL_CreateWindow("FOP project",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
    SCREEN_HEIGHT,SDL_WINDOW_OPENGL);

    SDL_Renderer *sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    
    SDL_Texture *sdlTexture = getImageTexture(sdlRenderer, "../main.bmp");

    SDL_Rect texture_rect = {.x=0, .y=0, .w=SCREEN_WIDTH, .h=SCREEN_HEIGHT};

    SDL_Event sdlEvent;
    SDL_bool shallExit = SDL_FALSE;
    while (shallExit == SDL_FALSE) 
    {
        SDL_RenderClear(sdlRenderer);
        SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, &texture_rect);
 
        Uint32 color = 0xffffff00;
        Sint16 x1 = 60, x2 = 580;
        Sint16 y1 = 50, y2 = 130;
        boxColor(sdlRenderer, x1, y1, x2, y2, color);
    
        Uint32 color2 = 0xffffff00;
        Sint16 x12 = 60, x22 = 580;
        Sint16 y12 = 180, y22 = 260;
        boxColor(sdlRenderer, x12, y12, x22, y22, color2);

        Uint32 color3 = 0xffffff00;
        Sint16 x13 = 60, x23 = 580;
        Sint16 y13 = 300, y23 = 380;
        boxColor(sdlRenderer, x13, y13, x23, y23, color3);   
             
       
        SDL_PollEvent(&sdlEvent) ;

        if (sdlEvent.type == SDL_QUIT)
        {
            shallExit = SDL_TRUE;
        }
        SDL_RenderPresent(sdlRenderer);
        SDL_Delay(1000 / FPS);
    }

    SDL_DestroyWindow(sdlWindow);

}

for (int i = 0; i < 3; )
    {
        x = rand() % t;
        if (!object[x].HaveOwner)
        {
            object[x].owner = Player[0];
            object[x].HaveOwner = 1;
            i++;
        }
        
    }

if (!object[i].HaveOwner)
        {
            i++ ;
        }
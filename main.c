#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


const int SCREEN_WIDTH = 1270;
const int SCREEN_HEIGHT = 850;
const int FPS = 60;

typedef struct play{
    int R ;
    int G ;
    int B ;
    int score;
    int Amount_of_state;
}play ;

typedef struct state{
    play owner ;
    int soldier ;
    int x ,y ;
    int shape;
    int size ;
}state ;

SDL_Texture* GetText(SDL_Renderer *Renderer,int size,char* Fontname,int R,int G,int B,char* str);

void ShowNumberOfSoldiers(SDL_Renderer *Renderer,int t ,state object[t]){
    SDL_Rect rect ;
    rect.h = 18 ;
    for (int i = 0; i < t; i++)
    {
        char str[20];
        sprintf(str,"%8d",object[i].soldier);
        rect.w = strlen(str) * 10 ;
        
        SDL_Texture *TextM = GetText(Renderer,15,"Arial.ttf",0,0,0,str);
        rect.x = object[i].x - (rect.w/2) - 20 ;
        rect.y = object[i].y + 30 ;

        SDL_RenderCopy(Renderer,TextM,NULL,&rect);
        SDL_DestroyTexture(TextM);

    }
    
}

void IncreaseSoldier(int t ,state object[t]){
    for (int i = 0; i < t; i++)
    {
        if (!(object[i].owner.R == 255 && object[i].owner.G == 255 && object[i].owner.B == 255))
        {
            if (object[i].soldier < 120)
            {
                object[i].soldier++;
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

int SetStateOwner(int t ,state object[t],int p ,play Player[p]){
    srand(time(NULL));
    int x ;
    int a[5] = {0};
    
    for (int i = 0; i < 4; i++)
    {
        object[i].owner = Player[0];
        object[i].soldier = 80 ;
    }
    Player[0].Amount_of_state += 4;

    object[4].owner = Player[1];
    Player[1].Amount_of_state++;
    
    object[5].owner = Player[2];
    Player[2].Amount_of_state++;
    
    object[6].owner = Player[3];
    Player[3].Amount_of_state++;
    
    object[7].owner = Player[1];
    Player[1].Amount_of_state++;
    
    object[8].owner = Player[2];
    Player[2].Amount_of_state++;

    
    x = (rand() % 4) + 1;
    object[9].owner = Player[x];
    Player[x].Amount_of_state++;

    
}


void CreatePlayer(SDL_Renderer *Renderer,int p ,play Player[p]){
    Player[0].R = 255 ,Player[0].G = 255 ,Player[0].B = 255,Player[0].Amount_of_state = 0;
    Player[1].R = 255 ,Player[1].G = 0 ,Player[1].B = 255 ,Player[1].Amount_of_state = 0;
    Player[2].R = 0 ,Player[2].G = 255 ,Player[2].B = 255 ,Player[2].Amount_of_state = 0;
    Player[3].R = 255 ,Player[3].G = 255 ,Player[3].B = 0 ,Player[3].Amount_of_state = 0;
    Player[4].R = 51 ,Player[4].G = 200 ,Player[4].B = 50 ,Player[4].Amount_of_state = 0;
}


void CreateState(SDL_Renderer *Renderer,int t ,state object[t]){
    int a ;
    int Distance = 60 ;
    int DistanceFromBorder = 80 ;
    srand(time(NULL));

    for (int i = 0; i < t; i++)
    {
        a = 0;
       
        object[i].x = (rand() % (SCREEN_WIDTH - 2*DistanceFromBorder - 60)) + (2*DistanceFromBorder + 60) / 2 ;
        object[i].y = (rand() % (SCREEN_HEIGHT - 2*DistanceFromBorder - 60)) + (2*DistanceFromBorder + 60) / 2 ;
        object[i].size = (rand () % 20) + 60 ;
        
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
            object[i].soldier = rand () % 30 + 20 ;
        }
        
    }
    

}

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
    SDL_Texture *TextM = GetText(Renderer,20,"Arial.ttf",0,0,0,"|");
    
    SDL_Rect text_rect = {.x=440, .y=600, .w=0, .h=95};
    SDL_Rect textHint_rect = {.x=440+1, .y=595, .w=20, .h=90};
    
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

        
        if ((i % 40) < 21)
        {
            SDL_RenderCopy(Renderer, TextM, NULL, &textHint_rect);
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
                text_rect.x -= 20;
                text_rect.w += 40 ;
                textHint_rect.x += 20 ;
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
            text_rect.x += 20;
            text_rect.w -= 40 ;
            textHint_rect.x -= 20 ;
            SDL_Delay(8000/FPS);
        }
        
        
        SDL_Delay(1000 / FPS);
        i %= 40 ;
        i++ ;
        SDL_DestroyTexture(TextName);
    }
    SDL_DestroyTexture(TextM);
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

    int t = 10 ;
    state object[t];
    CreateState(Renderer,t,object);

    int p = 5;
    play Player[p];
    CreatePlayer(Renderer,p,Player);

    SetStateOwner(t,object,p,Player);
    SDL_Texture *TextureSol = IMG_LoadTexture(Renderer, "../IMG/SoldierIcon.png");

    int x = 0 ;
    SDL_Event sdlEvent;
    SDL_bool Exit = SDL_FALSE;
    while (Exit == SDL_FALSE) 
    {
        SDL_SetRenderDrawColor(Renderer, 0 , 0 , 0 , 255);
        SDL_RenderClear(Renderer);
        SDL_RenderCopy(Renderer, TextureBG, NULL, &FullPic);
        

        for (int i = 0; i < t; i++)
        {
            
            if (object[i].shape)
            {
                filledCircleRGBA(Renderer,object[i].x,object[i].y,object[i].size,object[i].owner.R,object[i].owner.G,object[i].owner.B,2*object[i].soldier + 15);
            }
            else
            {
                boxRGBA(Renderer, object[i].x - object[i].size , object[i].y - object[i].size ,
                object[i].x + object[i].size, object[i].y + object[i].size,object[i].owner.R,object[i].owner.G,object[i].owner.B,2*object[i].soldier + 15);
            }
         
        }
        
        SoldierIcon(Renderer,t,object,TextureSol);
        x++ ;
        if (x == FPS/5)
        {
            IncreaseSoldier(t,object);
            x = 0 ;
        }
        ShowNumberOfSoldiers(Renderer,t,object);

        SDL_RenderPresent(Renderer);
        
        
        SDL_PollEvent(&sdlEvent) ;
        if (sdlEvent.type == SDL_QUIT)
        {
            Exit = SDL_TRUE;
            return 0 ;
        }
        
        SDL_Delay(1000 / FPS);
    }
    
    
    SDL_DestroyWindow(Window);
    return 0;

}
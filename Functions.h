#ifndef _HEADER_Functions_H
#define _HEADER_Functions_H

#include "Structs.h"

void SoldierEatPotion(mixture Potion[4],int t ,state object[t],int p ,play Player[p],sol *Soldier);

void setPotionTime(mixture Potion[4],int p ,play Player[p]);

void ShowPotion(SDL_Renderer *Renderer,mixture Potion[4]);

void AddPotion(int t ,state object[t],mixture Potion[4]);

void initPotion(SDL_Renderer *Renderer,mixture Potion[4]);

void RenderSoldiers(SDL_Renderer *Renderer,sol *Soldier,int p , play Player[p],int t ,state object[t]);

void ShowSoldier(SDL_Renderer *Renderer,sol *Soldier,int p , play Player[p],int t ,state object[t]);

void CreateSoldier(state i,state j,sol *Soldier,int p , play Player[p],int stateNumber,int destSatate);

void RenderHinter(SDL_Renderer *Renderer,int t ,state object[t],int Source[3],int Point[3]);

void SetAttack(SDL_Event sdlEvent,int t ,state object[t],int Source[3],int Point[3],int p ,play Player[p],sol *Soldier);

void RenderStates(SDL_Renderer *Renderer,int t ,state object[t]);

int Game(SDL_Window *Window,SDL_Renderer *Renderer,SDL_Texture *TextureBG,SDL_Rect FullPic,int t ,state object[t],int p ,play Player[p]);

int Isequal(play x,play y);

int getOwner(int p , play Player[p],state j);

void RenderLeaderBoard(SDL_Renderer *Renderer,SDL_Texture *BoardT,int p ,play Player[p],mixture Potion[4]);

void SetRank(int p ,play Player[p]);

void Getscore(int t ,state object[t],int p ,play Player[p]);

void ShowNumberOfSoldiers(SDL_Renderer *Renderer,int t ,state object[t]);

void IncreaseSoldier(int t ,state object[t],int p ,play Player[p]);

void SoldierIcon(SDL_Renderer *Renderer,int t ,state object[t],SDL_Texture *TextureSol);

int SetStateOwner(int t ,state object[t],int p ,play Player[p]);

void CreatePlayer(SDL_Renderer *Renderer,int p ,play Player[p]);

void CreateState(SDL_Renderer *Renderer,int t ,state object[t]);

int StartGame(SDL_Window *Window,SDL_Renderer *Renderer,SDL_Texture *TextureGameFirstPage,SDL_Rect FullPic,SDL_Texture *TextureBack,SDL_Rect Back);

void Render_border(SDL_Renderer *Renderer,SDL_Rect border,int size);

int Menu(SDL_Window *Window,SDL_Renderer *Renderer,SDL_Texture *TextureMenu,SDL_Rect FullPic,SDL_Texture *TextureBack,SDL_Rect Back);

int getName(SDL_Window *Window,SDL_Renderer *Renderer,SDL_Texture *TextureFirst,SDL_Rect FullPic,char name[20]);

SDL_Texture* GetText(SDL_Renderer *Renderer,int size,char* Fontname,int R,int G,int B,char* str);

SDL_bool init_TTF();

SDL_bool init_IMG();

SDL_bool init();

#endif
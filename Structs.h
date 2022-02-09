#ifndef HEADER_Structs_H
#define HEADER_Structs_H

typedef struct PlayerName
{
    char Name[20] ;
    int rank ;
    int Score ;

}PlayerName;



typedef struct sol{
    int R ;
    int G ;
    int B ;
    float x,y ;
    float x1,y1 ;
    float dx,dy;
    int active ;
    int owner ;
    int Playerowner;
    int dest ;
}sol;


typedef struct mixture{
    SDL_Texture *PotionPic;
    int x;
    int y;
    int active;
    int time;
    int activeTime ;
}mixture ;


typedef struct play{
    int R ;
    int G ;
    int B ;
    int score;
    int Amount_of_state;
    int rank;
    int SoldierOnSurface;
    int Potion;
    int PotionActiveTime;
}play ;


typedef struct state{
    play owner ;
    int soldier ;
    int ReadySoldier ;
    int x ,y ;
    int shape;
    int size ;
}state ;


#endif
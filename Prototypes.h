#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <time.h>
#include"Structure.c"
#include <SDL/SDL.h>
void BlitImage(SDL_Surface *Surface ,SDL_Surface *Ecran ,int X ,int Y);
void pause();
SDL_Rect Pos_Pion[9][9];
Cellule Hex[9][9];
SDL_Event mEvent;
SDL_Surface *Fleche_Inverse;
#endif // PROTOTYPES_H_INCLUDED

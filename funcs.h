#ifndef MINESWEEPER_DISPLAY_TEXT_H
#define MINESWEEPER_DISPLAY_TEXT_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

#include "slidebar.h"
#include "popup.h"
#include "table_box.h"

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 768 + 75
#define BOX_SIZE SCREEN_WIDTH / DEFAULT_SIDE

inline void showBG(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 198, 198, 198, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 47, 79, 79, 255);
    for (int i = 0; i < DEFAULT_SIDE; i++)
        SDL_RenderDrawLine(renderer, 0, 75 + i * BOX_SIZE, SCREEN_WIDTH, 75 + i * BOX_SIZE);

    for (int i = 0; i < DEFAULT_SIDE; i++)
        SDL_RenderDrawLine(renderer, 0 + i * BOX_SIZE, 75, 0 + i * BOX_SIZE, SCREEN_HEIGHT);
}

inline SDL_Texture* getTextureText(char *script, char *fontFile, int r, int g, int b, int a, int size, SDL_Renderer *renderer)
{
    //text color
    SDL_Color textColor;
    textColor.a = a;
    textColor.r = r;
    textColor.g = g;
    textColor.b = b;

    //opening font file
    TTF_Font *font = TTF_OpenFont(fontFile, size);

    SDL_Surface *text = TTF_RenderText_Solid(font, script, textColor); //creates the text
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, text); //transform to texture from surface
    TTF_CloseFont(font);

    return textTexture;
}

#endif //MINESWEEPER_DISPLAY_TEXT_H

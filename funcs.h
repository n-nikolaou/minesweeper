#ifndef MINESWEEPER_DISPLAY_TEXT_H
#define MINESWEEPER_DISPLAY_TEXT_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

#include "table_box.h"

#define SCREEN_WIDTH SIDE * BOX_SIZE
#define SCREEN_HEIGHT SIDE * BOX_SIZE

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

    //get the width and the height of the text given the pt size of the text
    int wText, hText;
    TTF_SizeText(font, script, &wText, &hText);
    SDL_Rect srcText;
    srcText.x = 0;
    srcText.y = 0;
    srcText.w = wText;
    srcText.h = hText;

    SDL_Surface *text = TTF_RenderText_Solid(font, script, textColor); //creates the text
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, text); //transform to texture from surface
    TTF_CloseFont(font);

    return textTexture;
}

#endif //MINESWEEPER_DISPLAY_TEXT_H

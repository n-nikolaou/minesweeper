#ifndef MINESWEEPER_SINGULAR_BOX_H
#define MINESWEEPER_SINGULAR_BOX_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "funcs.h"

class table_box;
class singular_box {
private:
    bool isOpen, isFlagged;
    int nearBombs, x, y;
    SDL_Renderer *renderer;
    SDL_Rect src, dst;
    SDL_Texture *texture;

public:
    singular_box(SDL_Renderer *renderer, int x, int y, int nearBombs);

    void showTexture();

    void openBox();
    void flagBox();

    bool hasOpened();
    bool hasFlagged();
};


#endif //MINESWEEPER_SINGULAR_BOX_H

#ifndef MINESWEEPER_SINGULAR_BOX_H
#define MINESWEEPER_SINGULAR_BOX_H

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "display_text.h"

#define BOX_SIZE 50

class singular_box {
private:
    bool isOpen;
    int nearBombs;
    SDL_Renderer *renderer;
    SDL_Rect src, dst;
    SDL_Texture *texture;

public:
    singular_box(SDL_Renderer *renderer, int x, int y, int nearBombs);

    void showTexture();
    bool hasBeenClicked();
};


#endif //MINESWEEPER_SINGULAR_BOX_H

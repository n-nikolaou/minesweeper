#ifndef MINESWEEPER_SLIDEBAR_H
#define MINESWEEPER_SLIDEBAR_H

#include "funcs.h"

class slidebar {
private:
    SDL_Rect dst, ball;
    SDL_Renderer *renderer;
    int *selection, size, x, y, w, pos;

public:
    slidebar(SDL_Renderer*, int*, int, int, int, int);

    void showBar();
    void hasBeenClicked(int);

    int getPos();
};


#endif //MINESWEEPER_SLIDEBAR_H

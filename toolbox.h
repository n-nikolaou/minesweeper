#ifndef MINESWEEPER_TOOLBOX_H
#define MINESWEEPER_TOOLBOX_H

#include "funcs.h"

class toolbox {
private:
    int remainingBombs;
    bool gameOver;
    SDL_Renderer *renderer;
    SDL_Rect leftBox, lBoxT, rightBox, rBoxT;

public:
    toolbox(SDL_Renderer*);

    void showTexture(int, char*);

    void reduceRemaining();
    void increaseRemaining();
};


#endif //MINESWEEPER_TOOLBOX_H

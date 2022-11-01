#ifndef MINESWEEPER_TOOLBOX_H
#define MINESWEEPER_TOOLBOX_H

#include "funcs.h"

class popup;
class toolbox {
private:
    int remainingBombs;
    bool gameOver;
    SDL_Renderer *renderer;
    SDL_Rect leftBox, lBoxT, rightBox, rBoxT, srcSettings, settingsBox;
    popup *settings;

public:
    toolbox(SDL_Renderer*, popup*);

    void showTexture(int, char*);
    void hasBeenClicked(bool *hasStarted, bool *isMenuOpen);

    void reduceRemaining();
    void increaseRemaining();
};


#endif //MINESWEEPER_TOOLBOX_H

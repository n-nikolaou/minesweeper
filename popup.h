#ifndef MINESWEEPER_POPUP_H
#define MINESWEEPER_POPUP_H

#include "funcs.h"

class slidebar;
class popup {
private:
    SDL_Rect square;
    SDL_Renderer *renderer;
    slidebar *bombBar, *sideBar;

public:
    popup(SDL_Renderer *renderer);

    void openWindow();
    void hasBeenClicked();
};


#endif //MINESWEEPER_POPUP_H

#ifndef MINESWEEPER_TABLE_BOX_H
#define MINESWEEPER_TABLE_BOX_H

#define DEFAULT_SIDE 12
#define DEFAULT_BOMBS DEFAULT_SIDE * DEFAULT_SIDE * 20 / 100

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <thread>

#include "singular_box.h"
#include "toolbox.h"

class toolbox;
class singular_box;
class table_box {
private:
    singular_box ***table;
    int **numTable, **noBombs;
    SDL_Renderer *renderer;
    toolbox *menu;

public:
    table_box(SDL_Renderer *renderer, toolbox *menu);

    void fillTable();
    void fillSquare(int i, int j);

    bool doesBoxNoBomb(int i, int j);

    void renderTable();
    void hasBeenClicked(bool *hasStarted);
    void hasBeenRightClicked();

    void openOuterSquare(int i, int j);
};


#endif //MINESWEEPER_TABLE_BOX_H

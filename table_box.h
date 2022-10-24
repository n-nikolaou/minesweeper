#ifndef MINESWEEPER_TABLE_BOX_H
#define MINESWEEPER_TABLE_BOX_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "singular_box.h"

#define SIDE 20
#define BOMBS 80

class table_box {
private:
    singular_box ***table;
    int **numTable, **noBombs;
    SDL_Renderer *renderer;

public:
    table_box(SDL_Renderer *renderer);

    void fillTable();
    void fillSquare(int i, int j);

    bool doesBoxNoBomb(int i, int j);

    void renderTable();
    void hasBeenClicked(bool *hasStarted);
};


#endif //MINESWEEPER_TABLE_BOX_H

#ifndef MINESWEEPER_TABLE_BOX_H
#define MINESWEEPER_TABLE_BOX_H

#define SIDE 20
#define BOMBS 60

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "singular_box.h"

class singular_box;
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

    void openOuterSquare(int i, int j);
};


#endif //MINESWEEPER_TABLE_BOX_H

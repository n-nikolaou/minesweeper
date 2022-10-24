#ifndef MINESWEEPER_TABLE_BOX_H
#define MINESWEEPER_TABLE_BOX_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "singular_box.h"

#define SIDE 20
#define BOMBS 200

class table_box {
private:
    singular_box ***table;
    int **numTable;

public:
    table_box(SDL_Renderer *renderer);

    void fillTable();
    void fillSquare(int i, int j);

    void renderTable();

};


#endif //MINESWEEPER_TABLE_BOX_H

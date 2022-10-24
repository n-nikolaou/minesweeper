#include "table_box.h"

#include <cstdlib>
#include <ctime>
#include "iostream"
void table_box::fillSquare(int i, int j)
{
    if (i > 0) numTable[i - 1][j] = (numTable[i - 1][j] == -1) ? -1 : numTable[i - 1][j] + 1;
    if (i < SIDE - 1) numTable[i + 1][j] = (numTable[i + 1][j] == -1) ? -1 : numTable[i + 1][j] + 1;

    if (j > 0) numTable[i][j - 1] = (numTable[i][j - 1] == -1) ? -1 : numTable[i][j - 1] + 1;
    if (j < SIDE - 1) numTable[i][j + 1] = (numTable[i][j + 1] == -1) ? -1 : numTable[i][j + 1] + 1;

    if (i > 0 && j > 0) numTable[i - 1][j - 1] = (numTable[i - 1][j - 1] == -1) ? -1 : numTable[i - 1][j - 1] + 1;
    if (i < SIDE - 1 && j > 0) numTable[i + 1][j - 1] = (numTable[i + 1][j - 1] == -1) ? -1 : numTable[i + 1][j - 1] + 1;
    if (i > 0 && j < SIDE - 1) numTable[i - 1][j + 1] = (numTable[i - 1][j + 1] == -1) ? -1 : numTable[i - 1][j + 1] + 1;
    if (i < SIDE - 1 && j < SIDE - 1) numTable[i + 1][j + 1] = (numTable[i + 1][j + 1] == -1) ? -1 : numTable[i + 1][j + 1] + 1;
}

void table_box::fillTable()
{
    for (int i = 0; i < SIDE; i++)
        for (int j = 0; j < SIDE; j++)
            numTable[i][j] = 0;

    int randT;

    for (int i = 0; i < BOMBS; i++)
    {
        randT = (std::time(0) * rand()) % (SIDE * SIDE);
        while (numTable[randT / SIDE][randT % SIDE] == -1 || doesBoxNoBomb(randT / SIDE, randT % SIDE))
            randT = (randT + 1) % (SIDE * SIDE);

        numTable[randT / SIDE][randT % SIDE] = -1;
    }

    for (int i = 0; i < SIDE; i++)
        for (int j = 0; j < SIDE; j++)
            if (numTable[i][j] == -1) fillSquare(i, j);

    for (int i = 0; i < SIDE; i++)
        for (int j = 0; j < SIDE; j++)
            table[i][j] = new singular_box(renderer, j * BOX_SIZE, i * BOX_SIZE, numTable[i][j]);
}

table_box::table_box(SDL_Renderer *renderer)
{
    this->renderer = renderer;

    table = (singular_box***) malloc(SIDE * SIDE * sizeof(singular_box**));
    for (int i = 0; i < SIDE; i++)
    {
        table[i] = (singular_box**) malloc(SIDE * sizeof(singular_box*));
        for (int j = 0; j < SIDE; j++)
            table[i][j] = (singular_box*) malloc(sizeof(singular_box));
    }

    numTable = (int**) malloc(SIDE * sizeof(int*));
    for (int i = 0; i < SIDE; i++)
        numTable[i] = (int*) malloc(SIDE * sizeof(int));

    noBombs = (int**) malloc(9 * sizeof(int*));
    for (int i = 0; i < 9; i++)
    {
        noBombs[i] = (int *) malloc(2 * sizeof(int));
        noBombs[i][0] = -1;
        noBombs[i][1] = -1;
    }
}

void table_box::renderTable()
{
    for (int i = 0; i < SIDE; i++)
        for (int j = 0; j < SIDE; j++)
            table[i][j]->showTexture();
}

bool table_box::doesBoxNoBomb(int I, int J)
{
    for (int i = 0; i < 9; i++)
        if (noBombs[i][0] == J && noBombs[i][1] == I) return true;

    return false;
}

void table_box::hasBeenClicked(bool *hasStarted)
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    if (!(*hasStarted))
    {
        *hasStarted = true;
        int i, j;
        i = mouseY / BOX_SIZE;
        j = mouseX / BOX_SIZE;

        if (i > 0 && j > 0)
        {
            noBombs[0][0] = j - 1;
            noBombs[0][1] = i - 1;
        }
        if (i > 0)
        {
            noBombs[1][0] = j;
            noBombs[1][1] = i - 1;
        }
        if (i > 0 && j < SIDE - 1)
        {
            noBombs[2][0] = j + 1;
            noBombs[2][1] = i - 1;
        }
        if (j > 0)
        {
            noBombs[3][0] = j - 1;
            noBombs[3][1] = i;
        }
        noBombs[4][0] = j;
        noBombs[4][1] = i;
        if (j < SIDE - 1)
        {
            noBombs[5][0] = j + 1;
            noBombs[5][1] = i;
        }
        if (i < SIDE - 1 && j > 0)
        {
            noBombs[6][0] = j - 1;
            noBombs[6][1] = i + 1;
        }
        if (i < SIDE - 1)
        {
            noBombs[7][0] = j;
            noBombs[7][1] = i + 1;
        }
        if (i < SIDE - 1 && j < SIDE - 1)
        {
            noBombs[8][0] = j + 1;
            noBombs[8][1] = i + 1;
        }

        fillTable();

        renderTable();
        SDL_RenderPresent(renderer);
    }
}
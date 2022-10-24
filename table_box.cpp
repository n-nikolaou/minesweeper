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
        while (numTable[randT / SIDE][randT % SIDE] == -1)
            randT = (randT + 1) % (SIDE * SIDE);

        numTable[randT / SIDE][randT % SIDE] = -1;
    }

    for (int i = 0; i < SIDE; i++)
        for (int j = 0; j < SIDE; j++)
            if (numTable[i][j] == -1) fillSquare(i, j);

}

table_box::table_box(SDL_Renderer *renderer)
{
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

    fillTable();

    for (int i = 0; i < SIDE; i++)
        for (int j = 0; j < SIDE; j++)
            table[i][j] = new singular_box(renderer, j * BOX_SIZE, i * BOX_SIZE, numTable[i][j]);
}

void table_box::renderTable()
{
    for (int i = 0; i < SIDE; i++)
        for (int j = 0; j < SIDE; j++)
            table[i][j]->showTexture();
}
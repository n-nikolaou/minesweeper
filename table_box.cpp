#include "table_box.h"

#include <cstdlib>
#include <ctime>

void table_box::fillSquare(int i, int j)
{
    if (i > 0) numTable[i - 1][j] = (numTable[i - 1][j] == -1) ? -1 : numTable[i - 1][j] + 1;
    if (i < DEFAULT_SIDE - 1) numTable[i + 1][j] = (numTable[i + 1][j] == -1) ? -1 : numTable[i + 1][j] + 1;

    if (j > 0) numTable[i][j - 1] = (numTable[i][j - 1] == -1) ? -1 : numTable[i][j - 1] + 1;
    if (j < DEFAULT_SIDE - 1) numTable[i][j + 1] = (numTable[i][j + 1] == -1) ? -1 : numTable[i][j + 1] + 1;

    if (i > 0 && j > 0) numTable[i - 1][j - 1] = (numTable[i - 1][j - 1] == -1) ? -1 : numTable[i - 1][j - 1] + 1;
    if (i < DEFAULT_SIDE - 1 && j > 0) numTable[i + 1][j - 1] = (numTable[i + 1][j - 1] == -1) ? -1 : numTable[i + 1][j - 1] + 1;
    if (i > 0 && j < DEFAULT_SIDE - 1) numTable[i - 1][j + 1] = (numTable[i - 1][j + 1] == -1) ? -1 : numTable[i - 1][j + 1] + 1;
    if (i < DEFAULT_SIDE - 1 && j < DEFAULT_SIDE - 1) numTable[i + 1][j + 1] = (numTable[i + 1][j + 1] == -1) ? -1 : numTable[i + 1][j + 1] + 1;
}

void table_box::fillTable()
{
    for (int i = 0; i < DEFAULT_SIDE; i++)
        for (int j = 0; j < DEFAULT_SIDE; j++)
            numTable[i][j] = 0;

    int randT;

    for (int i = 0; i < DEFAULT_BOMBS; i++)
    {
        randT = (std::time(0) * rand()) % (DEFAULT_SIDE * DEFAULT_SIDE);
        while (numTable[randT / DEFAULT_SIDE][randT % DEFAULT_SIDE] == -1 || doesBoxNoBomb(randT / DEFAULT_SIDE, randT % DEFAULT_SIDE))
            randT = (randT + 1) % (DEFAULT_SIDE * DEFAULT_SIDE);

        numTable[randT / DEFAULT_SIDE][randT % DEFAULT_SIDE] = -1;
    }

    for (int i = 0; i < DEFAULT_SIDE; i++)
        for (int j = 0; j < DEFAULT_SIDE; j++)
            if (numTable[i][j] == -1) fillSquare(i, j);

    for (int i = 0; i < DEFAULT_SIDE; i++)
        for (int j = 0; j < DEFAULT_SIDE; j++)
            table[i][j] = new singular_box(renderer, j * BOX_SIZE, i * BOX_SIZE, numTable[i][j]);
}

table_box::table_box(SDL_Renderer *renderer, toolbox *menu)
{
    this->renderer = renderer;
    this->menu = menu;

    table = (singular_box***) malloc(DEFAULT_SIDE * DEFAULT_SIDE * sizeof(singular_box**));
    for (int i = 0; i < DEFAULT_SIDE; i++)
    {
        table[i] = (singular_box**) malloc(DEFAULT_SIDE * sizeof(singular_box*));
        for (int j = 0; j < DEFAULT_SIDE; j++)
            table[i][j] = new singular_box(renderer, j * BOX_SIZE, i * BOX_SIZE, -2);
    }

    numTable = (int**) malloc(DEFAULT_SIDE * sizeof(int*));
    for (int i = 0; i < DEFAULT_SIDE; i++)
        numTable[i] = (int*) malloc(DEFAULT_SIDE * sizeof(int));

    noBombs = (int**) malloc(9 * sizeof(int*));
    for (int i = 0; i < 9; i++)
    {
        noBombs[i] = (int *) malloc(2 * sizeof(int));
        noBombs[i][0] = -1;
        noBombs[i][1] = -1;
    }

    showBG(renderer);
    renderTable();
}

void table_box::renderTable()
{
    for (int i = 0; i < DEFAULT_SIDE; i++)
        for (int j = 0; j < DEFAULT_SIDE; j++)
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

    if (mouseY > 75)
    {
        int i, j;
        i = (mouseY - 75) / (BOX_SIZE);
        j = mouseX / (BOX_SIZE);
        if (!(*hasStarted))
        {
            *hasStarted = true;

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
            if (i > 0 && j < DEFAULT_SIDE - 1)
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
            if (j < DEFAULT_SIDE - 1)
            {
                noBombs[5][0] = j + 1;
                noBombs[5][1] = i;
            }
            if (i < DEFAULT_SIDE - 1 && j > 0)
            {
                noBombs[6][0] = j - 1;
                noBombs[6][1] = i + 1;
            }
            if (i < DEFAULT_SIDE - 1)
            {
                noBombs[7][0] = j;
                noBombs[7][1] = i + 1;
            }
            if (i < DEFAULT_SIDE - 1 && j < DEFAULT_SIDE - 1)
            {
                noBombs[8][0] = j + 1;
                noBombs[8][1] = i + 1;
            }

            fillTable();
        }

        showBG(renderer);
        openOuterSquare(i, j);
        renderTable();
    }
}

void table_box::openOuterSquare(int i, int j)
{
    table[i][j]->openBox();

    if (numTable[i][j] == 0)
    {
        //open the neighbor boxes with zero bombs if the haven't been already opened
        if (i > 0 && j > 0) if (numTable[i - 1][j - 1] == 0 && !table[i - 1][j - 1]->hasOpened()) openOuterSquare(i - 1, j - 1);
        if (i > 0 && j < DEFAULT_SIDE - 1) if (numTable[i - 1][j + 1] == 0 && !table[i - 1][j + 1]->hasOpened()) openOuterSquare(i - 1, j + 1);
        if (i < DEFAULT_SIDE - 1 && j > 0) if (numTable[i + 1][j - 1] == 0 && !table[i + 1][j - 1]->hasOpened()) openOuterSquare(i + 1, j - 1);
        if (i < DEFAULT_SIDE - 1 && j < DEFAULT_SIDE - 1) if (numTable[i + 1][j + 1] == 0 && !table[i + 1][j + 1]->hasOpened()) openOuterSquare(i + 1, j + 1);

        if (i > 0) if (numTable[i - 1][j] == 0 && !table[i - 1][j]->hasOpened()) openOuterSquare(i - 1, j);
        if (j > 0) if (numTable[i][j - 1] == 0 && !table[i][j - 1]->hasOpened()) openOuterSquare(i, j - 1);
        if (j < DEFAULT_SIDE - 1) if (numTable[i][j + 1] == 0 && !table[i][j + 1]->hasOpened()) openOuterSquare(i, j + 1);
        if (i < DEFAULT_SIDE - 1) if (numTable[i + 1][j] == 0 && !table[i + 1][j]->hasOpened()) openOuterSquare(i + 1, j);

        //open all the neighbor boxes of the zero-bomb-boxes
        if (i > 0 && j > 0) table[i - 1][j - 1]->openBox();
        if (i > 0 && j < DEFAULT_SIDE - 1) table[i - 1][j + 1]->openBox();
        if (i < DEFAULT_SIDE - 1 && j > 0) table[i + 1][j - 1]->openBox();
        if (i < DEFAULT_SIDE - 1 && j < DEFAULT_SIDE - 1) table[i + 1][j + 1]->openBox();

        if (i > 0) table[i - 1][j]->openBox();
        if (j > 0) table[i][j - 1]->openBox();
        if (j < DEFAULT_SIDE - 1) table[i][j + 1]->openBox();
        if (i < DEFAULT_SIDE - 1) table[i + 1][j]->openBox();

    }
}

void table_box::hasBeenRightClicked()
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    if (mouseY > 75)
    {
        int i, j;
        i = (mouseY - 75) / (BOX_SIZE);
        j = mouseX / (BOX_SIZE);

        if (!table[i][j]->hasOpened())
        {
            showBG(renderer);
            table[i][j]->flagBox();
            renderTable();
            if (table[i][j]->hasFlagged()) menu->reduceRemaining();
            else menu->increaseRemaining();
        }
    }
}
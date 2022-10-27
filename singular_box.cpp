#include "singular_box.h"

singular_box::singular_box(SDL_Renderer *renderer, int x, int y, int nearBombs)
{
    this->renderer = renderer;
    this->nearBombs = nearBombs;

    src.x = 0;
    src.y = 0;
    src.w = 70;
    src.h = 70;

    this->x = x;
    this->y = y;

    dst.x = x;
    dst.y = y;
    dst.w = BOX_SIZE;
    dst.h = BOX_SIZE;

    isFlagged = false;
    isOpen = false;
}

void singular_box::showTexture()
{
    if (isFlagged) texture = IMG_LoadTexture(renderer, "C:/Users/nickn/Documents/minesweeper/files/flag.png");
    else if (!isOpen) texture = IMG_LoadTexture(renderer, "C:/Users/nickn/Documents/minesweeper/files/unopened_box.png");
    else
    {
        dst.x = x + BOX_SIZE / 10;
        dst.y = y + BOX_SIZE / 10;
        dst.w = 9 * BOX_SIZE / 10;
        dst.h = 9 * BOX_SIZE / 10;

        if (nearBombs == -1) texture = IMG_LoadTexture(renderer, "C:/Users/nickn/Documents/minesweeper/files/bomb.png");
        else if (nearBombs == 1) texture = getTextureText("1", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 0, 0, 255, 255, 40, renderer);
        else if (nearBombs == 2) texture = getTextureText("2", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 0, 170, 0, 255, 40, renderer);
        else if (nearBombs == 3) texture = getTextureText("3", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 170, 0, 0, 255, 40, renderer);
        else if (nearBombs == 4) texture = getTextureText("4", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 0, 0, 139, 255, 40, renderer);
        else if (nearBombs == 5) texture = getTextureText("5", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 139, 69, 19, 255, 40, renderer);
        else if (nearBombs == 6) texture = getTextureText("6", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 0, 200, 200, 255, 40, renderer);
        else if (nearBombs == 7) texture = getTextureText("7", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 0, 0, 0, 255, 40, renderer);
        else if (nearBombs == 8) texture = getTextureText("8", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 230, 0, 180, 255, 40, renderer);
        else if (nearBombs == 0) texture = getTextureText("0", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 198, 198, 198, 255, 40, renderer);
    }

    SDL_RenderCopy(renderer, texture, &src, &dst);
}

void singular_box::openBox()
{
    isOpen = true;
}

void singular_box::flagBox()
{
    isFlagged = !isFlagged;
}

bool singular_box::hasOpened()
{
    return isOpen;
}
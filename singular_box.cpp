#include "singular_box.h"

singular_box::singular_box(SDL_Renderer *renderer, int x, int y, int nearBombs)
{
    this->renderer = renderer;
    this->nearBombs = nearBombs;

    src.x = 0;
    src.y = 0;
    src.w = 70;
    src.h = 70;

    dst.x = x + BOX_SIZE / 10;
    dst.y = y + BOX_SIZE / 10;
    dst.w = 8 * BOX_SIZE / 10;
    dst.h = 8 * BOX_SIZE / 10;

    isOpen = true;
}

void singular_box::showTexture()
{
    if (!isOpen) texture = IMG_LoadTexture(renderer, "C:/Users/nickn/Documents/minesweeper/files/unopened_box.png");
    else
    {
        if (nearBombs == -1) texture = IMG_LoadTexture(renderer, "C:/Users/nickn/Documents/minesweeper/files/bomb.png");
        else if (nearBombs == 1) texture = getTextureText("1", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 0, 0, 255, 255, 40, dst.x, dst.y, renderer);
        else if (nearBombs == 2) texture = getTextureText("2", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 0, 170, 0, 255, 40, dst.x, dst.y, renderer);
        else if (nearBombs == 3) texture = getTextureText("3", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 170, 0, 0, 255, 40, dst.x, dst.y, renderer);
        else if (nearBombs == 4) texture = getTextureText("4", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 0, 0, 139, 255, 40, dst.x, dst.y, renderer);
        else if (nearBombs == 5) texture = getTextureText("5", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 139, 69, 19, 255, 40, dst.x, dst.y, renderer);
        else if (nearBombs == 6) texture = getTextureText("6", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 0, 200, 200, 255, 40, dst.x, dst.y, renderer);
        else if (nearBombs == 7) texture = getTextureText("7", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 0, 0, 0, 255, 40, dst.x, dst.y, renderer);
        else if (nearBombs == 8) texture = getTextureText("8", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 230, 0, 180, 255, 40, dst.x, dst.y, renderer);
        else if (nearBombs == 0) texture = getTextureText("0", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 198, 198, 198, 255, 40, dst.x, dst.y, renderer);
    }

    SDL_RenderCopy(renderer, texture, &src, &dst);
}

bool singular_box::hasBeenClicked()
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    if (mouseX >= dst.x && mouseX <= (dst.x + dst.w) && (mouseY >= dst.y && mouseY <= (dst.y + dst.h)))
    {
        if (!isOpen) isOpen = true;
        return true;
    }

    return false;
}
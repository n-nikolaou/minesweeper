#include "singular_box.h"

singular_box::singular_box(SDL_Renderer *renderer, int x, int y, int nearBombs)
{
    this->renderer = renderer;
    this->nearBombs = nearBombs;
    texture = IMG_LoadTexture(renderer, "C:/Users/nickn/Documents/minesweeper/files/unopened_box.png");
    src.x = 0;
    src.y = 0;
    src.w = 76;
    src.h = 76;

    dst.x = x;
    dst.y = y;
    dst.w = BOX_SIZE;
    dst.h = BOX_SIZE;

    isOpen = false;
}

void singular_box::showTexture()
{
    if (!isOpen)
        SDL_RenderCopy(renderer, texture, &src, &dst);
    else
    {
        if (nearBombs == 1) texture = getTextureText("1", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 0, 0, 255, 255, 30, dst.x, dst.y, renderer);
        else if (nearBombs == 2) texture = getTextureText("2", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 0, 255, 0, 255, 30, dst.x, dst.y, renderer);
        else if (nearBombs == 3) texture = getTextureText("3", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 255, 0, 0, 255, 30, dst.x, dst.y, renderer);
        else if (nearBombs == 4) texture = getTextureText("4", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 0, 0, 139, 255, 30, dst.x, dst.y, renderer);
        else if (nearBombs == 5) texture = getTextureText("5", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 165, 42, 42, 255, 30, dst.x, dst.y, renderer);
        else if (nearBombs == 6) texture = getTextureText("6", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 0, 255, 255, 255, 30, dst.x, dst.y, renderer);
        else if (nearBombs == 7) texture = getTextureText("7", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 0, 0, 0, 255, 30, dst.x, dst.y, renderer);
        else if (nearBombs == 8) texture = getTextureText("8", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 128, 128, 128, 255, 30, dst.x, dst.y, renderer);
        else if (nearBombs == 0) texture = getTextureText("0", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 0, 0, 0, 0, 30, dst.x, dst.y, renderer);
    }
}

bool singular_box::hasBeenClicked()
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    if (mouseX >= dst.x && mouseX <= (dst.x + dst.w) && (mouseY >= dst.y && mouseY <= (dst.y + dst.h)))
    {
        isOpen = !isOpen;
        return true;
    }

    return false;
}
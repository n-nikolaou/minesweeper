#include "slidebar.h"

slidebar::slidebar(SDL_Renderer *renderer, int *selection, int size, int x, int y, int w)
{
    this->renderer = renderer;
    this->selection = selection;
    this->size = size;
    this->x = x;
    this->y = y;
    this->w = w;
    pos = 2;
}

void slidebar::showBar()
{
    dst.x = x;
    dst.y = y;
    dst.w = w;
    dst.h = 5;
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
    SDL_RenderFillRect(renderer, &dst);

    ball.x = dst.x + dst.w * pos / (size - 1) - 7;
    ball.y = dst.y - 5;
    ball.w = 8;
    ball.h = 15;
    SDL_RenderFillRect(renderer, &ball);
}

void slidebar::hasBeenClicked(int mouseX)
{
    pos = (mouseX - 220) / (double) dst.w * size + 0.5;
    showBar();
}

int slidebar::getPos() {return pos;}
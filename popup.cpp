#include "popup.h"

popup::popup(SDL_Renderer *renderer)
{
    this->renderer = renderer;
    square.x = 205;
    square.y = 205;
    square.w = SCREEN_WIDTH - 2*205;
    square.h = SCREEN_HEIGHT - 2*205;
    bombBar = new slidebar(renderer, nullptr, 5, 220, 415, SCREEN_WIDTH - 2*205 - 20);
}

void popup::openWindow()
{
    SDL_SetRenderDrawColor(renderer, 80, 80, 80, 50);
    for (int i = 0; i < 5; i++)
    {
        SDL_RenderDrawLine(renderer, 200 + i, 200, 200 + i, SCREEN_HEIGHT - 205);
        SDL_RenderDrawLine(renderer, 200, 200 + i, SCREEN_WIDTH - 205, 200 + i);
        SDL_RenderDrawLine(renderer, SCREEN_WIDTH - 205 - i, 200, SCREEN_WIDTH - 205 - i, SCREEN_HEIGHT - 205);
        SDL_RenderDrawLine(renderer, SCREEN_WIDTH - 205, SCREEN_HEIGHT - 205 - i, 200, SCREEN_HEIGHT - 205 - i);
    }

    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderFillRect(renderer, &square);

    SDL_Rect src, dst;
    src.x = 0;
    src.y = 0;
    src.w = 1000;
    src.h = 1000;

    dst.x = SCREEN_WIDTH/2 - 100;
    dst.y = 220;
    dst.w = 200;
    dst.h = 30;

    SDL_Texture *settingsText = getTextureText("SETTINGS", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 30, 30, 30, 255, 40, renderer);
    SDL_RenderCopy(renderer, settingsText, &src, &dst);

    dst.x = 220;
    dst.y = 280;
    dst.w = 220;
    dst.h = 25;

    SDL_Texture *sideText = getTextureText("DIMENSIONS", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 70, 70, 70, 255, 40, renderer);
    SDL_RenderCopy(renderer, sideText, &src, &dst);

    dst.x = 220;
    dst.y = 380;
    dst.w = 120;
    dst.h = 25;

    SDL_Texture *bombsText = getTextureText("BOMBS", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 70, 70, 70, 255, 40, renderer);
    SDL_RenderCopy(renderer, bombsText, &src, &dst);

    dst.x = 220;
    dst.y = 480;
    dst.w = 240;
    dst.h = 25;

    SDL_Texture *startText = getTextureText("SAFE START", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 70, 70, 70, 255, 40, renderer);
    SDL_RenderCopy(renderer, startText, &src, &dst);

    dst.x = 220;
    dst.y = 515;
    dst.w = SCREEN_WIDTH - 2*205 - 20;
    dst.h = 20;

    SDL_Texture *infoText1 = getTextureText("This means that with the first", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 70, 70, 70, 255, 20, renderer);
    SDL_RenderCopy(renderer, infoText1, &src, &dst);

    dst.x = 220;
    dst.y = 540;
    dst.w = SCREEN_WIDTH - 2*205 - 20;
    dst.h = 20;

    SDL_Texture *infoText2 = getTextureText("click, there will be no bombs", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 70, 70, 70, 255, 20, renderer);
    SDL_RenderCopy(renderer, infoText2, &src, &dst);

    dst.x = 220;
    dst.y = 565;
    dst.w = SCREEN_WIDTH - 2*205 - 80;
    dst.h = 20;

    SDL_Texture *infoText3 = getTextureText("near the starting click.", "C:/Users/nickn/Documents/minesweeper/files/font.ttf", 70, 70, 70, 255, 20, renderer);
    SDL_RenderCopy(renderer, infoText3, &src, &dst);

    dst.x = SCREEN_WIDTH/2 - 80;
    dst.y = SCREEN_HEIGHT - 205 - 55;
    dst.w = 160;
    dst.h = 50;
    SDL_Texture *okayButton = IMG_LoadTexture(renderer, "C:/Users/nickn/Documents/minesweeper/files/okay.png");
    SDL_RenderCopy(renderer, okayButton, &src, &dst);

    bombBar->showBar();

    SDL_RenderPresent(renderer);
}

void popup::hasBeenClicked()
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    if (mouseX > 220 && mouseX < 220 + 415 + 8 && mouseY > 410 && mouseY < 430)
    {
        bombBar->hasBeenClicked(mouseX);
        openWindow();
    }
}
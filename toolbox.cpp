#include "toolbox.h"

toolbox::toolbox(SDL_Renderer *renderer, popup *settings)
{
    remainingBombs = DEFAULT_BOMBS;
    this->renderer = renderer;
    this->settings = settings;
    gameOver = false;

    leftBox.x = 100;
    leftBox.y = 15;
    leftBox.w = 100;
    leftBox.h = 45;

    lBoxT.x = 125;
    lBoxT.y = 20;
    lBoxT.w = 50;
    lBoxT.h = 35;

    rightBox.x = SCREEN_WIDTH - 300;
    rightBox.y = 15;
    rightBox.w = 200;
    rightBox.h = 45;

    rBoxT.x = SCREEN_WIDTH - 275;
    rBoxT.y = 20;
    rBoxT.w = 155;
    rBoxT.h = 35;

    settingsBox.x = SCREEN_WIDTH / 2 - 45/2;
    settingsBox.y = 15;
    settingsBox.w = 45;
    settingsBox.h = 45;

    srcSettings.x = 0;
    srcSettings.y = 0;
    srcSettings.w = 70;
    srcSettings.h = 70;
}

void toolbox::showTexture(int time, char* dots)
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 200;
    src.h = 200;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &leftBox);
    SDL_RenderFillRect(renderer, &rightBox);

    char *num = (char*) malloc(6 * sizeof(char));
    sprintf(num, "%d\0", remainingBombs);
    SDL_Texture *textBombs = getTextureText(num, "C:/Users/nickn/Documents/minesweeper/files/digital.ttf", 0, 220, 10, 255, 80, renderer);
    SDL_RenderCopy(renderer, textBombs, &src, &lBoxT);

    if (time / 60 < 10 && time % 60 < 10)
        sprintf(num, "0%d%s0%d\0", time / 60, dots, time % 60);
    else if (time / 60 >= 10 && time % 60 < 10)
        sprintf(num, "%d%s0%d\0", time / 60, dots, time % 60);
    else if (time / 60 < 10 && time % 60 >= 10)
        sprintf(num, "0%d%s%d\0", time / 60, dots, time % 60);
    else
        sprintf(num, "%d%s%d\0", time / 60, dots, time % 60);

    SDL_Texture *settings = IMG_LoadTexture(renderer, "C:/Users/nickn/Documents/minesweeper/files/settings.png");
    SDL_RenderCopy(renderer, settings, &srcSettings, &settingsBox);

    SDL_Texture *textTime = getTextureText(num, "C:/Users/nickn/Documents/minesweeper/files/digital.ttf", 0, 220, 10, 255, 80, renderer);
    SDL_RenderCopy(renderer, textTime, &src, &rBoxT);
}

void toolbox::hasBeenClicked(bool *hasStarted, bool *isMenuOpen)
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    if (mouseY > settingsBox.y && mouseY < settingsBox.h + settingsBox.h && mouseX > settingsBox.x && mouseX < settingsBox.x + settingsBox.w)
    {
        *isMenuOpen = true;
        settings->openWindow();
    }
}

void toolbox::reduceRemaining() {remainingBombs--;}

void toolbox::increaseRemaining() {remainingBombs++;}
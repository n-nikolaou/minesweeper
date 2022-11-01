#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <thread>

#include "popup.h"
#include "funcs.h"
#include "toolbox.h"

int secs = 0;
char *dots = (char*) malloc(2 * sizeof(char));
bool ready = false;

void startTool(toolbox *tBox, bool *hasStarted, SDL_Renderer *renderer)
{
    while (true)
    {
        if (*hasStarted) secs++;

        strcpy(dots, ":");
        tBox->showTexture(secs, dots);
        if (ready) SDL_RenderPresent(renderer);
        SDL_Delay(100);
        strcpy(dots, ":");
        tBox->showTexture(secs, dots);
        if (ready) SDL_RenderPresent(renderer);
        SDL_Delay(100);
        strcpy(dots, ":");
        tBox->showTexture(secs, dots);
        if (ready) SDL_RenderPresent(renderer);
        SDL_Delay(100);
        strcpy(dots, ":");
        tBox->showTexture(secs, dots);
        if (ready) SDL_RenderPresent(renderer);
        SDL_Delay(100);
        strcpy(dots, ":");
        tBox->showTexture(secs, dots);
        if (ready) SDL_RenderPresent(renderer);
        SDL_Delay(100);

        strcpy(dots, " ");
        tBox->showTexture(secs, dots);
        if (ready) SDL_RenderPresent(renderer);
        SDL_Delay(100);
        strcpy(dots, " ");
        tBox->showTexture(secs, dots);
        if (ready) SDL_RenderPresent(renderer);
        SDL_Delay(100);
        strcpy(dots, " ");
        tBox->showTexture(secs, dots);
        if (ready) SDL_RenderPresent(renderer);
        SDL_Delay(100);
        strcpy(dots, " ");
        tBox->showTexture(secs, dots);
        if (ready) SDL_RenderPresent(renderer);
        SDL_Delay(100);
        strcpy(dots, " ");
        tBox->showTexture(secs, dots);
        if (ready) SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
}

int main(int argc, char* args[]) {
    if(SDL_Init(SDL_INIT_EVERYTHING)) //initialize sdl
    {
        std::cout<<"Failed to initialize SDL: "<<SDL_GetError<<std::endl;
        return -1;
    }

    if(!IMG_Init(IMG_INIT_PNG)) std::cout<<IMG_GetError<<std::endl;
    if(TTF_Init()) std::cout<<TTF_GetError<<std::endl;

    //create window
    SDL_Window *window = SDL_CreateWindow("Basic Retro Minesweeper", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0); //create renderer

    SDL_Event event;
    bool isRunning = true;
    bool isMenuOpen = false;
    bool hasStarted = false;
    bool gameOver = false;

    popup *settings = new popup(renderer);
    toolbox *tBox = new toolbox(renderer, settings);
    std::thread toolBox(startTool, tBox, &hasStarted, renderer);
    table_box table(renderer, tBox);
    ready = true;

    while (isRunning)
    {
        while (SDL_PollEvent(&event))
            switch (event.type)
            {
                case SDL_QUIT:
                    isRunning = false;

                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT && !isMenuOpen) {
                        ready = false;
                        table.hasBeenClicked(&hasStarted);
                        tBox->hasBeenClicked(&hasStarted, &isMenuOpen);
                        ready = true;
                    }
                    else if (event.button.button == SDL_BUTTON_LEFT && isMenuOpen) {
                        settings->hasBeenClicked();
                    }
                    else if (event.button.button == SDL_BUTTON_RIGHT && hasStarted && !isMenuOpen)
                    {
                        ready = false;
                        table.hasBeenRightClicked();
                        ready = true;
                    }

            }
    }

    return 0;
}

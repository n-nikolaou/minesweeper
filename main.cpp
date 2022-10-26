#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "funcs.h"

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

    showBG(renderer);
    SDL_RenderPresent(renderer);
    table_box table(renderer);

    SDL_Event event;
    bool isRunning = true;
    bool hasStarted = false;

    while (isRunning)
    {
        while (SDL_PollEvent(&event))
            switch (event.type)
            {
                case SDL_QUIT:
                    isRunning = false;

                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        showBG(renderer);
                        table.hasBeenClicked(&hasStarted);
                        SDL_RenderPresent(renderer);
                    }
                //    else if (event.button.button == SDL_BUTTON_RIGHT)

            }
    }

    int i;
    std::cin>>i;



    return 0;
}

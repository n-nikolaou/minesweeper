#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "table_box.h"

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

int main(int argc, char* args[]) {
    if(SDL_Init(SDL_INIT_EVERYTHING)) //initialize sdl
    {
        std::cout<<"Failed to initialize SDL: "<<SDL_GetError<<std::endl;
        return -1;
    }

    if(!IMG_Init(IMG_INIT_PNG)) std::cout<<IMG_GetError<<std::endl;
    if(TTF_Init()) std::cout<<TTF_GetError<<std::endl;

    //create window
    SDL_Window *window = SDL_CreateWindow("Basic Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0); //create renderer

    SDL_SetRenderDrawColor(renderer, 198, 198, 198, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 47, 79, 79, 255);
    for (int i = 0; i < 21; i++)
        SDL_RenderDrawLine(renderer, 0, 0 + i * 50, SCREEN_WIDTH, 0 + i * 50);

    for (int i = 0; i < 21; i++)
        SDL_RenderDrawLine(renderer, 0 + i * 50, 0, 0 + i * 50, SCREEN_HEIGHT);

    table_box table(renderer);
    table.renderTable();

    SDL_RenderPresent(renderer);

    SDL_Event event;
    bool isRunning = true;

    while (isRunning)
    {
        while (SDL_PollEvent(&event))
            switch (event.type)
            {
                case SDL_QUIT:
                    isRunning = false;
//
//                case SDL_MOUSEBUTTONDOWN:
//                    if (event.button.button == SDL_BUTTON_RIGHT)

            }
    }

    int i;
    std::cin>>i;



    return 0;
}

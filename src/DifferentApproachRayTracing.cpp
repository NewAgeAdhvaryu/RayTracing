#define SDL_MAIN_HANDLED
#include<iostream>
#include<SDL2/SDL.h>
#include "ray_inte.h"

using namespace std;

int main(){
    //Init Everything in SDL2
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *win = SDL_CreateWindow("ray", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 700, SDL_WINDOW_RESIZABLE);
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;
    SDL_Event e;
    while (running) // Main Loop
    {
        SDL_PollEvent(&e); 
        if(e.type == SDL_QUIT){ //Terminating the Ray Tracing
            running = false;
            break;
        }
        Body S(100,30,400,400); // Init Star
        Ray r;                  // Init Ray
        Body A(20,10,665, 620); // Init Planet
        Body E(20,10,200, 200); // Init Planet
        
        SDL_SetRenderDrawColor(ren,0,0,0,255); 
        SDL_RenderClear(ren);

        // Rendering the Star
        SDL_SetRenderDrawColor(ren, 255, 255, 200, 150);
        S.RenderBody(ren);
        
        //Rendering planet
        // SDL_SetRenderDrawColor(ren, 255, 255, 200, 150);
        // E.RenderBody(ren);
        
        //Rendering planet
        SDL_SetRenderDrawColor(ren, 0, 200, 0, 150);
        A.RenderBody(ren);

        // Ray Tracing
        r.GenRay(ren,400,400,100,A);
        r.GenRay(ren,1,S,A);

        SDL_RenderPresent(ren);
    }
     SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}

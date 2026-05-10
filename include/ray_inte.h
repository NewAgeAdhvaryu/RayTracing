#include<SDL2/SDL.h>
#include<vector>
#include<cmath>
#include "planet_new.h"
#define PI 3.141528
class Ray{
    public:
    void GenRay(SDL_Renderer *ren,int x0, int y0, double r, Body B){
        double inte = 10.1, co = 0;
       for(; r <= 2000; r++){

           for (double i = 0; i <= 2*PI; i+=0.001)
           {
               int x = x0 + (r*cos(i));  
               int y = y0 + (r*sin(i));  
               if(x <= B.x0 - B.r || y <= B.y0 - B.r){
               SDL_SetRenderDrawColor(ren, 210 - co,210 - co,180 - co,255 - inte);
               SDL_RenderDrawPoint(ren,x,y);
               }
            }
            co += 0.34;
        }
       }
    void GenRay(SDL_Renderer *ren, double r, Body S, Body b){
        double slope_angle = atan(abs(tan((S.y0 - b.y0)/(S.x0 - b.y0))));
        double inte = 40, co = 0;
        double x0 = b.x0 - b.r;
        double y0 = b.y0 - b.r;
       for(r = r; r <= 5; r++){

           for (double i = 0; i <= 2*PI; i+=0.001)
           {
               int x = x0 + (r*cos(i));  
               int y = y0 + (r*sin(i));  
               double dis = (x - b.x0)*(x - b.x0) + (y - b.y0)*(y - b.y0);
               if(dis > b.r){
               SDL_SetRenderDrawColor(ren, 210 - co,210 - co,180 - co,255 - inte);
               SDL_RenderDrawPoint(ren,x,y);
               }
            }
            co += 34;
        }
       }
};


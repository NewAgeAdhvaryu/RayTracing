#include<iostream>

#include<SDL2/SDL.h>
using namespace std;
class Ray;
class Body{

    protected:
    public:
    double r, m;
    int x0, y0, z0;
    float *body_buffer;
    Body();
    Body(double r0, double m0, int x, int y){
        r = r0;
        m = m0;
        x0 = x;
        y0 = y;
    }
    void RenderBody(SDL_Renderer *ren){
        for (int i = x0 - r; i <= x0 + r; i++)
        {
            for (int j = y0 - r; j <= y0 + r; j++)
            {
                for(int k = z0 - r; k <= z0 + r; k++){

                    double dis = ((i - x0)*(i - x0)) + ((j - y0)*(j - y0)) + ((k - z0) * (k - z0));
                    if(dis <= r*r){
                        SDL_RenderDrawPoint(ren,i,j);
                    }
                }
            }
            
        }
        
    }
};
#include <iostream>
#include <GL/glut.h>

#include "cuda-of-life.hpp"
#include "engine.hpp"
#include <random>
#include <time.h>
#include <cstring>
CudaOfLife::CudaOfLife(){
    srand(time(NULL));
    for(int i = 0; i < 50; ++i)
        universe[rand()%100][rand()%100] = true;
}
void CudaOfLife::CPU(){
    // find neighbours
    int count;
    bool map[100][100];
    for(int i = 1; i< 99; ++i)
        for(int j=1; j<99; ++j){
            count = universe[i-1][j] + universe[i][j-1] + universe[i-1][j-1] +
                         universe[i+1][j] + universe[i][j+1] + universe[i+1][j+1] +
                         universe[i-1][j+1] + universe[i+1][j-1];
            if(count < 2 || count > 3)
                map[i][j] = false;
            else if (count == 2 || count == 3)
                map[i][j] = true;
        }
    std::memcpy(universe, map, sizeof(universe));
    //free(map);
    return;
}
bool CudaOfLife::GetCell(int x, int y){
    return universe[x][y];
}
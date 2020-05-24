#include <iostream>
#include "engine.hpp"
int main(int argc, char** argv)
{
    printf("CUDA of Life is running\n");
    Engine app{argc, argv};
    app.Run();
    return 0;
}
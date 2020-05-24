#include <GL/glut.h>
#include <iostream>
#include "u.hpp"

__global__ void Hello(){
    printf("Hello From Cuda~ \n");
}
void DrawGrid(int HALF_GRID_SIZE)
{
    glBegin(GL_LINES);
    glColor3f(0.75f, 0.75f, 0.75f);
    for(int i=-HALF_GRID_SIZE;i<=HALF_GRID_SIZE;i++)
    {
        glVertex3f((float)i,0,(float)-HALF_GRID_SIZE);
        glVertex3f((float)i,0,(float)HALF_GRID_SIZE);

        glVertex3f((float)-HALF_GRID_SIZE,0,(float)i);
        glVertex3f((float)HALF_GRID_SIZE,0,(float)i);
    }
    glEnd();

    //call it like this
    DrawGrid(10);
}

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, 0.0, 0.5);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
        glVertex3f(0.0, 0.0, 0.5);
    glEnd();
    glFlush();
}
 
int main(int argc, char** argv)
{
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(400, 400);
    glutCreateWindow("Hello world!");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}
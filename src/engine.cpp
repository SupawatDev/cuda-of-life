#include "engine.hpp"
#include "cuda-of-life.hpp"
#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>
float Engine::w = 0.00344f;
float Engine::s = 0.00356f;
float Engine::r = 1.0f;
float Engine::px = -43.f;
float Engine::py = -63.f;
float Engine::timer = 0.0f;
int Engine::window_id = 0;
CudaOfLife * Engine::cof = new CudaOfLife();
Engine::Engine(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(600,600);
    window_id = glutCreateWindow("Cuda of Life");


    return;
}
Engine::~Engine(){
    free(cof);
}
void Engine::Run(){
    glutDisplayFunc(renderScene);
    glutReshapeFunc(WindowResize);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(OnKeyboard);
    glutMainLoop();   
}
void Engine::WindowResize(int w, int h){
    if(h == 0) h = 1;
    float ratio = 1.0*w/h;
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glViewport(0,0, w, h);
    gluPerspective(0, ratio, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    return;
}

void Engine::renderScene(void){
	// Clear Color and Depth Buffers
    if(timer > 1.0f){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        for(int i = -500; i < 500; ++i)
        for(int j= -500; j < 500; ++j){
                if(cof->GetCell(i+500, j+500)) glColor3f(0.f, 1.f, 0.4f);
                else glColor3f(0.f, 0.f, 0.f);
                glBegin(GL_POLYGON);
                float x_pos = s*(i+px);
                float y_pos = s*(j+py);
                glVertex3f(x_pos,y_pos,0);
                glVertex3f(x_pos,y_pos+w,0);
                glVertex3f(x_pos+w,y_pos+w,0);
                glVertex3f(x_pos+w,y_pos,0);
                glEnd();
            }
        cof->CPU();
        timer = 0.0f;
    }

    timer += 0.05f;
	glutSwapBuffers();
}

void Engine::OnKeyboard(unsigned char key, int x, int y){
    switch(key){
        case 'q':
            s += 0.001f*r;
            w += 0.001f*r;
            r += 0.01f;
            printf("x: %f, y: %f, s: %f, w: %f\n", px, py, s, w);
            break;
        case 'e':
            s -= 0.001f*r;
            w -= 0.001f*r;
            r += 0.01f;
            break;
        case 'w':
            py -= 0.25f;
            break;
        case 's':
            py += 0.25f;
            break;
        case 'a':
            px += 0.25f;
            break;
        case 'd':
            px -= 0.25f;
            break;
        case 'x':
            glutDestroyWindow ( window_id );
            exit(0);
            break;
        default:
            r = 1.0f;
            break;
    }

}
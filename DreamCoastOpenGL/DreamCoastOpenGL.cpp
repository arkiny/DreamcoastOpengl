// DreamCoastOpenGL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "freeglut.h"
#include <gl/GLU.h>

void InitLight()
{
    GLfloat mat_diffuse[] = {.5, .4, .3, 1};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_ambient[] = {.5, .4, .3, 1};
    GLfloat mat_shininess[] = { 15 };

    GLfloat light_specular[] = {1,1,1,1};
    GLfloat light_diffuse[] = {.8, .8, .8 , 1.0};
    GLfloat light_ambient[] = { .3, .3, .3, 1.0 };
    GLfloat light_position[] = {-3, 6, 3, 0};
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void MyDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 0, 0, 0, -1, 0, 1, 0);
    glutSolidTeapot(0.5);
    glFlush();
}

void MyReshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

int main(int argc, char** argv)
{
    std::cout << "Hello World!\n";
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpeGL Sample Drawing");
    glClearColor(0.4, 0.4, 0.4, 0.0);
    InitLight();
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutMainLoop();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

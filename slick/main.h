#define _CRT_SECURE_NO_WARNINGS
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
//Slick headers
#include "include/structs.h"
#include "include/camera.h"
#include "include/texture.h"
#include "include/button.h"

const int DEF_DISPLAYMODE = GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH;
const int DEF_POSX = 200;
const int DEF_POSY = 200;
const int DEF_WIDTH = 800;
const int DEF_HEIGHT = 600;
const int DEF_BITS = 32;
const int DEF_RATES = 60;
const char DEF_WINNAME[128] = "Slick engine";
const Color DEF_CLEARCOLOR = { 1.0f, 1.0f, 1.0f };
const float DEF_ORTHO = 100.0;
const float movespeed = 0.01;

SLICamera cam;
SLITexture tex;
SLITexture Floor;
unsigned int FPSmeter = 0;
float Light_pos[3] = { 0.0, 50.0, 0.0 };
float Light_dir[3] = { 0.0, 0.0, 0.0 };
float Light_intensive[4] = { 10.0, 10.0, 10.0, 0.0 };
float Floor_pos[3] = {-100.0, 0.0, -100.0};
float _Floor_pos[3] = {100.0, 0.0, 100.0};

struct Settings
{
    unsigned int DisplayMode;
    unsigned int posx;
    unsigned int posy;
    unsigned int height;
    unsigned int width;
    Color ClearColor;
    char* WinName;
} Sets;

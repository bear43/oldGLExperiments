#ifndef BUTTON_H
#define BUTTON_H
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <string.h>
#include "structs.h"
const int CountOfPointers_Button = 64;
struct SLIButton
{
    unsigned int ID;
    const char* Text;
    int x;
    int y;
    int w;
    int h;
    Color PassiveColor;
    Color ActiveColor;
    bool Draw;
    bool Focused;
    unsigned int textSize;
    void Init(char* text, int posx, int posy, int width, int height, Color passivecol, Color activcol, void (*callback)(void));
    void Destroy();
    void (*func)();
};

void DestroyButton(unsigned int ID);
void ButtonPressed(float x, float y, float z);//Проверяет координаты мыши с координатой кнопки
void DrawButtons();
void Mouse(int a, int state, int x, int y);
Color Color3f(float r, float g, float b);
void CreateButton(SLIButton but);//Create button. Return button ID
void ButtonFunc(unsigned int id);
void Focus(unsigned int id);
void UnFocus(unsigned int id);
int ButtonFocused(float x, float y, float z);
int GetButtonIDText(char* buttext);
SLIButton* GetButtonPointer(unsigned int id);
#endif

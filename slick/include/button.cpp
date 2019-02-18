#include "button.h"

SLIButton* PButton[CountOfPointers_Button] = {0};

void SLIButton::Init(char* text, int posx, int posy, int width, int height, Color passivecol, Color activcol, void (*callback)(void))
{
    SLIButton::Text = text;
    SLIButton::x = posx;
    SLIButton::y = posy;
    SLIButton::w = width;
    SLIButton::h = height;
    SLIButton::PassiveColor = passivecol;
    SLIButton::ActiveColor = activcol;
    SLIButton::Draw = true;
    SLIButton::textSize = 11;
    SLIButton::Focused = false;
    SLIButton::func = callback;
    for(unsigned int i = 0; i < CountOfPointers_Button; i++)
    {
        if(PButton[i])
        {
        }
        else
        {
            PButton[i] = this;
            SLIButton::ID = i;
            break;
        }
    }
}

void SLIButton::Destroy()
{
    PButton[SLIButton::ID] = 0;
}

void DestroyButton(unsigned int ID)
{
    PButton[ID] = 0;
}

int ButtonFocused(float x, float y, float z)
{
    for(unsigned int i = 0; i < CountOfPointers_Button; i++)
    {
        if(PButton[i])
        {
            if(x >= PButton[i]->x-PButton[i]->w/2 && y >= PButton[i]->y-PButton[i]->h/2)
            {
                if(x <= PButton[i]->x+PButton[i]->w/2 && y <= PButton[i]->y+PButton[i]->h/2)
                {
                    return i;
                }
            }
        }
    }
    return -1;
}
void DrawButtons()
{

    for(unsigned int i = 0; i < CountOfPointers_Button; i++)
    {
        if(PButton[i])
        {
            if(PButton[i]->Draw) CreateButton(*PButton[i]);
        }
    }
}
void CreateButton(SLIButton but)
{
    if(but.Draw)
    {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        float DeltaX = 400.0/but.w;
        float DeltaY = 400.0/but.h;
        glTranslatef(but.x-but.w/2, but.y-but.h/2, 0.0);
        glPushMatrix();
        glScalef(1/DeltaX, 1/DeltaY, 0.0);
        if(but.Focused) glColor3f(but.ActiveColor.red, but.ActiveColor.green, but.ActiveColor.blue);
        else glColor3f(but.PassiveColor.red, but.PassiveColor.green, but.PassiveColor.blue);
        glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(0, 400);
        glVertex2f(400, 400);
        glVertex2f(400, 0);
        glEnd();
        glPopMatrix();
        glTranslatef(but.w/2-glutStrokeLength(GLUT_STROKE_ROMAN, (unsigned char*)but.Text)/DeltaX/2, but.h/2-85/DeltaY/2, 0);
        glScalef(1/DeltaX*but.textSize, 1/DeltaY*but.textSize, 0.0);
        glColor3f(1.0, 1.0, 1.0);
        for(unsigned int i=0; i<strlen(but.Text); i++)
        {
            glutStrokeCharacter(GLUT_STROKE_ROMAN, but.Text[i]);
        }
        glPopMatrix();
    }
}

void ButtonFunc(unsigned int id)
{
    PButton[id]->func();
}
void Focus(unsigned int id)
{
    if(PButton[id])
    {
        PButton[id]->Focused = true;
    }
}

void UnFocus(unsigned int id)
{
    if(PButton[id])
    {
        PButton[id]->Focused = false;
    }
}

int GetButtonIDText(char* buttext)
{
    for(unsigned int i = 0; i < CountOfPointers_Button; i++)
    {
        if(PButton[i])
        {
            if(strcmp(buttext, PButton[i]->Text))
            {
                return i;
            }
        }
    }
    return 0;
}
SLIButton* GetButtonPointer(unsigned int id)
{
    return PButton[id];
}

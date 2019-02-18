#include "main.h"

void DrawCube()
{
    glColor3f(1.0, 1.0, 1.0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex.texture);
    glBegin(GL_POLYGON);
    glTexCoord3f(0, 0, 0); glVertex3f(5.0, -25.0, -25.0);
    glTexCoord3f(1, 0, 0); glVertex3f(5.0, -25.0, 25.0);
    glTexCoord3f(1, 1, 0); glVertex3f(5.0, 25.0, 25.0);
    glTexCoord3f(0, 1, 0); glVertex3f(5.0, 25.0, -25.0);
    glEnd();
    glBegin(GL_POLYGON);
    glTexCoord3f(0, 0, 0); glVertex3f(40.0, -25.0, -25.0);
    glTexCoord3f(1, 0, 0); glVertex3f(40.0, -25.0, 25.0);
    glTexCoord3f(1, 1, 0); glVertex3f(40.0, 25.0, 25.0);
    glTexCoord3f(0, 1, 0); glVertex3f(40.0, 25.0, -25.0);
    glEnd();
    glBegin(GL_POLYGON);
    glTexCoord3f(0, 0, 0); glVertex3f(5.0, -25.0, -25.0);
    glTexCoord3f(1, 0, 0); glVertex3f(40.0, -25.0, -25.0);
    glTexCoord3f(1, 1, 0); glVertex3f(40.0, 25.0, -25.0);
    glTexCoord3f(0, 1, 0); glVertex3f(5.0, 25.0, -25.0);
    glEnd();
    glBegin(GL_POLYGON);
    glTexCoord3f(0, 0, 0); glVertex3f(5.0, -25.0, 25.0);
    glTexCoord3f(1, 0, 0); glVertex3f(40.0, -25.0, 25.0);
    glTexCoord3f(1, 1, 0); glVertex3f(40.0, 25.0, 25.0);
    glTexCoord3f(0, 1, 0); glVertex3f(5.0, 25.0, 25.0);
    glEnd();
    glBegin(GL_POLYGON);
    glTexCoord3f(0, 0, 0); glVertex3f(5.0, 25.0, -25.0);
    glTexCoord3f(1, 0, 0); glVertex3f(40.0, 25.0, -25.0);
    glTexCoord3f(1, 1, 0); glVertex3f(40.0, 25.0, 25.0);
    glTexCoord3f(0, 1, 0); glVertex3f(5.0, 25.0, 25.0);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, Floor.texture);
    glBegin(GL_POLYGON);
    /*glTexCoord3d(1, 0, 1);*/glTexCoord2d(0, 0); glVertex3f(-100.0, 0.0, -100.0);
    /*glTexCoord3d(-1, 0, 1);*/ glTexCoord2d(20, 0); glVertex3f(100.0, 0.0, -100.0);
    /*glTexCoord3d(-1, 0, -1);*/ glTexCoord2d(20, 20); glVertex3f(100.0, 0.0, 100.0);
    /*glTexCoord3d(1, 0, -1);*/ glTexCoord2d(0, 20); glVertex3f(-100.0, 0.0, 100.0);
    glDisable(GL_TEXTURE_2D);
    glEnd();
}

void Refresh()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    cam.Draw();
    DrawCube();
    glFlush();
    glutSwapBuffers();
}

void Motion(int x, int y)
{
    int a = (x - Sets.width/2);
    int b = (y - Sets.height/2);
    if(a == 0 && b == 0) return;
    cam.MovebyAngle(a*movespeed, b*movespeed);
	printf("Delta = %f\n", cam._GetRangeBetweenPosAndDir());
}

void Mouse(int a, int state, int x, int y)
{

}

void FPS(int val)
{
    FPSmeter = 0;
    glutTimerFunc(1000, FPS, 0);
}

void Idle()
{
    FPSmeter++;
    glutWarpPointer(Sets.width/2, Sets.height/2);
    Refresh();
}

void Reshape(int width, int height)
{
    Sets.width = width;
    Sets.height = height;
    Refresh();
}

void Key(unsigned char key, int x, int y)
{
    if(key == 'w')
    {
        cam.MoveToMouseDirection(STRAIGHT, 0.5);
    }
    if(key == 'a')
    {
        cam.MoveToMouseDirection(LEFT, 0.5);
    }
    if(key == 'd')
    {
        cam.MoveToMouseDirection(RIGHT, 0.5);
    }
    if(key == 's')
    {
        cam.MoveToMouseDirection(BACK, 0.5);
    }
    if(key == 'r')
    {
    }
    if(key == 27)//esc
    {
        glutLeaveGameMode();
		exit(0);
    }
    if(key == 'g')
    {
        glutEnterGameMode();
    }
}

void _CreateWindow(Settings _new, void (*Dcallback)(void), void (*Rcallback)(int, int))
{
    glutInitDisplayMode(_new.DisplayMode);
    glutInitWindowPosition(_new.posx, _new.posy);
    glutInitWindowSize(_new.width, _new.height);
    glutCreateWindow(_new.WinName);
    glClearColor(Sets.ClearColor.red, Sets.ClearColor.green, Sets.ClearColor.blue, 0.0f);
    cam.OrthoAndPerspective(DEF_ORTHO, DEF_WIDTH, DEF_HEIGHT, 60.0);
	cam.Init(new Vector3(0.0, 2.0, 0.0), new Vector3(5.0, 2.0, 0.0), new Vector3(0.0, 1.0, 0.0));
    char buf[32];
    sprintf(buf, "%ix%i:%i@%i", DEF_WIDTH, DEF_HEIGHT, DEF_BITS, DEF_RATES);
    glutGameModeString("1920x1080:32");
    //glutEnterGameMode();
    glutDisplayFunc(Dcallback);
    glutReshapeFunc(Rcallback);
    glutMouseFunc(Mouse);
    glutPassiveMotionFunc(Motion);
    glutKeyboardFunc(Key);
    FPS(0);
    glutIdleFunc(Idle);
}

void InitDefault()
{
    Sets.ClearColor = DEF_CLEARCOLOR;
    Sets.DisplayMode = DEF_DISPLAYMODE;
    Sets.height = DEF_HEIGHT;
    Sets.posx = DEF_POSX;
    Sets.posy = DEF_POSY;
    Sets.width = DEF_WIDTH;
    Sets.WinName = (char*)(DEF_WINNAME);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    InitDefault();
    _CreateWindow(Sets, Refresh, Reshape);
    Floor.Set("floor.bmp");
    Floor.Load();
    Floor.Bind();
    tex.Set("s.bmp");
    tex.Load();
    tex.Bind();
    glutSetCursor(GLUT_CURSOR_NONE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, Light_pos);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Light_dir);
    glLightfv(GL_LIGHT0, GL_AMBIENT, Light_intensive);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_FRONT);
    glutMainLoop();
    return 0;
}

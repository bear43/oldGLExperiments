#ifndef CAMERA_H
#define CAMERA_H
#include "structs.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <vector>

#define STACK_OVERFLOW 1
#define STACK_SUCCESSFUL 0
#define STACK_ERROR 2

#define STRAIGHT 1
#define RIGHT 2
#define LEFT 3
#define BACK 4

#define NORMAL_SENTENSIVE 3.0

/* Stack */
/*  ortho
    aspect
    width
    height
    AngleOfPerspective
    pos[0]
    pos[1]
    pos[2]
    look[0]
    look[1]
    look[2]
    up[0]
    up[1]
    up[2]
    angle[0]
    angle[1]
*/
/* Stack */



const float PI = 3.141592653;
const unsigned int Stacksize = 16;


class SLICamera
{
    private:
    float angle[2];
    float ortho;
    float aspect;
    float width;
    float height;
    float AngleOfPerspective;//gluPerspective(angle, aspect, near, far)
    public:
	Vector3 Direction;
	Vector3 Position;
	Vector3 UP;
	void LookAt(Vector3 Pos, Vector3 Look, Vector3 _Up);
    void MovebyAngle(float alpha, float betta);//Двигает камеру, исходя из разности координат мыши x и y(Углы поворота angle и betta)
    void LookAt(Vector3 NewLookAtPosition);
    void Up(Vector3 NewUpPosition);
    void MoveToMouseDirection(int direction, float speed);//Двигает камеру по направлению мыши(по взгляду) вперед
    void Move(unsigned int direction, float stepsize);//Двигает камеру прямо, направо, налево, назад. stepsize - скорость шага или разность между начальными координатами и конечными
    void Draw();
    void Init(Vector3* CameraPosition, Vector3* LookAtPosition, Vector3* UpPosition);
    void OrthoAndPerspective(float distance, float w, float h, float perspectiveangle);
	float sentensive;
	Vector3 GetRangeBetweenPosAndDir();
	float _GetRangeBetweenPosAndDir();
};

#endif

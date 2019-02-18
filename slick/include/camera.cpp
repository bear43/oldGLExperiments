#include "camera.h"

Vector3 SLICamera::GetRangeBetweenPosAndDir()
{
	return Direction-Position;
}

float SLICamera::_GetRangeBetweenPosAndDir()
{
	Vector3 res = Direction-Position;
	return sqrt(pow(res.x, 2) + pow(res.y, 2) + pow(res.z, 2));
}


void SLICamera::MovebyAngle(float alpha, float betta)//Двигает камеру, исходя из разности координат мыши x и y
{
	angle[0] += alpha*sentensive;
	angle[1] += betta*sentensive;
    Direction.x=Position.x + cos(angle[0]*PI/180);
    Direction.y=Position.y - sin(angle[1]*PI/180);
    Direction.z=Position.z + sin(angle[0]*PI/180)*cos(angle[1]*PI/180);
}

void SLICamera::MoveToMouseDirection(int direction, float speed)
{
	Vector3 tmp = GetRangeBetweenPosAndDir();
    if(direction == STRAIGHT)
    {
		Position = Position + tmp*speed;
		Direction = Direction + tmp*speed;
    }
    if(direction == RIGHT)
    {
		tmp = tmp.VecMultiple(Vector3 (0.0, 1.0, 0.0));
		Position = Position + tmp*speed;
		Direction = Direction + tmp*speed;
    }
    if(direction == LEFT)
    {
		tmp = tmp.VecMultiple(Vector3 (0.0, 1.0, 0.0));
		Position = Position - tmp*speed;
		Direction = Direction - tmp*speed;
    }
    if(direction == BACK)
    {
		Position = Position - tmp*speed;
		Direction = Direction - tmp*speed;
    }
}

void SLICamera::LookAt(Vector3 NewLookAtPosition)
{
	Direction = NewLookAtPosition;
}

void SLICamera::Draw()
{
    if(angle[0] > 360.0) angle[0] = 0.0;
    if(angle[0] < -360.0) angle[0] = 0.0;
    if(angle[1] > 360.0) angle[1] = 0.0;
    if(angle[1] < -360.0) angle[1] = 0.0;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);
    glOrtho(-ortho, ortho, -ortho, ortho, -ortho, ortho);
    gluPerspective(AngleOfPerspective, width/height, -ortho, ortho);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	gluLookAt(Position.x, Position.y, Position.z, Direction.x, Direction.y, Direction.z, UP.x, UP.y, UP.z);
}

void SLICamera::Init(Vector3* CameraPosition, Vector3* LookAtPosition, Vector3* UpPosition)
{
	Position = *CameraPosition;
	Direction = *LookAtPosition;
	UP = *UpPosition;
	sentensive = NORMAL_SENTENSIVE;
}

void SLICamera::Up(Vector3 NewUpPosition)
{
	UP = NewUpPosition;
}

void SLICamera::OrthoAndPerspective(float distance, float w, float h, float perspectiveangle)
{
    ortho = distance;
    width = w;
    height = h;
    AngleOfPerspective = perspectiveangle*PI/180;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    glOrtho(-distance, distance, -distance, distance, -distance, distance);
	gluPerspective(AngleOfPerspective, w/h, -distance, distance);
    glMatrixMode(GL_MODELVIEW);
}



void SLICamera::Move(unsigned int direction, float stepsize)
{
}

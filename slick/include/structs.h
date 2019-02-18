#ifndef STRUCTS_H
#define STRUCTS_H
#include <GL/gl.h>
#include <GL/glu.h>
struct Coord
{
    float x;
    float y;
    float z;
};
struct Color
{
    float red;
    float green;
    float blue;
};
class Vector3
{
	public:
	Vector3();
	Vector3(float a, float b, float c);
	float x;
	float y;
	float z;
	Vector3 operator+(const Vector3& plus);
	Vector3 operator-(const Vector3& minus);
	Vector3 operator*(const Vector3& a);
	Vector3 operator*(const int& a);
	Vector3 operator*(const float& a);
	void operator=(const Vector3& a);
	Vector3 VecMultiple(Vector3 a);
};

Color Color3f(float r, float g, float b);
Coord WndCoordToWorld(int x, int y, int z);
#endif

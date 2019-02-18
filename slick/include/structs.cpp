#include "structs.h"
Color Color3f(float r, float g, float b)
{
    Color coltmp;
    coltmp.red = r;
    coltmp.green = g;
    coltmp.blue = b;
    return coltmp;
}

Coord WndCoordToWorld(int x, int y, int z)
{
    double rx = 0, ry = 0, rz = 0;
    double q[16];
    int w[3];
    double e[16];
    glGetDoublev(GL_PROJECTION_MATRIX, q);
    glGetIntegerv(GL_VIEWPORT, w);
    glGetDoublev(GL_MODELVIEW_MATRIX, e);
    gluUnProject((double)x, (double)y, (double)z, e, q, w, &rx, &ry, &rz);
    ry = 400 - ry;
    Coord ret;
    ret.x = (float)rx;
    ret.y = (float)ry;
    ret.z = (float)rz;
    return ret;
}

Vector3::Vector3()
{
}

Vector3::Vector3(float a, float b, float c)
{
	x = a;
	y = b;
	z = c;
}

Vector3 Vector3::operator+(const Vector3& plus)
{
	Vector3 res;
	res.x = Vector3::x + plus.x;
	res.y = Vector3::y + plus.y;
	res.z = Vector3::z + plus.z;
	return res;
}

Vector3 Vector3::operator-(const Vector3& minus)
{
	Vector3 res;
	res.x = Vector3::x - minus.x;
	res.y = Vector3::y - minus.y;
	res.z = Vector3::z - minus.z;
	return res;
}

Vector3 Vector3::operator*(const Vector3& a)
{
	Vector3 res;
	res.x = Vector3::x*a.x;
	res.y = Vector3::y*a.y;
	res.z = Vector3::z*a.z;
	return res;
}

Vector3 Vector3::operator*(const int& a)
{
	Vector3 res;
	res.x = Vector3::x*a;
	res.y = Vector3::y*a;
	res.z = Vector3::z*a;
	return res;
}

Vector3 Vector3::operator*(const float& a)
{
	Vector3 res;
	res.x = Vector3::x*a;
	res.y = Vector3::y*a;
	res.z = Vector3::z*a;
	return res;
}

void Vector3::operator=(const Vector3& a)
{
	this->x = a.x;
	this->y = a.y;
	this->z = a.z;
}

Vector3 Vector3::VecMultiple(Vector3 a)
{
    Vector3 result;
	result.x = Vector3::y*a.z - Vector3::z*a.y;
	result.y = Vector3::z*a.x - Vector3::x*a.z;
	result.z = Vector3::x*a.y - Vector3::y*a.x;
    return result;
/*	this->x = Vector3::y*a.z - Vector3::z*a.y;
	this->y = Vector3::z*a.x - Vector3::x*a.z;
	this->z = Vector3::x*a.y - Vector3::y*a.x;*/
}
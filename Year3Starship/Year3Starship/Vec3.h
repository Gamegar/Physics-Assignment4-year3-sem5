#ifndef VEC3_H
#define VEC3_H

class Vec3
{
public:
	float x, y, z;

	Vec3(float x_, float y_, float z_);
	Vec3();

	void SetZero();
};
#endif
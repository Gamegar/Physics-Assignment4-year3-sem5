#ifndef VEC3_H
#define VEC3_H

class Vec3
{
public:
	float x, y, z;

	Vec3(float x_, float y_, float z_);
	Vec3();

	void SetZero();

	inline Vec3& operator * (const Vec3& vec3)
	{
		x = x * vec3.x;
		y = y * vec3.y;
		z = z * vec3.z;

		Vec3 Answer = Vec3(x, y, z);
		return Answer;
	}
};
#endif
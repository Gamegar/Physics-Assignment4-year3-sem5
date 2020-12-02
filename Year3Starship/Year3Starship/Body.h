#ifndef BODY_H
#define BODY_H
#include "Vec3.h"


class Body
{
public:

	Vec3 velocityi;
	Vec3 position;
	Vec3 acceleration;
	Vec3 CenterMass;
	Vec3 velocityf;
	Vec3 VeccenMas;
	Vec3 LinerVel;
	Vec3 angularVeli;
	Vec3 angularVelf;
	Vec3 LinearImp;
	float mass;

	void Update(float timeStep);

	void LinearVelocity();

	Body(Vec3 acceleration_, Vec3 velocityi_, Vec3 centerMass_, Vec3 velocityf_, Vec3 VeccenMas_ , Vec3 angularVelf_, Vec3 LinerVel_, Vec3 LinearImp_, Vec3 angularVeli_,float mass_);
	Body(float mass_);
};

#endif 
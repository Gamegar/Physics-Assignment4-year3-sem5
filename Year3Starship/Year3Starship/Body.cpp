#include "Body.h"
#include <math.h>


Body::Body(Vec3 acceleration_, Vec3 velocityi_, Vec3 centerMass_, Vec3 velocityf_,Vec3 VeccenMas_, Vec3 angularVel_,
	Vec3 LinerVel_,  Vec3 LinearImp_, Vec3 angularVeli_,float mass_ )
{



}


Body::Body(float mass_)
{
	mass = mass_;
	
	position.SetZero();
	acceleration.SetZero();
	velocityi.SetZero();
	velocityf.SetZero();


}
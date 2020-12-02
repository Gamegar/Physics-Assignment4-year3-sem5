#include "Vec3.h"



Vec3::Vec3(float x_, float y_, float z_) {

	x = x_;
	y = y_;
	z = z_;

};
Vec3::Vec3() {


	SetZero();


}
//set everything to zero
void Vec3::SetZero() {


	x = 0.0;
	y = 0.0;
	z = 0.0;



};
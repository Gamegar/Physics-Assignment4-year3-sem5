#include"vec3.h"
#include <stdio.h>
#include <iostream>
#include "Body.h"
#include <math.h>
#include <fstream>


int main()
{
	Vec3 impact (-8,1,0);
	float Coef = 0.5;
	Vec3 NStation  (2 / 3, 1 / 3, 2 / 3);
	float mass, mose;
	Vec3  N(0.66,0.33,0.66);
	Vec3 ISS(20,40,20);
	Vec3 IAS(0.1, 0.1, 0.1);
	Vec3 RST(-10, 2, 0);
	Vec3 RAS(2, -1, 0);
	float VR;
	float J;

	Vec3  JRN1;
	Vec3 JRR1;
	Vec3 JRV1;
	
	Vec3 JRN2;
	Vec3 JRR2;
	Vec3 JRV2;
	float JN1;
	float JN2;

	//starship information
	Body StarStation(mass = 1000);
	StarStation.mass = 100;
	StarStation.CenterMass.x = 0;
	StarStation.CenterMass.y = 0;
	StarStation.CenterMass.z = 0;

	StarStation.velocityi.x = 0;
	StarStation.velocityi.y = 0;
	StarStation.velocityi.z = 0;



	//asteroid information
	Body Asteroid(mose = 1);
	Asteroid.velocityi.x = 20000;
	Asteroid.velocityi.y = 10000;
	Asteroid.velocityi.z = 20000;
	Asteroid.mass = 1;

	Asteroid.CenterMass.x = -10;
	Asteroid.CenterMass.y = 2;
	Asteroid.CenterMass.z = 0;

	Asteroid.VeccenMas.x =20000 ;


	Asteroid.LinerVel.x =  Asteroid.velocityi.x/1;
	Asteroid.LinerVel.y = Asteroid.velocityi.y / 1;
	Asteroid.LinerVel.z = Asteroid.velocityi.z / 1;

	Asteroid.LinearImp.x = 1 * Asteroid.velocityi.x;


	


	VR = ((N.x) * (Asteroid.velocityi.x)) + ((N.y) * (Asteroid.velocityi.y)) + ((N.z) * (Asteroid.velocityi.z));
	

	//find linear impulse


	//n.[I1(R1*n)*R1]
	JRN1.x = (((((RST.y*N.z) - (RST.z*N.y)))) );
	JRN1.y = (((((RST.x*N.z) - (RST.z*N.x)))) );
	JRN1.z = (((((RST.x*N.y) - (RST.y*N.x)))));

	JRR1.x = ((-ISS.y*JRN1.z) - (-ISS.z*JRN1.y));
	JRR1.y = ((-ISS.x*JRN1.z) - (-ISS.z*JRN1.x));
	JRR1.z = ((-ISS.x*JRN1.y) - (-ISS.y*JRN1.x));

	JRV1.x = ((JRR1.y*RST.z) - (JRR1.z*RST.y));
	JRV1.y = ((JRR1.x*RST.z) - (JRR1.z*RST.x));
	JRV1.z = ((JRR1.x*RST.y) - (JRR1.y*RST.x));

	JN1 = (N.x*JRV1.x) + (N.y*JRV1.y) + (N.z*JRV1.z) ;


	//n.[I2(R2*n)*R2]
	JRN2.x = (((((RAS.y*N.z) - (RAS.z*N.y)))));
	JRN2.y = (((((RAS.x*N.z) - (RAS.z*N.x)))));
	JRN2.z = (((((RAS.x*N.y) - (RAS.y*N.x)))));

	JRR2.x = ((-IAS.y*JRN2.z) - (-IAS.z*JRN2.y));
	JRR2.y = ((-IAS.x*JRN2.z) - (-IAS.z*JRN2.x));
	JRR2.z = ((-IAS.x*JRN2.y) - (-IAS.y*JRN2.x));

	JRV2.x = ((JRR2.y*RAS.z) - (JRR2.z*RAS.y));
	JRV2.y = ((JRR2.x*RAS.z) - (JRR2.z*RAS.x));
	JRV2.z = ((JRR2.x*RAS.y) - (JRR2.y*RAS.x));

	JN2 = (N.x*JRV2.x) + (N.y*JRV2.y) + (N.z*JRV2.z);


	//
	J = (VR*(Coef + 1)) / ((1 / StarStation.mass) + (1 / Asteroid.mass) + JN1 + JN2)   ;
std::cout << "J " <<J <<std::endl;
	// final calculations for Final velocity of space station
	StarStation.velocityf.x = StarStation.velocityi.x + (((J*N.x) + (J*N.y)  + (J * N.z)) / StarStation.mass);
	
	StarStation.velocityf.y = StarStation.velocityi.y + ( (J*N.y)  / StarStation.mass);
	StarStation.velocityf.z = StarStation.velocityi.z + (( J * N.z) / StarStation.mass);
	// final Calculations for Final angular rotation of Space station

	StarStation.angularVelf.x = StarStation.angularVeli.x +
		((-ISS.x*((RST.x*((J*(N.x)) + (J*(N.y)) + (J*N.z))) + (RST.y*((J*(N.x)) + (J*(N.y)) + (J*N.z))) + (RST.z*((J*(N.x)) + (J*(N.y)) + (J*N.z))))));
		 
	StarStation.angularVelf.y = StarStation.angularVeli.y + (-ISS.y*((RST.x*((J*(N.x)) + (J*(N.y)) + (J*N.z))) + (RST.y*((J*(N.x)) + (J*(N.y)) + (J*N.z)))
		+ (RST.z*((J*(N.x)) + (J*(N.y)) + (J*N.z)))));
		


			StarStation.angularVelf.z = StarStation.angularVeli.z +(-ISS.z*((RST.x*((J*(N.x)) + (J*(N.y)) + (J*N.z))))+ (RST.y*((J*(N.x)) + (J*(N.y)) + (J*N.z))) 
				+ (RST.z*((J*(N.x)) + (J*(N.y)) + (J*N.z))));



			std::cout <<  "velocity x " <<  StarStation.velocityf.x<< std::endl;
}
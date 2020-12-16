#include"vec3.h"
#include <stdio.h>
#include <iostream>
#include "Body.h"
#include <math.h>
#include <fstream>


int main()
{//impact point
	Vec3 impact(-8, 1, 0);
	//coefficient
	float Coef = 0.5;

	Vec3 NStation(2 / 3, 1 / 3, 2 / 3);
	float mass, mose;
	Vec3  N(0.66, 0.33, 0.66);

	//I Spaceship
	Vec3 ISS(20, 40, 20);
	//I Asteroid
	Vec3 IAS(0.1, 0.1, 0.1);
	//R spaceship
	Vec3 RST(-10, 2, 0);
	//R asteroid
	Vec3 RAS(2, -1, 0);

	float VR;
	float J;

	Vec3  JRN1;
	Vec3 JRR1;
	Vec3 JRV1;

	Vec3 JRN2;
	Vec3 JRR2;
	Vec3 JRV2;
	Vec3 V;


	float JN1;
	float JN2;

	//starship information
	Body StarStation(mass = 100);
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

	Asteroid.VeccenMas.x = 20000;


	Asteroid.LinerVel.x = Asteroid.velocityi.x / 1;
	Asteroid.LinerVel.y = Asteroid.velocityi.y / 1;
	Asteroid.LinerVel.z = Asteroid.velocityi.z / 1;

	Asteroid.LinearImp.x = 1 * Asteroid.velocityi.x;





	VR = ((N.x) * (Asteroid.velocityi.x)) + ((N.y) * (Asteroid.velocityi.y)) + ((N.z) * (Asteroid.velocityi.z));
	//VR = ((0.66) * (20000)) + ((0.33) * (10000) + ((0.66) * (20000)); 
	// VR = (13,200) + (3300) + (13,200); 
	//VR = 29,700; 
	//VR = n . (intitial vel 1 - intitial vel 2)

	//find linear impulse


	//n.[I1(R1*n)*R1]



	JRN1 = RST.operator*(N);


	JRR1 = ISS.operator*(JRN1);
	//[I1(R1*n)*R1]


	JRV1 = JRR1.operator*(RST);
	//n.[I1(R1*n)*R1]
	JN1 = (N.x*JRV1.x) + (N.y*JRV1.y) + (N.z*JRV1.z);
	//

	//n.[I2(R2*n)*R2]

	//R2*N
	//JRN2.x = (((((RAS.y*N.z) - (RAS.z*N.y)))));
	//JRN2.y = (((((RAS.x*N.z) - (RAS.z*N.x)))));
	//JRN2.z = (((((RAS.x*N.y) - (RAS.y*N.x)))));
	JRN2 = RAS.operator*(N);
	std::cout << "JRN2: " << JRN2.x << std::endl;
	std::cout << "JRN2: " << JRN2.y << std::endl;
	std::cout << "JRN2: " << JRN2.z << std::endl;
	//I2(R2*n)
	//JRR2.x = ((-IAS.y*JRN2.z) - (-IAS.z*JRN2.y));
	//JRR2.y = ((-IAS.x*JRN2.z) - (-IAS.z*JRN2.x));
	//JRR2.z = ((-IAS.x*JRN2.y) - (-IAS.y*JRN2.x));
	JRR2 = IAS.operator*(JRN2);
	//[I2(R2*n)*R2]
	//JRV2.x = ((JRR2.y*RAS.z) - (JRR2.z*RAS.y));
	//JRV2.y = ((JRR2.x*RAS.z) - (JRR2.z*RAS.x));
	//JRV2.z = ((JRR2.x*RAS.y) - (JRR2.y*RAS.x));
	JRV2 = JRR2.operator*(RAS);
	//n.[I2(R2*n)*R2]
	//Use Cross product.
	std::cout << "JRV2: " << JRV2.x << std::endl;
	std::cout << "JRV2: " << JRV2.y << std::endl;
	std::cout << "JRV2: " << JRV2.z << std::endl;

	JN2 = (N.x*JRV2.x) + (N.y*JRV2.y) + (N.z*JRV2.z);
	//JN2 = N.operator*(JRV2); 

	//J
	std::cout << "JN2: " << JN2 << std::endl;
	J = (VR*(Coef + 1)) / ((1 / StarStation.mass) + (1 / Asteroid.mass) + JN1 + JN2);
	//J = (44,550) / ((0.01) + (1) + JN1 + JN2); 

	std::cout << "J: " << J << std::endl;
	// final calculations for Final velocity of space station
	StarStation.velocityf.x = StarStation.velocityi.x + (((J*N.x) + (J*N.y) + (J * N.z)) / StarStation.mass);

	StarStation.velocityf.y = StarStation.velocityi.y + ((J*N.y) / StarStation.mass);
	StarStation.velocityf.z = StarStation.velocityi.z + ((J * N.z) / StarStation.mass);

	std::cout << "Final Velosity Of Space station: " << StarStation.velocityf.x
		<< " " << StarStation.velocityf.y << " " << StarStation.velocityf.z << std::endl;

	// final Calculations for Final angular rotation of Space station

	StarStation.angularVelf.x = StarStation.angularVeli.x +
		((-ISS.x*((RST.x*((J*(N.x)) + (J*(N.y)) + (J*N.z))) + (RST.y*((J*(N.x)) + (J*(N.y)) + (J*N.z))) + (RST.z*((J*(N.x)) + (J*(N.y)) + (J*N.z))))));

	StarStation.angularVelf.y = StarStation.angularVeli.y + (-ISS.y*((RST.x*((J*(N.x)) + (J*(N.y)) + (J*N.z))) + (RST.y*((J*(N.x)) + (J*(N.y)) + (J*N.z)))
		+ (RST.z*((J*(N.x)) + (J*(N.y)) + (J*N.z)))));



	StarStation.angularVelf.z = StarStation.angularVeli.z + (-ISS.z*((RST.x*((J*(N.x)) + (J*(N.y)) + (J*N.z)))) + (RST.y*((J*(N.x)) + (J*(N.y)) + (J*N.z)))
		+ (RST.z*((J*(N.x)) + (J*(N.y)) + (J*N.z))));



	std::cout << "Final Angular Velosity: " << StarStation.angularVelf.x <<
		" " << StarStation.angularVelf.y << " " << StarStation.angularVelf.z << std::endl;
}
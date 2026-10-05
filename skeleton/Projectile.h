#pragma once
#include "Particle.h"
#include <cmath>
class Projectile : public Particle
{
public:
	Projectile(float Mass, float Speed, float SimSpeed, float Gravity, Vector3D Pos, Vector3D Dir, float Damp);

	void changeMass(float Mass);
	void changeGrav(float Grav);

protected:

private:
	float realMass;
	float realSpeed;
	float simSpeed;
	float realGravity;

	void updateSimulationParameters();
};


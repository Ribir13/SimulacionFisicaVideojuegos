#pragma once
#include "Particle.h"
#include <cmath>
class Projectile : public Particle
{
public:
	Projectile(float Mass, float Speed, float SimSpeed, float Gravity, Vector3D Pos, Vector3D Dir, float Damp,
		float time = 5.0f, ParticleShape ps = ParticleShape::Sphere, Vector4 Color = Vector4(1.0f, 1.0f, 1.0f, 1.0f), float Scale = 2.0f);

	void changeMass(float Mass);
	void changeGrav(float Grav);

protected:

private:
	float realMass;
	float realSpeed;
	float simSpeed;
	float realGravity;

	void updateParam();
};


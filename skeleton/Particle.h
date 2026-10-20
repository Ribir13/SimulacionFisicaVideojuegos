#pragma once

#include "Vector3D.h"
#include "PxPhysics.h"
#include "RenderUtils.hpp"

class Particle
{
public:
	enum ParticleShape {
		Sphere, Square
	};
	Particle(float Mass, float Gravity, Vector3D Pos, Vector3D Vel, Vector3D Acc, float Damp, float Time = 5,
		ParticleShape ps = ParticleShape::Sphere, Vector4 Color = Vector4(1.0f, 1.0f, 1.0f, 1.0f), float Scale = 2.0f);
	~Particle();

	void integrate(double t);
	void integrateSemi(double t);

	bool isDead();
	void updateLife(double dt);

protected:
	float mass;
	float gravity;
	Vector3D acc;
	Vector3D vel;
	physx::PxTransform pose;
	RenderItem* renderItem;

	Vector3D prevPos;
	bool pp = false;

	float damp;

	float timeToLive;

	float spawnAccumulator = 0.0f;
};


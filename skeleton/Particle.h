#pragma once

#include "Vector3D.h"
#include "PxPhysics.h"
#include "RenderUtils.hpp"

class Particle
{
public:
	Particle(float Mass, float Gravity, Vector3D Pos, Vector3D Vel, Vector3D Acc, float Damp);
	~Particle();

	void integrate(double t);
	void integrateSemi(double t);

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
};


#pragma once

#include "Vector3D.h"
#include "PxPhysics.h"
#include "RenderUtils.hpp"

class Particle
{
public:
	Particle(Vector3D Pos, Vector3D Vel, Vector3D Acc);
	~Particle();

	void integrate(double t);

private:
	Vector3D acc;
	Vector3D vel;
	physx::PxTransform pose;
	RenderItem* renderItem;
};


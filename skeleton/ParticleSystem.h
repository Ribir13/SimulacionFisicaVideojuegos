#pragma once

#include "ParticleGenerator.h"

class ParticleSystem
{
public:
	ParticleSystem();
	~ParticleSystem();

	void update(double dt);

	void addGen(float SpawnTime, Vector3D Vel, Vector3D Pos, float LifeTime,
		ParticleGenerator::TYPE type = ParticleGenerator::POINT, float Spread = 5.3f, float Radius = 1.0f);
private:
	std::vector<ParticleGenerator*> partGens;
};


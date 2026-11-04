#pragma once

#include "ParticleGenerator.h"
#include "ForceGenerator.h"
#include "ForceGravity.h"

class ParticleSystem
{
public:
	ParticleSystem();
	~ParticleSystem();

	void update(double dt);
	

	ParticleGenerator* addGen(float SpawnTime, Vector3D Vel, Vector3D Pos, float LifeTime,
		ParticleGenerator::TYPE type = ParticleGenerator::POINT, float Spread = 5.3f, float Radius = 1.0f);

	void addGravGen(float GR, ParticleGenerator* pg);
	void addGravGenToAll(float GR, ParticleGenerator* pg);
private:
	std::vector<ParticleGenerator*> partGens;
	std::vector<ForceGenerator*> forceGens;
};


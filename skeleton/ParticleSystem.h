#pragma once

#include "ParticleGenerator.h"
#include "ForceGenerator.h"
#include "ForceGravity.h"
#include "ForceWind.h"

class ParticleSystem
{
public:
	ParticleSystem();
	~ParticleSystem();

	void update(double dt);
	

	ParticleGenerator* addGen(float SpawnTime, Vector3D Vel, Vector3D Pos, float LifeTime,
		ParticleGenerator::TYPE type = ParticleGenerator::POINT, float Spread = 5.3f, float Radius = 1.0f);

	void addGravGen(float GR, ParticleGenerator* pg);
	void addGravGenToAll(float GR);

	void addWindGenToAll(Vector3D V1, Vector3D V2, Vector3D V3, Vector3D V, float K1);
private:
	std::vector<ParticleGenerator*> partGens;
	std::vector<ForceGenerator*> forceGens;
};


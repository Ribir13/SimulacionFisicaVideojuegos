#pragma once

#include "ParticleGenerator.h"
#include "ForceGenerator.h"
#include "ForceGravity.h"
#include "ForceWind.h"
#include "ForceTornado.h"
#include "ForceExplosion.h"

class ParticleSystem
{
public:
	ParticleSystem();
	~ParticleSystem();

	void update(double dt);
	

	ParticleGenerator* addGen(float SpawnTime, Vector3D Vel, Vector3D Pos, float LifeTime,
		ParticleGenerator::TYPE type = ParticleGenerator::POINT, float Spread = 5.3f, float Radius = 1.0f, float Mass = 1.0f);

	void addGravGen(float GR, ParticleGenerator* pg);
	void addGravGenToAll(float GR);

	void addWindGenToAll(Vector3D Center, float Anc, float Alt, Vector3D V, float K1);
	void addTornadoGenToAll(float K, Vector3D Center, float Anc, float Alt, float K1);
	void addExplGenToAll(Vector3D Center, float R, float K, float Dur);

	void toogleForces();
private:
	std::vector<ParticleGenerator*> partGens;
	std::vector<ForceGenerator*> forceGens;
};


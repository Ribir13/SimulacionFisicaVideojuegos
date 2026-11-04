#include "ParticleSystem.h"


ParticleSystem::ParticleSystem() {

}

ParticleSystem::~ParticleSystem() {
    for (auto* p : partGens) {
        delete p;
    }
    partGens.clear();


    for (auto* f : forceGens) {
        delete f;
    }
    forceGens.clear();
}

void ParticleSystem::update(double dt) {
    for (auto it = partGens.begin(); it != partGens.end(); ++it) {
        ParticleGenerator* p = *it;
        p->update(dt);
    }
}

ParticleGenerator* ParticleSystem::addGen(float SpawnTime, Vector3D Vel, Vector3D Pos, float LifeTime,
    ParticleGenerator::TYPE type, float Spread, float Radius) {
    ParticleGenerator* pg = new ParticleGenerator(SpawnTime, Vel, Pos, LifeTime, type, Spread, Radius);

    partGens.push_back(pg);
    return pg;
}

void ParticleSystem::addGravGen(float GR, ParticleGenerator* pg) {
    ForceGravity* fg = new ForceGravity(GR);
    forceGens.push_back(fg);
    pg->addForceGenerator(fg);
}

void ParticleSystem::addGravGenToAll(float GR) {
    ForceGravity* fg = new ForceGravity(GR);
    forceGens.push_back(fg);
    for (auto it = partGens.begin(); it != partGens.end(); it++) {
        (*it)->addForceGenerator(fg);
    }
}

void ParticleSystem::addWindGenToAll(Vector3D V1, Vector3D V2, Vector3D V3, Vector3D V, float K1)
{
    ForceWind* fw = new ForceWind(V1, V2, V3, V, K1);
    forceGens.push_back(fw);
    for (auto it = partGens.begin(); it != partGens.end(); it++){
        (*it)->addForceGenerator(fw);
    }
}
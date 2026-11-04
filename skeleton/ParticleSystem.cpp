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

void ParticleSystem::addGravGenToAll(float GR, ParticleGenerator* pg) {
    ForceGravity* fg = new ForceGravity(GR);
    forceGens.push_back(fg);
    for (auto it = partGens.begin(); it != partGens.end(); it++) {
        (*it)->addForceGenerator(fg);
    }
}
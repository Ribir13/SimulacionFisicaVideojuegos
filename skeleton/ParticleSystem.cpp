#include "ParticleSystem.h"


ParticleSystem::ParticleSystem() {

}

ParticleSystem::~ParticleSystem() {
    for (auto* p : partGens) {
        delete p;
    }
    partGens.clear();
}

void ParticleSystem::update(double dt) {
    for (auto it = partGens.begin(); it != partGens.end(); ++it) {
        ParticleGenerator* p = *it;
        p->update(dt);
    }
}

void ParticleSystem::addGen(float SpawnTime, Vector3D Vel, Vector3D Pos, float LifeTime,
    ParticleGenerator::TYPE type, float Spread, float Radius) {
    ParticleGenerator* pg = new ParticleGenerator(SpawnTime, Vel, Pos, LifeTime, type, Spread, Radius);

    partGens.push_back(pg);
}
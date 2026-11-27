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
    for (auto it = forceGens.begin(); it != forceGens.end();) {
        (*it)->update(dt);
        if ((*it)->isFinished()) {
            for (ParticleGenerator* pg : partGens) {
                pg->removeFG(*it);
            }
            delete* it;
            it = forceGens.erase(it);
        }
        else {
            ++it;
        }
    }
    for (auto it = partGens.begin(); it != partGens.end(); ++it) {
        ParticleGenerator* p = *it;
        p->update(dt);
    }
}

ParticleGenerator* ParticleSystem::addGen(float SpawnTime, Vector3D Vel, Vector3D Pos, float LifeTime,
    ParticleGenerator::TYPE type, float Spread, float Radius, float Mass) {
    ParticleGenerator* pg = new ParticleGenerator(SpawnTime, Vel, Pos, LifeTime, type, Spread, Radius, Mass);

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

void ParticleSystem::addWindGenToAll(Vector3D Center, float anc, float alt, Vector3D V, float K1)
{
    ForceWind* fw = new ForceWind(Center, anc, alt, V, K1);
    forceGens.push_back(fw);
    for (auto it = partGens.begin(); it != partGens.end(); it++) {
        (*it)->addForceGenerator(fw);
    }
}

void ParticleSystem::addTornadoGenToAll(float K, Vector3D Center, float Anc, float Alt, float K1)
{
    ForceTornado* ft = new ForceTornado(K, Center, Anc, Alt, K1);
    forceGens.push_back(ft);
    for (auto it = partGens.begin(); it != partGens.end(); it++) {
        (*it)->addForceGenerator(ft);
    }
}

void ParticleSystem::addExplGenToAll(Vector3D Center, float R, float K, float Dur)
{
    ForceExplosion* ft = new ForceExplosion(Center, R, K, Dur);
    forceGens.push_back(ft);
    for (auto it = partGens.begin(); it != partGens.end(); it++) {
        (*it)->addForceGenerator(ft);
    }
}

void ParticleSystem::addSpringGenBetweenTwo(double k, double resting_length, Particle* first, Particle* second)
{
    SpringForceGenerator* ft = new SpringForceGenerator(k, resting_length, first);
    forceGens.push_back(ft);
    for (auto it = partGens.begin(); it != partGens.end(); it++) {
        (*it)->addForceGenerator(ft);
    }
}

void ParticleSystem::toogleForces() {
    for (ForceGenerator* fg : forceGens) {
        fg->setActive(!fg->getActive());
    }
}
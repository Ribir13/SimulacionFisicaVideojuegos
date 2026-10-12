#include "ParticleSystem.h"
#include <algorithm>
#include <cmath>
#include <iostream>

ParticleSystem::ParticleSystem(float SpawnTime, Vector3D Vel, Vector3D Dir, Vector3D Pos, float LifeTime,
    TYPE type, float Spread, float Radius) :
    spawnTime(SpawnTime), vel(Vel), dir(Dir.normalize()), pos(Pos), lifeTime(LifeTime),
     type(type), spread(spread), radius(radius), m_engine(std::random_device{}()), distribution(0.0f, 1.0f) {

}

ParticleSystem::~ParticleSystem() {
    for (auto* p : particles) {
        delete p;
    }
    particles.clear();
}

void ParticleSystem::update(double dt) {
    timer += static_cast<float>(dt);

    if (timer >= spawnTime) {
        timer = 0.0f;
        newParticle();
    }

    for (auto it = particles.begin(); it != particles.end(); ) {
        Particle* p = *it;

        p->integrateSemi(dt);
        p->updateLife(dt);

        if (p->isDead()) {
            std::cout << "Borrando particula" << std::endl;
            delete p;
            it = particles.erase(it);
        }
        else {
            ++it;
        }
    }
}

void ParticleSystem::newParticle() {
    std::cout << "Creando particula" << std::endl;
    Vector3D pPos = pos;
    Vector3D pVel = vel;

    float x = distribution(m_engine);
    float y = distribution(m_engine);
    float z = distribution(m_engine);

    switch (type) {
    case POINT:
        pVel.x += x * spread;
        pVel.y += y * spread;
        pVel.z += z * spread;
        break;
    case CONE:
        break;
    }

    Particle* p = new Particle(1.0f, -10.0f, pPos, pVel, Vector3D(0.0f, 0.0f, 0.0f), 0.98f, lifeTime);
    particles.push_back(p);
}
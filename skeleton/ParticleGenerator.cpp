#include "ParticleGenerator.h"
#include <algorithm>
#include <cmath>
#include <iostream>

ParticleGenerator::ParticleGenerator(float SpawnTime, Vector3D Vel, Vector3D Pos, float LifeTime,
    TYPE type, float Spread, float Radius) :
    spawnTime(SpawnTime), vel(Vel), pos(Pos), lifeTime(LifeTime),
     type(type), spread(Spread), radius(Radius), m_engine(std::random_device{}()), uniformDist(-1.0f, 1.0f), gaussDist(0.0f, 1.0f) {
    typedist = TYPEDIST::GAUSS;
    scaling = false;
}

ParticleGenerator::~ParticleGenerator() {
    for (auto* p : particles) {
        delete p;
    }
    particles.clear();
    forceGens.clear();
}

void ParticleGenerator::update(double dt) {
    timer += static_cast<float>(dt);

    if (timer >= spawnTime) {
        timer = 0.0f;
        newParticle();
    }

    for (auto it = particles.begin(); it != particles.end(); ) {
        Particle* p = *it;

        p->resetForce();
        for (auto* fg : forceGens) {
            fg->updateForce(p, dt);
        }
        p->integrateSemi(dt);
        p->updateLife(dt);

        if (p->isDead()) {
            delete p;
            it = particles.erase(it);
        }
        else {
            ++it;
        }
        if (scaling) {
            p->updateScale();
        }
    }
}

void ParticleGenerator::newParticle() {
    Vector3D pPos = pos;
    Vector3D pVel = vel;

    float x = randVal(-1.0f, 1.0f);
    float y = randVal(-1.0f, 1.0f);
    float z = randVal(-1.0f, 1.0f);

    switch (type) {
    case POINT:
        pVel.x += x * spread;
        pVel.y += y * spread;
        pVel.z += z * spread;
        break;
    case CONE:
        break;
    }

    Particle* p = new Particle(1.0f, pPos, pVel, Vector3D(0.0f, 0.0f, 0.0f), 0.98f, lifeTime, shape, color, scale);
    particles.push_back(p);
}

float ParticleGenerator::randVal(float min, float max) {
    switch (typedist) {
    case UNI:
        return uniformDist(m_engine);

    case GAUSS:
        return gaussDist(m_engine);
    }
}

void ParticleGenerator::custom(Particle::ParticleShape Shape, Vector4 Color, float Scale)
{
    shape = Shape;
    color = Color;
    scale = Scale;
}
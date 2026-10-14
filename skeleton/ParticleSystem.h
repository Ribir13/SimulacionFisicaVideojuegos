#pragma once

#include "Particle.h"
#include <vector>
#include <random>

class ParticleSystem
{
public:
    enum TYPE {
        POINT,
        CONE
    };

    ParticleSystem(float SpawnTime, Vector3D Vel, Vector3D Pos, float LifeTime,
        TYPE type = POINT, float Spread = 5.3f, float Radius = 1.0f); //variables opcionales para sphere y cone.
    ~ParticleSystem();

    void update(double dt);
    void newParticle();

private:
    std::vector<Particle*> particles;

    float spawnTime;
    Vector3D vel;
    Vector3D pos;
    float lifeTime;

    TYPE type;
    float spread;
    float radius;

    float timer = 0.0f;

    std::mt19937 m_engine;
    std::normal_distribution<float> distribution;

};

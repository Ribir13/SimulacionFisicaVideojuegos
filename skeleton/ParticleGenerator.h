#pragma once

#include "Particle.h"
#include <vector>
#include <random>
#include "ForceGravity.h"

class ParticleGenerator
{
public:
    enum TYPE {
        POINT,
        CONE
    };

    enum TYPEDIST {
        UNI,
        GAUSS
    };

    ParticleGenerator(float SpawnTime, Vector3D Vel, Vector3D Pos, float LifeTime,
        TYPE type = POINT, float Spread = 5.3f, float Radius = 1.0f); //variables opcionales para cone.
    ~ParticleGenerator();

    void update(double dt, std::vector<ForceGenerator*>& forceGens);
    void newParticle();
    void setDist(TYPEDIST t) { typedist = t; };
    void applyForces(std::vector<ForceGenerator*>& forceGens, double dt);
    void integrateParticles(double dt);

    std::vector<Particle*>& getParticles() { return particles; }
private:
    std::vector<Particle*> particles;

    float spawnTime;
    Vector3D vel;
    Vector3D pos;
    float lifeTime;

    TYPE type;
    TYPEDIST typedist;
    float spread;
    float radius;

    float timer = 0.0f;

    std::mt19937 m_engine;
    std::uniform_real_distribution<float> uniformDist;
    std::normal_distribution<float> gaussDist;

    float randVal(float min, float max);
};

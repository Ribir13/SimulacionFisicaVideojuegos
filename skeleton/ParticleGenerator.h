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

    void update(double dt);
    void newParticle();
    void setDist(TYPEDIST t) { typedist = t; };
    void addForceGenerator(ForceGenerator* fg) {forceGens.push_back(fg);}
    void integrateParticles(double dt);

    void custom(Particle::ParticleShape Shape, Vector4 Color, float Scale = 2.0f);
    void setScaling(bool s) { scaling = s; }
    void setRandColor(bool s) { randColor = s; }

    void removeFG(ForceGenerator* fg);
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

    bool scaling;
    bool randColor;

    float timer = 0.0f;

    std::mt19937 m_engine;
    std::uniform_real_distribution<float> uniformDist;
    std::normal_distribution<float> gaussDist;

    float randVal(float min, float max);

    std::vector<ForceGenerator*> forceGens;

    Particle::ParticleShape shape = Particle::ParticleShape::Sphere;
    Vector4 color = Vector4(1, 1, 1, 1);
    float scale = 2.0f;
};
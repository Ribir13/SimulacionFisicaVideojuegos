#pragma once
#include "ForceGenerator.h"

class ForceExplosion : public ForceGenerator {
public:
    ForceExplosion(Vector3D Center, float R, float K, float Dur);
    void updateForce(Particle* p, double dt) override;
    void update(double dt) override;
private:
    Vector3D center;
    float radius, k, dur;
    double t = 0.0;
};
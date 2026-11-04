#pragma once
#include "ForceGenerator.h"

class ForceWind :
    public ForceGenerator
{
public:
    ForceWind(Vector3D Center, float anc, float alt, Vector3D V, float K1 = 0.8f);
    void updateForce(Particle* p, double dt) override;

protected:
    Vector3D v;
    float k1, k2 = 0;

    Vector3D center;
    float anc, alt;

    bool inside(Vector3D pos);
};


#pragma once
#include "ForceGenerator.h"

class ForceWind :
    public ForceGenerator
{
public:
    ForceWind(Vector3D V1, Vector3D V2, Vector3D V3, Vector3D V, float K1 = 0.8f);

    void updateForce(Particle* p, double dt) override;

private:
    Vector3D v1, v2, v3;
    Vector3D v;
    float k1, k2 = 0;

    bool inside(Vector3D pos);
};


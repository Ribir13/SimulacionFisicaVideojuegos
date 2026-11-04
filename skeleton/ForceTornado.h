#pragma once
#include "ForceWind.h"

class ForceTornado :
    public ForceWind
{
public:
    ForceTornado(float K, Vector3D Center, float Anc, float Alt, float K1 = 0.8f);
    void updateForce(Particle* p, double dt) override;
private:
    float k; //strength
};


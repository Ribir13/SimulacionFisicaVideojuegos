#pragma once

#include "ForceGenerator.h"

class ForceGravity :
    public ForceGenerator
{
public:
    ForceGravity(float Gr) ;
    void updateForce(Particle* p, double dt) override;
private:
    float gr;
};


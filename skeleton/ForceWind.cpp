#include "ForceWind.h"

ForceWind::ForceWind(Vector3D V1, Vector3D V2, Vector3D V3, Vector3D V, float K1 )
    : v1(V1), v2(V2), v3(V3), v(V), k1(K1) {
}

bool ForceWind::inside(Vector3D pos)
{
    return (pos.x >= v1.x && pos.x <= v3.x &&
            pos.y >= v1.y && pos.y <= v3.y &&
            pos.z >= v1.z && pos.z <= v2.z);
}

void ForceWind::updateForce(Particle* p, double dt)
{
    Vector3D pos = p->getPosition();
    if (inside(pos)){
        Vector3D force = (v - p->getVelocity()) * k1 + (v - p->getVelocity()) * (v- p->getVelocity()).magnitude() * k2;
        p->addForce(force);
    }
}
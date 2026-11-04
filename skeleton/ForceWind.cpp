#include "ForceWind.h"

ForceWind::ForceWind(Vector3D Center, float anc, float alt, Vector3D V, float K1) 
    : center(Center), anc(anc), alt(alt), v(V), k1(K1) {
}

bool ForceWind::inside(Vector3D pos)
{
    return (pos.x >= center.x - (anc / 2.0f) && pos.x <= center.x + (anc / 2.0f) &&
            pos.y >= center.y && pos.y <= center.y + alt &&
            pos.z >= center.z - (anc / 2.0f) && pos.z <= center.z + (anc / 2.0f));
}

void ForceWind::updateForce(Particle* p, double dt)
{
    if (active) {
        Vector3D pos = p->getPosition();
        if (inside(pos)) {
            Vector3D force = (v - p->getVelocity()) * k1 + (v - p->getVelocity()) * (v - p->getVelocity()).magnitude() * k2;
            p->addForce(force);
        }
    }
}
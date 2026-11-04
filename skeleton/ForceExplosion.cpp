#include "ForceExplosion.h"
#include <cmath>

ForceExplosion::ForceExplosion(Vector3D Center, float R, float K, float Tau)
    : center(Center), radius(R), k(K), dur(Tau) {
}

void ForceExplosion::update(double dt) {
    t += dt;
}

void ForceExplosion::updateForce(Particle* p, double dt) {
    if (active) {
        Vector3D pos = p->getPosition();
        float r = sqrt(pow(pos.x - center.x, 2) + pow(pos.y - center.y, 2) + pow(pos.z - center.z, 2));
        if (r < radius && dur > 0.0f && r != 0.0f) {
            Vector3D force = (pos - center) * (k / pow(r, 2)) * exp(-t / dur);
            p->addForce(force);
        }
        else {
            p->addForce(Vector3D(0, 0, 0));
        }
    }
}
#include "ForceTornado.h"

ForceTornado::ForceTornado(float K, Vector3D Center, float Anc, float Alt, float K1)
    : ForceWind(Center, Anc, Alt, Vector3D(0,0,0), K1), k(K) {
}

void ForceTornado::updateForce(Particle* p, double dt) {
    Vector3D pos = p->getPosition();
    if (inside(pos)) {
        v = (Vector3D(-(pos.z - center.z), 50 - (pos.y - center.y), pos.x - center.x)) * k;
        ForceWind::updateForce(p, dt);
    }
}
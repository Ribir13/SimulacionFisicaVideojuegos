#include "ForceGravity.h"

ForceGravity::ForceGravity(float Gr): gr(Gr) {

}

void ForceGravity::updateForce(Particle* p, double dt) {
    p->addForce(Vector3D(0.0f, gr, 0.0f));
}
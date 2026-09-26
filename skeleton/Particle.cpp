#include "Particle.h"

#include <cmath>

Particle::Particle(Vector3D Pos, Vector3D Vel, Vector3D Acc, float Damp) {
    pose = physx::PxTransform(Pos.operator physx::PxVec3());
    vel = Vel;
    acc = Acc;
    damp = Damp;

    physx::PxShape* esfera = CreateShape(physx::PxSphereGeometry(2.0f));
    renderItem = new RenderItem(esfera, &pose, Vector4(0.0f, 0.0f, 1.0f, 1.0f));
}

Particle::~Particle() {
    delete renderItem;
    renderItem = nullptr;
}

void Particle::integrate(double t)
{
    vel = (vel + acc * t) * pow(damp, t);
    pose.p = pose.p + vel.operator physx::PxVec3() * t;
}
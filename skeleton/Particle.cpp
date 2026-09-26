#include "Particle.h"

Particle::Particle(Vector3D Pos, Vector3D Vel) {
    pose = physx::PxTransform(Pos.operator physx::PxVec3());
    vel = Vel;

    physx::PxShape* esfera = CreateShape(physx::PxSphereGeometry(2.0f));
    renderItem = new RenderItem(esfera, &pose, Vector4(0.0f, 0.0f, 1.0f, 1.0f));
}

Particle::~Particle() {
    delete renderItem;
    renderItem = nullptr;
}

void Particle::integrate(double t)
{
    pose.p = pose.p + vel.operator physx::PxVec3() * t;
}
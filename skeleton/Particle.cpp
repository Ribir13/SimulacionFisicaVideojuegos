#include "Particle.h"

#include <cmath>

Particle::Particle(Vector3D Pos, Vector3D Vel, Vector3D Acc, float Damp) {
    pose = physx::PxTransform(Pos.operator physx::PxVec3());
    vel = Vel;
    acc = Acc;
    damp = Damp;

    Vector3D initialVel = (vel + acc * gFixedTimestep) * pow(damp, gFixedTimestep);
    prevPos = Pos - initialVel * gFixedTimestep;

    physx::PxShape* esfera = CreateShape(physx::PxSphereGeometry(2.0f));
    renderItem = new RenderItem(esfera, &pose, Vector4(0.0f, 0.0f, 1.0f, 1.0f));
}

Particle::~Particle() {
    delete renderItem;
    renderItem = nullptr;
}

void Particle::integrateSemi(double t)
{
    vel = (vel + acc * t) * pow(damp, t);
    pose.p = pose.p + vel.operator physx::PxVec3() * t;
}

void Particle::integrate(double t)
{
    Vector3D currPos = pose.p;
    pose.p = pose.p * 2.0 - prevPos + acc * pow(t, 2);
    prevPos = currPos;
}
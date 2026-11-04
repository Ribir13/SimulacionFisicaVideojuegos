#include "Particle.h"

#include <cmath>

Particle::Particle(float Mass, Vector3D Pos, Vector3D Vel, Vector3D Acc, float Damp, float Time, ParticleShape ps, Vector4 Color, float Scale) {
    pose = physx::PxTransform(Pos.operator physx::PxVec3());
    mass = Mass;
    vel = Vel;
    acc = Acc;
    damp = Damp;
    timeToLive = Time;
    iniTimeToLive = Time;
    iniScale = Scale;

    physx::PxShape* shape;

    if (ps == ParticleShape::Sphere) {
        shape = CreateShape(physx::PxSphereGeometry(Scale));
    }
    else if (ps == ParticleShape::Square) {
        shape = CreateShape(physx::PxBoxGeometry(Scale, Scale, Scale));
    }

    renderItem = new RenderItem(shape, &pose, Color);
    renderItem->scale = Scale;
}

Particle::~Particle() {
    if (renderItem != nullptr) {
        renderItem->release();
        renderItem = nullptr;
    }
}

void Particle::integrateSemi(double t)
{
    Vector3D p = pose.p;
    prevPos = p;

    vel = (vel + acc * t) * pow(damp, t);

    pose.p = pose.p + vel.operator physx::PxVec3() * t;

    pp = true;
}

void Particle::integrate(double t) {
    if (!pp) {
        integrateSemi(t);
    }
    else {
        Vector3D currPos = pose.p;
        pose.p = pose.p * 2.0 - prevPos + acc * pow(t, 2);
        prevPos = currPos;
    }
}

//(notas) getCamera Camera 1cam = getCamera()
// getDic() devuelve el vetor direccion de la camara, ha que normmalizarlo.

bool Particle::isDead() {
    return timeToLive <= 0.0f;
}

void Particle::updateLife(double dt) {
    timeToLive -= static_cast<float>(dt);
}

void Particle::addForce(Vector3D force) {
    acc += force / mass;
}

void Particle::resetForce() {
    acc = Vector3D(0.0f, 0.0f, 0.0f);
}

void Particle::custom(ParticleShape ps, Vector4 Color, float Scale)
{
    physx::PxShape* shape;
    if (ps == ParticleShape::Sphere) {
        shape = CreateShape(physx::PxSphereGeometry(Scale));
    }
    else if (ps == ParticleShape::Square) {
        shape = CreateShape(physx::PxBoxGeometry(Scale, Scale, Scale));
    }
    shape->acquireReference();
    renderItem->shape->release();
    renderItem->shape = shape;
    renderItem->color = Color;
}

void Particle::updateScale() {
    if (!isDead()) {
        renderItem->scale = iniScale * (timeToLive / iniTimeToLive);
    }
}
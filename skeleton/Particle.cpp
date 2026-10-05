#include "Particle.h"

#include <cmath>

Particle::Particle(float Mass, float Gravity, Vector3D Pos, Vector3D Vel, Vector3D Acc, float Damp) {
    pose = physx::PxTransform(Pos.operator physx::PxVec3());
    mass = Mass;
    gravity = Gravity;
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

void Particle::integrateSemi(double t)
{
    Vector3D p = pose.p;
    prevPos = p;

    Vector3D gravityAcc(0.0f, gravity, 0.0f);

    Vector3D actualAcc = acc + gravityAcc;

    vel = (vel + actualAcc * t) * pow(damp, t);

    pose.p = pose.p + vel.operator physx::PxVec3() * t;

    pp = true;
}

void Particle::integrate(double t)
{
    if (!pp) {
        integrateSemi(t);
    }
    else {
        Vector3D currPos = pose.p;

        Vector3D gravityAcc(0.0f, gravity, 0.0f);
        Vector3D actualAcc = acc + gravityAcc;

        pose.p = pose.p * 2.0 - prevPos + actualAcc * pow(t, 2);
        prevPos = currPos;
    }
}

//getCamera Camera 1cam = getCamera()
// getDic() devuelve el vetor direccion de la camara, ha que normmalizarlo.
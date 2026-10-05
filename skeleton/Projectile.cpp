#include "Projectile.h"
#include <cmath>

Projectile::Projectile(float Mass, float Speed, float SimSpeed, float Gravity, Vector3D Pos, Vector3D Dir, float Damp)
    : Particle(0.0f, 0.0f, Pos, Dir* SimSpeed, Vector3D(0.0f, 0.0f, 0.0f), Damp) {
    realMass = Mass;
    realSpeed = Speed;
    simSpeed = SimSpeed;
    realGravity = Gravity;
    updateParam();
}

void Projectile::updateParam()
{
    mass = realMass * pow(realSpeed, 2) / pow(simSpeed, 2);
    gravity = realGravity * pow(simSpeed, 2) / pow(realSpeed, 2);
}

void Projectile::changeMass(float Mass)
{
    realMass += Mass;
    updateParam();
}

void Projectile::changeGrav(float Grav)
{
    realGravity += Grav;
    updateParam();
}
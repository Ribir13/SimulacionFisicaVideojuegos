#include "Projectile.h"

Projectile::Projectile(float Mass, float Speed, float SimSpeed, float Gravity, Vector3D Pos, Vector3D Dir, float Damp)
    : Particle(0.0f, 0.0f, Pos, Dir* SimSpeed, Vector3D(0.0f, 0.0f, 0.0f), Damp) {
    realMass = Mass;
    realSpeed = Speed;
    simSpeed = SimSpeed;
    realGravity = Gravity;
    updateSimulationParameters();
}

void Projectile::updateSimulationParameters()
{
    mass = realMass * (realSpeed * realSpeed) / (simSpeed * simSpeed);
    gravity = realGravity * (simSpeed * simSpeed) / (realSpeed * realSpeed);
}

void Projectile::changeMass(float Mass)
{
    realMass += Mass;
    updateSimulationParameters();
}

void Projectile::changeGrav(float Grav)
{
    realGravity += Grav;
    updateSimulationParameters();
}
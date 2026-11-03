#include "Projectile.h"
#include <cmath>

Projectile::Projectile(float Mass, float Speed, float SimSpeed, Vector3D Pos, Vector3D Dir, float Damp, 
    float Time, ParticleShape ps, Vector4 Color , float Scale)
    : Particle(Mass* pow(Speed, 2) / pow(SimSpeed, 2), Pos, Dir* SimSpeed, Vector3D(0.0f, 0.0f, 0.0f), Damp, Time, ps, Color, Scale) {
    realMass = Mass;
    realSpeed = Speed;
    simSpeed = SimSpeed;
    updateParam();
}

void Projectile::updateParam()
{
    mass = realMass * pow(realSpeed, 2) / pow(simSpeed, 2);
}

void Projectile::changeMass(float Mass)
{
    realMass += Mass;
    updateParam();
}

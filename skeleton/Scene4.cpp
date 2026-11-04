#include "Scene4.h"
#include "Vector3D.h"
#include <vector>
#include <iostream>

void Scene4::init() {
    gPhysicsTimeAccumulator = 0.0;

    m_ps = new ParticleSystem();

    ParticleGenerator* ps = m_ps->addGen(0.01f, Vector3D(10.0f, 60.0f, 10.0f), Vector3D(-90.0f, -20.0f, -90.0f), 3.0f);
    ps->setScaling(true);
    ParticleGenerator* ps2 = m_ps->addGen(0.01f, Vector3D(6.0f, 60.0f, 6.0f), Vector3D(-90.0f, -20.0f, -140.0f), 15.0f, ParticleGenerator::POINT, 2.0f);
    ps2->custom(Particle::ParticleShape::Square, Vector4(2.0f, 0.0f, 0.0f, 1.0f));
    ParticleGenerator* ps3 = m_ps->addGen(0.04f, Vector3D(20.0f, 20.0f, 20.0f), Vector3D(-90.0f, -20.0f, -40.0f), 0.3f, ParticleGenerator::POINT, 200.0f);
    ps3->custom(Particle::ParticleShape::Sphere, Vector4(2.0f, 0.0f, 0.0f, 15.0f));
    ps3->setRandColor(true);
    ps3->setScaling(true);
    //m_ps->addGravGenToAll(-20.0f);
    //m_ps->addGravGen(40.0f, ps);
    //m_ps->addWindGenToAll(Vector3D(-90.0f, -20.0f, -90.0f), 100.0f, 90.0f, Vector3D(20, 0, 0), 0.5f);
    m_ps->addTornadoGenToAll(9.0f, Vector3D(-90, 0, -90), 200.0f, 40000.0f, 1.0f);
}

void Scene4::update(double dt)
{
    // Lógica/Integración del alumno (por ejemplo, movimiento simple)
    //m_transform.p.y -= static_cast<float>(9.8 * dt);
    gPhysicsTimeAccumulator += dt;

    while (gPhysicsTimeAccumulator >= gFixedTimestep)
    {
        if (m_ps != nullptr) {
            m_ps->update(gFixedTimestep);
        }
        gPhysicsTimeAccumulator -= gFixedTimestep;
    }
}

void Scene4::keyPress(unsigned char key, const physx::PxTransform& camera) {
    switch (key) {
    case('p'):
        m_ps->addExplGenToAll(Vector3D(-90.0f, 10.0f, -90.0f), 500.0f, 10000.0f, 0.4f);
        break;
    }
}

void Scene4::cleanup() {
    delete m_ps;
    m_ps = nullptr;
}

void Scene4::setColorByDot(RenderItem*& renderItem, physx::PxShape* esfera, physx::PxTransform* transform, double dot)
{
}
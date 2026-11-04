#include "Scene2.h"
#include "Vector3D.h"
#include <vector>
#include <iostream>

void Scene2::init() {
    gPhysicsTimeAccumulator = 0.0;

    m_ps = new ParticleSystem();

    ParticleGenerator* ps = m_ps->addGen(0.01f, Vector3D(10.0f, 60.0f, 10.0f), Vector3D(-90.0f, -20.0f, -90.0f), 3.0f);
    ps->setScaling(true);
    ps->setDist(ParticleGenerator::TYPEDIST::GAUSS);
    ParticleGenerator* ps2 = m_ps->addGen(0.01f, Vector3D(10.0f, 60.0f, 10.0f), Vector3D(-70.0f, -20.0f, -140.0f), 3.0f);
    ps2->setDist(ParticleGenerator::TYPEDIST::UNI);
    ps2->setScaling(true);

    ParticleGenerator* ps3 = m_ps->addGen(0.01f, Vector3D(10.0f, 60.0f, 10.0f), Vector3D(90.0f, -20.0f, 90.0f), 3.0f,
        ParticleGenerator::TYPE::POINT, 5.3f, 1.0f, 30.0f);
    ps3->setDist(ParticleGenerator::TYPEDIST::UNI);
    ps3->setScaling(true);
    ParticleGenerator* ps4 = m_ps->addGen(0.01f, Vector3D(10.0f, 60.0f, 10.0f), Vector3D(70.0f, -20.0f, 140.0f), 3.0f,
        ParticleGenerator::TYPE::POINT, 5.3f, 1.0f, 300.0f);
    ps4->setDist(ParticleGenerator::TYPEDIST::UNI);
    ps4->setScaling(true);

    m_ps->addWindGenToAll(Vector3D(90.0f, -20.0f, 90.0f), 250, 250, Vector3D(5000,0,0), 1.0f);

    m_ps->addGravGenToAll(-20.0f);
    //m_ps->addWindGenToAll(Vector3D(10, 20, 10), 100.0f, 90.0f, Vector3D(20, 0, 0), 0.5f);
    //m_ps->addTornadoGenToAll(9.0f, Vector3D(-90, 0, -90), 200.0f, 40000.0f, 1.0f);
}

void Scene2::update(double dt)
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

void Scene2::keyPress(unsigned char key, const physx::PxTransform& camera) {
    switch (key) {
    case('p'):
        if (active)
            m_ps->addExplGenToAll(Vector3D(-90.0f, 10.0f, -90.0f), 500.0f, 10000.0f, 0.4f);
        break;
    case('m'):
        m_ps->toogleForces();
        active = !active;
        break;
    }
}
 
void Scene2::cleanup() {
    delete m_ps;
    m_ps = nullptr;
}

void Scene2::setColorByDot(RenderItem*& renderItem, physx::PxShape* esfera, physx::PxTransform* transform, double dot)
{
}
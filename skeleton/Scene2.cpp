#include "Scene2.h"
#include "Vector3D.h"
#include <vector>
#include <iostream>

void Scene2::init() {
    gPhysicsTimeAccumulator = 0.0;

    m_ps = new ParticleSystem(0.1f, Vector3D(0.0f,0.0f,0.0f), Vector3D(1.0f, 1.0f, 1.0f), Vector3D(0.0f, 0.0f, 0.0f), 5.0f);

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

    }
}
 
void Scene2::cleanup() {
    delete m_ps;
    m_ps = nullptr;
}

void Scene2::setColorByDot(RenderItem*& renderItem, physx::PxShape* esfera, physx::PxTransform* transform, double dot)
{
}
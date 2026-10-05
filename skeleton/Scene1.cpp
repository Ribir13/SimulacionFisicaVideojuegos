#include "Scene1.h"
#include "Vector3D.h"
#include <vector>
#include <iostream>

void Scene1::init() {
    gPhysicsTimeAccumulator = 0.0;
}
void Scene1::update(double dt)
{
    // Lógica/Integración del alumno (por ejemplo, movimiento simple)
    //m_transform.p.y -= static_cast<float>(9.8 * dt);
    gPhysicsTimeAccumulator += dt;

    while (gPhysicsTimeAccumulator >= gFixedTimestep)
    {
        for (auto* proj : m_projectiles)
        {
            if (proj)
            {
                proj->integrate(gFixedTimestep);
            }
        }
        gPhysicsTimeAccumulator -= gFixedTimestep;
    }
}

void Scene1::keyPress(unsigned char key, const physx::PxTransform& camera) {
    Vector3D pos = camera.p;
    Vector3D dir = Vector3D(camera.q.rotate(physx::PxVec3(0.0f, 0.0f, -1.0f)));
    switch (key) {
        case 'p':
        {
            m_projectiles.push_back(new Projectile(20.0f, 250.0f, 25.0f, -9.8f, pos, dir, 0.98f));
            break;
        }
        case 'x':
        {
            for (auto* proj : m_projectiles) if (proj) proj->changeMass(-50.0f);
            break;
        }
        case 'z':
        {
            for (auto* proj : m_projectiles) if (proj) proj->changeMass(50.0f);
            break;
        }
        case 'v':
        {
            for (auto* proj : m_projectiles) if (proj) proj->changeGrav(-5000.0f);
            break;
        }
        case 'c':
        {
            for (auto* proj : m_projectiles) if (proj) proj->changeGrav(5000.0f);
            break;
        }
    }
}

void Scene1::cleanup() {

    for (auto* proj : m_projectiles) {
        delete proj;
    }
    m_projectiles.clear();
}

void Scene1::setColorByDot(RenderItem*& renderItem, physx::PxShape* esfera, physx::PxTransform* transform, double dot)
{
    if (dot > 0.0)      renderItem = new RenderItem(esfera, transform, Vector4(0.0f, 1.0f, 0.0f, 1.0f));
    else if (dot < 0.0) renderItem = new RenderItem(esfera, transform, Vector4(1.0f, 0.0f, 0.0f, 1.0f));
    else                renderItem = new RenderItem(esfera, transform, Vector4(1.0f, 1.0f, 0.0f, 1.0f));
}
#include "Scene0.h"
#include "Vector3D.h"
#include <vector>

void Scene0::init() {
	//physx::PxShape* esfera = CreateShape(physx::PxSphereGeometry(2.0f));

	//m_transform = physx::PxTransform(physx::PxVec3(0.0f, 10.0f, 0.0f));

	//// Se registra el RenderItem exactamente como en la plantilla original
	//m_renderItem = new RenderItem(esfera, &m_transform, Vector4(0.0f, 0.0f, 1.0f, 1.0f));

    // RETO A)
    Vector3D u = Vector3D(3.0, 1.0, 0.0);
    Vector3D v = Vector3D(0.0, 4.0, 0.0);
    Vector3D w = u.cross(v);

    u = u.normalize();
    v = v.normalize();
    w = w.normalize();

    u = u * 5.0f;
    v = v * 5.0f;
    w = w * 5.0f;

    physx::PxShape* esfera1 = CreateShape(physx::PxSphereGeometry(2.0f));
    m_transform1 = physx::PxTransform(u.operator physx::PxVec3());
    m_renderItem1 = new RenderItem(esfera1, &m_transform1, Vector4(0.0f, 0.0f, 1.0f, 1.0f));

    physx::PxShape* esfera2 = CreateShape(physx::PxSphereGeometry(2.0f));
    m_transform2 = physx::PxTransform(v.operator physx::PxVec3());
    m_renderItem2 = new RenderItem(esfera2, &m_transform2, Vector4(0.0f, 1.0f, 0.0f, 1.0f));

    physx::PxShape* esfera3 = CreateShape(physx::PxSphereGeometry(2.0f));
    m_transform3 = physx::PxTransform(w.operator physx::PxVec3());
    m_renderItem3 = new RenderItem(esfera3, &m_transform3, Vector4(1.0f, 0.0f, 0.0f, 1.0f));

    //Reto B)

    Vector3D d = Vector3D(0.0, 0.0, 1.0);


}

void Scene0::update(double dt) {
    // Lógica/Integración del alumno (por ejemplo, movimiento simple)
    //m_transform.p.y -= static_cast<float>(9.8 * dt);
}

void Scene0::keyPress(unsigned char key, const physx::PxTransform& camera) {
}

void Scene0::cleanup() {
    if (m_renderItem) {
        m_renderItem->release(); // Deregistra y destruye el item
        m_renderItem = nullptr;
    }
    if (m_renderItem1) {
        m_renderItem1->release(); // Deregistra y destruye el item
        m_renderItem1 = nullptr;
    }
    if (m_renderItem2) {
        m_renderItem2->release(); // Deregistra y destruye el item
        m_renderItem2 = nullptr;
    }
    if (m_renderItem3) {
        m_renderItem3->release(); // Deregistra y destruye el item
        m_renderItem3 = nullptr;
    }
}
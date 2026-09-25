#include "Scene0.h"
#include "Vector3D.h"
#include <vector>

void Scene0::init() {
	//physx::PxShape* esfera = CreateShape(physx::PxSphereGeometry(2.0f));

	//m_transform = physx::PxTransform(physx::PxVec3(0.0f, 10.0f, 0.0f));

	//// Se registra el RenderItem exactamente como en la plantilla original
	//m_renderItem = new RenderItem(esfera, &m_transform, Vector4(0.0f, 0.0f, 1.0f, 1.0f));

    // RETO A)
    //Vector3D u = Vector3D(3.0, 1.0, 0.0);
    //Vector3D v = Vector3D(0.0, 4.0, 0.0);
    //Vector3D w = u.cross(v);

    //u = u.normalize();
    //v = v.normalize();
    //w = w.normalize();

    //u = u * 5.0f;
    //v = v * 5.0f;
    //w = w * 5.0f;

    //physx::PxShape* esfera1 = CreateShape(physx::PxSphereGeometry(2.0f));
    //m_transform1 = physx::PxTransform(u.operator physx::PxVec3());
    //m_renderItem1 = new RenderItem(esfera1, &m_transform1, Vector4(0.0f, 0.0f, 1.0f, 1.0f));

    //physx::PxShape* esfera2 = CreateShape(physx::PxSphereGeometry(2.0f));
    //m_transform2 = physx::PxTransform(v.operator physx::PxVec3());
    //m_renderItem2 = new RenderItem(esfera2, &m_transform2, Vector4(0.0f, 1.0f, 0.0f, 1.0f));

    //physx::PxShape* esfera3 = CreateShape(physx::PxSphereGeometry(2.0f));
    //m_transform3 = physx::PxTransform(w.operator physx::PxVec3());
    //m_renderItem3 = new RenderItem(esfera3, &m_transform3, Vector4(1.0f, 0.0f, 0.0f, 1.0f));

    //Reto B)

    Vector3D d = Vector3D(0.0, 0.0, 1.0);

    Vector3D P_1 = Vector3D(2.0, 0.0, 3.0);
    Vector3D P_2 = Vector3D(-4.0, 0.0, 1.0);
    Vector3D P_3 = Vector3D(0.0, 0.0, -5.0);
    Vector3D P_4 = Vector3D(3.0, 0.0, 0.0);

    physx::PxShape* esferaP1 = CreateShape(physx::PxSphereGeometry(2.0f));
    m_transformP1 = physx::PxTransform(P_1.operator physx::PxVec3());
    physx::PxShape* esferaP2 = CreateShape(physx::PxSphereGeometry(2.0f));
    m_transformP2 = physx::PxTransform(P_2.operator physx::PxVec3());
    physx::PxShape* esferaP3 = CreateShape(physx::PxSphereGeometry(2.0f));
    m_transformP3 = physx::PxTransform(P_3.operator physx::PxVec3());
    physx::PxShape* esferaP4 = CreateShape(physx::PxSphereGeometry(2.0f));
    m_transformP4 = physx::PxTransform(P_4.operator physx::PxVec3());

    double dot1 = d.dot(P_1);
    setColorByDot(m_renderItemP1, esferaP1, &m_transformP1, dot1);

    double dot2 = d.dot(P_2);
    setColorByDot(m_renderItemP2, esferaP2, &m_transformP2, dot2);

    double dot3 = d.dot(P_3);
    setColorByDot(m_renderItemP3, esferaP3, &m_transformP3, dot3);

    double dot4 = d.dot(P_4);
    setColorByDot(m_renderItemP4, esferaP4, &m_transformP4, dot4);


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

    if (m_renderItemP1) {
        m_renderItemP1->release(); // Deregistra y destruye el item
        m_renderItemP1 = nullptr;
    }
    if (m_renderItemP2) {
        m_renderItemP2->release(); // Deregistra y destruye el item
        m_renderItemP2 = nullptr;
    }
    if (m_renderItemP3) {
        m_renderItemP3->release(); // Deregistra y destruye el item
        m_renderItemP3 = nullptr;
    }
    if (m_renderItemP4) {
        m_renderItemP4->release(); // Deregistra y destruye el item
        m_renderItemP4 = nullptr;
    }
}

void Scene0::setColorByDot(RenderItem*& renderItem, physx::PxShape* esfera, physx::PxTransform* transform, double dot)
{
    if (dot > 0.0)      renderItem = new RenderItem(esfera, transform, Vector4(0.0f, 1.0f, 0.0f, 1.0f));
    else if (dot < 0.0) renderItem = new RenderItem(esfera, transform, Vector4(1.0f, 0.0f, 0.0f, 1.0f));
    else                renderItem = new RenderItem(esfera, transform, Vector4(1.0f, 1.0f, 0.0f, 1.0f));
}
#pragma once

#include "Scene.h"

class Scene0: public Scene
{
public:
	explicit Scene0(std::string name) : Scene(std::move(name)) {}


	void init() override;
	void update(double dt) override;
	void keyPress(unsigned char key, const physx::PxTransform& camera) override;
	void cleanup() override;

	void setColorByDot(RenderItem*& renderItem, physx::PxShape* esfera, physx::PxTransform* transform, double dot);

private:
	physx::PxTransform m_transform;
	RenderItem* m_renderItem{ nullptr };

	physx::PxTransform m_transform1;
	RenderItem* m_renderItem1{ nullptr };
	physx::PxTransform m_transform2;
	RenderItem* m_renderItem2{ nullptr };
	physx::PxTransform m_transform3;
	RenderItem* m_renderItem3{ nullptr };

	physx::PxTransform m_transformP1;
	RenderItem* m_renderItemP1{ nullptr };
	physx::PxTransform m_transformP2;
	RenderItem* m_renderItemP2{ nullptr };
	physx::PxTransform m_transformP3;
	RenderItem* m_renderItemP3{ nullptr };
	physx::PxTransform m_transformP4;
	RenderItem* m_renderItemP4{ nullptr };
};


#pragma once

#include "Scene.h"
#include "vector"

class Scene2 : public Scene
{
public:
	explicit Scene2(std::string name) : Scene(std::move(name)) {}


	void init() override;
	void update(double dt) override;
	void keyPress(unsigned char key, const physx::PxTransform& camera) override;
	void cleanup() override;

	void setColorByDot(RenderItem*& renderItem, physx::PxShape* esfera, physx::PxTransform* transform, double dot);

private:
	ParticleSystem* m_ps = nullptr;
	// Global variables for physics timing. We use a fixed timestep for physics simulation, and accumulate time to determine when to step the physics simulation.
	double gPhysicsTimeAccumulator = 0.0;
	const double gFixedTimestep = 1.0 / 60.0;
};


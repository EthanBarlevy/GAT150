#include "physicsSystem.h"
#include "Math/mathUtils.h"

namespace vl
{
	const float PhysicsSystem::pixelsPerUnit = 48.0f;

	void PhysicsSystem::Initialize()
	{
		b2Vec2 gravity{ 0, 10 };
		m_world = std::make_unique<b2World>(gravity);
	}

	void PhysicsSystem::Shutdown()
	{
		//
	}

	void PhysicsSystem::Update()
	{
		m_world->Step(1.0f / 60.0f, 8, 3);
	}

	b2Body* PhysicsSystem::CreateBody(const Vector2& position, float angle, const RigidBodyData& data)
	{
		Vector2 worldPosition = ScreenToWorld(position);

		b2BodyDef bodyDef;
		bodyDef.type = (data.is_dynamic) ? b2_dynamicBody : b2_staticBody;
		bodyDef.position = *((b2Vec2*)(&worldPosition));
		bodyDef.angle = math::DegToRad(angle);
		bodyDef.fixedRotation = data.constrain_angle;
		b2Body* body = m_world->CreateBody(&bodyDef);

		return body;
	}

	void PhysicsSystem::DestroyBody(b2Body* body)
	{
		m_world->DestroyBody(body);
	}

}

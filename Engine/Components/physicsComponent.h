#pragma once
#include "includes.h"
#include "Math/vector2.h"

namespace vl
{
	class PhysicsComponent : public Component
	{
	public:
		PhysicsComponent() = default;
		
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Update() override;
		void ApplyForce(const Vector2& force) { m_acceleration += force; }

	public:
		Vector2 m_velocity{ Vector2::ZERO };
		Vector2 m_acceleration{ Vector2::ZERO };

		float m_damping{ 0.7f };

	};
}
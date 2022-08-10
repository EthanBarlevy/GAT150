#pragma once
#include "includes.h"

namespace vl
{
	class AudioComponent : public Component
	{
	public:
		AudioComponent() = default;

		void Update() override;
		void Play();
		void Stop();

	public:
		std::string m_soundName;
		bool m_playOnAwake{ false };
		bool m_loop{ false };
		float m_volume{ 1 };
		float m_pitch{ 1 };

	};
}
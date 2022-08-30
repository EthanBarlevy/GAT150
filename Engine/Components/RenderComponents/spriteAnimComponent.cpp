#include "spriteAnimComponent.h"
#include "Framework/actor.h"
#include "Renderer/texture.h"

namespace vl
{
    bool SpriteAnimComponent::Write(const rapidjson::Value& value) const
    {
        return false;
    }

    bool SpriteAnimComponent::Read(const rapidjson::Value& value)
    {
        std::string texture_name;
        READ_DATA(value, texture_name);

        m_texture = g_resourceManager.Get<Texture>(texture_name, g_renderer);

        READ_DATA(value, fps);
        READ_DATA(value, num_columns);
        READ_DATA(value, num_rows);
        READ_DATA(value, start_frame);
        READ_DATA(value, end_frame);

        return true;
    }

    void SpriteAnimComponent::Update()
    {
        // update frame
        frameTimer += (float)g_time.deltaTime;
        if (frameTimer >= 1.0f / fps)
        {
            frameTimer = 0;
            frame++;
            if (frame > end_frame)
            {
                frame = start_frame;
            }
        }
    }

    void SpriteAnimComponent::Draw(Renderer& renderer)
    {
        renderer.Draw(m_texture, GetSource(), m_owner->GetTransform(), registration, flipHorizontal);
    }

    Rect& SpriteAnimComponent::GetSource()
    {
        Vector2 cellSize = m_texture->GetSize() / Vector2{ num_columns, num_rows };

        int column = (frame - 1) % num_columns;
        int row = (frame - 1) / num_columns;

        source.x = (int)(column * cellSize.x);
        source.y = (int)(row * cellSize.y);
        source.w = (int)(cellSize.x);
        source.h = (int)(cellSize.y);

        return source;
    }
}

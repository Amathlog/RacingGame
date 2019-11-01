#pragma once

class SDL_Renderer;

class Renderable
{
public:
    Renderable(float zValue = 0.0f)
        : m_zValue(zValue)
    {
        static unsigned int s_ID = 0;
        m_id = ++s_ID;
    }

    virtual void Draw(SDL_Renderer* renderer) const = 0;
    unsigned int GetId() const { return m_id; }

    float GetZValue() const { return m_zValue; }
    void SetZValue(float zValue) { m_zValue = zValue; }

private:
    unsigned int m_id;
    float m_zValue;
};
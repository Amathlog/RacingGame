#pragma once

#include <unordered_map>
#include "SDL.h"
#include "singleton.h"

class Renderable;

class Renderer : public Singleton<Renderer>
{
public:
    void Update(float dt);

    void AddRenderable(unsigned int id, const Renderable* renderable);
    void RemoveRenderable(unsigned int id);

    void Initialize(unsigned int height, unsigned int width);
    void Close();

    void SetFramerate(unsigned int fps);

    ~Renderer()
    {
        Close();
    }

private:
    void Render();

    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;
    using MapIDToRenderable = std::unordered_map<unsigned int, const Renderable*>;
    MapIDToRenderable m_renderablesMap;
    float m_fixedDeltaTime = -1.0f;
    float m_lastUpdate = 0.0f;
    float m_currentTime = 0.0f;
};
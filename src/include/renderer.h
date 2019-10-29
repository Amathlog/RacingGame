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

    ~Renderer()
    {
        Close();
    }

private:
    void Render();

    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;
    std::unordered_map<unsigned int, const Renderable*> m_renderablesMap;
};
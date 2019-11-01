#include "renderer.h"
#include "renderable.h"

#include <queue>

void Renderer::Initialize(unsigned int height, unsigned int width)
{
    if (m_window != nullptr)
        return;

    SDL_Init(SDL_INIT_VIDEO);

    m_window = SDL_CreateWindow("SDL2Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        height, width, 0 );

    if (m_window == nullptr)
        return;

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    if (m_renderer == nullptr)
        return;

    m_currentTime = 0.0f;
    m_lastUpdate = -1.0f;
}

void Renderer::Close()
{
    if (m_window == nullptr && m_renderer != nullptr)
        return;

    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Renderer::AddRenderable(unsigned int id, const Renderable* renderable)
{
    m_renderablesMap.emplace(id, renderable);
}

void Renderer::RemoveRenderable(unsigned int id)
{
    m_renderablesMap.erase(id);
}

void Renderer::Update(float dt)
{
    if (m_renderer == nullptr)
        return;

    // Don't update the renderer if we don't need to.
    m_currentTime += dt;
    if (m_fixedDeltaTime < 0.0f || (m_currentTime - m_lastUpdate) < m_fixedDeltaTime)
        return;
    
    SDL_RenderClear(m_renderer);
    Render();
    SDL_RenderPresent(m_renderer);

    m_lastUpdate = m_currentTime;
}

void Renderer::Render()
{
    using T = const Renderable*;

    struct Less
    {
        bool operator()(T lhs, T rhs) const 
        {
            return lhs->GetZValue() < rhs->GetZValue();
        }
    };

    std::priority_queue<T, std::vector<T>, Less> renderingQueue;
    for(auto item : m_renderablesMap)
    {
        renderingQueue.push(item.second);
    }

    while(!renderingQueue.empty())
    {
        renderingQueue.top()->Draw(m_renderer);
        renderingQueue.pop();
    }
}
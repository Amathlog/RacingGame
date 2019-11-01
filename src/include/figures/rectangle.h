#pragma once

#include "../renderable.h"
#include "Box2D/Box2D.h"

class Rectangle : public Renderable
{
public:
    Rectangle(float zValue, b2Vec2 p1, b2Vec2 p2);

    void Draw(SDL_Renderer* renderer) const override;
    void Update(b2Vec2 p1, b2Vec2 p2;
private:
    b2Vec2 m_p1;
    b2Vec2 m_p2;
};
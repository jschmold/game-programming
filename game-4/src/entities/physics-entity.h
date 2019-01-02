#pragma once

// This will be the 
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

using namespace sf;

namespace Game4::Entities
{
    class PhysicsEntity
    {
    private:
        b2World* m_world;
        b2Body* m_body;
        b2PolygonShape* m_physShape;

        float m_density;
        float m_friction;

    public:
        virtual void addToWorld(b2World* world);
    };
}

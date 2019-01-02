#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "physics-entity.h"

using namespace sf;

namespace Game4::Entities
{

    class Player : public PhysicsEntity
    {
    private:
        
    public:
        Player();

        void onThink();
        void onDraw(RenderTarget* target);
        virtual void addToWorld(b2World* world);
    };

}

#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

using namespace sf;

namespace Game4::Entities
{

    class World
    {
    private:
        b2World* self;

    public:
        operator b2World*();

    };

}

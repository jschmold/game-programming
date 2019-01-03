#ifndef _H_PLAYER
#define _H_PLAYER

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "physics-entity.h"
#include "world-entity.h"

using namespace sf;

namespace Entities
{

    class Player : public PhysicsEntity, public WorldEntity
    {
    protected:
        RectangleShape* m_visShape;
        View*           m_view;
    public:
        Player(
            float       density,
            float       friction,
            b2World*    world,
            Vector2f    startPos,
            View*       camera
        );
        virtual ~Player();

        virtual void onThink();
        virtual void onDraw(RenderTarget* target);
        operator Drawable*();
    };

}

#endif

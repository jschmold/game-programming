#ifndef _H_PLAYER
#define _H_PLAYER

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

using namespace sf;

namespace Game3
{

    class Player : public Transformable
    {
    private:
        RectangleShape m_visShape;
        b2Body* m_body;
        b2Fixture* m_fixture;
        b2PolygonShape* m_physShape;
        b2World* world;

        bool canJump();
        bool isStandingOnSomething();
        void handleControls();

    public:
        Player(b2World* world, Vector2f size, Vector2f pos);
        ~Player();

        void setPosition(Vector2f pos);
        void setPosition(float posx, float posy);
        void setPosition(b2Vec2 pos);

        b2Vec2 getPhysPosition();

        void onDraw(RenderTarget *target);
        void onThink();
    };


} // namespace Game3

#endif

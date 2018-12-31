#ifndef _H_PLAYER
#define _H_PLAYER

#include <string>
#include <SFML/Graphics.hpp>
#include "common.h"

using namespace std;
using namespace sf;

#define USE_RADIANS 0x0001
#define USE_DEGREES 0x0010

#define DIRECTION_UP_DEGREES 0;
#define DIRECTION_DOWN_DEGREES 180;
#define DIRECTION_LEFT_DEGREES 270;
#define DIRECTION_RIGHT_DEGREES 90;

#define DIRECTION_RIGHT (0)
#define DIRECTION_LEFT (M_PI * 0.5)
#define DIRECTION_DOWN (M_PI)
#define DIRECTION_UP (M_PI * 1.5)

namespace Game2
{

    class Player : public Transformable
    {
    private:
        Sprite*        sprite;
        float          acceleration;
        float          friction;
        float          maxSpeed;
        float          turnSpeed;
        Vector2<float> velocity; // Effectively [amplitude, direction (rad)]
        float          rotation;
    public:
        Player(
               Sprite*   sprite,
               float     maxSpeed     = 12.0f,
               float     acceleration = 0.4f,
               float     friction     = 0.01f,
               float     turnSpeed    = 0.09f
            );

        void setSprite(Sprite* sprite);
        Sprite* getSprite();

        void onDraw(RenderTarget& target);
        void onThink();
        void applyForce(float direction, float amplitude, int flags = USE_RADIANS);
        void applyForce(Vector2f force);

    };
}

#endif

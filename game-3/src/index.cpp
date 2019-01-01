#include <iostream>
#include "player.h"
#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
using namespace Game3;

#define G_PHYS_TIMESTEP (1.0f / 60.0f)
#define G_PHYS_VEL_ITERATIONS 10
#define G_PHYS_POS_ITERATIONS 5

void isGround() {

}

void KeyPress(Window* window)
{
    if (Keyboard::isKeyPressed(Keyboard::Escape))
        window->close();
}

int main(int argc, char* argv[])
{
    // The whole wide world
    b2Vec2 gravity(0.0f, 0.4f);
    b2World world(gravity);

    // These apparently don't move?
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, 75.0f);

    // Tell the world what do, and get the ref to the body
    b2Body* groundBody = world.CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    // This function takes half. So 50->100 wide, 10 -> 20 height
    groundBox.SetAsBox(50.0f, 10.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    Player* ply = new Player(
        &world,
        Vector2f(5, 4),
        Vector2f(10, 10.f)
    );

    RenderWindow window;
    window.create(VideoMode(1280, 720),
                  "Physics Learning"s);

    View clientView(Vector2f(0, 0), Vector2f(200.f, 200.f));
    
    while (window.isOpen())
    {

        Event evt;
        while(window.pollEvent(evt))
        {
            switch(evt.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed: {
                if (Keyboard::isKeyPressed(Keyboard::Enter)) {
                    delete ply;
                    ply = new Player(
                        &world,
                        Vector2f(5, 4),
                        Vector2f(10, 10.f)
                    );
                }
            }
            default: break;
            }
        }

        world.Step(G_PHYS_TIMESTEP,
                    G_PHYS_VEL_ITERATIONS,
                    G_PHYS_POS_ITERATIONS);
        ply->onThink();

        RectangleShape ground(Vector2f(100, 20));
        ground.setOrigin(50, 10);
        auto groundPos = groundBody->GetPosition();
        ground.setPosition(groundPos.x, groundPos.y);
        ground.setFillColor(Color::Red);

        window.clear(Color::Transparent);
        window.setView(clientView);
        window.draw(ground);
        ply->onDraw(&window);
        window.display();

        KeyPress(&window);

    }

    return 0;
}

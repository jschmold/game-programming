#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "entities/entities.h"

using namespace std;
using namespace Entities;
using namespace sf;
int main(int argc, char* argv[])
{
    RenderWindow* window = new RenderWindow(VideoMode(1280, 720), "Game 4");

    World* world = new World(window, b2Vec2(0.0f, 4.f));
    Player* ply  = new Player(4.f, 0.2f, world, Vector2f(0.f, 2.f), *world);
    world->addDrawableEntity(ply);
    world->addWorldEntity(ply);

    while(window->isOpen())
    {
        Event evt;
        while(window->pollEvent(evt))
        {
            switch(evt.type)
            {
                case Event::KeyReleased: {
                    if (evt.key.code == Keyboard::Escape) window->close();
                    break;
                }
                default: break;
            }
        }

        window->clear(Color::Black);
        world->onThink();
        world->onDraw(window);
        window->display();
    }

    delete world;
    delete window;
    delete ply;

    return 0;
}

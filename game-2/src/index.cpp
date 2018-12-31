#include <iostream>
#include <math.h>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "player.h"

using namespace std;
using namespace sf;
using Game2::Player;

void HandleKeys(RenderWindow* window, Event* evt)
{
    if (Keyboard::isKeyPressed(Keyboard::Escape))
        window->close();
}

int main(int argc, char* argv[])
{
    ContextSettings settings;
    settings.majorVersion = 4;
    settings.minorVersion = 0;

    RenderWindow window;
    window.create(VideoMode(1280, 720, 32), "Something", Style::Default, settings);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    CircleShape triangle(80.f, 3);
    triangle.setPosition(-10, 0);
    triangle.setFillColor(Color::Green);
    auto triangleRect = triangle.getLocalBounds();
    cout << "Height: " << triangleRect.width << endl
         << "Width: " <<  triangleRect.height << endl;

    RenderTexture rectTexture;
    rectTexture.create(140, 120, ContextSettings(4, 6, 0));
    rectTexture.clear(Color::Red);
    rectTexture.setSmooth(true);
    rectTexture.draw(triangle);
    rectTexture.display();


    Sprite sprite(rectTexture.getTexture());

    Player* ply = new Player(&sprite);
    ply->setPosition(500, 500);

    cout << "Initial" << endl;

    while(window.isOpen())
    {
        Event evt;
        // This returns a list of events per frame
        while(window.pollEvent(evt))
        {
            if (evt.type == Event::Closed)
                window.close();

            if (evt.type == Event::KeyPressed)
            {
                HandleKeys(&window, &evt);
            }

        }
        ply->onThink();

        ply->onDraw(window);

        window.draw(triangle);
        window.display();
        window.clear(Color::White);
    }
    cout << "Done" << endl;

    return 0;
}

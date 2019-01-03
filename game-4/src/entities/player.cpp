#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "player.h"
#include "physics-entity.h"
#include "world-entity.h"

using namespace Entities;
using namespace sf;
using namespace std;

Player::Player(
    float       density,
    float       friction,
    b2World*    world,
    Vector2f    startPos,
    View*       view
) {
    // physics
    this->m_world    = world;

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(startPos.x, startPos.y);
    this->m_body = world->CreateBody(&bodyDef);

    b2PolygonShape physShape;
    physShape.SetAsBox(0.4f, 0.4f);

    b2FixtureDef fixtureDef;
    fixtureDef.friction = friction;
    fixtureDef.density  = density;
    fixtureDef.shape    = &physShape;

    this->m_body->CreateFixture(&fixtureDef);

    // visuals
    this->m_visShape = new RectangleShape();
    this->m_visShape->setSize(Vector2f(0.4f, 0.4f));
    this->m_visShape->setFillColor(Color::Green);
    this->m_visShape->setOrigin(0.2f, 0.2f);

    this->m_view = view;
    this->m_view->setCenter(0.4f, 0.4f);
}

void Player::onThink()
{
    auto pos = this->m_body->GetPosition();
    this->m_visShape->setPosition(pos.x, pos.y);
    this->m_view->setCenter(pos.x, pos.y);
}

void Player::onDraw(RenderTarget* target)
{
    target->draw(*this->m_visShape);
}

Player::~Player()
{
    this->m_world->DestroyBody(this->m_body);
}


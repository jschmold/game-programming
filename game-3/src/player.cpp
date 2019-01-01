#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "player.h"
#include <iostream>
#include <cstdlib>

using namespace sf;
using namespace Game3;
using namespace std;


Player::Player(b2World* world, Vector2f size, Vector2f pos)
{
    this->world = world;
    this->m_visShape = RectangleShape(size);
    this->m_visShape.setOrigin(size.x / 2, size.y / 2);
    this->m_visShape.setFillColor(Color::Blue);
    this->setOrigin(size.x / 2, size.y / 2);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(pos.x, pos.y);

    this->m_body = world->CreateBody(&bodyDef);

    b2PolygonShape physShape;
    physShape.SetAsBox(size.x, size.y);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &(physShape);
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    auto fixture = this->m_body->CreateFixture(&fixtureDef);

    this->m_physShape = &physShape;
    this->m_fixture = fixture;
}

Player::~Player()
{
    this->world->DestroyBody(this->m_body);
}

bool Player::isStandingOnSomething()
{
    for (b2ContactEdge* contact = this->m_body->GetContactList(); contact; contact = contact->next) 
    {
        auto otherPos = contact->other->GetPosition();
        if (otherPos.y > this->m_body->GetPosition().y) return true;
    }

    return false;
}

bool Player::canJump()
{
    return this->isStandingOnSomething();
}

void Player::setPosition(Vector2f pos)
{
    this->m_visShape.setPosition(pos);
    this->Transformable::setPosition(pos);
}

void Player::setPosition(float posx, float posy )
{
    this->setPosition(Vector2f(posx, posy));
}

void Player::setPosition(b2Vec2 vec)
{
    this->setPosition(vec.x, vec.y);
}

void Player::onThink()
{
    this->setPosition(this->m_body->GetPosition());
    this->handleControls();
}

void Player::onDraw(RenderTarget* target)
{
    target->draw(this->m_visShape);
}

void Player::handleControls()
{
    bool isStandingOnSomething = this->isStandingOnSomething();

    if (Keyboard::isKeyPressed(Keyboard::Up) && this->canJump()) {
        this->m_body->ApplyLinearImpulseToCenter(b2Vec2(0.f, -30.f), true);
    }

    if (Keyboard::isKeyPressed(Keyboard::Right) && isStandingOnSomething)
        this->m_body->ApplyForceToCenter(b2Vec2(20.f, 0), true);

    if (Keyboard::isKeyPressed(Keyboard::Left) && isStandingOnSomething)
        this->m_body->ApplyForceToCenter(b2Vec2(-20.f, 0), true);
}

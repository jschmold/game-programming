#include <iostream>
#include "player.h"
#include "common.h"
#include "math.h"

using namespace sf;
using namespace Game2;

Player::Player(Sprite* spr, float maxSpd, float accel, float fric, float turnSpd)
{
    maxSpeed = maxSpd;
    sprite = spr;
    velocity = Vector2<float>(0,0);
    acceleration = accel;
    friction = fric;
    turnSpeed = turnSpd;
    this->setRotation(sprite->getRotation());
    let spriteBounds = sprite->getGlobalBounds();
    this->setPosition(spriteBounds.left, spriteBounds.top);
}

void Player::setSprite(Sprite* sprt)
{
    this->sprite = sprt;
}

Sprite* Player::getSprite()
{
    return this->sprite;
}

void Player::onThink()
{
    // Modify direction
    if (Keyboard::isKeyPressed(Keyboard::Left))
        this->applyForce(DIRECTION_LEFT, 5.f);

    if (Keyboard::isKeyPressed(Keyboard::Right))
        this->applyForce(DIRECTION_RIGHT, 5.f);

    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        this->velocity = Vector2f(0, 0);
        this->applyForce(DIRECTION_RIGHT, 50.f);
    }

    // applyForce(DIRECTION_DOWN, 0.5f);

    let amplitude = this->velocity.x,
        direction = this->velocity.y;


    let x = cos(direction * M_PI / 180) * amplitude,
        y = sin(direction * M_PI / 180) * amplitude;

//  std::cout << "x: " << x << endl
//            << "y: " << y << endl
//            << "a: " << amplitude << endl
//            << "d: " << direction << endl
//            << endl;
    this->move(x, y);
    this->sprite->move(x, y);
}

void Player::onDraw(RenderTarget& target)
{
    target.draw(*this->sprite);
}

void Player::applyForce(float direction, float amplitude, int flags)
{
    if (flags & USE_DEGREES) {
        std::cout << "Using degrees";
        direction = direction * M_PI / 180;
    }

    let curAmp = this->velocity.x,
        curDir = this->velocity.y;

    let oldX = cos(curDir) * curAmp,
        oldY = sin(curDir) * curAmp;

    let newX = cos(direction) * amplitude,
        newY = sin(direction) * amplitude;


    this->velocity += Vector2f(amplitude, direction);
}

void Player::applyForce(Vector2f force)
{
    this->velocity += force;
}

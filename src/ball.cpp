#include "ball.h"

Ball::Ball(sf::RenderWindow *window):
    renwin_window(window)
{
    bounce = false;
    angle = 0.0;
    start_pos = {400, 300};
    this->rect_ball.setSize(sf::Vector2f(10, 10));
    this->rect_ball.setOrigin(5, 5);
    this->rect_ball.setPosition(start_pos);
}

Ball::~Ball() {}

void Ball::render()
{
    this->renwin_window->draw(rect_ball);
}

void Ball::update()
{

}

void Ball::launch()
{

}

void Ball::wallCollision()
{

}

void Ball::collides(Paddle *paddle)
{

}

void Ball::bounces(Paddle *paddle)
{

}

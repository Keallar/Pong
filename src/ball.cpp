#include "ball.h"

Ball::Ball(sf::RenderWindow *window):
    renwin_window(window)
{
    this->rect_ball.setSize(sf::Vector2f(10, 10));
    this->rect_ball.setOrigin(5, 5);
    this->rect_ball.setPosition(400, 300);
}

Ball::~Ball() {}

void Ball::render()
{
    this->renwin_window->draw(rect_ball);
}

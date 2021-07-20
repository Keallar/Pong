#pragma once

#include <SFML/Graphics.hpp>

#include "paddle.h"

class Ball
{
public:
    Ball(sf::RenderWindow *window);
    ~Ball();
    void render();
    void update();
    void launch();
    void wallCollision();
    void collides(Paddle* paddle);
    void bounces(Paddle* paddle);
private:
    sf::Vector2f start_pos;
    sf::RenderWindow *renwin_window;
    sf::RectangleShape rect_ball;
    bool bounce;
    float angle;
};

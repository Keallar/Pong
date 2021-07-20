#pragma once

#include <SFML/Graphics.hpp>

class Ball
{
public:
    Ball(sf::RenderWindow *window);
    ~Ball();
    void render();
    void update();
private:
    sf::RenderWindow *renwin_window;
    sf::RectangleShape rect_ball;
};

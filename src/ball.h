#pragma once

#include <SFML/Graphics.hpp>

#include "paddle.h"

enum eState
{   Peace,
    Launched,
    BouncedLeftWall,
    BouncedRightWall,
    BouncedTopWall,
    BouncedBottomWall,
    BouncedPaddle,
    Passed
};

class Ball
{
public:
    Ball(sf::RenderWindow *window);
    ~Ball();
    void render();
    void update(sf::Time time);
    void launch();
    void wallCollision();
    void collides(Paddle* paddle);
    void bounces(Paddle* paddle);
    void reset();
private:
    const int WIDTH = 800;
    const int HEIGHT = 600;

    eState state;

    sf::Vector2f start_pos;
    sf::RenderWindow *renwin_window;
    sf::RectangleShape rect_ball;

    bool b_dir_left;
    bool b_dir_right;
    bool b_bounce;
    float f_angle;
    float f_speed;
};

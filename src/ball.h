#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "paddle.h"

enum eState
{   Start,
    Launched,
    Bounced,
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
    bool passed(Paddle* paddle);
    void reset();
    sf::Vector2f calculateMove();
private:
    const int WIDTH = 800;
    const int HEIGHT = 600;

    eState state;

    sf::Vector2f start_pos;
    sf::RenderWindow *renwin_window;
    sf::RectangleShape rect_ball;

    sf::SoundBuffer soundbuf_main;
    sf::Sound sound_collide;

    bool b_dir_left;
    bool b_dir_right;
    sf::Vector2f vec_angle;
    float f_speed;
    float f_accel;
};

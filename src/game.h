#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "paddle.h"
#include "ball.h"

class Game
{
public:
    Game();
    ~Game();
    void run();
    void update(sf::Time deltaTime);
    void render();
    void processEvents();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
private:
    static const sf::Time TimePerFrame;

    sf::RenderWindow win_main;

    Paddle paddle_first;
    Paddle paddle_second;
    Ball ball_main;
};
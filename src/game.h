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
    sf::RenderWindow win_main;
    sf::RectangleShape line;
    sf::Font font_main;

    int score_first;
    int score_second;

    Paddle paddle_first;
    Paddle paddle_second;
    Ball ball_main;
};

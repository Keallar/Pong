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
    void changeScore();
private:
    static const sf::Time TimePerFrame;

    sf::RenderWindow win_main;
    sf::RectangleShape rect_line;
    sf::Font font_main;
    sf::Text text_score_zero;
    sf::Text text_score_first;
    sf::Text text_start_game;

    Paddle paddle_zero;
    Paddle paddle_first;
    Ball ball_main;

    bool b_start_game;
};

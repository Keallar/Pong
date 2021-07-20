#pragma once

#include <SFML/Graphics.hpp>

class Paddle
{
public:
    Paddle() = default;
    Paddle(sf::RenderWindow* window, int player);
    ~Paddle();
    void render();
    void update(sf::Time time);
    void handleEvent(sf::Keyboard::Key key, bool isPressed);
    void setY(int y);
private:
    sf::RenderWindow* renwin_window;
    sf::RectangleShape rectangle;
    int y;
    int n_player;
    int n_score;
    bool isPressedUp;
    bool isPressedDown;
    bool isPressedW;
    bool isPressedS;
};


#include "paddle.h"

Paddle::Paddle(sf::RenderWindow* window, int player)
{
    isPressedUp = false;
    isPressedDown = false;
    isPressedW = false;
    isPressedS = false;
    this->n_score = 0;
    this->y = 300;
    this->n_player = player;
    this->renwin_window = window;
    this->rectangle.setSize(sf::Vector2f(10, 100));
    this->rectangle.setOrigin(5, 50);
    if(player == 0){
        this->rectangle.setPosition(sf::Vector2f(25, this->y));
    }
    else if (player == 1){
        this->rectangle.setPosition(sf::Vector2f(775, this->y));
    }
}

Paddle::~Paddle() {}

//render paddle
void Paddle::render()
{
    this->renwin_window->draw(rectangle);
}

//logic of paddle
void Paddle::update(sf::Time time)
{
    if(isPressedS){
        this->y += time.asMilliseconds() * 0.3;
        setY(y);
    }
    if(isPressedW){
        this->y -= time.asMilliseconds() * 0.3;
        setY(y);
    }
    if(isPressedDown){
        this->y += time.asMilliseconds() * 0.3;
        setY(y);
    }
    if(isPressedUp){
        this->y -= time.asMilliseconds() * 0.3;
        setY(y);
    }
}

//events to move paddle
void Paddle::handleEvent(sf::Keyboard::Key key, bool isPressed)
{
    if(this->n_player == 0){
        if(key == sf::Keyboard::S){
            isPressedS = isPressed;
        }
        else if(key == sf::Keyboard::W){
            isPressedW = isPressed;
        }
    } else if (this->n_player == 1){
        if(key == sf::Keyboard::Up){
            isPressedUp = isPressed;
        }
        else if(key == sf::Keyboard::Down){
            isPressedDown = isPressed;
       }
    }
}

//check walls
void Paddle::setY(int y)
{
    if (y > 30 && y < 570)
    {
        if(n_player == 0)
            this->rectangle.setPosition(25, y);
        else if(n_player == 1)
            this->rectangle.setPosition(775, y);
    }
}

sf::RectangleShape Paddle::getRect() noexcept
{
    return rectangle;
}

int Paddle::getPlayer() noexcept
{
    return n_player;
}

void Paddle::incScore()
{
    n_score++;
}

int Paddle::getScore() noexcept
{
    return n_score;
}



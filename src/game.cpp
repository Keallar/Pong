#include <iostream>

#include "game.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game():
    win_main(sf::VideoMode(800, 600), "Pong"),
    paddle_first(&win_main, 0),
    paddle_second(&win_main, 1),
    ball_main(&win_main)
{
    if(!font_main.loadFromFile("../data/Fonts/font.ttf"))
        std::cerr << "Font wasn't loaded" << std::endl;
    text_score_first.setFont(font_main);
    text_score_first.setString("0");
    text_score_first.setCharacterSize(64);
    text_score_first.setPosition(sf::Vector2f(335, 10));
    text_score_second.setFont(font_main);
    text_score_second.setString("0");
    text_score_second.setCharacterSize(64);
    text_score_second.setPosition(sf::Vector2f(435, 10));
    score_first = 0;
    score_second = 0;
    rect_line.setSize(sf::Vector2f(5, 600));
    rect_line.setPosition(sf::Vector2f(400, 0));
    win_main.setVerticalSyncEnabled(true);
}

Game::~Game() {}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(win_main.isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)//???
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }

        render();
    }
}

void Game::update(sf::Time deltaTime)
{
    paddle_first.update(deltaTime);
    paddle_second.update(deltaTime);
    ball_main.update(deltaTime);
    ball_main.collides(&paddle_first);
    ball_main.collides(&paddle_second);
}

void Game::render()
{
    win_main.clear(sf::Color::Black);
    paddle_first.render();
    paddle_second.render();
    ball_main.render();
    this->win_main.draw(rect_line);
    this->win_main.draw(text_score_first);
    this->win_main.draw(text_score_second);
    win_main.display();
}

//events
void Game::processEvents()
{
    sf::Event event;
    while (win_main.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            win_main.close();
            break;
        case sf::Event::KeyPressed:
            this->handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            this->handlePlayerInput(event.key.code, false);
            break;
        default:
            break;
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    paddle_first.handleEvent(key, isPressed);
    paddle_second.handleEvent(key, isPressed);
}


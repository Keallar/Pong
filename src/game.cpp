#include <iostream>

#include "game.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game():
    win_main(sf::VideoMode(800, 600), "Pong"),
    paddle_first(&win_main, 0),
    paddle_second(&win_main, 1),
    ball_main(&win_main)
{
    font_main.loadFromFile("../data/font.ttf");
    if(!font_main.loadFromFile("../data/font.ttf"))
        std::cerr << "Font wasn't loaded" << std::endl;
    score_first = 0;
    score_second = 0;
    //line.setSize();
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
        while (timeSinceLastUpdate > TimePerFrame)
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
}

void Game::render()
{
    win_main.clear(sf::Color::Black);
    paddle_first.render();
    paddle_second.render();
    ball_main.render();
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


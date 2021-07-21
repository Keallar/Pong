#include <iostream>
#include <random>
#include <cmath>

#include "ball.h"

Ball::Ball(sf::RenderWindow *window):
    renwin_window(window)
{
    state = eState::Peace;
    b_dir_left = false;
    b_dir_right = false;
    b_bounce = false;
    f_angle = 0.0;
    f_speed = 0.f;
    start_pos = {WIDTH/2.f, HEIGHT/2.f};
    this->rect_ball.setSize(sf::Vector2f(10, 10));
    this->rect_ball.setOrigin(5, 5);
    this->rect_ball.setPosition(start_pos);
}

Ball::~Ball() {}

void Ball::render()
{
    this->renwin_window->draw(rect_ball);
}

void Ball::update(sf::Time time)
{
    f_speed = time.asMilliseconds() * 0.2f;

    sf::Vector2f v_motion (0.f, 0.f);
    if(state == eState::BouncedLeftWall){
        v_motion = {f_speed, 0};
    }
    else if(state == eState::BouncedRightWall){
        v_motion = {-f_speed, 0};
    }
    else if(state == eState::BouncedTopWall){
        v_motion = {f_speed * (float)std::sin(f_angle/180.f * M_PI), f_speed * (float)std::cos(f_angle/180.f * M_PI)};
    }
    else if(state == eState::BouncedBottomWall){
        v_motion = {f_speed * (float)std::sin(f_angle/180.f * M_PI), f_speed * (float)std::cos(f_angle/180.f * M_PI)};
    }
    else if(state == eState::Launched){
        //Start direction
        if(b_dir_left)
            v_motion = {f_speed * (float)std::sin(f_angle/180.f * M_PI), f_speed * (float)std::cos(f_angle/180.f * M_PI)};
        if(b_dir_right)
            v_motion = {f_speed * (float)std::sin(f_angle/180.f * M_PI), f_speed * (float)std::cos(f_angle/180.f * M_PI)};
    }
    else if (state == eState::Peace){
        this->launch();
    }
    this->wallCollision();
    this->rect_ball.move(v_motion);
}

void Ball::launch()
{
    state = eState::Launched;
    srand(time(0));
    int dir = std::rand() % 2;
    std::cout << dir << std::endl;
    if(dir == 0){
        b_dir_left = true;
        f_angle = std::rand() % 180 + 1;
    }
    else if (dir == 1){
        b_dir_right = true;
        f_angle = std::rand() % 180 + 181;
    }
}

void Ball::wallCollision()
{
    if(this->rect_ball.getPosition().x - this->rect_ball.getOrigin().x <= 0){
        state = eState::BouncedLeftWall;
    }
    else if(this->rect_ball.getPosition().x + this->rect_ball.getOrigin().x >= WIDTH){
        state = eState::BouncedRightWall;
    }
    else if(this->rect_ball.getPosition().y - this->rect_ball.getOrigin().y <= 0){
        f_angle += 180;
        state = eState::BouncedTopWall;
    }
    else if(this->rect_ball.getPosition().y + this->rect_ball.getOrigin().y >= HEIGHT){
        f_angle -= 180;
        state = eState::BouncedBottomWall;
    }
}

void Ball::collides(Paddle *paddle)
{

}

void Ball::bounces(Paddle *paddle)
{

}

void Ball::reset()
{

}

#include <iostream>
#include <random>
#include <cmath>

#include "ball.h"

Ball::Ball(sf::RenderWindow *window):
    renwin_window(window)
{
    state = eState::Start;
    b_dir_left = false;
    b_dir_right = false;
    vec_angle = {0.f, 0.f};
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
    f_speed = time.asMilliseconds() * 0.3f;

    sf::Vector2f v_motion (0.f, 0.f);

    //choose state of ball
    if(state == eState::Passed){
        this->reset();
    }
    else if(state == eState::Bounced){
        v_motion = calculateMove();
        state = eState::Launched;
    }
    else if(state == eState::Launched){
        this->wallCollision();
        v_motion = calculateMove();
    }
    else if(state == eState::Start){
        this->launch();
    }

    this->rect_ball.move(v_motion);
}

void Ball::launch()
{
    state = eState::Launched;
    srand(time(0));
    int dir = std::rand() % 2;
    //choose direction
    do{
        if(dir == 0){
            vec_angle.x = vec_angle.y = std::rand() % 180 + 1;
        }
        else if (dir == 1){
            vec_angle.x = vec_angle.y = std::rand() % 180 + 181;
        }
    } while (vec_angle.x < 100 && vec_angle.x > 80);
}

void Ball::wallCollision()
{
    if(this->rect_ball.getPosition().y - this->rect_ball.getOrigin().y <= 0 &&
            state != eState::Bounced){
        vec_angle.y = 180.f - vec_angle.y;
        state = eState::Bounced;
    }
    if(this->rect_ball.getPosition().y + this->rect_ball.getOrigin().y >= HEIGHT &&
            state != eState::Bounced)
    {
        vec_angle.y = 180.f - vec_angle.y;
        state = eState::Bounced;
    }
}

void Ball::collides(Paddle *paddle)
{
    if(paddle->getPlayer() == 0){
        if((this->rect_ball.getPosition().x - this->rect_ball.getOrigin().x <=
                paddle->getRect().getPosition().x + paddle->getRect().getOrigin().x) &&
                (this->rect_ball.getPosition().x - this->rect_ball.getOrigin().x >
                 paddle->getRect().getPosition().x) &&
                (this->rect_ball.getPosition().y - this->rect_ball.getOrigin().y <=
                 paddle->getRect().getPosition().y + paddle->getRect().getOrigin().y) &&
                (this->rect_ball.getPosition().y + this->rect_ball.getOrigin().y >=
                 paddle->getRect().getPosition().y - paddle->getRect().getOrigin().y)){
            //std::cout << paddle->getRect().getPosition().x << " " << 0 << std::endl;
            vec_angle.x *= -1.0f;
            state = eState::Bounced;
        }
    }
    else if(paddle->getPlayer() == 1){
        if((this->rect_ball.getPosition().x + this->rect_ball.getOrigin().x >=
                paddle->getRect().getPosition().x - paddle->getRect().getOrigin().x) &&
                (this->rect_ball.getPosition().x + this->rect_ball.getOrigin().x <
                 paddle->getRect().getPosition().x) &&
                (this->rect_ball.getPosition().y - this->rect_ball.getOrigin().y <=
                 paddle->getRect().getPosition().y + paddle->getRect().getOrigin().y) &&
                (this->rect_ball.getPosition().y + this->rect_ball.getOrigin().y >=
                 paddle->getRect().getPosition().y - paddle->getRect().getOrigin().y)){
            //std::cout << paddle->getRect().getPosition().x << " " << 1 << std::endl;
            vec_angle.x *= -1.0f;
            state = eState::Bounced;
        }
    }
}

bool Ball::passed(Paddle *paddle)
{
    if(paddle->getPlayer() == 0){
        if((this->rect_ball.getPosition().x - this->rect_ball.getOrigin().x <=
                paddle->getRect().getPosition().x)){
            state = eState::Passed;
            paddle->incScore();
            return true;
            //std::cout << paddle->getScore() << std::endl;
        }
    }
    else if(paddle->getPlayer() == 1){
        if((this->rect_ball.getPosition().x + this->rect_ball.getOrigin().x >=
                paddle->getRect().getPosition().x)){
            state = eState::Passed;
            paddle->incScore();
            return true;
            //std::cout << paddle->getScore() << std::endl;
        }
    }
    return false;;
}

void Ball::reset()
{
    state = eState::Start;
    this->rect_ball.setPosition(start_pos);
    b_dir_left = false;
    b_dir_right = false;
    vec_angle = {0.f, 0.f};
    f_speed = 0.f;
}

sf::Vector2f Ball::calculateMove()
{
    return {f_speed * (float)std::sin(M_PI * vec_angle.x/180.f),
                f_speed * (float)std::cos(M_PI * vec_angle.y/180.f)};
}

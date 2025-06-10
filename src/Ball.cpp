#include "Ball.hpp"

#include <cmath>

void Ball::reset_ball()
{
    this->rect.set_x(this->init_x);
    this->rect.set_y(this->init_y);
    this->speed = this->init_speed;
    this->angle = this->init_angle;
}

void Ball::logic(const double time, Paddle& paddle)
{
    this->speed = (1+time/(1<<7))*this->speed;
    float new_x = this->rect.x()+time*this->speed*std::cos(this->angle);
    if(new_x+this->rect.w() > this->x_bound)
        new_x = 2*(this->x_bound-this->rect.w())-new_x,
        this->angle = PI-this->angle;
    else if(new_x < 0)
        new_x = -new_x,
        this->angle = PI-this->angle;
    float new_y = this->rect.y()+time*this->speed*std::sin(this->angle);
    if(paddle.check_collision(this->rect))
        new_y = 2*(paddle.y()-this->rect.h())-new_y,
        this->angle = -(Ball::distribution(Ball::rng)*0.9+0.05)*PI,
        paddle.swap_player();
    if(new_y < 0)
        new_y = -new_y,
        this->angle = -this->angle;
    if(new_y > this->y_bound+this->rect.h())
        this->reset_ball(),
        paddle.increment_score();
    else
        this->rect.set_x(new_x),
        this->rect.set_y(new_y);
}
#ifndef BALL_HPP
#define BALL_HPP

#include "Entity.hpp"
#include "Paddle.hpp"
#include "Rectangle.hpp"

#include <random>

extern const double PI;

class Ball : public Entity
{
public:
    Ball(float _x, float _y, int _w, int _h, double speed, double angle, int window_w, int window_h, sf::Color _color = sf::Color::White)
        : rect(_x, _y, _w, _h, _color), speed{speed}, angle{angle}, x_bound{window_w}, y_bound{window_h},
          init_x{_x}, init_y{_y}, init_speed{speed}, init_angle{angle} {}
    void reset_ball();
    void logic(const double time, Paddle& paddle);
    void render(sf::RenderWindow& window) const {this->rect.render(window);}

    inline static std::random_device rng;
    inline static std::uniform_real_distribution<double> distribution;
private:
    float init_x, init_y;
    double init_speed, init_angle;

    double speed, angle;
    Rectangle rect;
    int x_bound, y_bound;
};

#endif // BALL_HPP
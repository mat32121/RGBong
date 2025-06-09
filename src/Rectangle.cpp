#include "Rectangle.hpp"

Rectangle::Rectangle(float _x, float _y, int _w, int _h, sf::Color _color)
{
    this->set_x(_x);
    this->set_y(_y);
    this->set_w(_w);
    this->set_h(_h);
    this->set_color(_color);
}

bool Rectangle::check_collision(const Rectangle& other) const
{
    return ((this->x() <= other.x() && other.x() <= this->x()+this->w())
            || (this->x() <= other.x()+other.w() && other.x()+other.w() <= this->x()+this->w())
            || (other.x() <= this->x() && this->x() <= other.x()+other.w())
            || (other.x() <= this->x()+this->w() && this->x()+this->w() <= other.x()+other.w()))
        && ((this->y() <= other.y() && other.y() <= this->y()+this->h())
            || (this->y() <= other.y()+other.h() && other.y()+other.h() <= this->y()+this->h())
            || (other.y() <= this->y() && this->y() <= other.y()+other.h())
            || (other.y() <= this->y()+this->h() && this->y()+this->h() <= other.y()+other.h()));
}

void Rectangle::render(sf::RenderWindow& window) const
{
    window.draw(this->_shape);
}
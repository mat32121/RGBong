#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class Rectangle
{
public:
    Rectangle(float _x, float _y, int _w, int _h, sf::Color _color = sf::Color::White);

    void set_x(float val) {this->_shape.setPosition({val, this->y()});}
    void set_y(float val) {this->_shape.setPosition({this->x(), val});}
    void set_w(int val) {this->_shape.setSize({val, this->h()});}
    void set_h(int val) {this->_shape.setSize({this->w(), val});}
    void set_color(sf::Color val) {this->_shape.setFillColor(val);}

    float x() const {return (int)this->_shape.getPosition().x;}
    float y() const {return (int)this->_shape.getPosition().y;}
    int w() const {return (int)this->_shape.getSize().x;}
    int h() const {return (int)this->_shape.getSize().y;}
    sf::Color color() const {return this->_shape.getFillColor();}
    
    bool check_collision(const Rectangle& other) const;
    
    void render(sf::RenderWindow& window) const;
    
private:
    sf::RectangleShape _shape;
};

#endif // RECTANGLE_HPP
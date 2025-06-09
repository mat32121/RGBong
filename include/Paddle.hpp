#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "Entity.hpp"
#include "Rectangle.hpp"
#include "KeyMap.hpp"

class Paddle : public Entity
{
public:
    Paddle(float _x, float _y, int _w, int _h, sf::Color _color = sf::Color::White)
        : rect{_x, _y, _w, _h, _color}, speed{2*_w}, current_player{0} {}
    void logic(const double time);
    void render(sf::RenderWindow& window) const {this->rect.render(window);}
    
    void swap_player();
    void increment_score();

    float x() const {return (int)this->rect.x();}
    float y() const {return (int)this->rect.y();}
    int w() const {return (int)this->rect.w();}
    int h() const {return (int)this->rect.h();}
    bool check_collision(const Rectangle& other) const {return this->rect.check_collision(other);}
private:
    Rectangle rect;
    const float speed;
    int current_player;
    int score[KeyMap::NUM_PLAYERS];
};

#endif // PADDLE_HPP
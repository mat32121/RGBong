#ifndef PADDLE_HPP
#define PADDLE_HPP

#include "Entity.hpp"
#include "Rectangle.hpp"
#include "KeyMap.hpp"

#include <array>

class Paddle : public Entity
{
public:
    Paddle(float _x, float _y, int _w, int _h, int window_w, std::array<sf::Color, KeyMap::NUM_PLAYERS> _colors = {sf::Color::Yellow, sf::Color::Blue});
    void logic(const double time);
    void render(sf::RenderWindow& window) const override {this->rect.render(window);}
    
    void swap_player();
    void increment_score();
    int get_score(int player);

    float x() const {return (int)this->rect.x();}
    float y() const {return (int)this->rect.y();}
    int w() const {return (int)this->rect.w();}
    int h() const {return (int)this->rect.h();}
    bool check_collision(const Rectangle& other) const {return this->rect.check_collision(other);}
private:
    Rectangle rect;
    const float speed;
    int current_player;
    std::array<int, KeyMap::NUM_PLAYERS> score;
    const int x_bound;
    std::array<sf::Color, KeyMap::NUM_PLAYERS> colors;
};

#endif // PADDLE_HPP
#include "Paddle.hpp"

Paddle::Paddle(float _x, float _y, int _w, int _h, int window_w, std::array<sf::Color, KeyMap::NUM_PLAYERS> _colors)
    : rect{_x, _y, _w, _h, _colors[0]}, speed{2*_w}, current_player{0}, x_bound{window_w}, colors{_colors}
{
    for(int i = 0; i < KeyMap::NUM_PLAYERS; ++i)
        this->score[i] = 0;
}

void Paddle::logic(const double time)
{
    if(KeyMap::left(this->current_player) && !KeyMap::right(this->current_player))
        this->rect.set_x(this->x()-time*this->speed);
    if(!KeyMap::left(this->current_player) && KeyMap::right(this->current_player))
        this->rect.set_x(this->x()+time*this->speed);
    if(this->x() < 0)
        this->rect.set_x(0);
    if(this->x()+this->w() > this->x_bound)
        this->rect.set_x(this->x_bound-this->w());
}

void Paddle::swap_player()
{
    this->current_player = (this->current_player+1)%KeyMap::NUM_PLAYERS;
    this->rect.set_color(this->colors[this->current_player]);
}

void Paddle::increment_score()
{
    for(int i = 0; i < KeyMap::NUM_PLAYERS; ++i)
        if(i != this->current_player)
            ++score[i];
}

int Paddle::get_score(int player)
{
    if(player >= KeyMap::NUM_PLAYERS)
        throw std::out_of_range("Invalid player number");
    return this->score[player];
}
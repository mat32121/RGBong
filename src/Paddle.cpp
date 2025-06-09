#include "Paddle.hpp"

void Paddle::logic(const double time)
{
    if(KeyMap::left(this->current_player) && !KeyMap::right(this->current_player))
        this->rect.set_x(this->x()-time*this->speed);
    if(!KeyMap::left(this->current_player) && KeyMap::right(this->current_player))
        this->rect.set_x(this->x()+time*this->speed);
    // if(this->x() < 0)
    //     this->rect.set_x(0);
    // if(this->x()+this->w() > WIDTH)
    //     this->rect.set_x(0);
}

void Paddle::swap_player()
{
    this->current_player = (this->current_player+1)%KeyMap::NUM_PLAYERS;
}

void Paddle::increment_score()
{
    for(int i = 0; i < KeyMap::NUM_PLAYERS; ++i)
        if(i != this->current_player)
            ++score[i];
}
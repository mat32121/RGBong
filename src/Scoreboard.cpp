#include "Scoreboard.hpp"

Scoreboard::Scoreboard(int num_players, int window_w, int window_h, std::array<sf::Color, KeyMap::NUM_PLAYERS> colors) : x_bound{window_w}, num_players{num_players}
{
    if(num_players > KeyMap::NUM_PLAYERS)
        throw std::out_of_range("Player number unsupported");
    this->font.loadFromFile("font.ttf");
    for(int i = 0; i < num_players; ++i)
        this->scores[i] = 0,
        this->score_text[i].setString("0"),
        this->score_text[i].setFont(this->font),
        this->score_text[i].setCharacterSize(window_h/20),
        this->score_text[i].setFillColor(colors[i]);
    this->toggle_offset();
}

void Scoreboard::set_score(int player, int score_value)
{
    if(player >= KeyMap::NUM_PLAYERS || player >= this->num_players)
        throw std::out_of_range("Invalid player number");
    this->score_text[player].setString(std::to_string(score_value));
    this->toggle_offset();
}

int Scoreboard::score(int player) const
{
    if(player >= KeyMap::NUM_PLAYERS || player >= this->num_players)
        throw std::out_of_range("Invalid player number");
    return this->scores[player];
}

void Scoreboard::render(sf::RenderWindow& window) const
{
    for(int i = 0; i < this->num_players; ++i)
        window.draw(this->score_text[i]);
}

void Scoreboard::toggle_offset()
{
    if(this->num_players > 1)
        this->score_text[1].setOrigin(-this->x_bound+this->score_text[1].getLocalBounds().width+this->score_text[1].getCharacterSize(), 0);
}
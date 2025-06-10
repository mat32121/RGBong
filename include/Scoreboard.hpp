#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

#include "Entity.hpp"
#include "KeyMap.hpp"

#include <array>

class Scoreboard : public Entity
{
public:
    Scoreboard(int num_players, int window_w, int window_h, std::array<sf::Color, KeyMap::NUM_PLAYERS> colors = {sf::Color::Yellow, sf::Color::Blue});

    void set_score(int player, int score_value);
    int score(int player) const;
    
    void render(sf::RenderWindow& window) const override;

private:
    void toggle_offset();

    std::array<int, KeyMap::NUM_PLAYERS> scores;
    std::array<sf::Text, KeyMap::NUM_PLAYERS> score_text;
    const int num_players;
    const int x_bound;
    
    sf::Font font;
};

#endif // SCOREBOARD_HPP
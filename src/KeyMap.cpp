#include "KeyMap.hpp"

#include <stdexcept>

void KeyMap::reset_input() noexcept
{
    for(int i = 0; i < KeyMap::NUM_PLAYERS; ++i)
        for(int j = 0; j < KeyMap::NUM_KEYS; ++j)
            KeyMap::keys[i][j] = false;
}

void KeyMap::parse_input(const sf::Event& event)
{
    for(int i = 0; i < KeyMap::NUM_PLAYERS; ++i)
        for(int j = 0; j < KeyMap::NUM_KEYS; ++j)
            if(event.key.code == KeyMap::key_mappings[i][j])
                KeyMap::keys[i][j] = (event.type == sf::Event::KeyPressed);
}

bool KeyMap::left(int player)
{
    if(player >= KeyMap::NUM_PLAYERS)
        throw std::out_of_range("Invalid player number");
    return KeyMap::keys[player][0];
}

bool KeyMap::right(int player)
{
    if(player >= KeyMap::NUM_PLAYERS)
        throw std::out_of_range("Invalid player number");
    return KeyMap::keys[player][1];
}
#ifndef KEYMAP_HPP
#define KEYMAP_HPP

#include <SFML/Graphics.hpp>

class KeyMap
{
public:
    static void reset_input() noexcept;
    static void parse_input(const sf::Event& event);
    static bool left(int player);
    static bool right(int player);

    static constexpr int NUM_PLAYERS = 2;
    static constexpr int NUM_KEYS = 2;
private:
    inline static bool keys[KeyMap::NUM_PLAYERS][KeyMap::NUM_KEYS];
    static constexpr sf::Keyboard::Key key_mappings[KeyMap::NUM_PLAYERS][KeyMap::NUM_KEYS] =
    {
        {sf::Keyboard::Key::A, sf::Keyboard::Key::D},
        {sf::Keyboard::Key::Left, sf::Keyboard::Key::Right}
    };
};

#endif // KEYMAP_HPP
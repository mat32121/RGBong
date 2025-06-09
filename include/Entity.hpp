#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity
{
public:
    virtual void render(sf::RenderWindow& window) const = 0;
};

#endif // ENTITY_HPP
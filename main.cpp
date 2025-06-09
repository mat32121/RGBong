#include <array>
#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Ball.hpp"
#include "Paddle.hpp"
#include "KeyMap.hpp"

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;
constexpr double FPS = 60;

const double PI = std::acos(-1);

int main()
{
    sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "RGBong");
    window.setFramerateLimit(FPS);

    Paddle paddle(WIDTH/2-HEIGHT/10, HEIGHT-HEIGHT/40, HEIGHT/5, HEIGHT/50);
    Ball ball(paddle.x()+paddle.w()/2, paddle.y()-paddle.h(), paddle.h(), paddle.h(), HEIGHT/2, -PI/4, WIDTH, HEIGHT);
    const std::array<Entity*, 2> entities({&paddle, &ball});

    sf::Clock clock;
    sf::Time accumulator = sf::Time::Zero;
    const sf::Time fps = sf::seconds(1.0/FPS);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
            switch(event.type)
            {
                case sf::Event::Closed: window.close(); break;
                case sf::Event::KeyReleased:
                case sf::Event::KeyPressed: KeyMap::parse_input(event); break;
            }

        accumulator = clock.restart();
        ball.logic(accumulator.asSeconds(), paddle);
        paddle.logic(accumulator.asSeconds());

        window.clear(sf::Color::Black);
        for(const Entity* entity : entities)
            entity->render(window);
        window.display();
    }
    return 0;
}
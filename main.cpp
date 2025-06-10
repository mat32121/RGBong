#include <array>
#include <cmath>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Ball.hpp"
#include "Paddle.hpp"
#include "KeyMap.hpp"
#include "Scoreboard.hpp"

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;
constexpr double FPS = 60;

const double PI = std::acos(-1);

int main()
{
    sf::RenderWindow window(sf::VideoMode({WIDTH, HEIGHT}), "RGBong");
    window.setFramerateLimit(FPS);

    Scoreboard scoreboard(KeyMap::NUM_PLAYERS, WIDTH, HEIGHT);
    Paddle paddle(WIDTH/2-HEIGHT/10, HEIGHT-HEIGHT/40, HEIGHT/5, HEIGHT/50, WIDTH);
    Ball ball(paddle.x()+paddle.w()/2, paddle.y()-paddle.h()-1, paddle.h(), paddle.h(), HEIGHT/2, -PI/4, WIDTH, HEIGHT);
    const std::array<Entity*, 3> entities({&scoreboard, &ball, &paddle});

    sf::Clock clock;
    sf::Time accumulator = sf::Time::Zero;
    const sf::Time fps = sf::seconds(1.0/FPS);

    bool paused = true;
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
            switch(event.type)
            {
                case sf::Event::Closed: window.close(); break;
                case sf::Event::KeyPressed: if(event.key.code == sf::Keyboard::Space) paused ^= true;
                case sf::Event::KeyReleased: KeyMap::parse_input(event); break;
            }

        accumulator = clock.restart();
        if(!paused)
        {
            ball.logic(accumulator.asSeconds(), paddle);
            paddle.logic(accumulator.asSeconds());
            for(int i = 0; i < KeyMap::NUM_PLAYERS; ++i)
                scoreboard.set_score(i, paddle.get_score(i));
        }

        window.clear(sf::Color::Black);
        for(const Entity* entity : entities)
            entity->render(window);
        window.display();
    }
    return 0;
}
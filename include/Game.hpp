#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "ObstacleManager.hpp"
#include "ResourceManager.hpp"



class Game {
public:
    Game();
    void run();
    static constexpr unsigned WINDOW_W = 1280;
    static constexpr unsigned WINDOW_H = 720;

private:
    void processEvents();
    void update(sf::Time dt);
    void render();

    sf::RenderWindow   window_;
    ResourceManager    resources_;
    Player             player_;
    ObstacleManager    obstacles_;
    sf::Font           font_;
    sf::Text           scoreText_;
    unsigned int       score_ = 0;
    sf::Clock          scoreClock_;
};

#endif // GAME_HPP

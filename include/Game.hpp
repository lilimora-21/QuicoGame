#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "ObstacleManager.hpp"
#include "ResourceManager.hpp"
#include <SFML/Audio.hpp>


class Game {
public:
    Game();
    void run();
    static constexpr unsigned WINDOW_W = 1280;
    static constexpr unsigned WINDOW_H = 720;

private:
    void showIntro();
    void processEvents();
    void update(sf::Time dt);
    void render();
    void showGameOver();

    sf::Texture introBackgroundTexture_;   
    sf::Sprite  introBackgroundSprite_; 
    sf::Music backgroundMusic_; 
    sf::SoundBuffer gameOverBuffer_;
    sf::Sound       gameOverSound_;
    sf::RenderWindow   window_;
    sf::Texture gameOverTexture_;
    sf::Sprite  gameOverSprite_;
    ResourceManager    resources_;
    Player             player_;
    ObstacleManager    obstacles_;
    sf::Font           font_;
    sf::Text           scoreText_;
    unsigned int       score_ = 0;
    sf::Clock          scoreClock_;

    sf::Texture        backgroundTexture_;   
    sf::Sprite         backgroundSprite_;    
};

#endif // GAME_HPP

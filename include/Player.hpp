#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Player {
public:
    Player(sf::Texture& texture);
    void    handleInput();
    void    update(sf::Time dt);
    void    draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;

private:
    sf::SoundBuffer jumpBuffer_;
    sf::Sound       jumpSound_;
    sf::Sprite sprite_;
    float      velocityY_ = 0.f;
    bool       isJumping_ = false;
    const float gravity_  = 981.f; // px/s²
    const float jumpSpeed_ = -700.f;
};

#endif // PLAYER_HPP

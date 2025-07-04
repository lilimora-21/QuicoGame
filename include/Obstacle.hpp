#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <SFML/Graphics.hpp>

enum class ObstacleType { Barrel, Papalote };

class Obstacle {
public:
    Obstacle(ObstacleType type, sf::Texture& tex, float startX);
    void update(sf::Time dt, float speedMultiplier);
    void          draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;

private:
    sf::Sprite   sprite_;
    float        speed_ = 200.f;
    ObstacleType type_;
};

#endif // OBSTACLE_HPP

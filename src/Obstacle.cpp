#include "Obstacle.hpp"

Obstacle::Obstacle(ObstacleType type, sf::Texture& tex, float startX)
: type_(type)
{
    sprite_.setTexture(tex);
    sprite_.setScale(0.1f, 0.1f);

    float y = 530.f; // Altura por defecto (barril)
    if (type == ObstacleType::Papalote) {
        y = 350.f; // Más arriba para el papalote
    }
    sprite_.setPosition(startX, y);
}
void Obstacle::update(sf::Time dt, float speedMultiplier) {
    sprite_.move(-speed_ * speedMultiplier * dt.asSeconds(), 0.f);
}

void Obstacle::draw(sf::RenderWindow& window) {
    window.draw(sprite_);
}

sf::FloatRect Obstacle::getBounds() const {
    return sprite_.getGlobalBounds();
}

#include "Obstacle.hpp"

Obstacle::Obstacle(ObstacleType type, sf::Texture& tex, float startX)
: type_(type)
{
    sprite_.setTexture(tex);
    sprite_.setScale(0.20f, 0.20f);
    sprite_.setPosition(startX, 300.f);
}

void Obstacle::update(sf::Time dt) {
    sprite_.move(-speed_ * dt.asSeconds(), 0.f);
}

void Obstacle::draw(sf::RenderWindow& window) {
    window.draw(sprite_);
}

sf::FloatRect Obstacle::getBounds() const {
    return sprite_.getGlobalBounds();
}

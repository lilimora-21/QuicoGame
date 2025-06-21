#include "Player.hpp"

Player::Player(sf::Texture& texture) {
    sprite_.setTexture(texture);
    sprite_.setScale(0.2f, 0.2f);
    sprite_.setPosition(100.f, 300.f);
}

void Player::handleInput() {
    if (!isJumping_ && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        isJumping_ = true;
        velocityY_ = jumpSpeed_;
    }
}

void Player::update(sf::Time dt) {
    if (isJumping_) {
        velocityY_ += gravity_ * dt.asSeconds();
        sprite_.move(0.f, velocityY_ * dt.asSeconds());

        if (sprite_.getPosition().y >= 300.f) {
            sprite_.setPosition(sprite_.getPosition().x, 300.f);
            isJumping_ = false;
            velocityY_ = 0.f;
        }
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite_);
}

sf::FloatRect Player::getBounds() const {
    return sprite_.getGlobalBounds();
}

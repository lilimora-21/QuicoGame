#include "Player.hpp"
#include <iostream>


Player::Player(sf::Texture& texture) {
    sprite_.setTexture(texture);
    sprite_.setScale(0.3f, 0.3f);
    sprite_.setPosition(200.f, 500.f);

    if (!jumpBuffer_.loadFromFile("resources/salto.ogg")) {
        std::cout << "No se pudo cargar el sonido de salto\n";
    }
    jumpSound_.setBuffer(jumpBuffer_);
}

void Player::handleInput() {
    if (!isJumping_ && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        isJumping_ = true;
        velocityY_ = jumpSpeed_;
         jumpSound_.play();
    }
}

void Player::update(sf::Time dt) {
    if (isJumping_) {
        velocityY_ += gravity_ * dt.asSeconds();
        sprite_.move(0.f, velocityY_ * dt.asSeconds());

        if (sprite_.getPosition().y >= 500.f) {
            sprite_.setPosition(sprite_.getPosition().x, 500.f);
            velocityY_ = 0.f; 
            isJumping_ = false;
            
        }
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite_);
}

sf::FloatRect Player::getBounds() const {
    return sprite_.getGlobalBounds();
}

#include "ObstacleManager.hpp"
#include "Game.hpp"

ObstacleManager::ObstacleManager(ResourceManager& resources)
: resources_(resources)
{}

void ObstacleManager::spawn() {
    ObstacleType type = (rand() % 2 == 0) ? ObstacleType::Barrel : ObstacleType::Papalote;
    auto& tex = resources_.getTexture(
        (type == ObstacleType::Barrel) ? "barril.png" : "papalote.png"
    );
    float startX = Game::WINDOW_W + 50.f;
    obstacles_.push_back(std::make_unique<Obstacle>(type, tex, startX));
}

void ObstacleManager::update(sf::Time dt, float speedMultiplier) {
    if (spawnClock_.getElapsedTime().asSeconds() > 2.5f) {
        spawn();
        spawnClock_.restart();
    }
    for (auto& obs : obstacles_)
        obs->update(dt, speedMultiplier);

    obstacles_.erase(
      std::remove_if(obstacles_.begin(), obstacles_.end(),
        [](auto& o){ return o->getBounds().left + o->getBounds().width < 0; }),
      obstacles_.end()
    );
}

void ObstacleManager::draw(sf::RenderWindow& window) {
    for (auto& obs : obstacles_)
        obs->draw(window);
}

bool ObstacleManager::checkCollision(const sf::FloatRect& playerBounds) {
    for (auto& obs : obstacles_)
        if (obs->getBounds().intersects(playerBounds))
            return true;
    return false;
}

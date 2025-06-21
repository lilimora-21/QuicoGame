#ifndef OBSTACLE_MANAGER_HPP
#define OBSTACLE_MANAGER_HPP

#include "Obstacle.hpp"
#include "ResourceManager.hpp"
#include <SFML/System.hpp>
#include <vector>
#include <memory>

class ObstacleManager {
public:
    ObstacleManager(ResourceManager& resources);
    void update(sf::Time dt);
    void draw(sf::RenderWindow& window);
    bool checkCollision(const sf::FloatRect& playerBounds);
    
private:
    void spawn();

    ResourceManager& resources_;
    sf::Clock        spawnClock_;
    std::vector<std::unique_ptr<Obstacle>> obstacles_;
};

#endif // OBSTACLE_MANAGER_HPP

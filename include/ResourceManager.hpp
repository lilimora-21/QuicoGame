#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class ResourceManager {
public:
    sf::Texture& getTexture(const std::string& filename);
    sf::Font&    getFont(const std::string& filename);

private:
    std::map<std::string, sf::Texture> textures_;
    std::map<std::string, sf::Font>    fonts_;
};

#endif // RESOURCE_MANAGER_HPP

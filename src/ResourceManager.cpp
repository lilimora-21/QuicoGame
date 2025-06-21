#include "ResourceManager.hpp"
#include <stdexcept>

sf::Texture& ResourceManager::getTexture(const std::string& filename) {
    auto it = textures_.find(filename);
    if (it != textures_.end()) return it->second;

    sf::Texture tex;
    if (!tex.loadFromFile("resources/" + filename))
        throw std::runtime_error("No se pudo cargar textura: " + filename);
    textures_[filename] = tex;
    return textures_[filename];
}

sf::Font& ResourceManager::getFont(const std::string& filename) {
    auto it = fonts_.find(filename);
    if (it != fonts_.end()) return it->second;

    sf::Font font;
    if (!font.loadFromFile("resources/" + filename))
        throw std::runtime_error("No se pudo cargar fuente: " + filename);
    fonts_[filename] = font;
    return fonts_[filename];
}

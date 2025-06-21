#include "Game.hpp"
#include <sstream>

Game::Game()
: window_(sf::VideoMode(WINDOW_W, WINDOW_H), "Quico Chrome")
, player_(resources_.getTexture("quico.png"))
, obstacles_(resources_)
{
    font_ = resources_.getFont("font.ttf");
    scoreText_.setFont(font_);
    scoreText_.setCharacterSize(24);
    scoreText_.setPosition(10.f, 10.f);
}

void Game::run() {
    sf::Clock clock;
    while (window_.isOpen()) {
        processEvents();
        sf::Time dt = clock.restart();
        update(dt);
        render();
    }
}

void Game::processEvents() {
    sf::Event e;
    while (window_.pollEvent(e)) {
        if (e.type == sf::Event::Closed)
            window_.close();
    }
    player_.handleInput();
}

void Game::update(sf::Time dt) {
    player_.update(dt);
    obstacles_.update(dt);

    if (obstacles_.checkCollision(player_.getBounds()))
        window_.close(); // fin de juego

    if (scoreClock_.getElapsedTime().asSeconds() >= 1.f) {
        score_ += 10;
        scoreClock_.restart();
    }
    std::ostringstream ss;
    ss << "Score: " << score_;
    scoreText_.setString(ss.str());
}

void Game::render() {
    window_.clear(sf::Color::White);
    player_.draw(window_);
    obstacles_.draw(window_);
    window_.draw(scoreText_);
    window_.display();
}

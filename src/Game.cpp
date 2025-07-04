#include "Game.hpp"
#include <sstream>
#include <filesystem>
#include <iostream> 
#include <SFML/Audio.hpp>

    void Game::showIntro() {
    sf::Text introText;
    introText.setFont(font_);
    introText.setString("");
    introText.setCharacterSize(48);
    introText.setFillColor(sf::Color::Black);
    introText.setPosition(WINDOW_W / 2.f - 350.f, WINDOW_H / 2.f - 50.f);

    while (window_.isOpen()) {
        sf::Event event;
        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window_.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                return;
        }
        window_.clear();
        window_.draw(introBackgroundSprite_);
        window_.draw(introText);
        window_.display();
    }
}

Game::Game()
: window_(sf::VideoMode(WINDOW_W, WINDOW_H), "Quico Chrome")
, player_(resources_.getTexture("quico.png"))
, obstacles_(resources_)
{
    font_ = resources_.getFont("font.ttf");
    scoreText_.setFont(font_);
    scoreText_.setCharacterSize(24);
    scoreText_.setPosition(10.f, 10.f);
    scoreText_.setFillColor(sf::Color::Black);

    std::cout << "Directorio actual: " << std::filesystem::current_path() << std::endl;

       // Música de fondo
    if (!backgroundMusic_.openFromFile("resources/cancionchavo.ogg")) {
        std::cout << "No se pudo cargar la música de fondo\n";
    }
    backgroundMusic_.setLoop(true);
    backgroundMusic_.play();

     // Sonido de Game Over
    if (!gameOverBuffer_.loadFromFile("resources/gameover.ogg")) {
        std::cout << "No se pudo cargar el sonido de Game Over\n";
    }
    gameOverSound_.setBuffer(gameOverBuffer_);

    // Cargar la imagen de fondo del intro
    if (!introBackgroundTexture_.loadFromFile("resources/intro.png")) {
        std::cout << "No se pudo cargar la imagen de fondo del intro\n";
    }
    introBackgroundSprite_.setTexture(introBackgroundTexture_);
    introBackgroundSprite_.setScale(
        float(WINDOW_W) / introBackgroundTexture_.getSize().x,
        float(WINDOW_H) / introBackgroundTexture_.getSize().y
    );
    
    // Cargar la imagen de fondo
    if (!backgroundTexture_.loadFromFile("resources/fondo.png")) {
        std::cout << "No se pudo cargar la imagen de fondo\n"; 
    }
    backgroundSprite_.setTexture(backgroundTexture_);
    backgroundSprite_.setScale(
    float(WINDOW_W) / backgroundTexture_.getSize().x,
    float(WINDOW_H) / backgroundTexture_.getSize().y
    );
    // Cargar la imagen de Game Over
    if (!gameOverTexture_.loadFromFile("resources/gameover.png")) {
    std::cout << "No se pudo cargar la imagen de Game Over\n";
    }
    gameOverSprite_.setTexture(gameOverTexture_);
    gameOverSprite_.setScale(
    float(WINDOW_W) / gameOverTexture_.getSize().x,
    float(WINDOW_H) / gameOverTexture_.getSize().y
);
}

void Game::run() {
    showIntro();
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
    float elapsed = scoreClock_.getElapsedTime().asSeconds();
    float speedMultiplier = 1.0f + elapsed * 0.5f; // Aumenta 5% por segundo

    player_.update(dt);
    obstacles_.update(dt, speedMultiplier);

    if (obstacles_.checkCollision(player_.getBounds())) {
        showGameOver();
        return;
    }

    if (scoreClock_.getElapsedTime().asSeconds() >= 1.f) {
        score_ += 10;
        scoreClock_.restart();
    }
    std::ostringstream ss;
    ss << "Score: " << score_;
    scoreText_.setString(ss.str());
}

void Game::render() {
    window_.clear();
    window_.draw(backgroundSprite_); 
    player_.draw(window_);
    obstacles_.draw(window_);
    window_.draw(scoreText_);
    window_.display();
}
void Game::showGameOver() {
    backgroundMusic_.stop();  
    gameOverSound_.play();

    sf::Text gameOverText;
    gameOverText.setFont(font_);
    gameOverText.setString("");
    gameOverText.setCharacterSize(64);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(WINDOW_W / 2.f - 300.f, WINDOW_H / 2.f - 100.f);

    while (window_.isOpen()) {
        sf::Event event;
        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window_.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window_.close();
        }
        window_.clear();
        window_.draw(gameOverSprite_);
        window_.draw(gameOverText);
        window_.display();
    }
}

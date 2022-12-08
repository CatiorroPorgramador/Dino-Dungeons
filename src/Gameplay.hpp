#pragma once

#include "../include/SFML/Graphics.hpp"
#include "Player.hpp"
 
class Gameplay {
public:
    // Contructor && Destructor
    Gameplay() {
        // Instances
        font.loadFromFile("data/font.ttf");

        fps_string = "FPS: ";
        this->fps_text.setScale(sf::Vector2f(0.8, 0.8));
        this->fps_text.setFont(this->font);
        this->fps_text.setPosition(sf::Vector2f(0.f, 0.f));
        this->fps_text.setString(fps_string);
    }

    ~Gameplay() {
    }

    // Functions
    void update() {
        player.update();

        float currentTime = clock.restart().asSeconds();
        float fps = 1.f / (currentTime - last_time);
        last_time = current_time;

        delta = clock.restart();

        fps_string = "fps: " + std::to_string(static_cast<int>(fps));
        fps_text.setString(fps_string);
    }

    void render(sf::RenderWindow *window) {
        window->draw(this->fps_text);

        player.render(window);
    }

private:
    sf::Clock clock;
    sf::Time delta;
    float last_time{0}, current_time{0}, fps{0};

    Player player;

    sf::Text fps_text;
    std::string fps_string;

    sf::Font font;
};
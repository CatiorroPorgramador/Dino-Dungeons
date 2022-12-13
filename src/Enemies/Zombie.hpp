#pragma once

#include "../include/SFML/Graphics.hpp"

class Zombie {
public:
    // Contructor && Destructor
    Zombie() {
        // Load/Init resources
        texture.loadFromFile("data/enemies/dino-zombie.png");

        rect_source = sf::IntRect();

        // Apply Texture
        sprite.setTexture(this->texture);
        sprite.scale(3.f, 3.f);
        sprite.setPosition(200, 200);
    }

    ~Zombie() {

    }

    void update() {
        this->sprite.move(offset);
    }

    void render(sf::RenderWindow *window) {
        if (live)
            window->draw(this->sprite);
    }

    void kill() {
        live = false;
    }

    sf::Sprite sprite;
    sf::Vector2f offset;

private:
    sf::Texture texture;

    sf::IntRect rect_source;

    bool live = true;

};
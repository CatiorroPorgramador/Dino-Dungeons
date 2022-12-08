#pragma once

#include "../include/SFML/Graphics.hpp"
#include <math.h>

class Player {
public:
    // Constructor && Destructor
    Player() {
        pos = sf::Vector2f(100.f, 40.f);
        scale = sf::Vector2f(3.f, 3.f);
        direction = sf::Vector2f();
        
        speed = 3.f;

        // Load Textures && Sounds
        texture.loadFromFile("data/player/male/doux/base/avoid.png");

        rect_source = sf::IntRect(0, 0, 24, 24);
        
        sprite.setTexture(this->texture);
        sprite.setTextureRect(this->rect_source);
        sprite.setOrigin(sf::Vector2f(8, 8));
        sprite.scale(scale);
        sprite.setPosition(pos);

        // Others
    }

    ~Player() {
        printf("Object Deleted: Player.\n");
    }

    // Methods
    void update() {

        this->sprite.move(direction);

        // Controls
        direction.x = (static_cast<int>(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) -
        static_cast<int>(sf::Keyboard::isKeyPressed(sf::Keyboard::A)));
        direction.y = (static_cast<int>(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) -
        static_cast<int>(sf::Keyboard::isKeyPressed(sf::Keyboard::W)));

        direction = normalize(direction);
        direction.x *= this->speed;
        direction.y *= this->speed;

        float dx = this->sprite.getPosition().x - this->mouse_pos.x;
        float dy = this->sprite.getPosition().y - this->mouse_pos.y;

        float rotation = (atan2(dy, dx)) * 180 / 3.14;

        this->sprite.setRotation(
            rotation
        );
    }

    void render(sf::RenderWindow *window) {
        window->draw(this->sprite);

        // Update
        mouse_pos = sf::Mouse::getPosition(*window);
    }

private:
    sf::Sprite sprite, sword_sprite;
    sf::Texture texture;
    sf::IntRect rect_source;

    sf::Vector2f pos, scale, direction;
    sf::Vector2i mouse_pos;
    float speed;

    sf::Vector2f normalize(const sf::Vector2f& source)
    {
        float length = sqrt((source.x * source.x) + (source.y * source.y));
        if (length != 0)
            return sf::Vector2f(source.x / length, source.y / length);
        else
            return source;
    }
};
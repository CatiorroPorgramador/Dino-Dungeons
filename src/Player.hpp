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
        swords_texture.loadFromFile("data/guns-spritesheet.png");

        rect_source = sf::IntRect(0, 0, 24, 24);
        sprite.setTexture(this->texture);
        sprite.setTextureRect(this->rect_source);
        sprite.setOrigin(sf::Vector2f(12, 8));
        sprite.scale(this->scale);
        sprite.setPosition(pos);

        swords_rect_source = sf::IntRect(16, 0, 16, 16);
        sword_sprite.setTexture(this->swords_texture);
        sword_sprite.setTextureRect(this->swords_rect_source);
        sword_sprite.setOrigin(sf::Vector2f(3, 12));
        sword_sprite.scale(this->scale);    

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

        this->sprite.setScale(
            sf::Vector2f((mouse_pos.x >= this->sprite.getPosition().x) ? scale.x : -scale.x, scale.y)
        );

        float dx = this->sword_sprite.getPosition().x - this->mouse_pos.x;
        float dy = this->sword_sprite.getPosition().y - this->mouse_pos.y;

        float rotation = (atan2(dy, dx)) * 180 / 3.14;

        this->sword_sprite.setRotation(
            rotation-140
        );
        this->sword_sprite.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y+20);
    }

    void render(sf::RenderWindow *window) {
        window->draw(this->sprite);
        window->draw(this->sword_sprite);

        // Update
        mouse_pos = sf::Mouse::getPosition(*window);
    }

private:
    sf::Sprite sprite, sword_sprite;
    sf::Texture texture, swords_texture;
    sf::IntRect rect_source, swords_rect_source;

    sf::Vector2f pos, scale, direction;
    sf::Vector2i mouse_pos;
    float speed;

    sf::Vector2f normalize(const sf::Vector2f& source)
    {
        float length = sqrt((source.x * source.x) + (source.y * source.y));

        return (length != 0) ? sf::Vector2f(source.x / length, source.y / length) : source;
    }
};
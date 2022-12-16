#pragma once

#include "../include/SFML/Graphics.hpp"
#include "Player.hpp"
#include "Enemies/Zombie.hpp"
#include "Engine/Collision.hpp"
#include "Engine/TileMap.hpp"
 
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

        // Level
        level_map.load("data/map.txt");
    }

    ~Gameplay() {
        printf("Gameplay ended.\n");
    }

    // Functions
    void update() {
        // Level Update
        if (Collision::PixelPerfect(player.sword_sprite, zombie.sprite) && player.in_attack)
            zombie.kill();

        float currentTime = clock.restart().asSeconds();
        float fps = 1.f / (currentTime - last_time);
        last_time = current_time;

        delta = clock.restart();

        fps_string = "Fps: " + std::to_string(static_cast<int>(fps));
        fps_text.setString(fps_string);

        // Objects
        level_offset = -player.direction;
        zombie.offset = level_offset;
        level_map.offset = level_offset;

        level_map.update();
        zombie.update();

        player.update();
    }

    void render(sf::RenderWindow *window) {
        window->draw(this->fps_text);

        level_map.render(window);
        
        player.render(window);

        zombie.render(window);
    }

private:
    sf::Clock clock;
    sf::Time delta;
    float last_time{0}, current_time{0}, fps{0};

    Player player;

    sf::Vector2f level_offset;

    Zombie zombie;

    TileMap level_map;

    sf::Text fps_text;
    std::string fps_string;

    sf::Font font;
};
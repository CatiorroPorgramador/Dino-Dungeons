#pragma once

#include "../include/SFML/Graphics.hpp"

//template<typename type>
class TileMap {
public:
    // Constructor && Destructor
    TileMap() {
        // Init variables
        

        scale = 4;

        // Load resources
        texture.loadFromFile("data/dungeons/normal-dungeon/floor-sheet.png");

        // Apply
        for (unsigned int y{}; y < coordinates.size(); ++y) {
            for (unsigned int x{}; x < coordinates[y].size(); ++x) {
                sf::Sprite* ns = new sf::Sprite();
                ns->setTexture(texture);
                ns->setTextureRect(sf::IntRect(coordinates[y][x]*16, 0, 16, 16));
                ns->setPosition(x*(16*scale), y*(16*scale));
                ns->setScale(scale, scale);

                sprites.push_back(ns);
            }
        }
    }

    ~TileMap() {
        for (int i{}; i < sprites.size(); ++i) {
            delete sprites[i];
            printf("Delete tilemap-sprites %d", i);
        }
    }

    // Methods
    void load(const char* filename) {
        FILE* f;
        f = fopen(filename, "r");

        char c;

        if (f) {
            while ((c = getc(f)) != EOF)
			    putchar(c);
        }

        fclose(f); 
    }

    void update() {
        for (auto sprite : sprites) {
            sprite->move(offset);
        }
    }

    void render(sf::RenderWindow* window) {
        for (auto sprite : sprites) {
            window->draw(*sprite);
        }
    }

    sf::Vector2f offset;

private:
    std::vector<std::vector<uint8_t>> coordinates;
    std::vector<sf::Sprite*> sprites;
    sf::Texture texture;

    float scale;
};
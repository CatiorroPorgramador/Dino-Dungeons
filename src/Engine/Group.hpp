#pragma once

#include "../include/SFML/Graphics.hpp"
#include <vector>

//template<typename type>
class Group {
public:
    void add(sf::Sprite sprite) {
        this->sprites.push_back(sprite);
        this->sprites_size = this->sprites.size();
    }

    void remove(sf::Sprite sprite) {
        for (auto& spr : this->sprites) {
            
        }
    }

private:
    std::vector<sf::Sprite> sprites;
    unsigned int sprites_size;
    
};
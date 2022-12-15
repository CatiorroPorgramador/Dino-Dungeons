#pragma once

#include "../include/SFML/Graphics.hpp"

//template<typename type>
class TileMap {
public:
    // Constructor && Destructor
    TileMap() {

    }

    // Methods
    void Load(const char* filename) {
        FILE* f;
        f = fopen(filename, "r");

        char c;

        if (f) {
            while ((c = getc(f)) != EOF)
			    putchar(c);
        }

        fclose(f); 
    }

private:

    
};
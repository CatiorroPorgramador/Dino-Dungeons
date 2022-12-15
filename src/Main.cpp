/*
it init
git add README.md
git commit -m "v0.0.3"
git branch -M main
git remote add origin https://github.com/CatiorroPorgramador/Dino-Dungeons.git
git push -u origin main
*/
#include <math.h>

#include "../include/SFML/Graphics.hpp"

#include "Gameplay.hpp"

int main(int argc, char **argv) {
    printf("Program Init.\n");

    // Window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;
    printf("antialiasingLevel: %d\n", settings.antialiasingLevel);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Dino Meteor Run", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    // Main Scene
    Gameplay *gameplay = new Gameplay();

    // Loop
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color(58, 58, 58, 255));

        // Update
        gameplay->update();

        // Draw
        gameplay->render(&window);

        // end the current frame
        window.display();
    }

    // Ended Program
    delete gameplay;

    printf("Program Finish.\n");
return(0);
}
#include <SFML/Graphics.hpp>


int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Program");

    const int cellSize = 50;
    const int n = 10;

    sf::RectangleShape cells[n][n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cells[i][j].setSize(sf::Vector2f(cellSize - 2, cellSize - 2));
            cells[i][j].setPosition(j * cellSize, i * cellSize);
            cells[i][j].setFillColor(sf::Color::White);
            cells[i][j].setOutlineColor(sf::Color::Black);
            cells[i][j].setOutlineThickness(1);
        }
    }

    // вариант 25
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) { 
            int length = n - i; 
            for (int j = 0; j < length; ++j) {
                cells[i][j].setFillColor(sf::Color::Green);
            }
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                window.draw(cells[i][j]);

        window.display();
    }

    return 0;
}

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "var25\"");

    sf::RectangleShape body(sf::Vector2f(300, 300));
    body.setPosition(50, 50);
    body.setFillColor(sf::Color(20, 20, 20)); 

    sf::RectangleShape grayPanel(sf::Vector2f(260, 55)); 
    grayPanel.setPosition(70, 155); 
    grayPanel.setFillColor(sf::Color(160, 160, 160));

    sf::CircleShape hub(40);
    hub.setOrigin(40, 40);
    hub.setPosition(200, 200);
    hub.setFillColor(sf::Color(180, 180, 180));

    sf::CircleShape innerCircle(15);
    innerCircle.setOrigin(15, 15);
    innerCircle.setPosition(200, 200);
    innerCircle.setFillColor(sf::Color::Black);

    sf::RectangleShape label(sf::Vector2f(220, 60));
    label.setPosition(90, 60);
    label.setFillColor(sf::Color(230, 230, 230));

    std::vector<sf::RectangleShape> lines;
    for (int i = 0; i < 5; ++i) {
        sf::RectangleShape line(sf::Vector2f(200, 2));
        line.setPosition(100, 70 + i * 10);
        line.setFillColor(sf::Color::Black);
        lines.push_back(line);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(body);
        window.draw(label);
        for (auto& line : lines)
            window.draw(line);
        window.draw(grayPanel);     
        window.draw(hub);          
        window.draw(innerCircle);   
        window.display();
    }

    return 0;
}

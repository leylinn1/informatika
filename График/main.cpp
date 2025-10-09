#include <SFML/Graphics.hpp>
#include <functional>
#include <cmath>
#include <iostream>

// ������� ��� ��������� �������
void drawGraph(sf::RenderWindow& window, std::function<float(float)> func, float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x); // ���������� �������� �������

        // �������������� ��������� � ��������
        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;

        // ���������� ����� � ������ ������
        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}

float f1(float x) {
    return 0; // y = 0
}

float f2(float x) {
    return x - 3; // y = x - 3
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Application for displaying graphs");

    sf::CircleShape userPoint(3); // ������ 3 �������
    userPoint.setFillColor(sf::Color::Red);
    bool userPointExists = false;

    // �������� ������
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
        return -1;
    }

    // ����� ��� ���������
    sf::Text coordinatesText;
    coordinatesText.setFont(font);
    coordinatesText.setCharacterSize(20);
    coordinatesText.setFillColor(sf::Color::White);
    coordinatesText.setPosition(10, 10);

    // ��� X � Y
    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(50, 300);
    xAxis[0].color = sf::Color::White;
    xAxis[1].position = sf::Vector2f(750, 300);
    xAxis[1].color = sf::Color::White;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 50);
    yAxis[0].color = sf::Color::White;
    yAxis[1].position = sf::Vector2f(400, 550);
    yAxis[1].color = sf::Color::White;

    const float scaleX = 30.0f;
    const float scaleY = 30.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // �������������� �������� ��������� � ��������������
                    float mathX = (mousePos.x - 400) / scaleX;
                    float mathY = -(mousePos.y - 300) / scaleY;

                    // ��������� ���������������� �����
                    userPoint.setPosition(mousePos.x - userPoint.getRadius(), mousePos.y - userPoint.getRadius());
                    userPointExists = true;

                    // ������ �������� ������� �����
                    std::string pos;
                    if (std::abs(f1(mathX) - mathY) < 0.05f || std::abs(f2(mathX) - mathY) < 0.05f) {
                        pos = "border";
                    }
                    else if (mathX - 3 > mathY && mathY > 0) {
                        pos = "3";
                    }
                    else if (mathX - 3 > mathY && mathY < 0) {
                        pos = "2";
                    }
                    else if (f2(mathX) < mathY && f1(mathX) < mathY) {
                        pos = "1";
                    }
                    else if ((f2(mathX) < mathY) && (f1(mathX) > mathY)) {
                        pos = "4";
                    };

                    // ���������� ������
                    coordinatesText.setString("Coordinates: (" + std::to_string(mathX) +
                        ", " + std::to_string(mathY) + ")\nPosition: " + pos);
                }
            }
        }

        // ������� ������
        window.clear();

        // ��������� ����
        window.draw(xAxis);
        window.draw(yAxis);

        // ��������� ��������
        drawGraph(window, f1, -10, 10, scaleX, scaleY, sf::Color::Blue);
        drawGraph(window, f2, -10, 10, scaleX, scaleY, sf::Color::Red);

        // ��������� ���������������� ����� � ������
        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
        }

        window.display();
    }

    return 0;
}

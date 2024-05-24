#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>


const float gravity = 95.8f;
const float damping = 0.8f;
const float air_resistance = 0.1f;

class Ball {
public:

    float radius;
    sf::Vector2f velocity;
    sf::CircleShape shape;

    Ball(float radius, float startX, float startY, sf::Color color)
        : radius(radius), velocity(0.0f, 0.0f) {
        shape.setRadius(radius);
        shape.setOrigin(radius, radius);
        shape.setPosition(startX, startY);
        shape.setFillColor(color);
    }

    void update(float deltaTime, float groundLevel) {
        
        float acceleration = gravity - (air_resistance * velocity.y);
        velocity.y += acceleration * deltaTime;

        shape.move(0, velocity.y * deltaTime);
        
        if (shape.getPosition().y + radius >= groundLevel) {
            shape.setPosition(shape.getPosition().x, groundLevel - radius);
            velocity.y = -velocity.y * damping;
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }
    
};

int main() {

    const int windW = 800;
    const int windH = 600;

    sf::RenderWindow window(sf::VideoMode(windW, windH), "Falling Balls Simulation");
    window.setFramerateLimit(60);

    std::vector<Ball> balls;
    

    balls.emplace_back(20.0f, 300.0f, 10.0f, sf::Color::Red);
    balls.emplace_back(40.0f, 400.0f, 10.0f, sf::Color::Green);
    balls.emplace_back(60.0f, 590.0f, 10.0f, sf::Color::Blue);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float deltaTime = clock.restart().asSeconds();

        for (auto& ball : balls) {
            ball.update(deltaTime, windH);
        }

        window.clear();
        for (auto& ball : balls) {
            ball.draw(window);
        }
        window.display();
    }

    return 0;
}

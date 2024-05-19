#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

namespace mt
{
    class Asteroid
    {
    private:
        float m_x, m_y;
        float m_v;
        float m_alfa;
        float m_r;
        sf::Texture m_texture;
        sf::Sprite m_sprite;
        bool m_active;

        const float pi = acos(-1);

    public:
        Asteroid() : m_active(true) {}

        Asteroid(const Asteroid&) = delete;
        Asteroid& operator=(const Asteroid&) = delete;

        Asteroid(Asteroid&& other)
            : m_x(other.m_x), m_y(other.m_y), m_v(other.m_v), m_alfa(other.m_alfa), m_r(other.m_r),
            m_texture(std::move(other.m_texture)), m_sprite(std::move(other.m_sprite)), m_active(other.m_active)
        {
            other.m_active = false;
        }

        Asteroid& operator=( Asteroid&& other)
        {
            if (this != &other)
            {
                m_x = other.m_x;
                m_y = other.m_y;
                m_v = other.m_v;
                m_alfa = other.m_alfa;
                m_r = other.m_r;
                m_texture = std::move(other.m_texture);
                m_sprite = std::move(other.m_sprite);
                m_active = other.m_active;
                other.m_active = false;
            }
            return *this;
        }

        bool Setup(float x, float y, float r, float v, float alfa, const std::string& texturePath)
        {
            m_x = x;
            m_y = y;
            m_r = r;
            m_v = v;
            m_alfa = alfa;

            if (!m_texture.loadFromFile(texturePath))
            {
                std::cout << "Error while loading texture: " << texturePath << std::endl;
                return false;
            }
            m_sprite.setTexture(m_texture);
            m_sprite.setScale(m_r / m_texture.getSize().x * 2, m_r / m_texture.getSize().y * 2);
            m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
            m_sprite.setPosition(m_x, m_y);

            std::cout << "Successfully loaded texture: " << texturePath << std::endl;
            return true;
        }

        sf::Sprite Get() const
        {
            return m_sprite;
        }

        float X() const { return m_x; }
        void X(float value) { m_x = value; m_sprite.setPosition(m_x, m_y); }

        float Y() const { return m_y; }
        void Y(float value) { m_y = value; m_sprite.setPosition(m_x, m_y); }

        float V() const { return m_v; }
        void V(float value) { m_v = value; }

        float Alfa() const { return m_alfa; }
        void Alfa(float value) { m_alfa = value; }

        float R() const { return m_r; }
        bool IsActive() const { return m_active; }
        void SetActive(bool active) { m_active = active; }

        void Move(float dt)
        {
            m_x += m_v * dt * cos(m_alfa);
            m_y += m_v * dt * sin(m_alfa);
            m_sprite.setPosition(m_x, m_y);
        }

        std::vector<Asteroid> SpecialAbility(const std::string& texturePath)
        {
            std::vector<Asteroid> newAsteroids;

            if (m_r > 10)
            {
                for (int i = 0; i < 3; ++i)
                {
                    Asteroid newAsteroid;
                    float newR = m_r / 3.0f;
                    float newV = m_v * 1.5f;
                    float newAlfa = static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (2 * pi));

                    if (newAsteroid.Setup(m_x, m_y, newR, newV, newAlfa, texturePath))
                    {
                        newAsteroids.push_back(std::move(newAsteroid));
                    }
                }
            }

            m_active = false;
            return newAsteroids;
        }
    };
}

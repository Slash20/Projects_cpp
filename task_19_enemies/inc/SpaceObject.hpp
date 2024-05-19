#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace mt
{
	class SpaceObject
	{
	protected:
		float m_x, m_y;
		float m_vx, m_vy;
		float m_r;
		sf::Texture m_textureShip;
		sf::Sprite m_spriteShip;

	public:
		SpaceObject() = default;
		virtual ~SpaceObject() {}

		bool Setup(float x, float y, float vx, float vy,
			const std::string& texturePath, float scaleFactor)
		{
			m_x = x;
			m_y = y;
			m_vx = vx;
			m_vy = vy;

			if (!m_textureShip.loadFromFile(texturePath))
			{
				std::cout << "Error while loading " << texturePath << std::endl;
				return false;
			}
			m_spriteShip.setTexture(m_textureShip);

			m_spriteShip.setScale(scaleFactor, scaleFactor);
			m_spriteShip.setOrigin(m_textureShip.getSize().x / 2, m_textureShip.getSize().y / 2);
			m_spriteShip.setPosition(m_x, m_y);

			if (m_textureShip.getSize().x > m_textureShip.getSize().y)
				m_r = scaleFactor * m_textureShip.getSize().x / 2;
			else
				m_r = scaleFactor * m_textureShip.getSize().y / 2;

			return true;
		}

		sf::Sprite Get()
		{
			return m_spriteShip;
		}

		void Move(float dt)
		{
			m_x += m_vx * dt;
			m_y += m_vy * dt;
			m_spriteShip.setPosition(m_x, m_y);
		}

		float X() const { return m_x; }
		void X(float value) { m_x = value; m_spriteShip.setPosition(m_x, m_y); }

		float Y() const { return m_y; }
		void Y(float value) { m_y = value; m_spriteShip.setPosition(m_x, m_y); }

		float Vx() const { return m_vx; }
		void Vx(float value) { m_vx = value; }

		float Vy() const { return m_vy; }
		void Vy(float value) { m_vy = value; }

		float R() const { return m_r; }

		virtual void Attack() {}
		virtual void SpecialAbility() {}
	};
}

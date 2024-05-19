#pragma once
#include <SFML/Graphics.hpp>
#include <SpaceObject.hpp>
#include <vector>
#include <Bullet.hpp>
#include <cmath>

namespace mt
{
	class UFO : public SpaceObject
	{
		std::vector<Bullet> m_bullets;
		sf::Clock m_fireClock;
		float m_fireRate; 

	public:
		UFO() : m_fireRate(1.0f) {} 
		virtual ~UFO() {}

		void Setup(float x, float y, float r, float v, const std::string& textureFile, float fireRate)
		{
			SpaceObject::Setup(x, y, r, v, textureFile, 1.0f);
			m_fireRate = fireRate;
		}

		void SpecialAbility()
		{
			if (m_fireClock.getElapsedTime().asSeconds() >= m_fireRate)
			{
				
				float bulletRadius = 15.0f;
				float bulletSpeed = 300.0f;
				float bulletAngle = 0.0f; 

				Bullet bullet(X(), Y(), bulletRadius, bulletSpeed * cos(bulletAngle), bulletSpeed * sin(bulletAngle));
				m_bullets.push_back(bullet);

				
				m_fireClock.restart();
			}
		}

		std::vector<Bullet>& GetBullets()
		{
			return m_bullets;
		}

		void UpdateBullets(float dt)
		{
			for (auto& bullet : m_bullets)
			{
				bullet.Move(dt);
			}

			
			m_bullets.erase(
				std::remove_if(m_bullets.begin(), m_bullets.end(), [](const Bullet& bullet) {
					return bullet.X() < 0 || bullet.X() > 1000 || bullet.Y() < 0 || bullet.Y() > 600;
					}),
				m_bullets.end());
		}
	};
}

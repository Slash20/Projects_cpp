#pragma once
#include <SFML/Graphics.hpp>

namespace mt
{

	class Triangle
	{
		float m_x, m_y;
		sf::ConvexShape m_tshape;


	public:
		Triangle() = default;

		Triangle(float x, float y) {
			Setup(x, y);
		}

		void Setup(float x, float y) {
			m_x = x;
			m_y = y;
			
			m_tshape.setPosition(m_x, m_y);
			m_tshape.setPointCount(3);
			m_tshape.setPoint(0, sf::Vector2f(0, 0));  
			m_tshape.setPoint(1, sf::Vector2f(100, 0));  
			m_tshape.setPoint(2, sf::Vector2f(50, 100));
			m_tshape.setRotation(rand());
			m_tshape.setFillColor(sf::Color::Yellow);
		}

		sf::ConvexShape Get() {
			return m_tshape;
		}
	};


}
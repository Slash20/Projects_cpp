#pragma once
#include <SFML/Graphics.hpp>

namespace mt
{

	class Rectangle
	{
		
		float m_x, m_y, m_a, m_b, m_c;
		sf::RectangleShape m_rshape;


	public:
		Rectangle() = default;

		Rectangle(float x, float y, float a, float b) {
			Setup(x, y, a, b);
		}

		void Setup(float x, float y, float a, float b) {
			m_x = x;
			m_y = y;
			
			m_a = a;
			m_b = b;

			
			m_rshape.setPosition(m_x, m_y);
			m_rshape.setSize(sf::Vector2f(m_a, m_b));
			m_rshape.setFillColor(sf::Color::Green);
		}

		sf::RectangleShape Get() {
			return m_rshape;
		}
	};


}
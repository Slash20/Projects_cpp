#pragma once
#include <SFML/Graphics.hpp>

namespace mt
{
	class Line
	{
		float m_x, m_y, m_a, m_b, m_c;
		sf::RectangleShape m_lshape;
		

	public:
		Line() = default;

		Line(float x, float y, float a, float b) {
			Setup(x, y, a, b);
		}

		void Setup(float x, float y, float a, float b) {
			m_x = x;
			m_y = y;

			m_a = a;
			m_b = b;
			
			m_lshape.setPosition(m_x, m_y);
			m_lshape.setSize(sf::Vector2f(m_a, m_b));
			m_lshape.setRotation(rand());
			m_lshape.setFillColor(sf::Color::Blue);
		}

		sf::RectangleShape Get() {
			return m_lshape;
		}
	};
}
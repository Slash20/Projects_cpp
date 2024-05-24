#pragma once
#include <string>
#include <iostream>



namespace mt
{
	class Game
	{
		int m_width;
		int m_height;
		int m_n;
		std::string m_capture;
		sf::RenderWindow m_window;
		
	public:
		Game(int width, int height, const std::string& capture)
		{
			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		void Setup(int n)
		{
			m_n = n;

			m_window.create(sf::VideoMode(m_width, m_height), m_capture);

			srand(time(0));

			for (int i = 0; i < m_n; i++)
			{
				int x = rand() % 1000;
				int y = rand() % 600;
				int r = rand() % 100 + 1;
				
			}

			for (int i = 0; i < m_n; i++)
			{
				int x = rand() % 1000;
				int y = rand() % 600;

				int a = 200;
				int b = 50;
				
				
				
			}

			for (int i = 0; i < m_n; i++)
			{
				int x = rand() % 1000;
				int y = rand() % 600;

				
			}

			for (int i = 0; i < m_n; i++)
			{
				int x = rand() % 1000;
				int y = rand() % 600;

				int a = 150;
				int b = 5;

				
			}

		}

		void LifeCycle()
		{
			while (m_window.isOpen())
			{

				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						m_window.close();
				}

				m_window.clear();
				m_window.display();
			}
		}
	};
}
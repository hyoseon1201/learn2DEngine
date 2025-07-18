#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow renderWindow{ sf::VideoMode({1280, 720}), "Light Years" };
	std::cout << "hello world" << std::endl;

	while (renderWindow.isOpen())
	{
		while (const auto event = renderWindow.pollEvent())
		{
			if (const auto* closedEvent = event->getIf<sf::Event::Closed>())
			{
				renderWindow.close();
			}

			if (const auto* keyPressedEvent = event->getIf<sf::Event::KeyPressed>())
			{
				if (keyPressedEvent->code == sf::Keyboard::Key::Escape)
				{
					std::cout << "ESC key pressed!" << std::endl;
					renderWindow.close();
				}
			}
		}

		renderWindow.clear(sf::Color::Blue);
		renderWindow.display();
	}

	return 0;
}
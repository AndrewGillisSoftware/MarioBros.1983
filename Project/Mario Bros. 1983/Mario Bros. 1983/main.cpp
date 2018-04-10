#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 447), "MARIO, BROTHER!");
	Game game(window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		game.draw();
		window.display();
	}

	return 0;
}

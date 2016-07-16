#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>

//atoi(string) -> int

int main()
{
	sf::RenderWindow window(sf::VideoMode(200u, 200u), "SFML Demo");
	window.setFramerateLimit(60);
	sf::Event event;

	//Tekstin alustus
	sf::Font font;
	if (!font.loadFromFile("Fonts/arial.ttf"))
	{
		std::cout << "Loading a font failed!" << std::endl;
	}

	sf::Text text;
	sf::Text text2;

	text.setFont(font);
	text2.setFont(font);


	std::string test("huhuu");
	int luku1 = 1;
	int luku2 = 1;
	int vastaus = luku1 + luku2;

	text.setString(std::to_string(luku1) + "+" + std::to_string(luku2) + "=" + std::to_string(vastaus));
	text2.setString(std::to_string(luku1) + "+" + std::to_string(luku2) + "=");

	text.setCharacterSize(24);
	text2.setCharacterSize(24);

	//Input
	int playerAnswer = -1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
	{
		std::cout << "0 pressed\n";
		playerAnswer = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		std::cout << "0 pressed\n";
		playerAnswer = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		std::cout << "0 pressed\n";
		playerAnswer = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		std::cout << "0 pressed\n";
		playerAnswer = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		std::cout << "0 pressed\n";
		playerAnswer = 4;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
	{
		std::cout << "0 pressed\n";
		playerAnswer = 5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
	{
		std::cout << "0 pressed\n";
		playerAnswer = 6;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
	{
		std::cout << "0 pressed\n";
		playerAnswer = 7;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
	{
		std::cout << "0 pressed\n";
		playerAnswer = 8;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
	{
		std::cout << "0 pressed\n";
		playerAnswer = 9;
	}
	else
	{
		std::cout << "no pressed\n";
		playerAnswer = -1;
	}





	//Päälooppi
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		//window.draw(text);
		window.draw(text2);

		int playerAnswer = -1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
		{
			std::cout << "0 pressed\n";
			playerAnswer = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			std::cout << "1 pressed\n";
			playerAnswer = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			std::cout << "2 pressed\n";
			playerAnswer = 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			std::cout << "3 pressed\n";
			playerAnswer = 3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			std::cout << "4 pressed\n";
			playerAnswer = 4;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
		{
			std::cout << "5 pressed\n";
			playerAnswer = 5;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
		{
			std::cout << "6 pressed\n";
			playerAnswer = 6;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
		{
			std::cout << "7 pressed\n";
			playerAnswer = 7;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
		{
			std::cout << "8 pressed\n";
			playerAnswer = 8;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
		{
			std::cout << "9 pressed\n";
			playerAnswer = 9;
		}
		//else
		//{
		//	//std::cout << "no pressed\n";
		//	playerAnswer = -1;
		//}

		if (playerAnswer == vastaus)
		{
			window.draw(text);
		}

		window.display();
	}

	return 0;
}
//included libraries
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <string>
#include<cstdlib>
#include<ctime>
//


int main() // entry point for program
{
	
	//--------------------------------------
	// Game Setup
	//--------------------------------------

	// RenderWindow Creation
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Quick Draw",
		sf::Style::Titlebar | sf::Style::Close);

	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");

	// create text
	sf::Text titleText;
	titleText.setFont(gameFont);
	titleText.setString("Quick Draw");
	titleText.setCharacterSize(36);
	titleText.setFillColor(sf::Color::Magenta);
	titleText.setPosition(gameWindow.getSize().x / 2 - titleText.getLocalBounds().width / 2, 30);

	sf::Text authorText;
	authorText.setFont(gameFont);
	authorText.setString("David Melville");
	authorText.setPosition(gameWindow.getSize().x / 2 - authorText.getLocalBounds().width / 2, 80);


	//Seed our random number generation
	srand(time(NULL));

	//Timer functionality
	float signalTimeLowerLimit = 5.0f;
	float signalTimeUpperLimit = 10.0f;
	sf::Time timeTilSignal = sf::seconds(signalTimeLowerLimit);
	sf::Time timeSinceSignal = sf::seconds(0.0f);
	sf::Clock gameClock;







	// Create button sprite
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");

	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);

	// centers the sprite on the screen
	buttonSprite.setPosition(
		gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2
	);
	//----------------------------------------
	// End of game setup
	//----------------------------------------


	// Game Loop
	while (gameWindow.isOpen())
	{

		//------------------------
		//Input
		//------------------------
		sf::Event gameEvent;
		// Process Events
		while (gameWindow.pollEvent(gameEvent))
		{			

			if (gameEvent.type == sf::Event::MouseButtonPressed)
			{
				if (buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x, gameEvent.mouseButton.y))
				{
					int range = (int)(signalTimeUpperLimit - signalTimeLowerLimit);

					// generates a number between 0 and the range and adds the lower limit
					float signalSeconds = rand() % range + signalTimeLowerLimit;
					timeTilSignal = sf::seconds(signalSeconds);
				}
			}



			// check if the event is the the close event
			if (gameEvent.type == sf::Event::Closed)
			{
				gameWindow.close();
			}
		}
		//------------------------
		//End Input
		//------------------------

		//------------------------
		//Update
		//------------------------
		sf::Time frameTime = gameClock.restart();

		timeTilSignal = timeTilSignal - frameTime;

		if (timeTilSignal.asSeconds() <= 0.0f)
		{
			buttonSprite.setColor(sf::Color::Red);
		}
		//------------------------
		//End Update
		//------------------------



		// set background colour
		gameWindow.clear(sf::Color::White);

		//TODO Draw EVRYTHING
		gameWindow.draw(buttonSprite);
		gameWindow.draw(titleText);
		gameWindow.draw(authorText);



		// Display the contents of the window on the screen
		gameWindow.display();

	}// end of while loop




	return 0;
}// end of main function
//included libraries
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <string>
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

	//Timer functionality
	float signalTimeLowerLimit = 5.0f;
	float signalTimeUpperLimit = 10.0f;
	sf::Time timeTilSignal = sf::seconds(0.0f);
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

		//------------------------
		//End Update
		//------------------------



		// set background colour
		gameWindow.clear(sf::Color::Cyan);

		//TODO Draw EVRYTHING
		gameWindow.draw(buttonSprite);



		// Display the contents of the window on the screen
		gameWindow.display();

	}// end of while loop




	return 0;
}// end of main function
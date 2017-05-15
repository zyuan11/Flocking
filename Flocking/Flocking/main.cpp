#include "main.h"

int main()
{
	//initialization
	int flockInitSize = 1;

	VehicleSystem myFlock = VehicleSystem();
	myFlock.flockInit(flockInitSize);

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Flocking");
	
	PVector target = PVector(100.0f, 50.0f);
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		
		for (int i = 0; i < myFlock.getSize(); ++i) {
			window.draw(myFlock.flock[i].shape);
			myFlock.flock[i].seek(target);
			myFlock.flock[i].update();
		}
		window.display();
	}

	return 0;
}

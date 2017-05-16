#include "main.h"

int main()
{
	//initialization
	int flockInitSize = 25;

	VehicleSystem myFlock = VehicleSystem();
	myFlock.flockInit(flockInitSize);

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Flocking");
	sf::Vector2i cursor;
	sf::CircleShape cursorShape(10);
	cursorShape.setFillColor(sf::Color(255, 102, 84));
	cursorShape.setOutlineColor(sf::Color::Black);
	cursorShape.setPosition(0.0f, 0.0f);

	
	PVector target;
	target.set(100.0f, 50.0f);
	Vehicle *newVehicle;

	//behaviour
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonReleased) {
				cursor = sf::Mouse::getPosition(window);
				cursorShape.setPosition(sf::Vector2f(cursor.x, cursor.y));
				target.set(cursor.x, cursor.y);
			}

			if (event.type == sf::Event::KeyReleased) {
				//add / remove vehicle from vehicle system by pressing up / down arrow key
				if (event.key.code == sf::Keyboard::Up) {
					newVehicle = new Vehicle;
					newVehicle->VehicleInit(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
					myFlock.addVehicle(newVehicle);
				}
				else if (myFlock.getSize() > 0 && event.key.code == sf::Keyboard::Down) {
					myFlock.removeVehicle();
				}

			}
		}

		window.clear();

		//draw cursorshape
		window.draw(cursorShape);

		//sepration weight adjustment
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			myFlock.TurnOnSep();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			myFlock.TurnOffSep();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			myFlock.IncreaseSep();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			myFlock.DecreaseSep();

		//alighment weight adjustment
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			myFlock.TurnOnAli();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			myFlock.TurnOffAli();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			myFlock.IncreaseAli();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
			myFlock.DecreaseAli();

		//coherent weight adjustment
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			myFlock.TurnOnCoh();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
			myFlock.TurnOffCoh();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
			myFlock.IncreaseCoh();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
			myFlock.DecreaseCoh();

		//draw & update each vehicle in vehicle system
		for (int i = 0; i < myFlock.getSize(); ++i) {
			window.draw(myFlock.flock[i].shape);
			myFlock.flock[i].DoFlock(myFlock.flock, myFlock.SepWeight, myFlock.AliWeight, myFlock.CohWeight, cursor);
			myFlock.flock[i].update();			
		}
		window.display();
	}

	return 0;
}

#include "main.h"

int main()
{
	//initialization
	int flockInitSize = 10;

	VehicleSystem myFlock = VehicleSystem();
	myFlock.flockInit(flockInitSize);

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Flocking");
	sf::Vector2i cursor;
	
	PVector target;
	target.set(100.0f, 50.0f);
	Vehicle *newVehicle;

	//behaviour
	bool DoSeparate = true;	
	bool DoAlign = false;
	bool DoCoheret = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyReleased) {
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
				cout << "Turn Off Separation" << endl;
				DoSeparate = false;
			}
			else {
				cout << "Turn On Separation" << endl;
				DoSeparate = true;
			}
		}
		if (event.key.code == sf::Keyboard::S) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
				cout << "Turn Off Alignment" << endl;
				 DoAlign = false;
			}
			else {
				cout << "Turn On Alignment" << endl;
				DoAlign = true;
			}
		}
		if (event.key.code == sf::Keyboard::D) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
				cout << "Turn Off Coherent" << endl;
				DoCoheret = false;
			}
			else {
				cout << "Turn On Coherent" << endl;
				DoCoheret = true;
			}
		}

		//target update by cursor position
		cursor = sf::Mouse::getPosition(window);
		target.set(cursor.x, cursor.y);
		//create new vehicle if click
		for (int i = 0; i < myFlock.getSize(); ++i) {
			window.draw(myFlock.flock[i].shape);
			if (DoSeparate)
				myFlock.flock[i].separate(myFlock.flock);
			if (DoAlign)
				myFlock.flock[i].align(myFlock.flock);
			if (DoCoheret)
				myFlock.flock[i].coheret(myFlock.flock);
			else
				myFlock.flock[i].seek(target);
			
			myFlock.flock[i].update();			
		}
		window.display();
	}

	return 0;
}

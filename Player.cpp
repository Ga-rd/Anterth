#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Player {

	RenderWindow* window;
	CircleShape player;

	int players;
	int score;

	float x, y;
	float speed;
	Vector2f velocity;

public:
	Player() {
		this->score = 0;
		this->players = players;
		this->window = window;

		this->x, y = 100;

		this->player.setRadius(15);
		this->player.setOrigin(Vector2f(25, 25));
		this->player.setPosition(Vector2f(x, y));
		this->speed = 100;
		this->velocity = Vector2f(0, 0);

		this->player.setFillColor(Color(255, 255, 255));
		
	};


	CircleShape draw() {
		return player;
	};
	
	void fire() {
		Vertex line[] = { Vector2f(this->player.getPosition().x, this->player.getPosition().y), Vector2f(Mouse::getPosition().x, Mouse::getPosition().y) };
		window->draw(line, 2, Lines);

	}

	void update(float time, Event event) {

		if (Keyboard::isKeyPressed(Keyboard::A)) { player.move(-1 * speed * time, 0); }
		if (Keyboard::isKeyPressed(Keyboard::D)) { player.move(1 * speed * time, 0); }
		if (Keyboard::isKeyPressed(Keyboard::W)) { player.move(0, -1 * speed * time); }
		if (Keyboard::isKeyPressed(Keyboard::S)) { player.move(0, 1 * speed * time); }
		if (Mouse::isButtonPressed(Mouse::Left)) { fire(); }

		this->player.move(velocity);



		
	};
};

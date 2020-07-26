#include <iostream>
#include <SFML/Graphics.hpp>

#define TEXTURES "images/tiles.png"

const int tile_width = 30;
const int N = 20; // height
const int M = 10; // width

int field[M][N] = {0};

int figures[7][4] = {
	1,3,5,7, // I
	2,3,4,5, // S
	3,5,4,6, // Z
	3,5,4,7, // T
	2,3,5,7, // L
	3,5,7,6, // J
	2,3,4,5  // O
};

struct Point {
	int x;
	int y;
} a[4], b[4];

int main() {
	sf::RenderWindow window(sf::VideoMode(320, 480), "Tetris");

	sf::Texture texture;
	texture.loadFromFile(TEXTURES);

	sf::Sprite sprite(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, tile_width, tile_width));

	int dx = 0; // horisontal move tatramino
	bool rotate = 0;

	float time = 0;
	float timer = 0;
	float delay = 0.3;

	sf::Clock clock;
	sf::Event event;

	while (window.isOpen()) {
		time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Up)
					rotate = true;
				else if (event.key.code == sf::Keyboard::Left)
					dx = -1;
				else if (event.key.code == sf::Keyboard::Right)
					dx = 1;
		}

		for (int i = 0; i < 4; i++)
			a[i].x += dx;

		if (rotate) {
			Point p = a[1]; // center of rotate
			for (int i = 0; i < 4; i++) {
				int x = a[i].y - p.y;
				int y = a[i].x - p.x;
				a[i].x = p.x - x;
				a[i].y = p.y + y;
			}
		}

		if (timer > delay) {
			for (int i = 0; i < 4; i++)
				a[i].y++;
			timer = 0;
		}

		int type = 2; // type tetramino
		if (a[0].x == 0)
			for (int i = 0; i < 4; i++) {
				a[i].x = figures[type][i] % 2;
				a[i].y = figures[type][i] / 2;
			}

		dx = 0;
		rotate = 0;

		window.clear(sf::Color::White);

		for (int i = 0; i < 4; i++) {
			sprite.setPosition(a[i].x * tile_width, a[i].y * tile_width);
			window.draw(sprite);
		}

		window.display();
	}

	return 0;
}

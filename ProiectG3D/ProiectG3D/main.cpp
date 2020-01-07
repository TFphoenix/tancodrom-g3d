#include <GL/glew.h>
#include <chrono>
#include <iostream>

#include "Display.h"
#include "Settings.h"

#include "Terrain.h"
#include "Tank.h"
#include "Helicopter.h"
#include "HelicopterLandingPad.h"
#include "BigSpotlight.h"
#include "DirtStadium.h"
#include "Vegetation.h"
#include "Skybox.h"
#include "Showcase.h"
#include "Human.h"
#include "Hangar.h"

int main()
{
	// Start Time
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	// Display
	Display display(Settings::WindowWidth, Settings::WindowHeight, "G3D - Tancodrom & Elicoptere");

	// Camera & Transform
	Camera camera(glm::vec3(0, 10, -100), 70.0f, static_cast<float>(Settings::WindowWidth) / Settings::WindowHeight, 0.01f, 1000.0f);
	display.SetCamera(camera);

	// Objects Vector
	std::vector<Object*> objects;

	// Vegetation
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(15, 0, -21))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(17, 0, -22))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(7, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(-3, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(-7, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(10, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(-8, 0, -25))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(-5, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(-10, 0, -24))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(0, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(20, 0, -23))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(23, 0, 0))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(23, 0, -10))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(23, 0, -10))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(21, 0, -10))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(22, 0, -12))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(23, 0, -16))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(23, 0, -7))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(23, 0, 5))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(23, 0, 10))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(-23, 0, -5))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(-23, 0, 10))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(-23, 0, 3))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(-10, 0, 23))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(5, 0, 23))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(-5, 0, 23))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(23, 0, -17))));

	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(170, 0, -8))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(170, 0, 0))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(170, 0, 2))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(170, 0, -2))));
	objects.push_back(new Vegetation(Vegetation::Type::FLOWER, Transform(glm::vec3(170, 0, -1))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(170, 0, 0))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(170, 0, 10))));

	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(130, 0, -9))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(130, 0, 2))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(125, 0, -1))));
	objects.push_back(new Vegetation(Vegetation::Type::GRASS, Transform(glm::vec3(130, 0, -5))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(130, 0, 8))));

	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(130, 0, 8))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(130, 0, 8))));
	objects.push_back(new Vegetation(Vegetation::Type::BUSH, Transform(glm::vec3(130, 0, 8))));

	// Terrain
	objects.push_back(new Terrain);

	// Tanks
	objects.push_back(new Tank(Tank::CLASSIC, Transform(glm::vec3(50, 4, -50))));
	objects.push_back(new Tank(Tank::DOUBLE, Transform(glm::vec3(50, 0, 50))));
	objects.push_back(new Tank(Tank::TURTLE, Transform(glm::vec3(-50, 0, -50))));
	objects.push_back(new Tank(Tank::OLD, Transform(glm::vec3(-400, 9, -300), glm::vec3(0, glm::radians(-90.0f), glm::radians(-13.0f)), glm::vec3(1.2f, 1.2f, 1.2f))));

	// Helicopters
	objects.push_back(new Helicopter(Helicopter::CLASSIC, Transform(glm::vec3(-20, 80, 0))));
	objects.push_back(new Helicopter(Helicopter::ROUND, Transform(glm::vec3(130, 70, 0))));

	// Helicopter Landing Pads
	objects.push_back(new HelicopterLandingPad);
	objects.push_back(new HelicopterLandingPad(Transform(glm::vec3(150, 0, 0))));

	// Big Spotlights
	objects.push_back(new BigSpotlight(Transform(glm::vec3(-100, 0, 90), glm::vec3(0, glm::radians(-45.0f), 0))));
	objects.push_back(new BigSpotlight(Transform(glm::vec3(-200, 0, 90))));
	objects.push_back(new BigSpotlight(Transform(glm::vec3(-300, 0, 90), glm::vec3(0, glm::radians(45.0f), 0))));
	objects.push_back(new BigSpotlight(Transform(glm::vec3(-100, 0, 210), glm::vec3(0, glm::radians(225.0f), 0))));
	objects.push_back(new BigSpotlight(Transform(glm::vec3(-200, 0, 210), glm::vec3(0, glm::radians(180.0f), 0))));
	objects.push_back(new BigSpotlight(Transform(glm::vec3(-300, 0, 210), glm::vec3(0, glm::radians(135.0f), 0))));

	// Stadium
	objects.push_back(new DirtStadium(Transform(glm::vec3(-200, 0, 150))));

	//Skybox
	Skybox skybox;

	//Humans
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(0, 0, 250), glm::vec3(0, glm::radians(30.0f), 0))));
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(5, 0, 260))));
	objects.push_back(new Human(Human::DIANA, Transform(glm::vec3(3, 0, 262))));
	objects.push_back(new Human(Human::STEVE, Transform(glm::vec3(10, 0, 255))));
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(150, 0, 265), glm::vec3(0, glm::radians(45.0f), 0))));
	objects.push_back(new Human(Human::DIANA, Transform(glm::vec3(155, 0, 260), glm::vec3(0, glm::radians(180.0f), 0))));
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(160, 0, 300))));
	objects.push_back(new Human(Human::DIANA, Transform(glm::vec3(270, 0, 275), glm::vec3(0, glm::radians(20.0f), 0))));
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(275, 0, 270))));
	objects.push_back(new Human(Human::STEVE_CROSSED, Transform(glm::vec3(285, 0, 270))));

	objects.push_back(new Human(Human::OLGA_CROSSED, Transform(glm::vec3(-350, 0, 0), glm::vec3(0, glm::radians(45.0f), 0))));
	objects.push_back(new Human(Human::STEVE, Transform(glm::vec3(-355, 0, 5), glm::vec3(0, glm::radians(45.0f), 0))));
	objects.push_back(new Human(Human::DIANA, Transform(glm::vec3(-360, 0, -105), glm::vec3(0, glm::radians(45.0f), 0))));
	objects.push_back(new Human(Human::STEVE_CROSSED, Transform(glm::vec3(-355, 0, -107), glm::vec3(0, glm::radians(40.0f), 0))));
	objects.push_back(new Human(Human::OLGA_CROSSED, Transform(glm::vec3(-350, 0, -250), glm::vec3(0, glm::radians(25.0f), 0))));
	objects.push_back(new Human(Human::STEVE, Transform(glm::vec3(-345, 0, -250), glm::vec3(0, glm::radians(45.0f), 0))));
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(-340, 0, -245), glm::vec3(0, glm::radians(45.0f), 0))));
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(-380, 0, 270), glm::vec3(0, glm::radians(45.0f), 0))));

	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(55, 0, -60))));
	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(40, 0, 0))));

	objects.push_back(new Human(Human::DIANA, Transform(glm::vec3(155, 0, -50))));
	objects.push_back(new Human(Human::OLGA, Transform(glm::vec3(150, 0, -55))));

	objects.push_back(new Human(Human::DIANA, Transform(glm::vec3(-90, 0, 130))));
	objects.push_back(new Human(Human::STEVE, Transform(glm::vec3(-80, 0, 145))));
	objects.push_back(new Human(Human::OLGA, Transform(glm::vec3(-90, 0, 150))));

	objects.push_back(new Human(Human::JOHN, Transform(glm::vec3(165, 0, 50))));
	objects.push_back(new Human(Human::DIANA, Transform(glm::vec3(160, 0, 60))));
	objects.push_back(new Human(Human::STEVE, Transform(glm::vec3(40, 0, 30))));

	//Showcases
	objects.push_back(new Showcase(Showcase::OPEN_CAGE, Transform(glm::vec3(0, 0, 300))));
	objects.push_back(new Showcase(Showcase::CLOSED_CAGE, Transform(glm::vec3(70, 0, 300))));
	objects.push_back(new Showcase(Showcase::OPEN_CAGE, Transform(glm::vec3(140, 0, 300))));
	objects.push_back(new Showcase(Showcase::CLOSED_CAGE, Transform(glm::vec3(210, 0, 300))));
	objects.push_back(new Showcase(Showcase::OPEN_CAGE, Transform(glm::vec3(280, 0, 300))));

	objects.push_back(new Showcase(Showcase::RAMP, Transform(glm::vec3(-400, 0, 0))));
	objects.push_back(new Showcase(Showcase::RAMP, Transform(glm::vec3(-400, 0, -100))));
	objects.push_back(new Showcase(Showcase::RAMP, Transform(glm::vec3(-400, 0, -200))));
	objects.push_back(new Showcase(Showcase::RAMP, Transform(glm::vec3(-400, 0, -300))));

	// Hangar
	objects.push_back(new Hangar(Transform(glm::vec3(300, 0, -200))));

	// Load Time measure: ~1.8s, ~2.5s, ~22.5s
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	std::cout << "Load Time = " << std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count() / 1000.0f << "[seconds]" << std::endl;



	// Render loop
	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.3f);

		// Render skybox
		skybox.Draw(camera.GetView(), camera.GetProjection());

		// Render all objects in scene
		for (auto& object : objects)
		{
			object->UpdateThenDraw(camera);
		}

		display.Update();
	}

	return 0;
}

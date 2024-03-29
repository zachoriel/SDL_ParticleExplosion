#include "pch.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include <math.h>
#include "Screen.h"
#include "Swarm.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{	
	srand(time(NULL));

	Screen screen;

	if (!screen.Init())
	{
		cout << "Error initializing SDL." << endl;
	}

	Swarm swarm;

	while (true)
	{
		// Draw particles
		int elapsed = SDL_GetTicks();

		swarm.UpdatePosition(elapsed);

		unsigned char red = (1 + sin(elapsed * 0.0003)) * 128;
		unsigned char green = (1 + sin(elapsed * 0.0004)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0005)) * 128;

		const Particle * const pParticles = swarm.GetParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			Particle particle = pParticles[i];

			int x = (particle.m_xPos + 1) * Screen::halfScreenWidth;
			int y = particle.m_yPos * Screen::halfScreenWidth + Screen::halfScreenHeight;

			screen.SetPixel(x, y, red, green, blue);
		}

		// Apply blur effect
		screen.BoxBlur();

		// Draw the screen
		screen.Update();

		// Check for messages/events
		if (!screen.ProcessEvents())
		{
			break;
		}
	}

	screen.Close();
	
	return 0;
}
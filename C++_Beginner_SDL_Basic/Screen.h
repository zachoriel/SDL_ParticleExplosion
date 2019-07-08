#pragma once

#include "SDL.h"

class Screen
{
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;

public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

	const static int halfScreenWidth = SCREEN_WIDTH / 2;
	const static int halfScreenHeight = SCREEN_HEIGHT / 2;

	Screen();
	~Screen();

	bool Init();
	void Update();
	void SetPixel(int xPos, int yPos, Uint8 red, Uint8 green, Uint8 blue);
	bool ProcessEvents();
	void Close();
	void BoxBlur();
};


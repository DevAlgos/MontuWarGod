#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "Entity.h"


class GameWindow
{
public:
	GameWindow(uint16_t width, uint16_t height, const char* title);
	~GameWindow();

	SDL_Texture* LoadTexture(const char* filename);
	SDL_Renderer* getRenderer() { return m_Renderer; }

	int getRefreshRate();

	void render(Entity& ent);
	void clear();
	void display();

private:
	uint16_t m_Width, m_Height;
	const char* m_Title;

	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
};


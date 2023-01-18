#pragma once

#include <array>
#include <vector>
#include <SDL.h>



class Map
{
public:
	Map(std::array<std::array<int, 24>, 40> map, std::vector<SDL_Texture*> TextureList);

	void DrawMap(SDL_Renderer* renderer);

private:
	std::array<std::array<int, 24>, 40> m_Map;
	std::vector<SDL_Texture*> m_TextureList;

	SDL_Rect src, dst;
};

#include "Map.h"

Map::Map(std::array<std::array<int, 24>, 40> map, std::vector<SDL_Texture*> TextureList)
	: m_TextureList(TextureList)
{
	for (int row = 0; row < 40; row++)
	{
		for (int column = 0; column < 24; column++)
		{
			m_Map[row][column] = map[row][column];
		}
	}

	src.x, src.y = 0;
	src.w = 32, src.h = 30;

	dst.x, dst.y = 0;
	dst.w = 32, dst.h = 30;
}



void Map::DrawMap(SDL_Renderer* renderer)
{
	for (int row = 0; row < 40; row++)
	{
		for (int column = 0; column < 24; column++)
		{
			int type = m_Map[row][column];

			dst.x = row * 32;
			dst.y = column * 30;

			if (type == 0) {
				SDL_RenderCopy(renderer, m_TextureList[0], &src, &dst);
			}
			else if(type == 1){
				SDL_RenderCopy(renderer, m_TextureList[1], &src, &dst);
			}

			
		}
	}
}

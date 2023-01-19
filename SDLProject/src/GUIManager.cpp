#include "GUIManager.h"



GUIManager::GUIManager(SDL_Renderer* p_Renderer)
	: m_Renderer(p_Renderer)
{
	if (TTF_Init() == -1)
		std::cerr << "TTF Lib Failed to init:\n" << TTF_GetError() << std::endl;
}

GUIManager::~GUIManager()
{
	
}

void GUIManager::update()
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	for (int i = 0; i < m_Rectangles.size(); i++)
	{
		SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(m_Renderer, &m_Rectangles[i]);
		SDL_RenderCopy(m_Renderer, m_ButtonLists[i], NULL, &m_Rectangles[i]);
	}

	for (int i = 0; i < m_TextureLists.size(); i++)
	{
		SDL_RenderCopy(m_Renderer, m_TextureLists[i], nullptr, &m_RectsLists[i]);
	}




	if (p_MouseButtonDown)
	{
		for (int i = 0; i < m_Rectangles.size(); i++)
		{
			if (x >= m_Rectangles[i].x && x <= m_Rectangles[i].w + m_Rectangles[i].x && y >= m_Rectangles[i].y && y <= m_Rectangles[i].h + m_Rectangles[i].y)
			{
				std::cout << "You Pressed button at: " << " " << m_Rectangles[i].x << " " << m_Rectangles[i].y << std::endl;
			}
			
		}
	}
	
}

void GUIManager::addText(const char* fontFile, int pSize, const char* text, SDL_Rect rect, SDL_Color color)
{
	TTF_Font* ourFont = TTF_OpenFont(fontFile, pSize);
	if (!ourFont)
		std::cerr << "Could Not Load TTF Font:\n" << TTF_GetError() << std::endl;

	

	SDL_Surface* fontSurface = TTF_RenderText_Solid(ourFont, text, color);

	SDL_Texture* textureText = SDL_CreateTextureFromSurface(m_Renderer,fontSurface);

	SDL_FreeSurface(fontSurface);

	m_TextureLists.push_back(textureText);
	m_RectsLists.push_back(rect);

	TTF_CloseFont(ourFont);
}

void GUIManager::addButton(const char* fontFile, const char* text, int pSize, SDL_Color color, int x, int y, int width, int height)
{
	TTF_Font* ourFont = TTF_OpenFont(fontFile, pSize);
	if (!ourFont)
		std::cerr << "Could Not Load TTF Font:\n" << TTF_GetError() << std::endl;


	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = width;
	r.h = height;


	SDL_Surface* fontSurface = TTF_RenderText_Solid(ourFont, text, color);

	SDL_Texture* textureText = SDL_CreateTextureFromSurface(m_Renderer, fontSurface);

	SDL_FreeSurface(fontSurface);

	m_ButtonLists.push_back(textureText);
	m_Rectangles.push_back(r);


	TTF_CloseFont(ourFont);
}

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
	for (int i = 0; i < m_TextureLists.size(); i++)
	{
		SDL_RenderCopy(m_Renderer, m_TextureLists[i], nullptr, &m_RectsLists[i]);
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

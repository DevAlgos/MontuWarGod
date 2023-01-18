#include "GameWindow.h"

GameWindow::GameWindow(uint16_t width, uint16_t height, const char* title) :
	m_Width(width), m_Height(height), m_Title(title), m_Window(nullptr), m_Renderer(nullptr)
{
	m_Window = SDL_CreateWindow(m_Title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_Width, m_Height, SDL_WINDOW_SHOWN);

	if (!m_Window)
		std::cout << "Window failed to construct, Error:\n" << SDL_GetError() << std::endl;


	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!m_Renderer)
		std::cout << "Renderer failed to construct, Error:\n" << SDL_GetError() << std::endl;
}

GameWindow::~GameWindow()
{
	SDL_DestroyWindow(m_Window);
}

SDL_Texture* GameWindow::LoadTexture(const char* filename)
{
	SDL_Texture* texture = nullptr;
	texture = IMG_LoadTexture(m_Renderer, filename);

	if (!texture)
		std::cout << "Failed to create texture at: " << filename <<
		"\nError code:\n" << SDL_GetError() << std::endl;

	return texture;
}


int GameWindow::getRefreshRate()
{
	int displayIndex = SDL_GetWindowDisplayIndex(m_Window);

	SDL_DisplayMode mode;
	SDL_GetDisplayMode(displayIndex, 0, &mode);

	return mode.refresh_rate;
}

void GameWindow::render(Entity& ent)
{
	SDL_Rect src, dst;
	src.x = ent.getCurrentFrame().x;
	src.y = ent.getCurrentFrame().y;
	src.w = ent.getCurrentFrame().w;
	src.h = ent.getCurrentFrame().h;

	
	

	dst.x = ent.getX();
	dst.y = ent.getY();
	dst.w = ent.getCurrentFrame().w * 5;
	dst.h = ent.getCurrentFrame().h * 5;



	SDL_RenderCopy(m_Renderer, ent.getTex(), &src, &dst);
}

void GameWindow::clear()
{
	SDL_RenderClear(m_Renderer);
}

void GameWindow::display()
{
	SDL_RenderPresent(m_Renderer);
}

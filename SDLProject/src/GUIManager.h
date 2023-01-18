#pragma once

#include <SDL_ttf.h>
#include <SDL.h>
#include <iostream>
#include <vector>


class GUIManager
{
public:
	GUIManager(SDL_Renderer* p_Renderer);
	~GUIManager();

	void update();
	void addText(const char* fontFile, int pSize, const char* text, SDL_Rect rect, SDL_Color color);
	virtual void addButton() {}; //for Menu, soon to be added



private:
	SDL_Renderer* m_Renderer;
	std::vector<SDL_Texture*> m_TextureLists; //will find a more efficient way later than to use vectors
	std::vector<SDL_Rect> m_RectsLists;

};
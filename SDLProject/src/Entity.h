#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <vector>




class Entity
{
public:
	Entity(float x, float y, float width, float height, SDL_Texture* tex);
	Entity(float x, float y, float width, float height, std::vector<SDL_Texture*> Textures);
	
	void UpdateEntity(float new_x, float new_y);
	void UpdateDimensions(float width, float height);
	virtual void Update() {};
	

	float getX() { return m_X; }
	float getY() { return m_Y; }
	float getSrcX() { return m_CurrentFrame.x; }
	float getSrcY() { return m_CurrentFrame.y; }



	void setX(float value) { m_X = value; }
	void setY(float value) { m_Y = value; }
	void setSrcX(float value) { m_CurrentFrame.x = value; }
	void setSrcY(float value) { m_CurrentFrame.y = value; }


	void setW(float value) { m_CurrentFrame.w = value; }
	void setH(float value) { m_CurrentFrame.h = value; }



	SDL_Texture* getTex() { return m_Texture; }
	SDL_Rect getCurrentFrame() { return m_CurrentFrame; }

private:
	float m_X, m_Y;
	SDL_Rect m_CurrentFrame;

	SDL_Texture* m_Texture;
	std::vector<SDL_Texture*> m_Textures;
};
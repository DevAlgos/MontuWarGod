#include "Entity.h"

Entity::Entity(float x, float y, float width, float height, SDL_Texture* tex)
	: m_X(x), m_Y(y), m_Texture(tex)
{
	m_CurrentFrame.x = 0;
	m_CurrentFrame.y = 0;
	m_CurrentFrame.h = width;
	m_CurrentFrame.w = height;


}

Entity::Entity(float x, float y, float width, float height, std::vector<SDL_Texture*> Textures)
	: m_X(x), m_Y(y), m_Textures(Textures)
{
	m_CurrentFrame.x = 0;
	m_CurrentFrame.y = 0;
	m_CurrentFrame.h = width;
	m_CurrentFrame.w = height;
}

void Entity::UpdateEntity(float new_x, float new_y)
{
	m_X = new_x;
	m_Y = new_y;
	
}

void Entity::UpdateDimensions(float width, float height)
{
	m_CurrentFrame.w = width;
	m_CurrentFrame.h = height;
}
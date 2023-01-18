#include "Player.h"
#include <iostream>

Player::Player(float x, float y, float width, float height, float velocity, std::vector<SDL_Texture*> Textures)
	: Entity{x,y,width,height,Textures}, m_Velocity(velocity), m_Width(width), m_Height(height)
{
}

Player::Player(float x, float y, float width, float height, float velocity, SDL_Texture* Textures)
: Entity {x, y, width, height, Textures}, m_Velocity(velocity), m_Width(width), m_Height(height)
{
}

Player::Player(float x, float y, float width, float height, float velocity, int numbofTexturesX, int numbofTexturesY, int FPS, SDL_Texture* SpriteSheet)
	: Entity {x,y,width,height,SpriteSheet}, m_Velocity(velocity), m_Width(width), m_Height(height), m_FPS(FPS)
{
	
	SDL_QueryTexture(SpriteSheet, NULL, NULL, &textureWidth, &textureHeight);

	m_FrameWidth = textureWidth / numbofTexturesX;
	m_FrameHeight = textureHeight / numbofTexturesY;

	

	setSrcX(0);
	setSrcY(0);

	UpdateDimensions(m_FrameWidth, m_FrameHeight);

	
}



void Player::moveXRight(int textureIndex)
{
	int res = 1280 - 100;
	if (getX() < res)
		if ((getX() + m_Velocity) > res) {
			int tempVelo = res - getX();
			setX(getX() + tempVelo);
		} else
		{
			setX(getX() + m_Velocity);
		}
		
}

void Player::moveXLeft(int textureIndex)
{
	int res = 0 + m_Width;
	if (getX() > res)
		if ((getX() - m_Velocity) < res) {
			int tempVelo = getX();
			setX(getX() - tempVelo);
		}
		else
		{
			setX(getX() - m_Velocity);
		}
}

void Player::moveYUp(int textureIndex)
{
	int res = 0;
	if (getY() > res)
		if ((getY() - m_Velocity) < res) {
			int tempVelo = getY();
			setY(getY() - tempVelo);
		}
		else
		{
			setY(getY() - m_Velocity);
		}
}

void Player::moveYDown(int textureIndex)
{
	int res = 720 - 100;
	if (getY() < res)
		if ((getY() + m_Velocity) > res) {
			int tempVelo = res - getY();
			setY(getY() + tempVelo);
		}
		else
		{
			setY(getY() + m_Velocity);
		}
	
}

void Player::Update()
{
	if (p_MoveXRight)
		moveXRight(0);
	else if (p_MoveXLeft)
		moveXLeft(0);
	else if (p_MoveYUp)
		moveYUp(0);
	else if (p_MoveYDown)
		moveYDown(0);
	else if(p_MouseMotion)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);

		float ghost_x = getX();
		float ghost_y = getY();

		float gradient = ghost_y / ghost_x;

		/*float distance = sqrt(pow(ghost_x,2) + pow(ghost_y,2));
		std::cout << "distance from ghost: " << distance << std::endl;
		std::cout << "Gradient: " << gradient << std::endl;*/

		/*int r = round(gradient);
		int d = round(distance);*/


		if (x == getX())
			;
		else if (x > getX())
			setX(ghost_x += m_Velocity);
		else if (x < getX())
			setX(ghost_x -= m_Velocity);


		if (y == getY())
			;
		else if (y > getY())
			setY(ghost_y += m_Velocity);
		else if (y < getY())
			setY(ghost_y -= m_Velocity);

		/*ghost.setX(x-10);
		ghost.setY+(y-10);*/
	}

	
		
	
}

void Player::UpdateSprite()
{
	if (p_MouseMotion)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);

		float ghost_x = getX();
		float ghost_y = getY();



		if (x == getX())
			;
		else if (x > getX())
			setX(ghost_x += m_Velocity);
		else if (x < getX())
			setX(ghost_x -= m_Velocity);


		if (y == getY())
			;
		else if (y > getY())
			setY(ghost_y += m_Velocity);
		else if (y < getY())
			setY(ghost_y -= m_Velocity);
	}

	m_FrameTime++;
	if (m_FPS / m_FrameTime == 2)
	{
		m_FrameTime = 0;
	
	
		setSrcX(getSrcX() + m_FrameWidth);

		if (getSrcX() >= textureWidth)
			setSrcX(0);
		
		
		
	}



}

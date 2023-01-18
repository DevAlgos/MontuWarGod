#pragma once

#include "Entity.h"
#include <vector>

class Player : public Entity
{
public:
	Player(float x, float y, float width, float height, float velocity, std::vector<SDL_Texture*> Textures); //Inefficient but option will still be there
	Player(float x, float y, float width, float height, float velocity, SDL_Texture* Textures); //single textures
	Player(float x, float y, float width, float height, float velocity, int numbofTexturesX, int numbofTexturesY, int FPS, SDL_Texture* SpriteSheet); //most efficient

	void moveXRight(int textureIndex); 
	void moveXLeft(int textureIndex);

	void moveYUp(int textureIndex);
	void moveYDown(int textureIndex);

	void Update() override;
	void UpdateSprite(); //Only Use if u are using sprite sheet option

	void setVelocity(float value) { m_Velocity = value; }


	bool p_MoveXRight, p_MoveXLeft;
	bool p_MoveYUp, p_MoveYDown;
	bool p_MouseMotion;

private:
	float m_Velocity = 0;
	float m_Width, m_Height;

	int m_FrameWidth, m_FrameHeight;
	int m_FPS;
	int m_FrameTime = 0;

	int textureWidth, textureHeight;


};
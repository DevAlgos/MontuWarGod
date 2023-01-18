#include "Application.h"
#include "GameWindow.h"
#include "Player.h"
#include "Map.h"
#include "GUIManager.h"

#include <vector>
#include <iostream>
#include <SDL.h>

#include <array>
#include <cmath>



Application::Application()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		std::cout << "SDL_INIT Failed, Error:\n " << SDL_GetError() << std::endl;

	if (!IMG_Init(IMG_INIT_PNG))
		std::cout << "IMG_INIT Failed, Error:\n" << SDL_GetError() << std::endl;
}

Application::~Application()
{
	SDL_Quit();
}

void Application::Run()
{
	GameWindow window(1280, 720, "Game Window");
	GUIManager manager(window.getRenderer());
	

	bool isRunning = true;
	SDL_Event e;

	
	SDL_Texture* texture2 = window.LoadTexture("gfx/images/spritesheet.png");

	SDL_Texture* GrassTexture = window.LoadTexture("gfx/images/Grass.png");
	SDL_Texture* SkyTexture = window.LoadTexture("gfx/images/Sky.png");

	

	SDL_Rect r2;
	r2.x = 1280/2 - 300;
	r2.y = 100;
	r2.w = 600;
	r2.h = 100;
	manager.addText("fonts/perrygothic/PERRYGOT.ttf", 32, "MONTU WAR GOD",r2, {255,255,0});


	std::vector<SDL_Texture*> TextureList;

	TextureList.push_back(SkyTexture);
	TextureList.push_back(GrassTexture);
	


	std::array<std::array<int, 24>, 40> mapList;
	mapList.fill({ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 });

	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 24; j++)
		{
			if (j < 5)
			{
				mapList[i][j] = 0;
			}
			else {
				mapList[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < 40; i++)
	{
		std::cout << "\n";
		for (int j = 0; j < 24; j++)
		{
			std::cout << mapList[i][j] << " ";
		}
	}

	
    
	
	/*mapList.fill({ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 });*/

	Map map(mapList, TextureList);



	int changeX = 1280 / 2;
	int changeY = 720 / 2;

	Entity grass(0, 100, 32,30, GrassTexture);

	float velo = 2;

	Player ghost(changeX, changeY, 59, 30, velo,5,1,144, texture2);

	bool p_Menu = true; //how we swap between menu and game
	


	while (isRunning)
	{
		//will add a system to load in previous saves,levels, etc...
		if (!p_Menu)
		{
			float startFrame = SDL_GetTicks();



			while (SDL_PollEvent(&e))
			{

				switch (e.type)
				{
				case SDL_QUIT:
					isRunning = false;
					break;
				case SDL_MOUSEMOTION:
					ghost.p_MouseMotion = true;
					break;

				case SDL_MOUSEBUTTONDOWN:
					ghost.p_MouseMotion = false;

					int x, y;
					SDL_GetMouseState(&x, &y);

					if (x == 0 && y == 0)
						p_Menu = true;

					break;
					
				}





			}

			window.clear();

			/*for (Entity& i : Entities)
			{
				window.render(i);
			}*/




			map.DrawMap(window.getRenderer());
			window.render(ghost);
			ghost.UpdateSprite();
			manager.update();


			window.display();



			float EndFrame = SDL_GetTicks() - startFrame;
			float FPS = 1000 / EndFrame;

			//std::cout << "FPS: " << FPS << std::endl;
		}
		else {
			while (SDL_PollEvent(&e))
			{

				switch (e.type)
				{
				case SDL_QUIT:
					isRunning = false;
					break;
				case SDL_MOUSEBUTTONDOWN:
					int x, y;
					SDL_GetMouseState(&x, &y);

					std::cout << x << " " << y << std::endl;

					if (x == 0 && y == 0)
						p_Menu = false;
					break;
				}


				manager.update();
				window.display();
			}
		}
	}
		
		


		
	
}



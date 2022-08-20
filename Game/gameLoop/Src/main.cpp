#include "Game.h"
#include "Audio.h"
#include "dashboard.h"
#include "Help.h"
#include "Button.h"

Game *game = nullptr;
Dashboard* dashboard = nullptr;
Help* help = nullptr;
extern Button* buttonArray;

int main(int argc, char *argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	unsigned int frameStart;
	int frameTime;
	Audio a;


		dashboard = new Dashboard();
		dashboard->dashInit("Dashboard", 800, 640, false);

		while (dashboard->dashRunning())
		{
			frameStart = SDL_GetTicks();

			dashboard->dashHandleEvents();
			dashboard->dashUpdate();
			dashboard->dashRender();
			if (!Mix_PlayingMusic())
			{
				a.playMusic();
			}

			SDL_PollEvent(&Dashboard::dashEvent);
			switch (Dashboard::dashEvent.type)
			{
			case SDL_QUIT:
				dashboard->isDashRunning = false;
				dashboard->dashClean();
				break;
			case SDL_MOUSEBUTTONDOWN:
				if (Dashboard::dashEvent.button.button == SDL_BUTTON_LEFT)
				{
					a.playEffects();
					//std::cout << "Left click" <<std:: endl;
					if (buttonArray[0].isSelected)
					{
						std::cout << "Button Selected" << std::endl;
						dashboard->isDashRunning = false;
						dashboard->dashClean();

						game = new Game();
						game->init("GameWindow", 800, 640, false);

						while (game->running())
						{
							frameStart = SDL_GetTicks();

							game->handleEvents();
							game->update();
							game->render();
							if (!Mix_PlayingMusic())
							{
								a.playMusic();
							}

							frameTime = SDL_GetTicks() - frameStart;

							if (frameDelay > frameTime)
							{
								SDL_Delay(frameDelay - frameTime);
							}



							if (Game::isComplete == true)
							{
								if (Game::event.type == SDL_KEYDOWN)
								{
									switch (Game::event.key.keysym.sym)
									{
									case SDLK_m:
										game->isRunning = false;
										game->isComplete = false;
										//game->clean();
										dashboard = new Dashboard();
										dashboard->dashInit("Dashboard", 800, 640, false);
										dashboard->isDashRunning = true;

										break;
									default:
										break;
									}
								}
							}
						}
						game->clean();
					}
					else if (buttonArray[1].isSelected)
					{
						dashboard->isDashRunning = false;
						dashboard->dashClean();
					}
					else if (buttonArray[2].isSelected)
					{
						//std::cout << "hi" << std::endl;
						dashboard->isDashRunning = false;
						dashboard->dashClean();
						help = new Help();
						help->helpInit("Instructions", 500, 500, false);

						while (help->helpRunning())
						{
							frameStart = SDL_GetTicks();

							help->helpHandleEvents();
							//game->update();
							help->helpRender();
							//if (!Mix_PlayingMusic())
							//{
							//	a.playMusic();
							//}
							//a.playEffects();
							a.playMusic();
							frameTime = SDL_GetTicks() - frameStart;

							if (frameDelay > frameTime)
							{
								SDL_Delay(frameDelay - frameTime);
							}
						}
						help->helpClean();
						dashboard = new Dashboard();
						dashboard->dashInit("Dashboard", 800, 640, false);
						dashboard->isDashRunning = true;
					}

				}
			default:
				break;
			}
			switch (Dashboard::dashEvent.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				dashboard->isDashRunning = false;
				break;
			default:
				break;
			}
			frameTime = SDL_GetTicks() - frameStart;

			if (frameDelay > frameTime)
			{
				SDL_Delay(frameDelay - frameTime);
			}
		}
		dashboard->dashClean();


	game->clean();
	return 0;
}
#include "Main.h"
#include "GameStateManager.h"

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include <Windows.h>
#include <chrono>
#include <thread>


Main::Main(void)
{
	GameStateManager* gsm = GameStateManager::Instance();
	gsm->init();
	this->runLoop(gsm);
}


Main::~Main(void)
{
}

void Main::runLoop(GameStateManager* gsm) {
	double TARGET_FPS = 60;
	double OPTIMAL_TIME = 1000 / TARGET_FPS;

	//Instantiate Large Integers
	LARGE_INTEGER frequency; // ticks per second
	LARGE_INTEGER previousTime, currentTime, afterLoopTime; // ticks
	//Set Frequency
	QueryPerformanceFrequency(&frequency);
	//Set Previous Time (for the first time)
	QueryPerformanceCounter(&previousTime);

	//Instantiate FPS variables and set to 0
	long lastFpsTime = 0;
	int fps = 0;
	int gameState = 0;
	while (true) {		
		//Take current Time
		QueryPerformanceCounter(&currentTime);
		//Calculate difference (previousTime - currentTime)
		long updateLength = (currentTime.QuadPart - previousTime.QuadPart) * 1000.0 / frequency.QuadPart;

		//Previous time = current time
		previousTime = currentTime;
		//Calculate delta
		double delta = updateLength / OPTIMAL_TIME;
		//Add time difference to lastFpsTime
		lastFpsTime += updateLength;
		//Increase FPS since one frame has passed
		fps++;

		//If lastFpsTime > 1000 ms, set FPS to 0 and start re-calculating
		if (lastFpsTime >= 1000) {
			//std::cout << "FPS: "<< fps << std::endl;
			lastFpsTime = 0;
			fps = 0;
		}

		if(delta > 4.0) { delta = 4.0; }
		//UPDATE SHIT	
		gsm->handleEvents();		
		gsm->update(delta);
		//gsm->draw();
		gsm->draw();

		//Get time after loop
		QueryPerformanceCounter(&afterLoopTime);
		//Sleep if needed (if time took longer than optimal)
		if ((((previousTime.QuadPart - afterLoopTime.QuadPart) * 1000.0 / frequency.QuadPart) + OPTIMAL_TIME) > 0) {
			Sleep((((previousTime.QuadPart - afterLoopTime.QuadPart) * 1000.0 / frequency.QuadPart) + OPTIMAL_TIME));
		}
	}
}

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	Main* main = new Main();






	return 0;
}
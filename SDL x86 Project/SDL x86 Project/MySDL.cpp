#include "MySDL.h"
#include <math.h>
#include <random>
#include <iostream>


MySDL::MySDL(void)
{
}

void MySDL::init() {
	int width = 1280;
	int height = 720;
	int max_radius = 50;

	window = SDL_CreateWindow(
		"KMINT Opdrachten",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		false
		);

	renderer = SDL_CreateRenderer(window, -1, 0);
}

void MySDL::drawScreen() {
	SDL_RenderPresent(renderer);
}

void MySDL::drawTexture(SDL_Texture* texture, const SDL_Rect* dest, SDL_Rect* crop) {
	SDL_RenderCopy(renderer, texture, crop, dest);
}

void MySDL::clearScreen() {
	SDL_RenderClear(renderer);
}

SDL_Renderer* MySDL::getRenderer() {
	return this->renderer;
}

void MySDL::drawRectangle(int x, int y, int width, int height, int r, int g, int b) {
	this->setRenderColor(r,g,b);

	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
	SDL_RenderFillRect(renderer, &rect);
	this->resetRenderColor();
}

void MySDL::drawLine(int x1, int y1, int x2, int y2, int r, int g, int b) {
	this->setRenderColor(r,g,b);
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	this->resetRenderColor();
}

void MySDL::setRenderColor(int r, int g, int b) {
	SDL_SetRenderDrawColor(renderer, r,g,b,255);
}

void MySDL::resetRenderColor() {
	SDL_SetRenderDrawColor(renderer, 0,0,0,255);
}


MySDL::~MySDL(void)
{
}

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_ttf.h>
class MySDL
{
public:
	MySDL(void);

	void init();

	void drawScreen();
	void drawTexture(SDL_Texture* texture, const SDL_Rect* dest, SDL_Rect* crop);
	void clearScreen();

	SDL_Renderer* getRenderer();

	void drawRectangle(int x, int y, int width, int height, int r, int g, int b);
	void drawLine(int x1, int y1, int x2, int y2, int r, int g, int b);
	void drawText(std::string msg, int x, int y, int w, int h);

	void setRenderColor(int r, int g, int b);
	void resetRenderColor();

	virtual ~MySDL(void);

private:
	SDL_Surface* screen;
	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* font;
};


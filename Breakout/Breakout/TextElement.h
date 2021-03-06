#pragma once
#include <string>
class Texture;
class TextElement
{
public:
	TextElement(std::string message, int x = 0, int y = 0);
	void SetText(std::string message);
	int GetWidth();
	int GetHeight();
	void Render();
	~TextElement();
	void SetX(int x);
	void SetY(int y);
private:
	std::string message;
	Texture* texture = nullptr;
	int x;
	int y;
	int width;
	int height;
	//SDL_Rect* rect = nullptr;
};


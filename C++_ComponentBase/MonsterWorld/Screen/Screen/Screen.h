#pragma once

class Screen
{
	int width;
	int height;
	char* canvas;

	static Screen* instance;
	Screen(int width = 90, int height = 50)
		: width(width), height(height),
		canvas(new char[(width + 1)*height])

	{
		Input::Initialize();
	}
public:
	static Screen& getInstance();
	~Screen();
	void drawRect(const Position& pos, int w, int h);
	void draw(const char* shape, int w, int h, const Position& pos);
	void render();
	void clear();


	int getWidth() const { return width; }
	int getHeight() const { return height; }
};
#pragma once

class Turtle;

class Painter
{
public:
	Painter(Turtle*);
	bool DrawCircle(int, int, int);
	~Painter();

private:
	Turtle* turtle;
};


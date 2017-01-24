#include "Painter.h"
#include "Turtle.h"

Painter::Painter(Turtle *turtle) : turtle(turtle)
{
}

bool Painter::DrawCircle(int x, int y, int radius)
{
	turtle->PenDown();
	//turtle->PenUp();
	return true;
}

Painter::~Painter()
{
}

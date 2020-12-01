#include "classFruit.h"



Fruit::Fruit()
{
	generate_fruit();
}

COORD Fruit::get_fruit_pos()
{
	return fruit_pos;
}

void Fruit::generate_fruit()
{
	fruit_pos.X = 1 + (rand() % 58);
	fruit_pos.Y = 1 + (rand() % 38);
}



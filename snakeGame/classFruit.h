#pragma once
#include "classSnake.h"



// class fruit

class Fruit
{
private:
	COORD fruit_pos;           

public:
	Fruit();
	~Fruit();

	COORD get_fruit_pos();         // get fruit position

	void generate_fruit();         // giving the fruit new position 
};


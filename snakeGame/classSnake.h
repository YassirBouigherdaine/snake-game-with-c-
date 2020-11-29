#pragma once

#include<Windows.h>
#include<vector>



// class snake 

class Snake
{
private:
	int size;                              // current size
	char direction;                        // current direction
	int Step;
	COORD position; 
	std::vector<COORD> body;

public:
	Snake(COORD pos, int step);
	COORD get_head_pos();                  // get snake head position
	std::vector<COORD>get_body_pos();      // get snake body position

	// changing diection
	void turn_right();
	void turn_left();
	void turn_up();
	void turn_down();

	void move();                          // moving snake

	void add_size();                      // increasing the lenght of snake

};


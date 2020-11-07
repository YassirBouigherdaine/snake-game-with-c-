#pragma once

#include"classSnake.h"
#include"classFruit.h"

#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<time.h>



// game logic

// dimensions of the board

constexpr auto WIDTH = 60;
constexpr auto HEIGHT = 40;


bool gameOver = false;
int score = 0;

// creating objects
Snake snake({ WIDTH / 2,HEIGHT / 2 }, 1);
Fruit fruit;

COORD snake_head;
std::vector<COORD> snake_body;
COORD fruit_position;


//to put back the cursor in the origin of console
COORD cursor_origin;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y)
{
	cursor_origin.X = 0;
	cursor_origin.Y = 0;
	SetConsoleCursorPosition(console, cursor_origin);
}


// drawing game board

void board()
{
	snake_head = snake.get_head_pos();
	fruit_position = fruit.get_fruit_pos();
	snake_body = snake.get_body_pos();
	
	for (int i = 0; i < HEIGHT; i++)
	{
		std::cout << '#';

		for (int j = 0; j < WIDTH-2; j++)
		{
			if (i == 0 || i == HEIGHT - 1)
			{
				std::cout << '#';
			}

			else if (i == snake_head.Y && j+1 == snake_head.X)           // drawing the head of snake
			{
				std::cout << "*";
			}

			else if (i == fruit_position.Y && j+1 == fruit_position.X)
			{
				std::cout << "F";
			}

			else
			{
				// drawing the body of snake

				bool body_part = false;

				for (int k = 0; k < snake_body.size() - 1; k++)
				{
					if (i == snake_body[k].Y && j+1 == snake_body[k].X)
					{
						std::cout << "*";
						body_part = true;
						break;
					}

					// case head hit the body

					else if (snake_head.Y == snake_body[k].Y && snake_head.X == snake_body[k].X)
					{
						gameOver = true;
					}
				}

				if (!body_part)
				{
					std::cout << " ";
				}
			}
				
		}
		
		std::cout << '#' << std::endl;
	}
	std::cout << "\t\t\n Score: " << score;
	std::cout << "\n\t\t\n press [Q] to quit the game";
}

// get input from user
void Input()
{
	if (_kbhit())                         // any key board hit is true
	{
		switch (_getch())
		{
		case 'e': snake.turn_right();  
			break;

		case 'a': snake.turn_left();  
			break;

		case 'z': snake.turn_up();  
			break;

		case 's': snake.turn_down();  
			break;

		case 'q': gameOver = true;       // guit the game
		}
	}
}


void snake_collision()
{
	// collision of snake with the fruit
	if (snake_head.Y == fruit_position.Y && snake_head.X == fruit_position.X)
	{
		fruit.generate_fruit();
		snake.add_size();
		score++;
		// increase the level of the game
		if (score % 10 == 0)
		{
			snake.add_speed();
		}
	}

	// collision of snake with the wall
	else if (snake_head.Y > HEIGHT-1 || snake_head.Y <1 || snake_head.X > WIDTH-1 || snake_head.X < 1)
	{
		gameOver = true;
	}
 }




#include"setupGame.h"








int main()
{
	srand(time(0));

	fruit.generate_fruit();

	while (!gameOver)
	{
		SetConsoleCursorPosition(console, cursor_origin);

		board();
		
		Input();

		snake.move();
	
		snake_collision();
	
	}
	
	return 0;
}
#include "classSnake.h"



Snake::Snake(COORD pos, int step)
{
	position = pos;
	Step = step;
	size = 1;         
    body.push_back(position);
	direction = 'n';          // direction not defined yet
}

COORD Snake::get_head_pos()
{
    return position;
}

std::vector<COORD>Snake::get_body_pos()
{
    return body;
}

void Snake::add_size()
{
    size++;
}

void Snake::add_speed()
{
    Step++;
}

void Snake::turn_right()
{
	direction = 'e';
}

void Snake::turn_left()
{
    direction = 'a';
}
void Snake::turn_up()
{
    direction = 'z';
}
void Snake::turn_down()
{
    direction = 's';
}

void Snake::move()
{
    switch (direction)
    {
    case 'a':
        position.X -= Step;
        break;

    case 'e':
        position.X += Step;
        break;

    case 'z':
        position.Y -= Step;
        break;

    case 's':
        position.Y += Step;
        break;
    }

    body.push_back(position);

    if (body.size() > size)
    {
        body.erase(body.begin());    // removing position of the head
    }
}





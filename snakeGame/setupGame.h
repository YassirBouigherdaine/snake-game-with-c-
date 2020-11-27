#pragma once

#include"classSnake.h"
#include"classFruit.h"

#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<time.h>



// game logic



void gotoxy(int x, int y);

void board();         // drawing game board

void Input();        // get input from user

void eat_fruit();    // collision of snake with the fruit

void game();          // main game


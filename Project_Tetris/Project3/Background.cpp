#define _CRT_SECURE_NO_WARNINGS
#define CONSOLE_SCREEN_COLS_BYTES (50 * 3 + 1)
#include <iostream>
#include <string>
#include "Background.h"
#include <vector>


//배경 만들기 코드 

int Background[HEIGHT][WIDTH] = {{0}};
int index = 1;

void Backgroundunit() //배경함수 정의 2는 테두리, 0은 빈칸
{ //배경 변수 선언
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (j == 0 || j == 11 || i == 21 || i == 0)	{
				Background[i][j] = 2;
			}
			else
			{
				Background[i][j] = 0;
			}
		}
	}
}

void PrintBackground(vector<wstring>& screen) //배경함수 그리기 코드, 2일 때 벽 블럭, 1일때 무빙 블럭, 0일 때 공백
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (Background[i][j] == 2) //벽 블럭
			{
				//printf("□");
				
				if ((i == 0 || i == 21) && j >= 1 && j <= 10)
					screen[i][j] = L'─';
				else if(i == 0 && j == 0)
					screen[i][j] = L'┌';
				else if (i == 0 && j == 11)
					screen[i][j] = L'┐';
				else if (i == 21 && j == 0)
					screen[i][j] = L'└';
				else if (i == 21 && j == 11)
					screen[i][j] = L'┘';
				else 
					screen[i][j] = L'│';
			}
			else if (Background[i][j] == 1) //무빙블럭
			{
				//printf(" ■ ");
				
				screen[i][j] = L'▪';
			}
			else
			{
				//printf("   "); //공백
				
				screen[i][j] = L'    ';
			}
		}
		printf("\n");
	}
}


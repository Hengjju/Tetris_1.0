#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "Background.h"
using namespace std;

HANDLE hbuff[2];


int actBuff = 0;

void Dbuff()
{
	//hbuff는 화면버퍼 생성함수를 받는 배열 (2개 생성)
	hbuff[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	//CreateConsoleScreenBuffer 윈도우 콘솔에 출력할 수 있는 '화면 버퍼'를 생성하는 함수
	hbuff[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	//커서 속성 설정 : 크기 1, 보이지 않도록(false)
	CONSOLE_CURSOR_INFO cursorInfo = { 1, FALSE };
	//첫번째 버퍼에 설정 적용
	SetConsoleCursorInfo(hbuff[0], &cursorInfo);
	//두번째 버퍼에 설정 적용
	SetConsoleCursorInfo(hbuff[1], &cursorInfo);

	//현재 활성 화면 버퍼를 actBuff로 설정 (0은 비활성, 1은 활성)
	SetConsoleActiveScreenBuffer(hbuff[actBuff]);
}

void smoothgame(const vector<wstring>& screen)
{
	COORD pos = { 0, 0 }; //화면버퍼 위치
	DWORD written; // 
	wchar_t buffer[HEIGHT][WIDTH * 2 + 1];

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			buffer[i][j * 2] = screen[i][j];
			buffer[i][j * 2 + 1] = L' ';
		}
		buffer[i][WIDTH * 2] = L'\n';
	}

	SetConsoleCursorPosition(hbuff[actBuff], pos);
	WriteConsoleW(hbuff[actBuff], &buffer[0][0], HEIGHT * (WIDTH * 2 + 1), &written, NULL);

	actBuff = 1 - actBuff;
	SetConsoleActiveScreenBuffer(hbuff[actBuff]);
}



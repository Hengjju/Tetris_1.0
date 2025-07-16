#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include "Background.h"
#include "Dbuff.h"
using namespace std;

extern HANDLE hbuff[2]; //전역 변수 사용
extern int actBuff; //전역변수 사용

void G_over(vector<wstring>& screen)
{
	HANDLE currentBufferHandle = hbuff[actBuff];
	DWORD charsWritten;
	COORD cursorHome = { 20, 1 };

	DWORD numCellsToClear = (WIDTH * 2 + 1) * (HEIGHT + 1);

	FillConsoleOutputCharacterW(currentBufferHandle, L' ', numCellsToClear, cursorHome, &charsWritten);
	FillConsoleOutputAttribute(currentBufferHandle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY, numCellsToClear, cursorHome, &charsWritten);
	wstring gameOverMessage = L"G a m e  O v e r";
	wstring gameOverMessage1 = L"To Restart";
	wstring gameOverMessage2 = L"Press the 'R' Button";
	short mesX = (short)((WIDTH * 2 - gameOverMessage.length()) / 2);
	short mesY = (short)((HEIGHT / 2) - 3);

	//메시지 시작 위치 설정
	COORD messagePos = { mesX, mesY };

	//커서를 메시지 출력 위치로 이동
	SetConsoleCursorPosition(currentBufferHandle, messagePos);

	//Game over 메시지 출력
	WriteConsoleW(currentBufferHandle, gameOverMessage.c_str(), gameOverMessage.length(), &charsWritten, NULL);
	
	// 화면 버퍼 업데이트
	SetConsoleActiveScreenBuffer(currentBufferHandle);

	mesX = (short)((WIDTH * 2 - gameOverMessage1.length()) / 2);
	mesY = (short)((HEIGHT / 2) - 1);
	messagePos = { mesX, (short)(mesY + 2) };

	SetConsoleCursorPosition(currentBufferHandle, messagePos);

	//Game over 메시지 출력
	WriteConsoleW(currentBufferHandle, gameOverMessage1.c_str(), gameOverMessage1.length(), &charsWritten, NULL);

	// 화면 버퍼 업데이트
	SetConsoleActiveScreenBuffer(currentBufferHandle);

	mesX = (short)((WIDTH * 2 - gameOverMessage2.length()) / 2);
	mesY = (short)((HEIGHT / 2) - 1);
	messagePos = { mesX, (short)(mesY + 4) };


	SetConsoleCursorPosition(currentBufferHandle, messagePos);

	//Game over 메시지 출력
	WriteConsoleW(currentBufferHandle, gameOverMessage2.c_str(), gameOverMessage2.length(), &charsWritten, NULL);

	// 화면 버퍼 업데이트
	SetConsoleActiveScreenBuffer(currentBufferHandle);

	actBuff = 1 - actBuff;
}

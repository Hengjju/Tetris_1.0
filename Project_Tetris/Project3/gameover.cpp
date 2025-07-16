#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include "Background.h"
#include "Dbuff.h"
using namespace std;

extern HANDLE hbuff[2]; //���� ���� ���
extern int actBuff; //�������� ���

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

	//�޽��� ���� ��ġ ����
	COORD messagePos = { mesX, mesY };

	//Ŀ���� �޽��� ��� ��ġ�� �̵�
	SetConsoleCursorPosition(currentBufferHandle, messagePos);

	//Game over �޽��� ���
	WriteConsoleW(currentBufferHandle, gameOverMessage.c_str(), gameOverMessage.length(), &charsWritten, NULL);
	
	// ȭ�� ���� ������Ʈ
	SetConsoleActiveScreenBuffer(currentBufferHandle);

	mesX = (short)((WIDTH * 2 - gameOverMessage1.length()) / 2);
	mesY = (short)((HEIGHT / 2) - 1);
	messagePos = { mesX, (short)(mesY + 2) };

	SetConsoleCursorPosition(currentBufferHandle, messagePos);

	//Game over �޽��� ���
	WriteConsoleW(currentBufferHandle, gameOverMessage1.c_str(), gameOverMessage1.length(), &charsWritten, NULL);

	// ȭ�� ���� ������Ʈ
	SetConsoleActiveScreenBuffer(currentBufferHandle);

	mesX = (short)((WIDTH * 2 - gameOverMessage2.length()) / 2);
	mesY = (short)((HEIGHT / 2) - 1);
	messagePos = { mesX, (short)(mesY + 4) };


	SetConsoleCursorPosition(currentBufferHandle, messagePos);

	//Game over �޽��� ���
	WriteConsoleW(currentBufferHandle, gameOverMessage2.c_str(), gameOverMessage2.length(), &charsWritten, NULL);

	// ȭ�� ���� ������Ʈ
	SetConsoleActiveScreenBuffer(currentBufferHandle);

	actBuff = 1 - actBuff;
}

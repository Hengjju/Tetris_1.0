#include <iostream>
#include "Blockshape.h" //Blockshape, �� ���� ���� ���� ����

// �� ��� �ڵ�
#define B_S 4

int Blockshape[B_S][B_S] = { {0} }; //�� �ʱ�ȭ
int B_S_I[B_S][B_S] =
{ {1,1,1,1} };// I�� ��

int B_S_T[B_S][B_S] =
{ {0,1,0},{1,1,1} }; //T�� ��

int B_S_L[B_S][B_S] =
{ {0,0,1},{1,1,1} }; // L�� ��

int B_S_J[B_S][B_S] =
{ {1,0,0},{1,1,1} }; // J�� ��

int B_S_S[B_S][B_S] =
{ {0,1,1},{1,1,0} }; // S�� ��

int B_S_Z[B_S][B_S] =
{ {1,1,0},{0,1,1} }; // Z�� ��

int B_S_O[B_S][B_S] =
{ {1,1},{1,1} }; // O�� ��

void Blocksh()
{
	int Blockshape[B_S][B_S] = {{0}}; //�� �ʱ�ȭ
	int B_S_I[B_S][B_S] =
	{ {1,1,1,1} };// I�� ��

	int B_S_T[B_S][B_S] =
	{ {0,1,0},{1,1,1} }; //T�� ��

	int B_S_L[B_S][B_S] =
	{ {0,0,1},{1,1,1} }; // L�� ��

	int B_S_J[B_S][B_S] =
	{ {1,0,0},{1,1,1} }; // J�� ��

	int B_S_S[B_S][B_S] =
	{ {0,1,1},{1,1,0} }; // S�� ��

	int B_S_Z[B_S][B_S] =
	{ {1,1,0},{0,1,1} }; // Z�� ��

	int B_S_O[B_S][B_S] =
	{ {1,1},{1,1} }; // O�� ��
}


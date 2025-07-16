#include <iostream>
#include "Blockshape.h" //Blockshape, 각 블럭들 전역 변수 선언

// 블럭 모양 코드
#define B_S 4

int Blockshape[B_S][B_S] = { {0} }; //블럭 초기화
int B_S_I[B_S][B_S] =
{ {1,1,1,1} };// I자 블럭

int B_S_T[B_S][B_S] =
{ {0,1,0},{1,1,1} }; //T자 블럭

int B_S_L[B_S][B_S] =
{ {0,0,1},{1,1,1} }; // L자 블럭

int B_S_J[B_S][B_S] =
{ {1,0,0},{1,1,1} }; // J자 블럭

int B_S_S[B_S][B_S] =
{ {0,1,1},{1,1,0} }; // S자 블럭

int B_S_Z[B_S][B_S] =
{ {1,1,0},{0,1,1} }; // Z자 블럭

int B_S_O[B_S][B_S] =
{ {1,1},{1,1} }; // O자 블럭

void Blocksh()
{
	int Blockshape[B_S][B_S] = {{0}}; //블럭 초기화
	int B_S_I[B_S][B_S] =
	{ {1,1,1,1} };// I자 블럭

	int B_S_T[B_S][B_S] =
	{ {0,1,0},{1,1,1} }; //T자 블럭

	int B_S_L[B_S][B_S] =
	{ {0,0,1},{1,1,1} }; // L자 블럭

	int B_S_J[B_S][B_S] =
	{ {1,0,0},{1,1,1} }; // J자 블럭

	int B_S_S[B_S][B_S] =
	{ {0,1,1},{1,1,0} }; // S자 블럭

	int B_S_Z[B_S][B_S] =
	{ {1,1,0},{0,1,1} }; // Z자 블럭

	int B_S_O[B_S][B_S] =
	{ {1,1},{1,1} }; // O자 블럭
}


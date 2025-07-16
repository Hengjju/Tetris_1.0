#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;


#define WIDTH 12
#define HEIGHT 22


extern int Background[HEIGHT][WIDTH]; // 전역 변수 설정
extern int index;

void Backgroundunit(); // 배경 함수에 대한 정의 (지역변수 x)
void Backgroundunit1(); // 배경 테두리 계속 지속
void PrintBackground(vector<wstring>& screen); //(지역변수 x)
void moveblock(int* X, int* Y);
void PhysicsLogic(int X, int Y, vector<wstring>& screen);
void turnB(char ch);

#endif

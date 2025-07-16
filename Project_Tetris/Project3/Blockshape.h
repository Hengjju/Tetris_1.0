#ifndef BLOCKSHAPE_H
#define BLOCKSHAPE_H
using namespace std;
#include <string>
#include <vector>


extern int Blockshape[4][4];
extern int B_S_I[4][4];
extern int B_S_T[4][4];
extern int B_S_L[4][4];
extern int B_S_J[4][4];
extern int B_S_Z[4][4];
extern int B_S_S[4][4];
extern int B_S_O[4][4];

void Blocksh(); //전역변수(블럭들)의 정의코드
void moveblock(int* X, int* Y);
void randb();
void PhysicsLogic(int X, int Y, vector<wstring>& screen);
void turnB(char ch);
void HardDrop();

#endif

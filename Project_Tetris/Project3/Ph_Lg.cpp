#include <iostream>
#include "Background.h"
#include "Blockshape.h"

// 블록을 배경에 배치하는 함수
void PhysicsLogic(int X, int Y, vector<wstring>& screen) // 오류날 시 char screen만 지우면 됨
{
    // 블록을 배경에 배치
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (Blockshape[i][j] == 1)
            {
                //Background[X + i][Y + j] = 1; // 블록을 배경에 배치
                screen[X + i][Y + j] = L'▪';
            }
        }
    }
}
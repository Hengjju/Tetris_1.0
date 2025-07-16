#include <iostream>
#include "Background.h"
#include "Blockshape.h"

// 블록을 움직일 때 잔상 제거
void ClearGhost(int X, int Y)
{
    // 블록을 배경에 배치
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (Blockshape[i][j] == 1)
            {
                Background[X + i][Y + j] = 0; // 블록을 배경에 배치
            }
        }
    }
}
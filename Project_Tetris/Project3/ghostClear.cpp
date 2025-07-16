#include <iostream>
#include "Background.h"
#include "Blockshape.h"

// ����� ������ �� �ܻ� ����
void ClearGhost(int X, int Y)
{
    // ����� ��濡 ��ġ
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (Blockshape[i][j] == 1)
            {
                Background[X + i][Y + j] = 0; // ����� ��濡 ��ġ
            }
        }
    }
}
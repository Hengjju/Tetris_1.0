#include <stdio.h>
#include <conio.h>
#include "move.h"
#include "Blockshape.h"
#include "Background.h"
#include "ghostClear.h"



void moveBlock2(int* X, int* Y, int ch) // 좌, 우 이동
{
    //ClearGhost(*X, *Y);
    int find = 0, floor = 0, Index = 0, ifloor;
    char ct = 0;
    for (int i = 3; i >= 0; i--) // 블록의 각 열을 확인
    {
        for (int j = 0; j < 4; j++) // 블록의 각 행을 확인
        {
            if (Blockshape[i][j] == 1) // 블록이 존재하는 위치
            {
                if (find == 0 && Blockshape[i][j] == 1) //블럭을 찾은 횟수가 0이고, 블럭이 i번째 열, j번째 행에 블럭이 있다면
                    floor = i; //그 블럭이 있는곳이 바닥이다                 
                if (j >= Index) {//오른쪽으로 얼마나 튀어나와있나 확인 
                    Index = j;  // 몇 번쨰 행에 그 블럭이 있는가
                    ifloor = i; //몇 번째 열에 그 블럭이 있는가
                }
                find++;
            }
        }
    }
    /*if (_kbhit()) {
        ct = _getch();*/
 
    
        ct = _getch();
        switch (ct) {
        case 75: // ← 왼쪽
            if (Background[*X][*Y - 1] == 0) //왼쪽에 블럭이 없다면 이동가능
                (*Y)--;
            break;
        case 77: // → 오른쪽
            if (Background[*X + ifloor][*Y + Index + 1] == 0 || Background[*X][*Y + Index + 1] == 0) // 오른쪽에 블럭이 없다면 이동가능
                (*Y)++;
            break;
        case 80: // ↓ 아래
            if (Background[*X + floor + 1][*Y] == 0 || Background[*X + floor + 2][*Y] == 0 || Background[*X + floor + 3][*Y] == 0) // 아래에 블럭이 없다면 이동 가능
                (*X)++;
            break;
        default:
            break;
        }

        for (int i = 3; i >= 0; i--) // 블록의 행을 뒤에서부터 확인 (아래에서부터)
        {
            for (int j = 0; j < 4; j++) // 블록의 열을 확인
            {
                if (Blockshape[i][j] == 1)
                {
                    Background[*X + i][*Y + j] = 1;  // 블록을 한 칸 아래로 내림
                }
            }
        }
        //}
    
}



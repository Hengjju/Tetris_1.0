#include <iostream>
#include <windows.h>
#include "Blockshape.h"
#include "Background.h"

int canMove = 1;

// 블록을 1초마다 아래로 내리는 함수
void moveblock(int* X, int* Y) // x는 위 아래, y좌우
{
    int find = 0, floor = 0, cant = 0, bump = 0, bfloor = 0; //find : 밑에 블럭이 있는지 확인하는 변수, //
    canMove = 1; // 함수가 호출될 때마다 canMove를 초기화

    // 먼저 전체 블록을 검사해서 내려갈 수 있는지 확인
    for (int i = 3; i >= 0; i--) // 블록의 각 행을 확인
    {
        for (int j = 0; j < 4; j++) // 블록의 각 열을 확인
        {
            if (Blockshape[i][j] == 1) // 블록이 존재하는 위치
            { 
                if (find == 0 && Blockshape[i][j] == 1)
                    floor = i; //find가 0이면 이번에 찾은 것이 처음인 블럭인 것
                find++;
                // 만약 바닥에 있는 블럭이고 밑에 블럭이 0이 아니라면 
                if (floor == i && Background[*X + i + 1][*Y + j] != 0)
                    cant++; //밑에 내려갈 수 있는지 없는지 확인   
            }
        }
    }
    
    for (int i = 0; i <= 3; i++) // 블록의 각 열을 확인
    {
        bump = 0;
        bfloor = -1;
        for (int j = 3; j >= 0; j--) // 블록의 각 행을 확인
        {
            if (i == 0 && Blockshape[j][i] == 1) //만약 0번째 열에 블럭이 있으면 bump를 1 증가 그 때의 행을 bfloor에 저장 
            { 
                bump++;
                bfloor = j;
            }
            else if (i == 1 && Blockshape[j][i] == 1)//만약 1번째 열에 블럭이 있으면 bump를 1 증가 그 때의 행을 bfloor에 저장
            {
                bump++;
                bfloor = j;
            }
            else if(i == 2 && Blockshape[j][i] == 1)//만약 2번째 열에 블럭이 있으면 bump를 1 증가 그 때의 행을 bfloor에 저장
            {
                bump++;
                bfloor = j;
            }
            else if(i == 3 && Blockshape[j][i] == 1)//만약 3번째 열에 블럭이 있으면 bump를 1 증가 그 때의 행을 bfloor에 저장
            {
                bump++;
                bfloor = j;
            }
        }
        if (bump == 1 && Background[*X + bfloor + bump][*Y + i] != 0) // 그 열에 블럭이 하나만 있으면 그 블럭은 튀어나온 블럭
            cant++;
        else if (bump == 2 && Background[*X + bfloor + bump][*Y + i] != 0)
            cant++;
    }

    // 만약 블록이 내려갈 수 있다면 
    if (cant == 0)
    {
        // 블록을 한 칸 아래로 이동
        for (int i = 3; i >= 0; i--) // 블록의 행을 뒤에서부터 확인 (아래에서부터)
        {
            for (int j = 0; j < 4; j++) // 블록의 열을 확인
            {
                if (Blockshape[i][j] == 1)
                {
                    Background[*X + i + 1][*Y + j] = 1;  // 블록을 한 칸 아래로 내림
                    Background[*X + i][*Y + j] = 0;      // 원래 자리를 비움
                }
            }
        }
        (*X)++; // Y값을 증가시켜 블록을 내리기
    }
    else if (cant >= 1) //만약 cant 변수 값이 1보다 같거나 크다면 움직일 수 없다.
    {
        canMove = 0;
    }
    //Sleep(100);

}

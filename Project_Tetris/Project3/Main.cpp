#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <locale>
#include "Background.h"
#include "Blockshape.h"
#include "randb.h"
#include "move.h"
#include "Clearblock.h"
#include "move2.h"
#include "ghostClear.h"
#include "turnblock.h"
#include "Dbuff.h"
#include "smoothgame.h"
#include "Hdrop.h"
#include "gameover.h"
using namespace std;


int rotationIndex;
int RandB;
int X, Y;
int loop = 0;
int keypressed;
int indexB[20] = { 0 };
int countnum = 0;


int main()
{
    
    locale::global(locale(""));
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    Dbuff();
    vector<wstring> screen(HEIGHT, wstring(WIDTH,L' ')); //더블버퍼 실행
    int X = 1, Y = 4;  // 초기 블록 위치
   
    // 배경 초기화 (경계선)

    Backgroundunit();
    canMove = 0;

    while (1)
    {
        for (int i = 0; i <= 19; i++)
            indexB[i] = 0;
        countnum = 0;
        if (canMove == 0) //새로운 블럭이 생성될 때 canMove가 0이면 그 다음 블럭이 안 내려옴
        {
            X = 1, Y = 4;
            rotationIndex = 0;

            srand(time(NULL));

            RandB = rand() % 7;
            // 랜덤한 블럭 배치
            randb();

            canMove = 1;
            BlockClear();
        }

        PrintBackground(screen);
        
        PhysicsLogic(X, Y, screen);

        smoothgame(screen);

        if (_kbhit())
        {
            char ct = _getch(); //키 입력 변수
            ClearGhost(X, Y);

            if (ct == 32)
                HardDrop(&X, &Y, screen, ct);
            else if (ct == 0 || ct == -32)
                moveBlock2(&X, &Y, ct);
            else if (ct == 'z' || ct == 'Z')
                turnB(ct);
            
        }
                   
        if (loop == 200) //루프가 200이 되면 그 떄 밑으로 내림
        {
            loop = loop % 200;
            moveblock(&X, &Y); // 루프가 돌 떄 마다 밑으로 내리는 로직
            
        }           
        loop++;  //한 루프가 끝나면 1씩 더함

        //for (int i = 20; i >= 1; i--) //1부터 20까지
        //{
        for (int j = 1; j <= 10; j++) //1부터 10까지
        {
            if (Background[1][j] == 1 && Background[2][j] && Background[3][j]) // 만약 블럭이 1이라면
            {
                //indexB[i] = indexB[i] + 1; // 해당 열의 index에 수를 올림
                G_over(screen); //키 입력 변수
                if (_kbhit())
                {
                    char ct = _getch(); // r, R 버튼을 누르면 재시작하도록
                    if (ct == 114 || ct == 82)
                    {
                        Backgroundunit();
                    }

                }
            }
        }
        //}
        //for (int i = 20; i >= 1; i--) // 
           // if (indexB[i] >= 1)
                //countnum++;
        //if (countnum == 20)
        //{
            






        //}
        
    }
    return 0;
}




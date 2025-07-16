#include <iostream>
#include <vector>
#include <conio.h>
#include "Blockshape.h"
#include "Background.h"
#include "Dbuff.h"
#include "Ph_Lg.h"
#include "ghostClear.h"
using namespace std;

void HardDrop(int *X, int *Y, vector<wstring>& screen, int key)
{
	//ClearGhost(*X, *Y);
	int Fblock[4][4] = { 0 }; //바닥 블럭 체크
	int Wcheck[4] = { 0 }; //가로블럭의 바닥이 체크됐는지 확인
	int BIndex[4] = { 0 }; //블럭에서 얼마나 떨어져있는지 확인해서 제일 가깝게 있는 블록 바로 위에다가 쌓기
	

	//떨어지는 블럭의 바닥의 위치를 구하는 코드
	
		for (int i = 3; i >= 0; i--) // 블록의 각 행을 확인
			for (int j = 0; j <= 3; j++) // 블록의 각 열을 확인
				if (Blockshape[i][j] == 1) // 블록이 존재하는 위치
				{
					switch (j) {
					case 0:
						if (Wcheck[0] == 0) //0번째 블럭 중 바닥 블럭을 찾은 적이 없다면
						{
							Wcheck[0] = 1; //가로 0번째 블럭의 바닥을 찾음
							Fblock[i][0] = 1; //움직이는 블럭의 바닥 부분 만을 나타내는 블럭
							
						}
						if (Fblock[i][0] == 1)
						{
							for (int k = *X + i + 1; k <= 21; k++)
							{
								BIndex[0]++;
								if (Background[k][*Y] == 1) //떨어지는 바닥블럭과 쌓여있는 블럭 사이의 거리 구하기
									break;
							}
						}
						break;
					case 1:
						if (Wcheck[1] == 0)
						{
							Wcheck[1] = 1; //가로 1번째 블럭의 바닥을 찾음
							Fblock[i][1] = 1;
							
						}
						if (Fblock[i][1] == 1)
						{
							for (int k = *X + i + 1; k <= 21; k++)
							{
								BIndex[1]++;
								if (Background[k][*Y + 1] == 1) //떨어지는 바닥블럭과 쌓여있는 블럭 사이의 거리 구하기
									break;
							}
						}
						break;
					case 2:
						if (Wcheck[2] == 0)
						{
							Wcheck[2] = 1; //가로 2번째 블럭의 바닥을 찾음
							Fblock[i][2] = 1;
							
						}
						if (Fblock[i][2] == 1)
						{

							for (int k = *X + i + 1; k <= 21; k++)
							{
								BIndex[2]++;
								if (Background[k][*Y + 2] == 1) //떨어지는 바닥블럭과 쌓여있는 블럭 사이의 거리 구하기
									break;
							}
						}
						break;
					case 3:
						if (Wcheck[3] == 0)
						{
							Wcheck[3] = 1; //가로 3번째 블럭의 바닥을 찾음
							Fblock[i][3] = 1;
							
						}
						if (Fblock[i][3] == 1)
						{
							for (int k = *X + i + 1; k <= 21; k++)
							{
								BIndex[3]++;
								if (Background[k][*Y + 3] == 1) //떨어지는 바닥블럭과 쌓여있는 블럭 사이의 거리 구하기
									break;
							}
						}
						break;
					default :
						break;
					}
				}


		int index = 21;
		for (int i = 0; i <= 3; i++)
		{
			if (Wcheck[i] == 1 )
				if(BIndex[i] < index)
					index = BIndex[i];
		}

		if (index > 0)
			*X = *X + index - 1;
		else
			*X = *X;

		for (int i = 3; i >= 0; i--) // 블록의 행을 뒤에서부터 확인 (아래에서부터)
		{
			for (int j = 0; j < 4; j++) // 블록의 열을 확인
			{
				if (Blockshape[i][j] == 1)
				{
					Background[*X + i][*Y + j] = 1;  
				}
			}
		}
}
#include <iostream>
#include <conio.h>
#include "move2.h"
#include "turnblock.h"
#include "Blockshape.h"
#include "randb.h"
#include "ghostClear.h"

#define B_S 4

//�� ȸ����Ű�� �ڵ�
void turnB(char ch)
{
	int B_S_I_1[B_S][B_S] =
	{ {1,1,1,1} };// I�� ��
	int B_S_I_2[B_S][B_S] =
	{ {1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0} }; // I�� ��

	int B_S_T_1[B_S][B_S] =
	{ {0,1,0},{1,1,1} }; //T�� ��
	int B_S_T_2[B_S][B_S] =
	{ {1,0,0},{1,1,0},{1,0,0} }; //T�� ��
	int B_S_T_3[B_S][B_S] =
	{ {0,0,0},{1,1,1},{0,1,0} }; //T�� ��
	int B_S_T_4[B_S][B_S] =
	{ {0,1,0},{1,1,0},{0,1,0} }; //T�� ��

	int B_S_L_1[B_S][B_S] =
	{ {0,0,1},{1,1,1} }; // L�� ��
	int B_S_L_2[B_S][B_S] =
	{ {1,0,0},{1,0,0},{1,1,0} }; // L�� ��
	int B_S_L_3[B_S][B_S] =
	{ {0,0,0},{1,1,1},{1,0,0} }; // L�� ��
	int B_S_L_4[B_S][B_S] =
	{ {1,1,0},{0,1,0},{0,1,0} }; // L�� ��

	int B_S_J_1[B_S][B_S] =
	{ {1,0,0},{1,1,1} }; // J�� ��
	int B_S_J_2[B_S][B_S] =
	{ {1,1,0},{1,0,0},{1,0,0} }; // J�� ��
	int B_S_J_3[B_S][B_S] =
	{ {0,0,0},{1,1,1},{0,0,1} }; // J�� ��
	int B_S_J_4[B_S][B_S] =
	{ {0,1,0},{0,1,0},{1,1,0} }; // J�� ��

	int B_S_S_1[B_S][B_S] =
	{ {0,1,1},{1,1,0} }; // S�� ��
	int B_S_S_2[B_S][B_S] =
	{ {1,0,0},{1,1,0},{0,1,0} }; // S�� ��
	int B_S_S_3[B_S][B_S] =
	{ {0,0,0},{0,1,1},{1,1,0} }; // S�� ��
	int B_S_S_4[B_S][B_S] =
	{ {1,0,0},{1,1,0},{0,1,0} }; // S�� ��

	int B_S_Z_1[B_S][B_S] =
	{ {1,1,0},{0,1,1} }; // Z�� ��
	int B_S_Z_2[B_S][B_S] =
	{ {0,1,0},{1,1,0},{1,0,0} }; // Z�� ��
	int B_S_Z_3[B_S][B_S] =
	{ {0,0,0},{1,1,0},{0,1,1} }; // Z�� ��
	int B_S_Z_4[B_S][B_S] =
	{ {0,1,0},{1,1,0},{1,0,0} }; // Z�� ��
;

	/*if (_kbhit())
	{
		ch = _getch(); */

		//ClearGhost(X, Y);
		rotationIndex += 1;
		if (rotationIndex >= 4)
			rotationIndex = rotationIndex % 4;
		switch (RandB) {
		case 0: // I�� ��
			if (rotationIndex == 0 || rotationIndex == 2)
			{
				
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_I_1[i][j];
			}
			else if (rotationIndex == 1 || rotationIndex == 3)
			{
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_I_2[i][j];
			}
			//moveBlock2(&X, &Y, ch);
			break;
		case 1: //T�� ��
			if (rotationIndex == 0)
			{
				
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_T_1[i][j];

			}
			else if (rotationIndex == 1)
			{
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_T_2[i][j];
			}
			else if (rotationIndex == 2)
			{
				
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_T_3[i][j];
			}
			else if (rotationIndex == 3)
			{
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_T_4[i][j];
			}
			//moveBlock2(&X, &Y, ch);
			break;
		case 2: //L�� ��
			if (rotationIndex == 0)
			{
				
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_L_1[i][j];
			}
			else if (rotationIndex == 1)
			{
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_L_2[i][j];
			}
			else if (rotationIndex == 2)
			{
				
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_L_3[i][j];
			}
			else if (rotationIndex == 3)
			{
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_L_4[i][j];
			}
			//moveBlock2(&X, &Y, ch);
			break;
		case 3: // J�� ��

			if (rotationIndex == 0)
			{
				
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_J_1[i][j];
			}
			else if (rotationIndex == 1)
			{
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_J_2[i][j];
			}
			else if (rotationIndex == 2)
			{
				
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_J_3[i][j];
			}
			else if (rotationIndex == 3)
			{
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_J_4[i][j];
			}
			//moveBlock2(&X, &Y, ch);
			break;
		case 4: // S�� ��
			if (rotationIndex == 0)
			{
				
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_S_1[i][j];
			}
			else if (rotationIndex == 1)
			{
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_S_2[i][j];
			}
			else if (rotationIndex == 2)
			{
				
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_S_3[i][j];
			}
			else if (rotationIndex == 3)
			{
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_S_4[i][j];
			}
			//moveBlock2(&X, &Y, ch);
			break;
		case 5: // Z�� ��
			if (rotationIndex == 0)
			{
				
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_Z_1[i][j];
			}
			else if (rotationIndex == 1)
			{
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_Z_2[i][j];
			}
			else if (rotationIndex == 2)
			{
				
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_Z_3[i][j];
			}
			else if (rotationIndex == 3)
			{
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						Blockshape[i][j] = B_S_Z_4[i][j];
			}
			//moveBlock2(&X, &Y, ch);
			break;

		default:
			break;
		}


}
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
	int Fblock[4][4] = { 0 }; //�ٴ� �� üũ
	int Wcheck[4] = { 0 }; //���κ��� �ٴ��� üũ�ƴ��� Ȯ��
	int BIndex[4] = { 0 }; //������ �󸶳� �������ִ��� Ȯ���ؼ� ���� ������ �ִ� ��� �ٷ� �����ٰ� �ױ�
	

	//�������� ���� �ٴ��� ��ġ�� ���ϴ� �ڵ�
	
		for (int i = 3; i >= 0; i--) // ����� �� ���� Ȯ��
			for (int j = 0; j <= 3; j++) // ����� �� ���� Ȯ��
				if (Blockshape[i][j] == 1) // ����� �����ϴ� ��ġ
				{
					switch (j) {
					case 0:
						if (Wcheck[0] == 0) //0��° �� �� �ٴ� ���� ã�� ���� ���ٸ�
						{
							Wcheck[0] = 1; //���� 0��° ���� �ٴ��� ã��
							Fblock[i][0] = 1; //�����̴� ���� �ٴ� �κ� ���� ��Ÿ���� ��
							
						}
						if (Fblock[i][0] == 1)
						{
							for (int k = *X + i + 1; k <= 21; k++)
							{
								BIndex[0]++;
								if (Background[k][*Y] == 1) //�������� �ٴں��� �׿��ִ� �� ������ �Ÿ� ���ϱ�
									break;
							}
						}
						break;
					case 1:
						if (Wcheck[1] == 0)
						{
							Wcheck[1] = 1; //���� 1��° ���� �ٴ��� ã��
							Fblock[i][1] = 1;
							
						}
						if (Fblock[i][1] == 1)
						{
							for (int k = *X + i + 1; k <= 21; k++)
							{
								BIndex[1]++;
								if (Background[k][*Y + 1] == 1) //�������� �ٴں��� �׿��ִ� �� ������ �Ÿ� ���ϱ�
									break;
							}
						}
						break;
					case 2:
						if (Wcheck[2] == 0)
						{
							Wcheck[2] = 1; //���� 2��° ���� �ٴ��� ã��
							Fblock[i][2] = 1;
							
						}
						if (Fblock[i][2] == 1)
						{

							for (int k = *X + i + 1; k <= 21; k++)
							{
								BIndex[2]++;
								if (Background[k][*Y + 2] == 1) //�������� �ٴں��� �׿��ִ� �� ������ �Ÿ� ���ϱ�
									break;
							}
						}
						break;
					case 3:
						if (Wcheck[3] == 0)
						{
							Wcheck[3] = 1; //���� 3��° ���� �ٴ��� ã��
							Fblock[i][3] = 1;
							
						}
						if (Fblock[i][3] == 1)
						{
							for (int k = *X + i + 1; k <= 21; k++)
							{
								BIndex[3]++;
								if (Background[k][*Y + 3] == 1) //�������� �ٴں��� �׿��ִ� �� ������ �Ÿ� ���ϱ�
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

		for (int i = 3; i >= 0; i--) // ����� ���� �ڿ������� Ȯ�� (�Ʒ���������)
		{
			for (int j = 0; j < 4; j++) // ����� ���� Ȯ��
			{
				if (Blockshape[i][j] == 1)
				{
					Background[*X + i][*Y + j] = 1;  
				}
			}
		}
}
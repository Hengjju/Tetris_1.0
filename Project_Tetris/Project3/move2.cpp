#include <stdio.h>
#include <conio.h>
#include "move.h"
#include "Blockshape.h"
#include "Background.h"
#include "ghostClear.h"



void moveBlock2(int* X, int* Y, int ch) // ��, �� �̵�
{
    //ClearGhost(*X, *Y);
    int find = 0, floor = 0, Index = 0, ifloor;
    char ct = 0;
    for (int i = 3; i >= 0; i--) // ����� �� ���� Ȯ��
    {
        for (int j = 0; j < 4; j++) // ����� �� ���� Ȯ��
        {
            if (Blockshape[i][j] == 1) // ����� �����ϴ� ��ġ
            {
                if (find == 0 && Blockshape[i][j] == 1) //���� ã�� Ƚ���� 0�̰�, ���� i��° ��, j��° �࿡ ���� �ִٸ�
                    floor = i; //�� ���� �ִ°��� �ٴ��̴�                 
                if (j >= Index) {//���������� �󸶳� Ƣ����ֳ� Ȯ�� 
                    Index = j;  // �� ���� �࿡ �� ���� �ִ°�
                    ifloor = i; //�� ��° ���� �� ���� �ִ°�
                }
                find++;
            }
        }
    }
    /*if (_kbhit()) {
        ct = _getch();*/
 
    
        ct = _getch();
        switch (ct) {
        case 75: // �� ����
            if (Background[*X][*Y - 1] == 0) //���ʿ� ���� ���ٸ� �̵�����
                (*Y)--;
            break;
        case 77: // �� ������
            if (Background[*X + ifloor][*Y + Index + 1] == 0 || Background[*X][*Y + Index + 1] == 0) // �����ʿ� ���� ���ٸ� �̵�����
                (*Y)++;
            break;
        case 80: // �� �Ʒ�
            if (Background[*X + floor + 1][*Y] == 0 || Background[*X + floor + 2][*Y] == 0 || Background[*X + floor + 3][*Y] == 0) // �Ʒ��� ���� ���ٸ� �̵� ����
                (*X)++;
            break;
        default:
            break;
        }

        for (int i = 3; i >= 0; i--) // ����� ���� �ڿ������� Ȯ�� (�Ʒ���������)
        {
            for (int j = 0; j < 4; j++) // ����� ���� Ȯ��
            {
                if (Blockshape[i][j] == 1)
                {
                    Background[*X + i][*Y + j] = 1;  // ����� �� ĭ �Ʒ��� ����
                }
            }
        }
        //}
    
}



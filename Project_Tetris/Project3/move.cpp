#include <iostream>
#include <windows.h>
#include "Blockshape.h"
#include "Background.h"

int canMove = 1;

// ����� 1�ʸ��� �Ʒ��� ������ �Լ�
void moveblock(int* X, int* Y) // x�� �� �Ʒ�, y�¿�
{
    int find = 0, floor = 0, cant = 0, bump = 0, bfloor = 0; //find : �ؿ� ���� �ִ��� Ȯ���ϴ� ����, //
    canMove = 1; // �Լ��� ȣ��� ������ canMove�� �ʱ�ȭ

    // ���� ��ü ����� �˻��ؼ� ������ �� �ִ��� Ȯ��
    for (int i = 3; i >= 0; i--) // ����� �� ���� Ȯ��
    {
        for (int j = 0; j < 4; j++) // ����� �� ���� Ȯ��
        {
            if (Blockshape[i][j] == 1) // ����� �����ϴ� ��ġ
            { 
                if (find == 0 && Blockshape[i][j] == 1)
                    floor = i; //find�� 0�̸� �̹��� ã�� ���� ó���� ���� ��
                find++;
                // ���� �ٴڿ� �ִ� ���̰� �ؿ� ���� 0�� �ƴ϶�� 
                if (floor == i && Background[*X + i + 1][*Y + j] != 0)
                    cant++; //�ؿ� ������ �� �ִ��� ������ Ȯ��   
            }
        }
    }
    
    for (int i = 0; i <= 3; i++) // ����� �� ���� Ȯ��
    {
        bump = 0;
        bfloor = -1;
        for (int j = 3; j >= 0; j--) // ����� �� ���� Ȯ��
        {
            if (i == 0 && Blockshape[j][i] == 1) //���� 0��° ���� ���� ������ bump�� 1 ���� �� ���� ���� bfloor�� ���� 
            { 
                bump++;
                bfloor = j;
            }
            else if (i == 1 && Blockshape[j][i] == 1)//���� 1��° ���� ���� ������ bump�� 1 ���� �� ���� ���� bfloor�� ����
            {
                bump++;
                bfloor = j;
            }
            else if(i == 2 && Blockshape[j][i] == 1)//���� 2��° ���� ���� ������ bump�� 1 ���� �� ���� ���� bfloor�� ����
            {
                bump++;
                bfloor = j;
            }
            else if(i == 3 && Blockshape[j][i] == 1)//���� 3��° ���� ���� ������ bump�� 1 ���� �� ���� ���� bfloor�� ����
            {
                bump++;
                bfloor = j;
            }
        }
        if (bump == 1 && Background[*X + bfloor + bump][*Y + i] != 0) // �� ���� ���� �ϳ��� ������ �� ���� Ƣ��� ��
            cant++;
        else if (bump == 2 && Background[*X + bfloor + bump][*Y + i] != 0)
            cant++;
    }

    // ���� ����� ������ �� �ִٸ� 
    if (cant == 0)
    {
        // ����� �� ĭ �Ʒ��� �̵�
        for (int i = 3; i >= 0; i--) // ����� ���� �ڿ������� Ȯ�� (�Ʒ���������)
        {
            for (int j = 0; j < 4; j++) // ����� ���� Ȯ��
            {
                if (Blockshape[i][j] == 1)
                {
                    Background[*X + i + 1][*Y + j] = 1;  // ����� �� ĭ �Ʒ��� ����
                    Background[*X + i][*Y + j] = 0;      // ���� �ڸ��� ���
                }
            }
        }
        (*X)++; // Y���� �������� ����� ������
    }
    else if (cant >= 1) //���� cant ���� ���� 1���� ���ų� ũ�ٸ� ������ �� ����.
    {
        canMove = 0;
    }
    //Sleep(100);

}

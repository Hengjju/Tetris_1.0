#include <iostream>
#include "Background.h"

void BlockClear()//full ���� => full ������ 10�̵Ǹ� �� ĭ�� �� á�ٰ� �ν� �� ������ �ʱ�ȭ�ϰ� ���� ���� ��ĭ �� ������ �ڵ�
{
	int full[HEIGHT -2] = { 0 }; 
	int count = 0; //�� ���� ���� �� �ִ��� Ȯ���ϴ� ����
	int index = 0; //���° ���� �����ΰ�
	for (int i = HEIGHT - 2; i >= 1; i--) // �׵θ��� ���̹Ƿ� 1���� 20����
		for (int j = 1; j <= WIDTH-2; j++) //�׵θ��� ���̹Ƿ� 1���� 10����
			if (Background[i][j] == 1)
				full[i-1] = full[i-1]+ 1; //1~20 ���� ����, full[1] ~ fill[20]���� (1�� ���� 21������)

	for (int i = 1; i <= HEIGHT-2 ; i++) // 20���� 1���� ���鼭
		if (full[i - 1] == 10)
		{//���� ���� �ִ��� Ȯ��, ���� �� ���� �ִٸ� count 1�� �߰�, �׶��� �ε����� index ������ �Է�
			count++;
			index = i;
		}

	if(count >= 1) //���� count�� 1���� ũ�ٸ� index���� ���� count�� +1�� �� ��ŭ �ݺ�
		for (int i = index; i >= count+1; i--)
			for(int j = 1; j <= WIDTH-2; j++)
				Background[i][j] = Background[i-count][j]; //count ����ŭ ������ ���̱� ������ count�� ��ŭ ������ ������� ��
		
		

	for (int i = 1; i <= count; i++)
		for (int j = 1; j < WIDTH - 1; j++) //��ĭ�� ������ �� ���� ���� 0���� ä���
			Background[i][j] = 0;

	count = 0;
}
int canMove = 1;

// ����� 1�ʸ��� �Ʒ��� ������ �Լ�
void moveblock(int* X, int* Y) // x�� �� �Ʒ�, y�¿�
{

    // �Ʒ��� ������ �� �ִ��� Ȯ��, �� �ٷ� �ؿ� ������ ��ֹ��� �ִ��� ������ Ȯ��
    for (int i = 3; i >= 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            if (Blockshape[i][j] == 1)
            {
                if(Background[*X + i + 1][*Y + j] == 0)
                {
                    Background[*X + i + 1][*Y + j] = 1; //�� �� ĭ ������
                    Background[*X + i][*Y + j] = 0; //���� �� ���� �Ųٱ�
                    canMove = 1;
                }
                else if (Background[*X + i + 1][*Y + j] == 1 || Background[*X + i + 1][*Y + j] == 2)
                { // �� �ٷ� ���� ���� �ִٸ� ������ �ֱ�
                    canMove = 0;
                    break;
                }
            }
            if (!canMove) break;
        }
    }
    if (canMove)
    {
        (*X)++; // Y���� �������� ����� ������
    }
    // ������ �� ������ ������
}
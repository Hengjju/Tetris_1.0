int canMove = 1;

// 블록을 1초마다 아래로 내리는 함수
void moveblock(int* X, int* Y) // x는 위 아래, y좌우
{

    // 아래로 내려갈 수 있는지 확인, 블럭 바로 밑에 구간에 장애물이 있는지 없는지 확인
    for (int i = 3; i >= 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            if (Blockshape[i][j] == 1)
            {
                if(Background[*X + i + 1][*Y + j] == 0)
                {
                    Background[*X + i + 1][*Y + j] = 1; //블럭 한 칸 내리기
                    Background[*X + i][*Y + j] = 0; //내린 후 위에 매꾸기
                    canMove = 1;
                }
                else if (Background[*X + i + 1][*Y + j] == 1 || Background[*X + i + 1][*Y + j] == 2)
                { // 블럭 바로 밑이 블럭이 있다면 가만히 있기
                    canMove = 0;
                    break;
                }
            }
            if (!canMove) break;
        }
    }
    if (canMove)
    {
        (*X)++; // Y값을 증가시켜 블록을 내리기
    }
    // 내려갈 수 있으면 내리기
}
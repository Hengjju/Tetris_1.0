#include <iostream>
#include "Background.h"

void BlockClear()//full 변수 => full 변수가 10이되면 그 칸이 다 찼다고 인식 그 블럭들을 초기화하고 위의 블럭을 한칸 씩 내리는 코드
{
	int full[HEIGHT -2] = { 0 }; 
	int count = 0; //몇 개가 가득 차 있는지 확인하는 변수
	int index = 0; //몇번째 부터 시작인가
	for (int i = HEIGHT - 2; i >= 1; i--) // 테두리는 벽이므로 1부터 20까지
		for (int j = 1; j <= WIDTH-2; j++) //테두리는 벽이므로 1부터 10까지
			if (Background[i][j] == 1)
				full[i-1] = full[i-1]+ 1; //1~20 까지 갯수, full[1] ~ fill[20]까지 (1층 부터 21층까지)

	for (int i = 1; i <= HEIGHT-2 ; i++) // 20부터 1까지 돌면서
		if (full[i - 1] == 10)
		{//꽉찬 것이 있는지 확인, 만약 꽉 찬게 있다면 count 1씩 추가, 그때의 인덱스를 index 변수에 입력
			count++;
			index = i;
		}

	if(count >= 1) //만약 count가 1보다 크다면 index에서 부터 count에 +1한 값 만큼 반복
		for (int i = index; i >= count+1; i--)
			for(int j = 1; j <= WIDTH-2; j++)
				Background[i][j] = Background[i-count][j]; //count 수만큼 없어질 것이기 때문에 count수 만큼 밑으로 내려줘야 함
		
		

	for (int i = 1; i <= count; i++)
		for (int j = 1; j < WIDTH - 1; j++) //한칸씩 내린뒤 맨 위의 공간 0으로 채우기
			Background[i][j] = 0;

	count = 0;
}
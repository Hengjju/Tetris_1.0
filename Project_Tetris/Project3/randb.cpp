#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Blockshape.h"
#include "randb.h"

void randb()
{
	if (RandB == 0) //I블럭 
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Blockshape[i][j] = B_S_I[i][j];
			}
		}
	}
	else if (RandB == 1) //T블럭
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Blockshape[i][j] = B_S_T[i][j];
			}
		}
	}
	else if (RandB == 2) //L블럭
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Blockshape[i][j] = B_S_L[i][j];
			}
		}
	}
	else if (RandB == 3)//J블럭
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Blockshape[i][j] = B_S_J[i][j];
			}
		}
	}
	else if (RandB == 4)//S블럭
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Blockshape[i][j] = B_S_S[i][j];
			}
		}
	}
	else if (RandB == 5)//Z블럭
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Blockshape[i][j] = B_S_Z[i][j];
			}
		}
	}
	else if (RandB == 6)//O블럭
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Blockshape[i][j] = B_S_O[i][j];
			}
		}
	}
	
}
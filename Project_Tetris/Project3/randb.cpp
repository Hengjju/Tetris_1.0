#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Blockshape.h"
#include "randb.h"

void randb()
{
	if (RandB == 0) //I�� 
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Blockshape[i][j] = B_S_I[i][j];
			}
		}
	}
	else if (RandB == 1) //T��
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Blockshape[i][j] = B_S_T[i][j];
			}
		}
	}
	else if (RandB == 2) //L��
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Blockshape[i][j] = B_S_L[i][j];
			}
		}
	}
	else if (RandB == 3)//J��
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Blockshape[i][j] = B_S_J[i][j];
			}
		}
	}
	else if (RandB == 4)//S��
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Blockshape[i][j] = B_S_S[i][j];
			}
		}
	}
	else if (RandB == 5)//Z��
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Blockshape[i][j] = B_S_Z[i][j];
			}
		}
	}
	else if (RandB == 6)//O��
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
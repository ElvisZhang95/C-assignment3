/*
   80429 Accepted to 1046.c
   Name: Shuhao Zhang  Id:201138949 x5sz2
*/
#include <stdio.h>
#include <stdlib.h>
//method for computing the largest sum of m adjacent numbers
int result_largest(int **matrix, int n, int m);

int main()
{
	//construct a matrix for storing the integer in grid
	int **matrix;
	//n is the size of matrix, m is the number of adjacent numbers
	//result is the answer(largest sum of m adjacent numbers)	
	int n,m,result;
	//used in for loop
	int i,j,k;
	//input the n and m
	scanf("%d %d", &n, &m);
	//allocate the memory for the matrix
	matrix = (int **)malloc(n*sizeof(int*));
	for(k=0;k<n;k++)
	{
		matrix[k]=(int *)malloc(n*sizeof(int));
	}
	//input the integers to the matrix
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	//get the result by method "result_largest"
	result=result_largest(matrix, n,m);
	//print outp
	printf("%d", result);
	
	//release the memory
	for(k=0;k<n;k++){
		free(matrix[k]);
	}
	free(matrix);
	return 0;
}

int result_largest(int **matrix, int n, int m)
{	
	//the sum of m adjacent numbers in different direction
	int sumrow=0;
	int sumcol=0;
	int sumdia1=0;
	int sumdia2=0;
	//maximum of the sum
	int max=0;
	//used in for loop
	int i,j,k;
	int **p = matrix;
	//move the start pointer by row
	for(i=0;i<n;i++)
	{
		//move the start pointer by column
		for(j=0;j<n;j++)
		{
			//move to the next adjacent number
			for(k=0;k<m;k++)
			{
				//avoid the pointer move outside the matrix
				if(j+k<n){
					//compute the sum of numbers in row
					sumrow=sumrow+p[i][j+k];
					//compute the sum of numbers in column
					sumcol=sumcol+p[j+k][i];
						if(i+k<n){
							//compute the sum of numbers from left top to right down
							sumdia1=sumdia1+p[i+k][j+k];
						}
						if(i-k>=0){
							//compute the sum of numbers from right top to left down
							sumdia2=sumdia2+p[i-k][j+k];
						}
				}
			//get the maximum
			if(sumrow>=max)
			{
				max = sumrow;
			}	
			if(sumcol>=max)
			{
				max = sumcol;
			}	
			if(sumdia1>=max)
			{
				max = sumdia1;
			}	
			if(sumdia2>=max)
			{
				max = sumdia2;
			}	
			}	
			//reset the value for next turn
			sumrow=0;
			sumcol=0;
			sumdia1=0;
			sumdia2=0;
		}
	}
	return max;
}

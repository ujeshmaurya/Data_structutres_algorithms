/*
WEEK 1:
Problem 6: Write a program to find out the transpose of a matrix.
Description: The Programs aims at finding the transpose of a matrix. It is useful in finding out the inverse of any matrix. It takes a matrix of size n*m as an input and prints its transpose as output.
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>

int main()
{
	int a[100][100],m,n,i,j,b[100][100];
	printf("Enter the size of the matrix(m*n)\n");
	scanf("%d %d",&m,&n);   //input size of matrix
	printf("Enter the matrix:\n");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);   //input matrix
			b[j][i]=a[i][j];
		}
	printf("You have entered\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);  //move its values
		}
		printf("\n");
	}
	printf("Transpose of the matrix is:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d ",b[i][j]);  //print the transpose
		}
		printf("\n");
	}
}

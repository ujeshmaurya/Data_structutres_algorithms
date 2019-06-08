/*
WEEK 1:
Problem 3: Write a program to calculate addition and multiplication of two matrices whose size and elements to be entered by user at runtime.
Description: The Programs aims at addition and multiplication of two matrices. It finds application in solving linear equations of n variables and n equations and various other purposes also. It takes two matrices ‘A’ and ‘B’ of size n*m and p*q respectively as input and prints the sum and multiplication of A and B matrix, if possible.
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>
int main()
{
 	int n,m,i,j,k,p,q,a[100][100],b[100][100],c[100][100],d[100][100],flags=1,flagm=1;
	printf("Enter dimensions of matrix 1\n");
		scanf("%d %d",&n,&m);   //input n,m
	printf("Enter elements of matrix 1\n");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);   //input A matrix
	printf("Enter dimensions of matrix 2\n");
		scanf("%d %d",&p,&q);   //input p,q
	printf("Enter elements of matrix 2\n");
	for(i=0;i<p;i++)
		for(j=0;j<q;j++)
			scanf("%d",&b[i][j]);   //input B matrix


	printf("1st Matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)        //print A matrix
			printf("%d  ",a[i][j]);
		printf("\n");
	}
	printf("2nd Matrix\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)        //print B matrix
			printf("%d  ",b[i][j]);
		printf("\n");
	}
	if((n!=p)&&(m!=q))
	{
		flags=0;        //condition for addition
		printf("Addition cant be done\n");
	}
	if(flags==1)
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			c[i][j]=a[i][j]+b[i][j];    //perform addition
	for(i=0;i<n;i++)
		for(j=0;j<q;j++)
			d[i][j]=0;
	if(m!=p)        //condition for multiplication
	{
		flagm=0;
		printf("Multiplication cant be done\n");
	}
if(flagm==1)
	for(i=0;i<n;i++)
		for(j=0;j<q;j++)
		{
			for(k=0;k<m;k++)    //perform multiplication
			{
				d[i][j]+=a[i][k]*b[k][j];
			}
		}
	if(flags==1)
	printf("SUM OF MATRIX :\n");
	if(flags==1)
	for(i=0;i<n;i++)    //print A+B matrix
	{
		for(j=0;j<m;j++)
			printf("%d  ",c[i][j]);
		printf("\n");
	}
	if(flagm==1)
	printf("PRODUCT OF MATRIX :\n");
	if(flagm==1)
	for(i=0;i<n;i++)
	{
		for(j=0;j<q;j++)    //print A*B matrix
			printf("%d  ",d[i][j]);
		printf("\n");
	}


}

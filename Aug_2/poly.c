/*
WEEK 1:
Problem 4: Write a program to add two polynomials whose degrees and coefficients are to be entered by user at runtime.
Description: The Programs aims at addition of two polynomial expression. It is useful in Algebraic Mathematics. It takes two polynomials of degree ‘m’ and ‘n’ as input and prints their sum as output.
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>

int main()
{
	int a[100],n,m,b[100],i,j;
	for(i=0;i<100;i++)
	{
		a[i]=0;
		b[i]=0;
	}
	printf("Enter the degree of polynomial 1\n");
	scanf("%d",&n);
	printf("Enter the polynomial 1\n");
	for(i=n;i>=0;i--)
	{
		printf("Enter the coefficient of x^%d : ",i);
		scanf("%d",&a[i]);      //input polynomial 1 of degree 'n'
	}
	printf("Enter the degree of polynomial 2\n");
	scanf("%d",&m);
	printf("Enter the polynomial 2\n");
	for(i=m;i>=0;i--)
	{
		printf("Enter the coefficient of x^%d : ",i);
		scanf("%d",&b[i]);      //input polynomial 1 of degree 'm'
	}
	for(i=(m>n)?m:n;i>=0;i--)   //print the sum
		printf("%dx^%d+ ",a[i]+b[i],i);
	printf("\n");


}


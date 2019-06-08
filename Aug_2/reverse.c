/*
WEEK 1:
Problem 5:  Write a program to reverse all the elements of an array.
Description: The Programs aims at reversing all the elements of an array. It is useful in reversing a string and finding palindromic strings. It takes an array of size ‘n’ as input and prints the array in reverse order.
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>

int main()
{
	int a[1000],n,i,j;
	printf("Enter the size of the array\n");
	scanf("%d",&n);     //input size of array
	printf("Enter the array\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);      //input array
	printf("You have entered\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	for(i=0;i<(n+1)/2;i++)  //reversing the array
	{
		j=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=j;
	}
	printf("Reversed Array:\n");
	for(i=0;i<n;i++)    //print reversed array
		printf("%d ",a[i]);
	printf("\n");
}

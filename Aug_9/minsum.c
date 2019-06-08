/*
WEEK 2:
Problem 7: Write a program to find out the minimum sum up to 2 digit numbers from the elements of array, and also tell the count of numbers.
Description: The Programs aims at finding the minimum sum upto 2 digit from the elements of an array, we take an array as an input and print the desired count value and the elements used as output.
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>

int main()
{
	int a[1000],n,i,sum=0,count=0;
	printf("Enter the size of array: \n");
	scanf("%d",&n); //input size of array
	printf("Enter the %d elements of array: \n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);  //input the array
	for(i=0;i<n;i++)
	{
		if(sum+a[i]<100)    //check if sum is less than 100
		{
			sum+=a[i];
			count++;
		}
	}                           //print sum and count
	printf("sum= %d, using no. of elements= %d\n",sum,count);
}

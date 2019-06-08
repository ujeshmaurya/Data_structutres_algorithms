/*
WEEK 2:
Problem 5:  Write a program to find all triplets in a sorted array that forms Geometric Progression(GP).
Description: The Programs aims at  finding all the triplets which are in GP from a sorted array. It takes an array of size ‘n’ as an input and prints the count and the triplets which are there in the array.
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>
#include<math.h>

int main()
{
	int a[1000],n,i,j,k,count=0;
	printf("Enter the size of array: \n");
	scanf("%d",&n);     //input array
	printf("Enter the %d elements of array: \n",n);
	for(i=0;i<n;i++)    //show existing array
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(a[i]*a[k]==a[j]*a[j]) //condition for geometric mean
				{
					count++;
					printf("%d , %d, %d\n",a[i],a[j],a[k]); //printing those triplets
				}
			}
		}
	}
	printf("No. of triplets= %d\n",count);  //print total count of triplets
}

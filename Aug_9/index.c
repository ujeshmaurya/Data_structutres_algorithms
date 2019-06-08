/*
WEEK 2:
Problem 2: An array is having the element of size n, another array is also of size n having the index of
the element. Now rearrange the order of first array as per the index.
Eg: A[] ={2,3,4}
1. index[ ] ={0,1,2}
A[] = [3, 2, 4];
index[] = [1, 0, 2];
Description: The Programs aims at rearranging a given array according to a given list of index. It takes an array of size ‘n’ and an array of indices of size ‘n’ as an input and it outputs the rearranged array.
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,*a,*b,*c;
	printf("Enter the size of array: \n");
	scanf("%d",&n);     //size of array input
	a=(int*)malloc(n*sizeof(int));
	b=(int*)malloc(n*sizeof(int));
	c=(int*)malloc(n*sizeof(int));
	printf("Enter the %d elements: \n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);  //array input
    printf("Enter the index no.: \n");
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);  //index input
    for(i=0;i<n;i++)
        c[i]=a[b[i]];       //rearranging array 'a' into 'c'
    for(i=0;i<n;i++)
        a[i]=c[i];
    printf("\nNew Arranged array: \n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);     //modified array 'a'
    printf("\n");
}

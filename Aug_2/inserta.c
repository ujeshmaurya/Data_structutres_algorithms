/*
WEEK-1
Problem 2: Write a program to insert an element in an array to be entered by user. Insertion position to be taken at runtime.
Description: The Programs aims at insertion of a new element in an existing array. It proves to be useful in dynamically modifying an array or a string without really allocating a full new array. It takes an array of size ‘n’, an element ‘m’ and an index ‘i’ where ‘m’ is to be inserted, and prints the modified array with ‘m’ inserted at ‘i’ position.Compiled By: UJESH MAURYA (2015UCP1338)
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>

int main()
{
	int a[1000],n,i,j,temp,p;
	printf("Enter the size of array\n");
	scanf("%d",&n);     //input size of array
	printf("Enter the array\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);  //array elements input
	printf("You have entered\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);     //print original array
	printf("\nEnter the element to be inserted:\n");
	scanf("%d",&p);     //input new element
	printf("Enter the position\n");
	scanf("%d",&j);     //input the position
	for(i=n-1;i>=j-1;i--)
		a[i+1]=a[i];    //shifting array
	a[j-1]=p;           //assigning new element
	printf("After insertion the array is:\n");
	for(i=0;i<n+1;i++)  //print modified array
		printf("%d ",a[i]);
}

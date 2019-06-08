/*
WEEK-1
Problem 1: Write a program to delete an element from an array, to be entered by user. Deletion position to be taken on runtime.

Description: The Programs aims at deletion of a particular element of a 0-based indexed array. It is useful in removing duplicate elements from an array. It takes an array of size ‘n’ and an index ‘i’ to be deleted, and prints the modified array with array[i] deleted.
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>

int main()
{
	int a[1000],n,i,j,temp,p;
	printf("Enter the size of array\n");
	scanf("%d",&n); //Array size input
	printf("Enter the array\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);  //Array input
	printf("You have entered\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);     //Array before deletion
	printf("\nEnter position from where element is to be deleted:\n");
	scanf("%d",&j);     //deletion position input
	for(i=j-1;i<n-1;i++)    //shifting the elements
		a[i]=a[i+1];
	printf("After insertion the array is:\n");
	for(i=0;i<n-1;i++)      //print modified array
		printf("%d ",a[i]);
}

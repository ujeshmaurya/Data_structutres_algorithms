/*
Mid Term Evaluation Problem:
Problem Statement:  Given an array of size ‘n’ and an integer ‘k’, first divide the array into two halves and then print both the subarrays after reversing the first ‘k’ values of each subarray. One should not use extra array to do this task.
Compiled by: UJESH MAURYA(2015UCP1338)
*/
#include<stdio.h>

int main()
{
	FILE *fp;
	int n,i,a[1000],k,mid,temp;
	fp=fopen("input.txt","r");
	printf("Enter size of array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		fscanf(fp,"%d",&a[i]);
	printf("Given array:\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	lab:
	printf("Enter value of k: ");
	scanf("%d",&k);
	if(n%2==0)
		mid=n/2;
	else
		mid=(n+1)/2;
	if(k>mid && n%2==0)
	{
		printf("ERROR!!! Value of k cant exceed %d in this case\nAgain Enter value of k\n",mid);
		goto lab;
	}
	if(k>mid-1 && n%2==1)
	{
		printf("ERROR!!! Value of k cant exceed %d in this case\nAgain Enter value of k\n",mid);
		goto lab;
	}
	for(i=0;i<k/2;i++)
	{
		temp=a[i];
		a[i]=a[k-i-1];
		a[k-i-1]=temp;
	}
	for(i=0;i<0+k/2;i++)
	{
		temp=a[mid+i];
		a[mid+i]=a[mid+k-i-1];
		a[mid+k-i-1]=temp;
	}
	printf("First Subarray:\n");
	for(i=0;i<mid;i++)
		printf("%d ",a[i]);
	printf("\nSecond Subarray:\n");
	for(i=mid;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	fclose(fp);

}

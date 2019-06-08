/*
WEEK 2:
Problem 3: Find out the intersection and union of two arrays.
Eg: arr1[]={7,1,5,2,3,6}
arr2[] = {3, 8, 6, 20, 7}
intersection: {3,6}
Description: The Programs aims at  finding intersection and union of two arrays. It may prove helpful in finding the duplicate elements in combination of two arrays. It takes two arrays of size ‘m’ and ‘n’ as input and prints their union and intersection.
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,m,i,j,k,l,*a,*b,*in,*un,uncount=0,incount=0;
	printf("Enter the size of array 1: \n");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("Enter the %d elements: \n",n);
	for(i=0;i<n;i++)        //input array 1
		scanf("%d",&a[i]);
	printf("Enter the size of array 2: \n");
	scanf("%d",&m);
	b=(int*)malloc(m*sizeof(int));
	printf("Enter the %d elements: \n",m);
	for(i=0;i<m;i++)        //input array 2
		scanf("%d",&b[i]);
	un=(int*)malloc((n+m)*sizeof(int));
	for(i=0;i<n+m;i++) //merging 2 arrays
	{
		if(i<n)
			un[i]=a[i];
		else
			un[i]=b[i-n];
	}
	for(i=0;i<n+m-uncount;i++)  //removing duplicacy from union
	{
		for(j=i+1;j<n+m-uncount;j++)
		{
			if(un[i]==un[j])
			{
				for(k=j;k<n+m-1;k++)
				{
					un[k]=un[k+1];
				}
				uncount++;
				j--;
			}
		}
	}
	printf("Union:\n{ ");
	for(i=0;i<n+m-uncount;i++)  //printing union
		printf("%d, ",un[i]);
	printf("}\n");
	k=0;
	in=(int*)malloc((n+m)*sizeof(int));
	for(i=0;i<n;i++)    //finding common elements in both
	{
		for(j=0;j<m;j++)
		{
			if(a[i]==b[j])
			{
				in[k++]=a[i];
				break;
			}
		}
	}
	for(i=0;i<k-incount;i++)        //removing duplicacy
	{
		for(j=i+1;j<k-incount;j++)
		{
			if(in[i]==in[j])
			{
				for(l=j;l<k-1;l++)
				{
					in[l]=in[l+1];
				}
				incount++;
				j--;
			}
		}
	}
	printf("Intersection:\n{ ");     //printing intersection
	for(i=0;i<k-incount;i++)
		printf("%d, ",in[i]);
	printf("}\n");
}

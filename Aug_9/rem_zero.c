/*
WEEK 2:
Problem 4: An array of random number is given. Now find out all the 0's and put them in the last of the
array.
1. Arr1[]={7,1,0,2,0,6,7,5,0,3,0}
Arr1[]={7,1,2,6,7,5,3,0,0,0,0}
Description: The Programs aims at  finding  all the 0 elements and putting them at the end of the array. This may prove helpful when we need to deal with 0 at last and give priority to the non zero elements. It takes an array of size ‘n’ as input and print the modified array with all the zeros at the last as output.
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,j,k,*a,uncount=0;
	printf("Enter the size of array: \n");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("Enter the %d elements: \n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);  //input array
	for(j=0;j<n-uncount;j++)
	{
		if(a[j]==0)
		{
			for(k=j;k<n-1;k++)
			{
				a[k]=a[k+1];    //delete zero from in between
			}
			a[n-uncount-1]=0;   //place zero at last
			uncount++;
			j--;
		}
	}
	printf("Modified Array: \n");
	for(i=0;i<n;i++)    //print modified array
		printf("%d ",a[i]);
	printf("\n");
}

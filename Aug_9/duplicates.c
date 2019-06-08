/*
Week 2:
Problem 1: WAP to create an array having n elements. Now create another array which is having n-i
elements similar to the first array. Now find out the duplicates in the array.
Description: The Programs aims at finding duplicate elements in an array and removing them. It takes an array of size ‘n’ as input and prints the modified array as output.
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,j,*a,b[1000];
	printf("Enter the size of array: \n");
	scanf("%d",&n);     //input size of array
	a=(int*)malloc(n*sizeof(int));  //allocate size
	printf("Enter the %d elements: \n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);  //input array
    for(i=0;i<n;i++)        //processing a[i]
    {
        for(j=i+1;j<n;j++)
            b[j]=a[j];      //find duplicate of a[i]
        for(j=i+1;j<n;j++)
            if(a[i]==b[j])
            {
                if(a[j]==-32743)
                    continue;
                printf("Duplicate of %d found at %d index\n",a[i],j);
                a[j]=-32743;
            }
    }
}

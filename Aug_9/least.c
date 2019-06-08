/*
WEEK 2:
Problem 8: Write a program to replace every element with the least greater element on its right. Any number will not be repeated.
Description: The Programs aims at replacing every element with the least greater element on its right indices. We take an array as an input and output the modified array with each element replaced with its least greater element on its right.
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>
#include<math.h>
int small2(int b[],int j,int n)
{                   //function to find least greater on right indexes
	int i,temp,k=j;
	for(i=j;i<n;i++)
		for( ;j<n;j++)
		{
			if(b[j]>b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	return b[k];
}


int main()
{
	int a[1000],b[1000],n,i,j,k,count=0,c[1000],p,temp,flag;
	printf("Enter the size of array: \n");
	scanf("%d",&n);
	printf("Enter the %d elements of array: \n",n);
	for(i=0;i<n;i++)    //input array
	{
		scanf("%d",&a[i]);
		c[i]=0;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
			b[j-(i+1)]=a[j];
        if(i==n-2)
            goto lab;
		for(p=0;p<n-i-1;p++)
            for(j=0 ;j<n-p-1;j++)
            {
                if(b[j]>b[j+1])
                {
                    temp=b[j];
                    b[j]=b[j+1];
                    b[j+1]=temp;
                }
            }
        flag=0;
        lab:
        for(j=0;j<n-i-1;j++)
            if(a[i]<b[j])
            {
                flag=1;
                printf("%d ",b[j]);
                c[i]=1;
                break;
            }
        if(flag==0)
        {
            printf("%d ",a[i]);
            c[i]=1;
        }
	}
	for(i=0;i<n;i++)
	{
		if(c[i]==0)
			printf("%d ",a[i]);
	}
	printf("\n");
}

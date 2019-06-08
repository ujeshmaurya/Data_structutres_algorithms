/*
WEEK 2:
Problem 6:   Find the 2nd minimum distance between the 2 elements of array.
Description: The Programs aims at  finding the 2nd minimum distance between 2 elements of array. It takes an array as an input and print the 2nd minimum distance of every element as output.
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>
#include<math.h>

int main()
{
	int a[1000],b[1000],n,i,j,k,p;
	printf("Enter the size of array: \n");
	scanf("%d",&n);
	printf("Enter the %d elements of array: \n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);  //array input
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			b[j-(i+1)]=fabs(a[i]-a[j]);
		}
		for(p=0;p<n-(i+1);p++)
        {
            for(j=0;j<n-(i+1)-p-1;j++)
                if(b[j]>b[j+1])
                {
                    b[j]=b[j]+b[j+1];
                    b[j+1]=b[j]-b[j+1];
                    b[j]=b[j]-b[j+1];
                }
        }
        for(p=0;p<n-(i+1);p++)
        {
            if(b[p]==b[p+1])
                continue;
            else
                break;
        }
        k=b[p+1];
        if(i==n-2)
            k=b[p];
		printf("%d--> %d\n",a[i],k); //2nd min distance of each element
	}
}

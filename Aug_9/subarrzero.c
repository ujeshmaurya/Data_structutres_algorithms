/*
WEEK 2:
Problem 9: Write a program to print all subarrays with zero sum.
Description: The Programs aims at printing all the subarrays of an array whose sum is 0. It is helpful in finding the powerset of a given set of ‘n’ elements whose sum is 0. It takes an array as an input and prints all the subarrays of it in a new line.
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>
#include<string.h>
char sa[5000][100];
int sai=0;
void print()    //print final value of subarrays after removing duplicacy
{
    int i,j,k,p,q,flag;
    for(i=0;i<sai;i++)
    {
        for(j=i+1;j<sai;j++)
            if(strcmp(sa[i],sa[j])==0)
        {
            sa[j][0]='\0';
        }
    }
    for(i=0;i<sai;i++)
    {
        flag=0;
            for(j=0;sa[i][j]!='\0';j++)
        {
            if(sa[i][j]=='\0')
                break;
            printf("%d ",(int)sa[i][j]-54);
            flag=1;
        }
        if(flag==1)
            printf("\n");
    }

}
void store(int a[],int n)   //store the subarrays whose sum is 0
{
   int i;
   for(i=0;i<n;i++)
        sa[sai][i]=(char)(a[i]+54);
    sa[sai][i]='\0';
   sai++;

}
int repeat(int a[],int n)   //recursive function to find subarrays
{
    /*if((n==1)&&(a[0]==0))
    {
        store(a,n);
        return 0;
    }*/
    if(n==1)
        return 0;
    int i,k,j=0,b[100],sum=0;
    for(j=0;j<n;j++)
    {
        k=0;
        for(i=0;i<n;i++)
        {
            if(i!=j)
                b[k++]=a[i];
        }
        repeat(b,n-1);  //recursive call
    }
    for(i=0;i<n-1;i++)
        sum+=b[i];
    if(sum==0)
    {
        store(b,n-1);
        return 0;
    }
}

int main()
{
	int a[1000],n,i,sum=0,j;
	printf("Enter the size of array: \n");
	scanf("%d",&n);
	printf("Enter the %d elements of array: \n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);  //array input
    for(i=0;i<5000;i++)
        for(j=0;j<100;j++)
            sa[i][j]=3247;
	repeat(a,n);
	if(sai!=0)
        print();    //print subarrays
	else
        printf("Not possible\n");   //if no subarray is possible

}

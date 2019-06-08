/*
WEEK 2:
Problem 10: Take the array which could be divided into two subarrays of equal sum.
Description: The Programs aims at dividing an array into two subarrays whose sum is equal. It may be helpful in dividing a fair-team-selection out of ‘n’ students whose marks are given, so that each team gets equal amount of talented students. It takes an array as input and prints the two subarrays of equal sum as output if it exists.
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>
#include<stdlib.h>

void print(int b[],int c[],int j,int k,int elb,int elc)
{       //function to print
    int i;
    printf("%d ",elc);
    for(i=0;i<j;i++)
    {
        if(b[i]==elb)
            continue;
        printf("%d ",b[i]);

    }
    printf("\nAND\n");
    printf("%d ",elb);
    for(i=0;i<k;i++)
    {
        if(c[i]==elc)
            continue;
        printf("%d ",c[i]);
    }
}

int main()
{
    int a[1000],b[500],c[500],p,i,j=0,k=0,n,sum1=0,sum2=0,diff,count=0,sh,temp;
    time_t t;
    printf("Enter the size of array: \n");
    scanf("%d",&n);
    printf("Enter the %d elements: \n",n);
    for(i=0;i<n;i++)    //array input
    {
        scanf("%d",&a[i]);
        if(sum1>=sum2)
        {
            c[k++]=a[i];
            sum2+=a[i];
        }
        else
        {
            b[j++]=a[i];
            sum1+=a[i];
        }
    }
    diff=sum2-sum1; //diff of 2 subarrays
    if(diff==0) //if diff becomes 0
    {
        for(i=0;i<j;i++)
            printf("%d ",b[i]);
        printf("\nAND\n");
        for(i=0;i<k;i++)
            printf("%d ",c[i]);
    }
    else if(diff%2==0)  //if diff is even
    {
        lab:
        for(i=0;i<j;i++)
        {
            for(p=0;p<k;p++)
            {
                if(c[p]-b[i]==diff/2)
                {
                    print(b,c,j,k,b[i],c[p]);
                    return 0;
                }

            }
        }
        count++;
        if(count>30000)
            return 0;
        if(count<15000)     //rearranging the array randomly
        {
            srand((unsigned) time(&t));
            sh=rand()%j;    //random function
            temp=b[sh];
            b[sh]=b[j-sh];
            b[j-sh]=temp;
        }
        else if(count>=15000)
        {
            srand((unsigned) time(&t));
            sh=rand()%k;        //random function
            temp=c[sh];
            c[sh]=c[k-sh];
            c[k-sh]=temp;
        }
        goto lab;
    }
}

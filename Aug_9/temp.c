#include<stdio.h>
#include<stdlib.h>
int lim=0;
int repeat(int a[],int  b[],int n,int sum)
{
    int c[100],currsum=0,l,flag;
    if(n==1)
        return 0;
    int i,j,k;
    for(i=0;i<n;i++)
    {
        k=0;
        for(j=0;j<n;j++)
        {
            if(i!=j)
                c[k++]=a[i];


        }
        repeat(c,b,n-1,sum);
    }
    for(i=0;i<n;i++)
        currsum+=c[i];
    if(currsum==sum/2)
    {
        for(i=0;i<n-1;i++)
            printf("%d ",c[i]);
        printf("\nAND\n");
        l=sizeof(b)/sizeof(int);
        for(i=0;i<l;i++)
        {
            flag=1;
            for(j=0;j<n-1;j++)
            {
                if(b[i]==c[j])
                    flag=0;
            }
            if(flag==1)
                printf("%d ",b[i]);

        }
        printf("\n");
        exit (0);

    }
    return 0;
}

int main()
{
    int *a,b[500],c[500],p,i,j=0,k=0,n,sum=0,sum2=0,diff,count=0,sh,temp;
    time_t t;
    printf("Enter the size of array: \n");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Enter the %d elements: \n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sh=repeat(a,a,n,sum);
    if(sh==0)
        printf("Not Found\n");
}

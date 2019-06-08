/*
WEEK 8:
Problem Statement:
Create Function for each question. And call it using switch case.(eg: case 1: Q1) .
Presentation matters.
1. Implement enqueue() function using array which will insert values in the queue.
2. Implement dequeue() function using linked list which will delete values from queue.
3. Implement Isfull() function, which will inform the user if queue is full.
4. Implement Isempty() function, which will inform the user if queue is empty.
5. Implement Print(), in which call of every function will be given.


Description: The Programs aims at implementation of queue.
QUEUE: Queue is used when things don’t have to be processed immediately, but have to be processed in First In First Out order like Breadth First Search. This property of Queue makes it also useful in following kind of scenarios.
1) When a resource is shared among multiple consumers. Examples include CPU scheduling, Disk Scheduling.
2) When data is transferred asynchronously (data not necessarily received at same rate as sent) between two processes. Examples include IO Buffers, pipes, file IO, etc.
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>
#include<stdlib.h>
struct node     //self referencial structure
{
    int data;
    struct node *next;
};
int arrisfull(int rear,int x,int det)       //to check if queue is full
{
    if(rear==x-1)
    {
        printf("\tQueue is Full\n");
        return 0;
    }
    else if(det==0)
    {
        if(rear!=-2)
            printf("\tQueue is not Full\n");
        else
            printf("\tQueue is not Full. But also it cannot accomodate more as LIMIT has REACHED!\n");
        return 1;
    }
    return 1;
}

int arrisempty(int front,int rear,int det)      //to check if queue is empty
{
    if(front<0 || front>rear)
    {
        printf("\tQueue is empty\n");
        return 0;
    }
    else if(det==0)
    {
        printf("\tQueue is not empty\n");
        return 1;
    }
    return 1;
}

int arrenq(int *rear,int *front,int *ptr,int x,int y)       //insertion in queue
{
    if(arrisfull(*rear,x,1)==0)
        return 0;
    if(*rear==-2)
    {
        printf("\tCannot insert more. LIMIT REACHED\n");
        return 0;
    }
    *rear+=1;
    ptr[*rear]=y;
    if(*front==-1)
        *front=0;
}

int arrdeq(int *rear,int *front,int *ptr,int x)     //to delete from queue
{
    if(arrisempty(*front,*rear,1)==0)
        return 0;
    printf("\t%d is deleted\n",ptr[*front]);
    *front+=1;
    if(*front==x)
        *rear=-2;
}

int qarray(int x)       //implementation of queue in array
{
    int i,j,n,y,*ptr,rear=-1,front=-1;
    ptr=(int*)malloc(x*sizeof(int));
    while(1)
    {
        printf("\n_______________________________________________\n");
        printf("\tENTER 1 : For insertion in queue\n");
        printf("\tENTER 2 : For deletion from queue\n");
        printf("\tENTER 3 : For calling Isempty()\n");
        printf("\tENTER 4 : For calling Isfull()\n");
        printf("\tENTER 5 : To jump to MAIN MENU\n");
        printf("\n_______________________________________________\n\n");
        printf("\tEnter your choice-->  ");
        scanf("%d",&n);
        if(n==5)
            return 0;
        switch(n)
        {
            case 1 : printf("\tEnter the data to be inserted-->  ");
                     scanf("%d",&y);
                     arrenq(&rear,&front,ptr,x,y);
                     break;
            case 2 : arrdeq(&rear,&front,ptr,x);
                     break;
            case 3 : arrisempty(front,rear,0);
                     break;
            case 4 : arrisfull(rear,x,0);
                     break;
            default : printf("\tWrong Input\n");
                      break;
        }
    }
}
struct node *ptr,*head,*rear,*front,*temp;
int flag=0;

int listisfull(int ri,int x)    //to check if queue list is full
{
    if(ri==x-1)
    {
        printf("\tQueue is Full\n");
        return 0;
    }
    else
    {
        if(ri!=-2)
            printf("\tQueue is not Full\n");
        else
            printf("\tQueue is not Full. But also it cannot accomodate more as LIMIT has REACHED!\n");
        return 1;
    }
    return 1;
}

int listisempty(int fi,int ri)      //to check if queue list is empty
{
    if(fi<0 || fi>ri)
    {
        printf("\tQueue is empty\n");
        return 0;
    }
    else
    {
        printf("\tQueue is not empty\n");
        return 1;
    }
    return 1;
}
int listenq(int *ri,int *fi,int x,int y)        //insertion in queue list
{
    if(*ri==x-1)
    {
        printf("\tQueue is Full\n");
        return 0;
    }
    if(*ri==-2)
    {
        printf("\tCannot insert more. LIMIT REACHED\n");
        return 0;
    }
    if(rear==NULL)
    {
        rear=ptr;
        rear->data=y;
        rear->next=NULL;
        *ri+=1;
        *fi+=1;
        front=rear;
    }
    else if(rear!=NULL)
    {
        ptr=(struct node*)malloc(sizeof(struct node));
        rear->next=ptr;
        rear=ptr;
        rear->data=y;
        rear->next=NULL;
        *ri+=1;
        if(flag==1)
        {
            temp=rear;
            flag=0;
        }
    }
}
int listdeq(int *ri,int *fi,int x)      //deletion from queue list
{
    struct node *ptr1;
    if(*fi<0 || *fi>*ri)
    {
        printf("\tQueue is empty\n");
        return 0;
    }
    if(front==NULL)
    {
        front=temp;
    }
    printf("\t%d is deleted\n",front->data);
    ptr1=front;
    if(front!=rear)
        front=front->next;
    else
    {
        flag=1;
        front=NULL;
    }

    *fi+=1;
    ptr1->next=NULL;
    if(*fi==x)
    {
        *ri=-2;
    }
}

int qlist(int x)        //implementation of queue using linked list
{
    int i,j,n,y,ri=-1,fi=-1;

    ptr=(struct node*)malloc(sizeof(struct node));
    head=ptr;
    rear=front=NULL;
    while(1)
    {
        printf("\n_______________________________________________\n");
        printf("\tENTER 1 : For insertion in queue\n");
        printf("\tENTER 2 : For deletion from queue\n");
        printf("\tENTER 3 : For calling Isempty()\n");
        printf("\tENTER 4 : For calling Isfull()\n");
        printf("\tENTER 5 : To jump to MAIN MENU\n");
        printf("\n_______________________________________________\n\n");
        printf("\tEnter your choice-->  ");
        scanf("%d",&n);
        if(n==5)
            return 0;
        switch(n)
        {
            case 1 : printf("\tEnter the data to be inserted-->  ");
                     scanf("%d",&y);
                     listenq(&ri,&fi,x,y);
                     //printf("%d\n",rear->data);
                     break;
            case 2 : listdeq(&ri,&fi,x);
                     break;
            case 3 : listisempty(fi,ri);
                     break;
            case 4 : listisfull(ri,x);
                     break;
            default : printf("\tWrong Input\n");
                      break;
        }
    }
}

int main()          //driver function
{
    int n,x,i,j;
    while(1)
    {
        printf("\n_______________________________________________\n");
        printf("ENTER 1 : For implementing queue using array\n");
        printf("ENTER 2 : For implementing queue using linked list\n");
        printf("ENTER 3 : To terminate the program\n");
        printf("[Isfull() and Isempty() are implemented inside 1 & 2]\n\n");
        printf("\n_______________________________________________\n");
        printf("Your Choice-->  ");
        scanf("%d",&n);
        if(n==3)
            break;
        switch(n)
        {
            case 1 : printf("Enter the size of Queue to implement:\n");
                     scanf("%d",&x);
                     qarray(x);
                     break;
            case 2 : printf("Enter the size of Queue to implement:\n");
                     scanf("%d",&x);
                     qlist(x);
                     break;
            default : printf("Wrong Input\n");
                      break;
        }

    }
}

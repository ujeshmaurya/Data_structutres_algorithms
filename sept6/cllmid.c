/*
WEEK 5:
Problem 1:  Find the middle element of the circular linked list.
Description: The Programs aims at creating circular linked list of n nodes and finding its middle node. We will use the most fastest algorithm to find out the middle most element.
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>
#include<stdlib.h>

struct node     //self referencial structure
{
	int data;
	struct node *link;
};

int main()
{
	int i,m,k;
	struct node *start,*ptr,*temp;
	start=NULL;
	printf("Enter the no. of elements to be created at first\n");
	scanf("%d",&m);
	for(i=0;i<m;i++)        //input linked list
	{
		if(i==0)
		{
			ptr=(struct node*)malloc(sizeof(struct node));
			printf("Enter the data for 1st node: \n");
			scanf("%d",&ptr->data);
			ptr->link=NULL;
			start=ptr;
			temp=start;
			printf("1st node constructed\n");
		}
		else if(i>0)
		{
			ptr=(struct node*)malloc(sizeof(struct node));
			printf("Enter the data for %d node: \n",i+1);
			scanf("%d",&ptr->data);
			ptr->link=NULL;
			temp->link=ptr;
			temp=ptr;
		}

	}
	ptr->link=start;        //linking last node with head
	ptr=start;
	temp=start;
	while(1)
    {       //algo for mid element
        if(ptr->link==start)
            break;
        if(ptr->link->link==start)
            break;
        temp=temp->link;
        ptr=ptr->link->link;
    }
	printf("Middle element of the circular linked list is : %d\n",temp->data);

}

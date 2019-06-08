/*
WEEK 4:
Problem 3: Find the middle node of the list and delete it.
Description: The Programs aims at creating linked list of n nodes and deleting its middle node. We will use the most fastest algorithm to find out the middle most element.
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
	int n=1,i,m,k,count=1;
	struct node *start,*ptr,*temp,*temp2,*temp3;
	start=NULL;
	printf("Enter the no. of elements to be created at first\n");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{                   //linked list input
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
	ptr=start;
	temp=start;
	temp2=start;
	while(1)
    {       //algo for finding middlemost element
        if(ptr->link==NULL)
            break;
        if(ptr->link->link==NULL)
            break;
        temp2=temp;
        temp=temp->link;
        ptr=ptr->link->link;
    }
    temp2->link=temp->link;     //deleting the middle element
    temp->link=NULL;
	printf("After deleting the Middle elements,The linked list becomes: \n");
	ptr=start;
	while(ptr!=NULL)
	{           //print modified list
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");


}

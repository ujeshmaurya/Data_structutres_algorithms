/*
WEEK 3:
Problem 1: Insert a node in the linked list
a. At the beginning
b. At the end
c. At a particular position.
Apply switch case for the options.
Description: The Programs aims at creation of a linked list and inserting nodes in it at runtime. This may prove helpful in managing public records in schools, hospitals, etc. We take a linked list of size ‘n’ as input and give options for inserting a new node in linked list.
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
	int n=1,i,m,k;
	struct node *start,*ptr,*temp,*temp2;
	start=NULL;
	printf("Enter the no. of elements to be created at first\n");
	scanf("%d",&m);
	for(i=0;i<m;i++)        //input initial linked list
	{
		if(i==0)
		{
			ptr=(struct node*)malloc(sizeof(struct node));
			printf("Enter the data for 1st node: \n");
			scanf("%d",&ptr->data);
			ptr->link=NULL;
			start=ptr;
			printf("1st node constructed\n");
		}
		else if(i>0)
		{
			ptr=(struct node*)malloc(sizeof(struct node));
			printf("Enter the data for %d node: \n",i+1);
			scanf("%d",&ptr->data);
			ptr->link=NULL;
			if(i==1)
				start->link=ptr;
			else
				temp->link=ptr;
			temp=ptr;
		}

	}
	while(n)        //infinite loop for asking user the options
	{
	printf("Please Enter your choice: \n");
	printf(" press 1 for insertion at beg.: \n");
	printf(" Press 2 for insertion at particular position: \n");
	printf(" Press 3 for insertion at last.: \n");
	printf(" Press 0 to exit the program: \n");
	printf(" Press 4 to print exisiting list\n");
	scanf("%d",&n);
	if(n==0)
		break;
	switch(n)
	{
		case 1:                 //insert at begin
			ptr=(struct node*)malloc(sizeof(struct node));
			printf("Enter the data to be inserted: \n");
			scanf("%d",&ptr->data);
			ptr->link=start;
			start=ptr;
			printf("Node created\n_____________________________\n");
			break;
		case 2:                 //insert at kth position
			ptr=(struct node*)malloc(sizeof(struct node));
			printf("Enter the position where you want to insert: \n");
			scanf("%d",&k);
			printf("Enter the data to be inserted: \n");
			scanf("%d",&ptr->data);
			temp=start;
			for(i=0;i<k-2;i++)
			{
				temp=temp->link;
			}
			temp2=temp->link;
			temp->link=ptr;
			ptr->link=temp2;
			printf("Node created\n_____________________________\n");
			break;
		case 3:                     //insert at last
			ptr=(struct node*)malloc(sizeof(struct node));
			printf("Enter the data to be inserted: \n");
			scanf("%d",&ptr->data);
			temp=start;
			while(temp->link!=NULL)
			{
				temp=temp->link;
			}
			temp->link=ptr;
			ptr->link=NULL;
			printf("Node created\n_____________________________\n");
			break;
		case 4:                 //print the current list
			temp=start;
			while(temp!=NULL)
			{
				printf("%d ",temp->data);
				temp=temp->link;
			}
			printf("\n");
			printf("_____________________________\n");
			break;
	}
	}

}

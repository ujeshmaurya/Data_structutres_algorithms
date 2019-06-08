/*
WEEK 4:
Problem 1:  Insert and delete a node in the doubly linked list.
Description: The Programs aims at creating a doubly linked list with options to modify the nodes by insertion and deletion at further stage. The advantage of using doubly linked list is that we can traverse in both directions, thus reducing time complexity.
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>
#include<stdlib.h>

struct node     //self referencial structure
{
	int data;
	struct node *link;
	struct node *prev;
};

int main()
{
	int n=1,i,m,k;
	struct node *start,*ptr,*temp,*temp2,*temp3;
	start=NULL;
	printf("Enter the no. of elements to be created at first\n");
	scanf("%d",&m);
	for(i=0;i<m;i++)        //input the linked list
	{
		if(i==0)
		{
			ptr=(struct node*)malloc(sizeof(struct node));
			printf("Enter the data for 1st node: \n");
			scanf("%d",&ptr->data);
			ptr->link=NULL;
			ptr->prev=NULL;
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
			ptr->prev=temp;
			temp->link=ptr;
			temp=ptr;
		}

	}
	while(n)        //infinite loop for giving options
	{
	printf("Please Enter your choice: \n");
	printf(" press 1 for insertion at beg.: \n");
	printf(" Press 2 for insertion at particular position: \n");
	printf(" Press 3 for insertion at last.: \n");
	printf(" Press 0 to exit the program: \n");
	printf(" Press 4 to print existing list\n");
	printf(" Press 5 for deletion at particular position: \n");
	scanf("%d",&n);
	if(n==0)
		break;
	switch(n)
	{
		case 1:         //insertion at beg
			ptr=(struct node*)malloc(sizeof(struct node));
			printf("Enter the data to be inserted: \n");
			scanf("%d",&ptr->data);
			ptr->prev=NULL;
			ptr->link=start;
			start->prev=ptr;
			start=ptr;
			printf("Node created\n_____________________________\n");
			break;
		case 2:     //insertion at k
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
			ptr->prev=temp;
			ptr->link=temp2;
			temp2->prev=ptr;
			printf("Node created\n_____________________________\n");
			break;
		case 3:     //insertion at last
			ptr=(struct node*)malloc(sizeof(struct node));
			printf("Enter the data to be inserted: \n");
			scanf("%d",&ptr->data);
			temp=start;
			while(temp->link!=NULL)
			{
				temp=temp->link;
			}
			temp->link=ptr;
			ptr->prev=temp;
			ptr->link=NULL;
			printf("Node created\n_____________________________\n");
			break;
		case 4:     //print the list
			temp=start;
			while(temp!=NULL)
			{
				printf("%d ",temp->data);
				temp=temp->link;
			}
			printf("\n");
			printf("_____________________________\n");
			break;
		case 5:         //deletion at kth position
			printf("Enter the position where you want to delete: \n");
			scanf("%d",&k);
			if(k==1)
			{
				start=start->link;
				start->prev=NULL;
				goto lab;
			}
			temp=start;
			for(i=0;i<k-2;i++)
			{
				temp=temp->link;
			}
			temp2=temp->link;
			if(temp2->link!=NULL)
			{
				temp3=temp2->link;
				temp->link=temp3;
				temp3->prev=temp;
			}
			else
				temp->link=NULL;
			temp2->prev=temp2->link=NULL;
			lab:
			printf("Node deleted\n_____________________________\n");
			break;
		default :
			printf("Invalid Input\n");
	}
	}

}

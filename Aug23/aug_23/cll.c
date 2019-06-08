/*
WEEK 4:
Problem 2:  Insert and delete a node in the circular linked list.
Description: The Programs aims at creating a circular linked list and giving options for modifying the nodes at a later stage. The advantage of circular linked list is that the last node is directly connected to the head node.
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
	struct node *start,*ptr,*temp,*temp2,*temp3;
	start=NULL;
	printf("Enter the no. of elements to be created at first\n");
	scanf("%d",&m);
	for(i=0;i<m;i++)        //linked list input
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
	ptr->link=start;        //link last node with head
	while(n)
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
		case 1:     //insertion at beg
			ptr=(struct node*)malloc(sizeof(struct node));
			printf("Enter the data to be inserted: \n");
			scanf("%d",&ptr->data);
			temp=start;
			while(temp->link!=start)
				temp=temp->link;
			ptr->link=start;
			start=ptr;
			temp->link=start;
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
			ptr->link=temp2;
			printf("Node created\n_____________________________\n");
			break;
		case 3:         //insertion at last
			ptr=(struct node*)malloc(sizeof(struct node));
			printf("Enter the data to be inserted: \n");
			scanf("%d",&ptr->data);
			temp=start;
			while(temp->link!=start)
			{
				temp=temp->link;
			}
			temp->link=ptr;
			ptr->link=start;
			printf("Node created\n_____________________________\n");
			break;
		case 4:     //print the list
			temp=start;
			while(1)
			{
				printf("%d ",temp->data);
				temp=temp->link;
				if(temp==start)
					break;
			}
			printf("\n");
			printf("_____________________________\n");
			break;
		case 5:         //deletion at kth
			printf("Enter the position where you want to delete: \n");
			scanf("%d",&k);
			temp=start;
			if(k==1)
			{
				while(temp->link!=start)
					temp=temp->link;
				start=start->link;
				temp->link=start;
				goto lab;
			}
			temp=start;
			for(i=0;i<k-2;i++)
			{
				temp=temp->link;
			}
			temp2=temp->link;
			if(temp2->link!=start)
			{
				temp3=temp2->link;
				temp->link=temp3;
			}
			else
				temp->link=start;
			temp2->link=NULL;
			lab:
			printf("Node deleted\n_____________________________\n");
			break;
		default :
			printf("Invalid Input\n");
	}
	}

}

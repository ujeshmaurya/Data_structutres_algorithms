/*
WEEK 3:
Problem 3:  Delete an element from particular position.
Description: The Programs aims at creating a linked list and deleting k’th node from that list. It is useful in deleting those record which are expired or are no longer valid. It takes a linked list as input and provide option for deleting k’th element and prints the updated list as output.
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
	for(i=0;i<m;i++)            //linked list input
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
	while(n)
	{
	printf("Please Enter your choice: \n");
	printf(" Press 1 for deletion at particular position: \n");
	printf(" Press 0 to exit the program: \n");
	printf(" Press 2 to print existing list\n");
	scanf("%d",&n);
	if(n==0)
		break;
	switch(n)
	{

		case 1:         //performing deletion
			printf("Enter the position where you want to delete: \n");
			scanf("%d",&k);
			if(k==1)            //primitive case
			{
				start=start->link;
				goto lab;
			}
			temp=start;     //rest of the cases
			for(i=0;i<k-2;i++)
			{
				temp=temp->link;
			}
			temp2=temp->link;
			temp3=temp2->link;
			temp->link=temp3;
			lab:
			printf("Node deleted\n_____________________________\n");
			break;
		case 2:
			temp=start;     //printing the list
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

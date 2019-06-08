/*
WEEK 5:
Problem 6: Write a program to remove duplicate nodes from a linked list.
Description: The Programs aims at removing duplicates nodes from a linked list. It may prove helpful in cleaning records from reduntant and useless data such as duplicates of data items which are already present. It takes a list as input and prints the modified list as output.
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
	ptr=start;
	printf("Before removing duplicates:\n");
	while(ptr!=NULL)        //show linked list
	{
		printf("%d  ",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
	if(m==1)        //primitive case
	{
		printf("After removing duplicates: \n %d\n",start->data);
		return 0;
	}
	ptr=start;
	while(ptr!=NULL)        //algo for duplicacy removal
	{
		temp=ptr->link;
		while(temp!=NULL)
		{
			if(ptr->data==temp->data)
			{
				temp2=ptr;
				while(temp2->link!=temp)
					temp2=temp2->link;
				temp2->link=temp->link;
				temp3=temp->link;
				temp->link=NULL;
				temp=temp3;

			}
			else
			temp=temp->link;
		}
		ptr=ptr->link;
	}
	ptr=start;
	printf("After removing duplicates:\n");
	while(ptr!=NULL)        //modified list
	{
		printf("%d  ",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
	return 0;
}

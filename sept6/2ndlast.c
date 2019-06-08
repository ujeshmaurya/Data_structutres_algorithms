/*
WEEK 5:
Problem 2: Find the 2nd last element of the singly linked list.
Description: The Programs aims at creating a single linked list and finding the 2nd last element of that list in O(n) complexity.
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
	int i,m,k,count=1;
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
	if(m==1)        //primitive case
		printf("2nd last element not found\n");
	else
	{
	ptr=start;
	temp=start->link;
	while(temp->link!=NULL)     //traverse till last
	{
		temp=temp->link;
		ptr=ptr->link;
	}           //print 2nd last
	printf("2nd last element of the linked list is : %d\n",ptr->data);
	}

}

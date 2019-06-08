/*
Problem 2: Implement a function to reverse a linked list, and return the head of the reversed list.
Description: The Programs aims at creating a linked list of n nodes and reversing the linkage if all the nodes thereby reversing the linked list. It proves helpful in finding out palindromic list. We take a linked list as  as input and print the reverse of it as output.
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
	struct node *start,*start1,*ptr,*temp,*temp2,*temp3;
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
	printf("Reversed linked list: \n");
	ptr=start;
	while(ptr->link!=NULL)
		ptr=ptr->link;
	start1=ptr;
	temp=ptr;
	lab2:
	ptr=start;
	while(ptr->link!=temp)  //reversing linked list
	{
		ptr=ptr->link;

	}
	temp->link=ptr;
		temp=ptr;
	if(ptr!=start)
		goto lab2;
	start->link=NULL;
	ptr=start1;
	while(ptr!=NULL)        //print reversed linked list
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}


}

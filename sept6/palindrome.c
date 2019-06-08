/*
WEEK 5:
Problem 5: Find out whether a singly linked list is palindrome or not.
Description: The Programs aims at finding out whether a linked list is palindrome or not. Palindromes are same even if they are reversed.
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
	int n=1,i,m,k,flag=1;
	struct node *start,*ptr,*temp,*temp2,*temp3;
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
	temp=ptr=start;
	if(m==1)        //primitive case
	{
		printf("Palindromic list\n");
		return 0;
	}
	while(ptr->link!=NULL)
		ptr=ptr->link;
	while(temp!=NULL)       //palindrome checking
	{
		if(temp->data!=ptr->data)
		{
			flag=0;
			break;
		}
		if((temp->link==ptr)||(temp==ptr))
			break;
		temp2=start;
		while(temp2->link!=ptr)
			temp2=temp2->link;
		ptr=temp2;
		temp=temp->link;
	}
	if(flag==0)     //printing message
		printf("Not a palindromic list\n");
	else
		printf("Palidromic list\n");
	return 0;

}

/*
WEEK 5:
Problem 4:  Find out the union and intersection of two list.
Description: The Programs aims at finding union and intersection of two linked list. It may prove helpful in finding the duplicate elements in combination of two lists. It takes two lists of size ‘m’ and ‘n’ as input and prints their union and intersection.
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
	int n,i,m,k,count=1;
	struct node *start1,*start2,*ptr,*temp,*temp2,*temp3;
	start1=NULL;        //head of list1
	start2=NULL;        //head of list2
	printf("Enter the no. of elements to be created in 1st list\n");
	scanf("%d",&m);
	for(i=0;i<m;i++)        //input list1
	{
		if(i==0)
		{
			ptr=(struct node*)malloc(sizeof(struct node));
			printf("Enter the data for 1st node: \n");
			scanf("%d",&ptr->data);
			ptr->link=NULL;
			start1=ptr;
			temp=start1;
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
	printf("Enter the no. of elements to be created in 2nd list\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)        //input list2
	{
		if(i==0)
		{
			ptr=(struct node*)malloc(sizeof(struct node));
			printf("Enter the data for 1st node: \n");
			scanf("%d",&ptr->data);
			ptr->link=NULL;
			start2=ptr;
			temp=start2;
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
	ptr=start1;
	printf("Union of these 2 list:\n");
	while(ptr!=NULL)        //finding union
	{
		printf("%d  ",ptr->data);
		ptr=ptr->link;
	}
	ptr=start2;
	while(ptr!=NULL)
	{
		printf("%d  ",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
	ptr=start1;
	printf("Intersection of the 2 lists:\n");
	while(ptr!=NULL)        //finding intersection
	{
		temp2=start2;
		while(temp2!=NULL)
		{
			if(temp2->data==ptr->data)
				printf("%d  ",ptr->data);
			temp2=temp2->link;
		}
		ptr=ptr->link;
	}
	printf("\n");
	return 0;
}

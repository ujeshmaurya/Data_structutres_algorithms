/*
WEEK 7:
Problem Statement:
Create Function for each question. And call it using switch case.(eg: case 1 : Q1) .
Presentation matters.
1. Implement SortStack() using recursion.
2. Print a function(name of your choice) for printing a pattern without using any loop.
3. Implement Infix2Prefix() function which will convert an infix expression to prefix.
4. Implement stack’s operation Push() using linked list.
Call of the every functions will be given into the Print() function.


Description: The Programs aims at implementing sortstack , recursion, infix to prefix, and stack using linked list.
STACK: Expression evaluation and syntax parsing. Calculators employing reverse Polish notation use a stack structure to hold values. Expressions can be represented in prefix, postfix or infix notations and conversion from one form to another may be accomplished using a stack.
RECURSION: Recursion is a programming technique in which a method makes a call to itself to solve a particular problem. Such methods are called recursive. Recursion is a programming technique whose correct usage leads to elegant solutions to certain problems like Tower Of Hanoi etc.
NOTATION (PREFIX):  In prefix the operator comes before both the operand. Prefix notation is nearly as easy to process; it's used in Lisp
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node         //self referencial structure
{
	int data;
	struct node *link;
};

int ssort()     //function to sort a stack
{
	int n=1,i,m,k=0,x,swap;
	struct node *start,*ptr,*temp,*temp2;
	start=NULL;
	printf("Enter the size of stack to be created\n");
	scanf("%d",&m);
	while(1)
	{
		printf("\nEnter 1 to push()\n");
		printf("Enter 2 to print current status of stack\n");
		printf("Enter 3 to exit stack function\n");
		printf("Enter 4 to sort the stack at current\n");
		scanf("%d",&n);
		if(n==3)
			return 0;
		switch(n)
		{
			case 1: printf("Enter data to push into stack\n");
					scanf("%d",&x);
					if(k>=m)
					{
						printf("WARNING!!!: Stack Overflow\n");
						break;
					}
					else if(k==0)
					{
						ptr=(struct node*)malloc(sizeof(struct node));
						start=ptr;
						start->data=x;
						start->link=NULL;
						temp=start;
						k++;
					}
					else
					{
						ptr=(struct node*)malloc(sizeof(struct node));
						ptr->data=x;
						ptr->link=temp;
						temp=ptr;
						k++;
					}
					break;
			case 2:	ptr=temp;
                    printf("CURRENT STACK:  ");
					while(ptr!=NULL)
					{
						printf("%d ",ptr->data);
						ptr=ptr->link;
					}
					printf("\n");
					break;
			case 4: ptr =temp;
					temp2=temp;
					while(ptr!=NULL)
					{
						temp2=temp;
						while(temp2->link!=NULL)
						{
							if(temp2->data>temp2->link->data)
							{
								swap=temp2->data;
								temp2->data=temp2->link->data;
								temp2->link->data=swap;
							}
							temp2=temp2->link;

						}
						ptr=ptr->link;
					}
					printf("STACK is sorted. You may check by printing the current stack.\n");
					break;
			default:
						printf("WARNING: Wrong Input\n");
						break;
		}

	}
	return 0;
}
int llist()     //function to implement stack in linked list
{
	int n=1,i,m,k=0,x;
	struct node *start,*ptr,*temp,*temp2;
	start=NULL;
	printf("Enter the size of stack to be created\n");
	scanf("%d",&m);
	while(1)
	{
		printf("\nEnter 1 to push()\n");
		printf("Enter 2 to print current status of stack\n");
		printf("Enter 3 to exit stack function\n");
		scanf("%d",&n);
		if(n==3)
			return 0;
		switch(n)
		{
			case 1: printf("Enter data to push into stack\n");
					scanf("%d",&x);
					if(k>=m)
					{
						printf("WARNING!!!: Stack Overflow\n");
						break;
					}
					else if(k==0)
					{
						ptr=(struct node*)malloc(sizeof(struct node));
						start=ptr;
						start->data=x;
						start->link=NULL;
						temp=start;
						k++;
					}
					else
					{
						ptr=(struct node*)malloc(sizeof(struct node));
						ptr->data=x;
						ptr->link=temp;
						temp=ptr;
						k++;
					}
					break;
			case 2:	ptr=temp;
					while(ptr!=NULL)
					{
						printf("%d ",ptr->data);
						ptr=ptr->link;
					}
					printf("\n");
					break;
			default:
						printf("WARNING!!!: Wrong Input\n");
						break;
		}

	}
	return 0;
}
int recur(int k)        //function to recurse
{
	if(k==0)
		return 0;
	else
	{
		printf("*");
		recur(k-1);
	}
	return 0;
}

int pattern(int n)      //function to print pattern using recursion
{
	if(n==0)
		return 0;
	else
	{
		recur(n);
		printf("\n");
		pattern(n-1);
	}
	return 0;
}
int infix2prefix()      //function to convert infix to prefix
{
    char a[1000][10],stack[1000],c[1000][10],d,e[1000][10],temp[100];
    int b[1000],i,j=0,p=0,len,t=-1,k=0;
    printf("Enter an infix expression (USE $ TO TERMINATE):\n");
    for(i=0; ;i++)
    {
        scanf("%s",a[i]);
        if(a[i][0]=='$')
            break;
    }
    a[i][0]='\0';
    len=i;
	for(i=0;i<len;i++)
		strcpy(c[i],a[len-i-1]);
	c[len][0]='\0';
	for(i=0;i<len;i++)
	{
		if(c[i][0]=='(')
			c[i][0]=')';
		else if(c[i][0]==')')
			c[i][0]='(';
	}
    i=0;
    while(c[i][0]!='\0')        //various cases for infix to prefix
    {
        if((c[i][0]=='*')||(c[i][0]=='/')||(c[i][0]=='%')||(c[i][0]=='+')||(c[i][0]=='-')||(c[i][0]=='(')||(c[i][0]==')')||(c[i][0]=='^'))
        {
            if(t==-1)
            {
                t++;
                stack[t]=c[i][0];
            }
            else if(((stack[t]=='(')||(c[i][0]=='('))&&(c[i][0]!=')'))
            {
                t++;
                stack[t]=c[i][0];
            }
            else if((stack[t]=='^')&&(c[i][0]=='^'))
            {
				e[k][0]=stack[t];
				e[k++][1]='\0';

                t--;
                t++;
                stack[t]=c[i][0];
            }
            else if((c[i][0]=='^')&&(stack[t]!='^'))
            {
                t++;
                stack[t]=c[i][0];
            }
            else if((stack[t]=='^')&&(c[i][0]!=')'))
            {

				e[k][0]=stack[t];
				e[k++][1]='\0';
                t--;
                if(t>-1)
                if(((c[i][0]=='-')||(c[i][0]=='+'))&&(stack[t]!='('))
                {

					e[k][0]=stack[t];
					e[k++][1]='\0';
                    t--;
                    if(t>-1)
                        if((stack[t]=='-')||(stack[t]=='+'))
                        {

						e[k][0]=stack[t];
						e[k++][1]='\0';
                        t--;
                        }
                }
                if(t>-1)
                if(((c[i][0]=='/')||(c[i][0]=='*')||(c[i][0]=='%'))&&((stack[t]=='/')||(stack[t]=='*')||(stack[t]=='%')))
                {

					e[k][0]=stack[t];
					e[k++][1]='\0';
                    t--;
                }
                t++;
                stack[t]=c[i][0];
            }
            else if(((stack[t]=='-')||(stack[t]=='+'))&&((c[i][0]=='%')||(c[i][0]=='*')||(c[i][0]=='/')||(c[i][0]=='^')))
            {
                t++;
                stack[t]=c[i][0];
            }
            else if(((stack[t]=='%')||(stack[t]=='/')||(stack[t]=='*')||(c[i][0]=='^'))&&(c[i][0]!=')')&&(c[i][0]!='^'))
            {

				e[k][0]=stack[t];
				e[k++][1]='\0';
                t--;
                j=t;
                if((c[i][0]=='+') || (c[i][0]=='-'))
                    if((stack[j]=='+') || (stack[j]=='-'))
                        while((stack[j]=='+')||(stack[j]=='-'))
                        {

							e[k][0]=stack[j];
							e[k++][1]='\0';
                            j--;
                            if(j=-1)
                                break;
                        }
                t=j;
                t++;
                stack[t]=c[i][0];
            }
            else if(((stack[t]=='-')||(stack[t]=='+'))&&((c[i][0]=='-')||(c[i][0]=='+')))
            {

				e[k][0]=stack[t];
				e[k++][1]='\0';
                t--;
                t++;
                stack[t]=c[i][0];
            }
            else if(c[i][0]==')')
            {
                j=t;
                while(stack[j]!='(')
                {

					e[k][0]=stack[j];
					e[k++][1]='\0';
                    j--;
                }
                t=j;
                t--;
            }
        }
        else
			strcpy(e[k++],c[i]);

        i++;
    }
    printf(" ");
    while(t!=-1)
    {
		e[k][0]=stack[t];
		e[k++][1]='\0';

        t--;
    }
	for(i=k-1;i>=0;i--)
		printf("%s ",e[i]);         //print the prefix
    printf("\n\n");
    return 0;
}
int main()      //driver function
{
	int x,n,i,j;
	while(1)
	{
		printf("___________________________________________________________\n");
		printf("Enter 1 for sortstack()\n");
		printf("Enter 2 for printing a pattern without using loop\n");
		printf("Enter 3 for Inorder() Traversal\n");
		printf("Enter 4 for infix to prefix conversion\n");
		printf("Enter 5 for PUSH() using linked list\n");
		printf("Enter 6 to exit() program\n");
		printf("___________________________________________________________\n");
		scanf("%d",&x);
		if(x==6)
			return 0;
		switch(x)
		{
			case 1: ssort();
					break;
			case 2: printf("Enter an integer\n");
					scanf("%d",&n);
					pattern(n);
					break;
			case 5: llist();
					break;
			case 4: infix2prefix();
					break;
			default: printf("WARNING!!!: Invalid Input\n");
					break;

		}
	}

}

/*
WEEK 6:
Problem Statement:
Create Function for each question. And call it using switch case.(eg: case1: Q1) .
Presentation matters.
1. Implement PUSH() in stack using array
2. Implement POP() from the stack using array.
3. Implement HeadRecursion() and TailRecursion().
4. Implement Infix2Postfix() function which will convert an infix expression to postfix.
5. Implement Print(), which will print all the above functions.


Description: The Programs aims at implementing stack, recursion and infix to postfix evaluation.
STACK: Expression evaluation and syntax parsing. Calculators employing reverse Polish notation use a stack structure to hold values. Expressions can be represented in prefix, postfix or infix notations and conversion from one form to another may be accomplished using a stack.
RECURSION: Recursion is a programming technique in which a method makes a call to itself to solve a particular problem. Such methods are called recursive. Recursion is a programming technique whose correct usage leads to elegant solutions to certain problems like Tower Of Hanoi etc.
NOTATIONS (POSTFIX): Postfix notation, also known as RPN, is very easy to process left-to-right. An operand is pushed onto a stack; an operator pops its operand(s) from the stack and pushes the result. Little or no parsing is necessary.
Compiled By: UJESH MAURYA (2015UCP1338)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top=-1,*st,n;
int push()      //function to push into stack
{
    top++;
    if(top==n)
    {
        printf("Overflow of stack.\n");
        top--;
        return 0;
    }
    printf("Enter the element you want to push\n");
    scanf("%d",&st[top]);
    return 0;
}
int pop()       //function to pop out of stack
{
    if(top==-1)
    {
        printf("Underflow of stack\n");
        return 0;
    }
    printf("%d is popped out of stack\n",st[top]);
    top--;
    return 0;
}
int print()     //function to print stack
{
    int i;
    if(top==-1)
    {
        printf("Underflow of stack. | Stack is empty\n");
        return 0;
    }
    printf("\n\nCurrent status of stack:\n");
    for(i=0;i<=top;i++)
        printf("%d  ",st[i]);
    printf("\n");
    return 0;
}
int sumhead(int n)      //head recursion
{
    int sum;
    if (n!=0)
    {
        printf("+%d",n);
        sum=n+sumhead(n-1); // sum() function calls itself
    }
    else
    {
        printf("=");
        return n;
    }
    return sum;
}
int sumtail(int n)      //tail recursion
{
    int sum;
    if (n!=0)
    {
        sum=n+sumtail(n-1); // sum() function calls itself
        if(n==1) printf("%d",n);
        else printf("+%d",n);
    }
    else
    {
        return n;
    }
    return sum;
}
int infix2postfix()     //function for infix to postfix
{
    char a[1000][10],stack[1000],c[1000],d;
    int b[1000],i,j=0,p=0,len,t=-1;
    printf("Enter an infix expression (USE $ TO TERMINATE):\n");
    for(i=0; ;i++)
    {
        scanf("%s",a[i]);
        if(a[i][0]=='$')
            break;
    }
    a[i][0]='\0';
    len=i;
    i=0;
    while(a[i][0]!='\0')        //various cases for infix to postfix
    {
        if((a[i][0]=='*')||(a[i][0]=='/')||(a[i][0]=='%')||(a[i][0]=='+')||(a[i][0]=='-')||(a[i][0]=='(')||(a[i][0]==')')||(a[i][0]=='^'))
        {
            if(t==-1)
            {
                t++;
                stack[t]=a[i][0];
            }
            else if(((stack[t]=='(')||(a[i][0]=='('))&&(a[i][0]!=')'))
            {
                t++;
                stack[t]=a[i][0];
            }
            else if((stack[t]=='^')&&(a[i][0]=='^'))
            {
                printf("%c ",stack[t]);
                t--;
                t++;
                stack[t]=a[i][0];
            }
            else if((a[i][0]=='^')&&(stack[t]!='^'))
            {
                t++;
                stack[t]=a[i][0];
            }
            else if((stack[t]=='^')&&(a[i][0]!=')'))
            {
                printf("%c ",stack[t]);
                t--;
                if(t>-1)
                if(((a[i][0]=='-')||(a[i][0]=='+'))&&(stack[t]!='('))
                {
                    printf("%c ",stack[t]);
                    t--;
                    if(t>-1)
                        if((stack[t]=='-')||(stack[t]=='+'))
                        {
                        printf("%c ",stack[t]);
                        t--;
                        }
                }
                if(t>-1)
                if(((a[i][0]=='/')||(a[i][0]=='*')||(a[i][0]=='%'))&&((stack[t]=='/')||(stack[t]=='*')||(stack[t]=='%')))
                {
                    printf("%c ",stack[t]);
                    t--;
                }
                t++;
                stack[t]=a[i][0];
            }
            else if(((stack[t]=='-')||(stack[t]=='+'))&&((a[i][0]=='%')||(a[i][0]=='*')||(a[i][0]=='/')||(a[i][0]=='^')))
            {
                t++;
                stack[t]=a[i][0];
            }
            else if(((stack[t]=='%')||(stack[t]=='/')||(stack[t]=='*')||(a[i][0]=='^'))&&(a[i][0]!=')')&&(a[i][0]!='^'))
            {
                printf("%c ",stack[t]);
                t--;
                j=t;
                if((a[i][0]=='+') || (a[i][0]=='-'))
                    if((stack[j]=='+') || (stack[j]=='-'))
                        while((stack[j]=='+')||(stack[j]=='-'))
                        {
                            printf("%c ",stack[j]);
                            j--;
                            if(j=-1)
                                break;
                        }
                t=j;
                t++;
                stack[t]=a[i][0];
            }
            else if(((stack[t]=='-')||(stack[t]=='+'))&&((a[i][0]=='-')||(a[i][0]=='+')))
            {
                printf("%c ",stack[t]);
                t--;
                t++;
                stack[t]=a[i][0];
            }
            else if(a[i][0]==')')
            {
                j=t;
                while(stack[j]!='(')
                {
                    printf("%c ",stack[j]);
                    j--;
                }
                t=j;
                t--;
            }
        }
        else
            printf("%s ",a[i]);
        i++;
    }
    printf(" ");
    while(t!=-1)
    {
        printf("%c ",stack[t]);
        t--;
    }
    printf("\n\n");
    return 0;
}
int main()      //driver function
{
    int i,j,x;
    printf("First Create a Stack. | Enter Size of stack to be created.\n");
    scanf("%d",&n);
    st=(int*)malloc(n*sizeof(int));
    printf("Stack of size %d has been created. | Now use the functions below.\n",n);
    while(1)        //infinite loop for user interaction
    {
        printf("\n\n---------------------------------------------------------\n");
        printf("ENTER 1: To push() element into stack\n");
        printf("ENTER 2: To pop() element out of stack\n");
        printf("ENTER 3: To implement headrecursion() and tailrecursion()\n");
        printf("ENTER 4: To convert infix expression to postfix.| infix2postfix()\n");
        printf("ENTER 5: To print() the status of STACK\n");
        printf("ENTER 6: To exit the program\n");
        printf("\n---------------------------------------------------------\n\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: printf("Sum of natural numbers till n will be implemented by tail and head recursion\n");
                    printf("Please enter value of n\n");
                    scanf("%d",&i);
                    printf("Result through head recursion:\n");
                    printf("%d\n",sumhead(i));
                    printf("\n\nResult through tail recursion:\n");
                    printf("=%d\n",sumtail(i));
                    break;
            case 4: infix2postfix(); break;
            case 5: print(); break;
            case 6: return 0; break;
            default: printf("Wrong input\n"); break;
        }
    }
}

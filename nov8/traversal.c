/*
WEEK : 9
1. Implement preorder_traversal() function using linked list which will traverse a tree in root first, left node second and right node in the last sequence.

2. Implement inorder_traversal() function using linked list which will traverse a tree in left first, root node second and right node in the last, sequence.

3. Implement postorder_traversal() function, using linked list which will traverse a tree in left first, root node second and right node in the last sequence.

4. In a class room there are N students sitting in the class, and M students are standing out of the class. When ever one students enters he has given K(1,2,3..) cards. When a student enters to the class he wishes to be seated with that student which has same number of cards. Help the student getting his exact seat and denote it with “Yes” or “No”

	Input					Output
	1,2,3,7,8				NO
	1,2,3,7,8,3				Yes
Description : This program focuses on the ways of doing depth traversals on trees, which are namely Preorder, Postorder and
Inorder. These traversals are used in different purposes, like if a parse tree of a formula is given then preorder traversal of that
parse tree will give prefix expression and postorder traversal will give postfix notation of that formula. This program also
describes solving a real life class/student problem using linked lists and algorithms for deletion, insertion of nodes in a
singly linked list.
Compiled By : UJESH MAURYA (2015UCP1338)
*/
#include <stdio.h>
#include <stdlib.h>

struct node //node for tree
{
     int data;
     struct node* left;
     struct node* right;
};
struct node1  //node for class-student problem
{
	int data;
	struct node *link;
};

/* Helper function that allocates a new node */
struct node* newNode(int data)
{
     struct node* node = (struct node*)malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;

     return(node);
}
/* Given a binary tree, print postorder traversal. */
void printPostorder(struct node* node)
{
     if (node == NULL)
        return;
     printPostorder(node->left);
     printPostorder(node->right);
     printf("%d ", node->data);
}
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node)
{
     if (node == NULL)
          return;
     printInorder(node->left);
     printf("%d ", node->data);
     printInorder(node->right);
}
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node* node)
{
     if (node == NULL)
          return;
     printf("%d ", node->data);
     printPreorder(node->left);
     printPreorder(node->right);
}

int main()
{
    int n=1,i,m,k,in,out,tt,flag,x,a[10];
    struct node1 *start,*ptr,*temp,*temp2,*start2,*ptr2,*temp3,*curr;
    printf("First Enter 7 elements to build a tree:\n");
    for(i=0;i<7;i++)
        scanf("%d",&a[i]);
    struct node *root  = newNode(a[0]);
     root->left             = newNode(a[1]);
     root->right           = newNode(a[2]);
     root->left->left     = newNode(a[3]);
     root->left->right   = newNode(a[4]);
     root->right->left=newNode(a[5]);
     root->right->right=newNode(a[6]);
    while(1)
    {
        printf("Enter 1 for pre-order traversal\n");
        printf("Enter 2 for in-order traversal\n");
        printf("Enter 3 for post-order traversal\n");
        printf("Enter 4 for the class/student problem\n");
        printf("Enter 0 to exit the program\n");
        scanf("%d",&x);
        if(x==0)
            break;
        switch(x)
        {
            case 1: printf("\t\t   %d\n\n\t\t%d\t%d\n\n\t   %d\t   %d  %d\t   %d\n",root->data,root->left->data,root->right->data,root->left->left->data,root->left->right->data,root->right->left->data,root->right->right->data);
                    printf("Pre-order traversal: ");
                    printPreorder(root);
                    printf("\n");
                    break;
            case 2: printf("\t\t   %d\n\n\t\t%d\t%d\n\n\t   %d\t   %d  %d\t   %d\n",root->data,root->left->data,root->right->data,root->left->left->data,root->left->right->data,root->right->left->data,root->right->right->data);
                    printf("In-order traversal: ");
                    printInorder(root);
                    printf("\n");
                    break;
            case 3: printf("\t\t   %d\n\n\t\t%d\t%d\n\n\t   %d\t   %d  %d\t   %d\n",root->data,root->left->data,root->right->data,root->left->left->data,root->left->right->data,root->right->left->data,root->right->right->data);
                    printf("Post-order traversal: ");
                    printPostorder(root);
                    printf("\n");
                    break;
            case 4: start=NULL;
                    printf("Enter the no. of students standing out\n");
                    scanf("%d",&out);
                    printf("Enter the no. of students sitting inside class\n");
                    scanf("%d",&in);
                    printf("Enter the %d cards which are inside the class as a list\n",in);
                    m=in;
                    for(i=0;i<m;i++)
                    {
                        if(i==0)
                        {
                            ptr=(struct node1*)malloc(sizeof(struct node1));
                            //printf("Enter the data for 1st node: \n");
                            scanf("%d",&ptr->data);
                            ptr->link=NULL;
                            start=ptr;
                            //printf("1st node constructed\n");
                        }
                        else if(i>0)
                        {
                            ptr=(struct node1*)malloc(sizeof(struct node1));
                            //printf("Enter the data for %d node: \n",i+1);
                            scanf("%d",&ptr->data);
                            ptr->link=NULL;
                            if(i==1)
                                start->link=ptr;
                            else
                                temp->link=ptr;
                            temp=ptr;
                        }

                    }
                    curr=ptr;
                    printf("Enter the %d cards which are outside the class the one by one\n",out);
                    m=out;
                    for(i=0;i<m;i++)
                    {
                        scanf("%d",&tt);
                        ptr2=start;
                        flag=0;
                        while(ptr2!=NULL)
                        {
                            if(tt==ptr2->data)
                            {
                                printf("YES\n");
                                flag=1;
                                    temp2=ptr2->link;
                                    ptr=(struct node1*)malloc(sizeof(struct node1));
                                    ptr->data=tt;
                                    ptr->link=temp2;
                                    ptr2->link=ptr;
                                    break;
                            }
                            ptr2=ptr2->link;
                        }
                        if(flag==0)
                        {
                            printf("No\n");
                            ptr=(struct node1*)malloc(sizeof(struct node1));
                            ptr->data=tt;
                            ptr->link=NULL;
                            curr->link=ptr;
                            curr=ptr;
                        }
                    }
                    printf("After Entering in the class the configuration becomes\n");
                    ptr=start;
                    while(ptr!=NULL)
                    {
                        printf("%d ",ptr->data);
                        ptr=ptr->link;
                    }
                    printf("\n");
                    break;
            default: printf("Wrong Choice\n");
        }
    }
    return 0;
}

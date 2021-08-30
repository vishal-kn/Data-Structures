#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *lchild,*rchild;
    int data;
};
struct node *create();
void preorder(struct node *root);
int main()
{
 struct node *root = create();
 void preorder(root);
 return 0;
}
struct node * create()
{
    
int x;
scanf("%d",&x);
if(x!=900)
{
struct node *newnode;
newnode=(struct node*)malloc (sizeof(struct node));

newnode->data=x;
printf("Enter left child for %d::",x);
newnode->lchild=create();
printf("Enter right child for %d::",x);
newnode->rchild=create();
return newnode;
    }
}

void preorder(struct node *root)
{
    if(root==NULL)
    return;

    printf("%d",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
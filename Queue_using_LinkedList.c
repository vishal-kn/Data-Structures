//Queue implemenataion in circular linked list.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enq(int data);
void deq();
int peek();
int isfull();
int isempty();
void display();

int main()
{
   int choice,data;
        while(1)
        {
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY ELEMENT AT FRONT\n4.DISPLAY THE QUEUE\n5.EXIT");
        printf("\nEnter Your Choice:");
        scanf("%d",&choice);
            switch(choice)
            {
                    case 1:
                    printf("ENTER DATA:");
                    scanf("%d",&data);
                    enq(data);
                    break;
                    case 2:
                    deq();
                    break;
                    case 3:
                    printf("Element at front is %d\n",peek());
                    break;
                    case 4:
                    display();
                    break;
                    case 5:
                    exit(1);
                    break;  
                    default:   
                    printf("\nWrong Choice Entered\n");                                                                                                                                              
                    break;
            }
        }
        return 0;
        }

void enq(int data)
{
     
    struct node *newnode;
    newnode= (struct node*) malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;

    if(front==NULL)
    {
      front=newnode;  
    }
    else
    rear->next=newnode;
    
    rear=newnode;
    rear->next=front;
}

void deq()
{
    struct node *p;
    if(front==NULL)
    {
        printf("UNDERFLOW");
        return;
    }
      p=front;
    front=front->next;
    free(p);
}

void display()
{
    if(front==NULL)
    {
        printf("UNDERFLOW!");
        return;
    }

    struct node *temp;
    temp=front;
    printf("\n\n");
    while(temp->next!=front)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n\n");
}
int peek()
{
    if(front==NULL)
    {
        printf("UNDERFLOW!");
        return;
    }
    return front->data;
}
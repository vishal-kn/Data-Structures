//CIRCULAR QUEUE IMPLEMEMTATION IN ARRAY
/* for circular queue us overflow condition as [front=(rear+1) mod MAX].*/
/* for linear queue us overflow condition as rear=MAX-1.*/
#include <stdio.h>
# define MAX 20

int QUEUE[MAX],front=-1,rear=-1;

void enq(int data);
void deq();
int peek();
int isfull();
int isempty();
void display();

int  main()
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

   int isempty()
   {
       if(front==-1 || front==rear+1)
       return 1;
       else 
       return 0;
   }

   int isfull()
   {
       if(front==(rear+1)%MAX)
       return 1;
       else 
       return 0;
   }

   void enq(int data)
   {
         if(isfull())
         {
             printf("\nOVERFLOW!\n");
             return;
         }
         if(front ==-1)
         front=0;
         rear++;
         QUEUE[rear]=data;

   }

void deq()
   {
      if(isempty())
      {
          printf("\nUNDERFLOW!\n");
         return;
      }
      else
      front++;
   }
 
 int peek()
 {
     if(isempty())
      {
          printf("\nUNDERFLOW!\n");
          return;
      }
    return  QUEUE[front]; 
 }

void display()
{
   if(isempty())
      {
          printf("\nUNDERFLOW!\n");
         return;
      }
      printf("\n\n");
      printf("QUEUE:");
      for(int i=front;i<=rear;i++)
      {
          printf("\t%d\t",QUEUE[i]);
      } 
      printf("\n\n");
}
 
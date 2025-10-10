#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct queue
{
    int r,f,data[SIZE];
};
typedef struct queue QUEUE;

void enqueue(QUEUE *q,int item)
{
    if(q->r==SIZE-1)
    {
        printf("\n Queue is full");
    }
    else
    {
        q->r=q->r+1;
        q->data[q->r]=item;
        if(q->f==-1)
        {
            q->f=0;
        }
    }
}

void dequeue(QUEUE *q)
{
    if(q->f==-1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nElement deleted is %d", q->data[q->f]);
        if(q->f==q->r)
        {
            q->f=-1;
            q->r=-1;
        }
        else
        {
            q->f=q->f+1;
        }
    }
}

void display(QUEUE q)
{
    if(q.f==-1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nQueue elements are:  ");
        for(int
            i=q.f;i<=q.r;i++)
        {
            printf("%d\t",q.data[i]);
        }
    }
}

int main()
{
   int item,ch;
   QUEUE q;

   q.f=-1;
   q.r=-1;

   while(1)
   {
       printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
       printf("Read choice:");
       scanf("%d",&ch);

       switch(ch)
       {
           case 1:
                printf("\nEnter element to enqueue: ");
                scanf("%d",&item);
                enqueue(&q,item);
                break;
           case 2:
                dequeue(&q);
                break;
           case 3:
                display(q);
                break;
           default:
                exit(0);
       }
   }
   return 0;
}

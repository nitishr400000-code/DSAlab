#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct stack
{
    int top;
    int data[SIZE];
};
typedef struct stack STACK;

void PUSH(STACK *S,int item)
{
    if(S->top==SIZE-1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        S->top=S->top+1;
        S->data[S->top]=item;
    }
}

void POP(STACK *S)
{
    if(S->top==-1)
    {
       printf("\nStack Underflow");
    }
    else
    {
        printf("Element popped is %d ",S->data[S->top]);
        S->top=S->top-1;
    }
}

void display(STACK S)
{
    if(S.top==-1)
    {
       printf("\nStack Empty");
    }
    else
    {
        printf("\nStack contents are:\n");
        for(int i=S.top; i>=0; i--)
        {
            printf("%d\n",S.data[i]);
        }
    }
}

int main()
{
    int ch, item;
    STACK S;
    S.top=-1;
    while(1)
    {
        printf("\n######################################################\n")
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Read choice : ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 : printf("\nRead the item to be pushed: ");
                     scanf("%d",&item);
                     PUSH (&S,item);
                     break;
            case 2 : POP (&S);
                     break;
            case 3 : display(S);
                     break;
            default : exit(0);
        }
    }
    return 0;
}

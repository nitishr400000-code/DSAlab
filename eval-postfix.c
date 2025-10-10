#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define SIZE 20

struct stack
{
    int top;
    float data[SIZE];
};
typedef struct stack STACK;

void PUSH (STACK *S,float item)
{
    S->data[++(S->top)]=item;
}

float POP (STACK *S)
{
    return S->data[(S->top)--];
}

float compute(float op1, char symbol, float op2)
{
    switch(symbol)
    {
        case '+' : return op1+op2;
        case '-' : return op1-op2;
        case '*' : return op1*op2;
        case '/' : return op1/op2;
        case '^' : return pow(op1,op2);
    }
}
 float evalpos(STACK *S,char postfix[20])
 {
     char symbol;
     float op1,op2,res;

     for(int i=0;postfix[i]!='\0';i++)
     {
         symbol=postfix[i];
         if(isdigit(symbol))
         {
             PUSH(S,symbol-'0');
         }
         else
         {
             op2=POP(S);
             op1=POP(S);
             res=compute(op1,symbol,op2);
             PUSH(S,res);
         }
     }
    return POP(S);
 }

 int main()
 {
     char postfix[20];
     float ans;
     STACK S;
     S.top=-1;
     printf("\nRead postfix expression : \n");
     scanf("%s",postfix);
     ans=evalpos(&S,postfix);
     printf("\nThe final result is %f",ans);
     return 0;
 }

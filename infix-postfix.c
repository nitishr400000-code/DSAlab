#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 20

struct stack
{
    int top;
    char data[SIZE];
};
typedef struct stack STACK;

void PUSH (STACK *S,char item)
{
    S->data[++(S->top)]=item;
}

char POP (STACK *S)
{
    return S->data[(S->top)--];
}

int preceed (char symbol)
{
    switch (symbol)
    {
        case '+' :
        case '-' : return 2;
        case '*' :
        case '/' : return 3;
        case '^' : return 4;

    }
}

void infx (STACK *S, char infix[20])
{
    int j=0;
    char symbol, postfix[20],temp;
    for(int i=0; infix[i]!='\0';i++)
    {
        symbol=infix[i];
        if (isalnum(symbol))
        {
            postfix[j++]=symbol;
        }
        else
        {
            switch(symbol)
            {
                case '(' : PUSH(S,symbol);
                           break;
                case ')' : temp=POP(S);
                           while(temp!='(')
                           {
                               postfix[j++]=temp;
                               temp=POP(S);
                           }
                           break;
                case '+' :
                case '-' :
                case '*' :
                case '/' :
                case '^' : if ((S->top==-1)||(S->data[S->top]=='('))
                            {
                                PUSH (S,symbol);
                            }
                            else
                            {
                                while(preceed(S->data[S->top])>=preceed(symbol)&&(S->top!=-1)&&S->data[S->top]!='(')
                                {
                                    postfix[j++]=POP(S);
                                }
                                PUSH(S,symbol);
                             }
                             break;
            }
        }
    }
    while(S->top!=-1)
    {
        postfix[j++]=POP(S);
    }
    postfix[j]='\0';
    printf("\nPostfix expression is %s", postfix);
}

int main()
{
    char infix[20];
    STACK S;
    S.top=-1;
    printf("\nRead the expression: \n");
    scanf("%s",infix);
    infx(&S,infix);
    return 0;
}

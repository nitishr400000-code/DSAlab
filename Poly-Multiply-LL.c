#include <stdio.h>
#include <stdlib.h>

struct node
{
    int co,po;
    struct node *add;
};
typedef struct node *NODE;

NODE insend (NODE start, int co, int po)
{
    NODE temp,cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->co=co;
    temp->po=po;
    temp->add=NULL;

    if (start==NULL)
    {
        return temp;
    }
    cur=start;
    while (cur->add!=NULL)
    {
        cur=cur->add;
    }
    cur->add=temp;
    return start;
}

NODE addterm1 (NODE res,int co,int po)
{
    NODE temp, cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->co=co;
    temp->po=po;
    temp->add=NULL;
    if (res==NULL)
    {
        return temp;
    }
    cur=res;
    while (cur!=NULL)
    {
        if (cur->po==po)
        {
            cur->co=cur->co+co;
            return res;
        }
        cur=cur->add;
    }
    if (cur==NULL)
    {
        res=insend (res,co,po);
    }
    return res;
}

NODE multiply (NODE poly1, NODE poly2)
{
    NODE p1,p2,res=NULL;
    for (p1=poly1;p1!=NULL;p1=p1->add)
        for(p2=poly2;p2!=NULL;p2=p2->add)
            res= addterm1 (res,p1->co*p2->co,p1->po+p2->po);
    return res;
}

void display (NODE start)
{
    NODE temp;
    if (start==NULL)
    {
        printf ("\nPolynomial is empty");
    }
    else
    {
        temp=start;
        while (temp->add!=NULL)
        {
            printf ("%d*x^%d+",temp->co,temp->po);
            temp=temp->add;
        }
        printf ("%d*x^%d",temp->co,temp->po);
    }
}

int main()
{
   NODE poly1=NULL,poly2=NULL,poly;
   int n,co,po;
   printf ("\nRead no. of terms of 1st polynomial: ");
   scanf ("%d",&n);
   for (int i=1;i<=n;i++ )
   {
       printf ("\nRead co and po of %d term: ",i);
       scanf ("%d%d",&co,&po);
       poly1=insend (poly1,co,po);
   }
   printf ("\nFirst polynomial is\n");
   display (poly1);

   printf ("\nRead no. of terms of 2nd polynomial: ");
   scanf ("%d",&n);
   for (int j=1;j<=n;j++ )
   {
       printf ("\nRead co and po of %d term: ",j);
       scanf ("%d%d",&co,&po);
       poly2=insend (poly2,co,po);
   }
   printf ("\nSecond polynomial is\n");
   display (poly2);

   poly =multiply (poly1,poly2);

   printf ("\nresulted polynomial is \n");

   display (poly);
   return 0;
}

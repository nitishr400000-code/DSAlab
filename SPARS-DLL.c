#include <stdio.h>
#include <stdlib.h>

struct node
{
    int row,col,data;
    struct node *next,*prev;
};
typedef struct node *NODE;

NODE insend (NODE start, int row, int col,int item)
{
    NODE temp,cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->row=row;
    temp->col=col;
    temp->data=item;
    temp->prev=NULL;
    temp->next=NULL;

    if (start==NULL)
    {
        return temp;
    }
    cur=start;
    while (cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=temp;
    temp->prev=cur;
    return start;
}

void display (NODE start)
{
    NODE temp;
    if (start==NULL)
    {
        printf ("\nList is empty");
    }
    else
    {
        printf ("\nRow\tColumn\tData\n");
        temp=start;
        while (temp!=NULL)
        {
            printf ("\n%d\t%d\t%d\n",temp->row,temp->col,temp->data);
            temp=temp->next;
        }
    }
}

void displayofmatrix (NODE start,int m, int n)
{
    NODE temp=start;
    for (int i=1; i<=m; i++)
    {
        for (int j=1; j<=n;j++)
        {
            if (temp!=NULL&&temp->row==i&&temp->col==j)
            {
                printf ("%d\t",temp->data);
                temp=temp->next;
            }
            else
            {
                printf ("0\t");
            }
        }
        printf ("\n");
    }

}

int main ()
{
    int m,n,item;
    NODE start=NULL;
    printf ("\nRead order of matrix: \n");
    scanf ("%d%d",&m,&n);
    printf ("\nRead elements:\n");

    for (int i=1; i<=m; i++)
    {
        for (int j=1; j<=n;j++)
        {
                scanf ("%d",&item);
                if (item!=0)
                {
                    start =insend (start,i,j,item);
                }
        }
    }
    display (start);

    printf ("\nSPARS matrix is: \n");
    displayofmatrix (start,m,n);

    return 0;
}

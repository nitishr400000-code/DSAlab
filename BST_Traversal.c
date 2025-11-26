#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right,*left;
};
typedef struct node *NODE;

NODE consBST (NODE root, int key)
{
    NODE temp,cur,prev;
    temp=(NODE)malloc (sizeof (struct node));
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    if (root==NULL)
        return temp;
    cur=root;
    prev=NULL;
    while (cur!=NULL)
    {
        prev=cur;
        if (key<cur->data)
            cur=cur->left;
        else
            cur=cur->right;
    }
    if (key<prev->data)
        prev->left=temp;
    else
        prev->right=temp;
    return root;
}

void pre_order (NODE root)
{
    if (root!=NULL)
    {
        printf ("%d\t",root->data);
        pre_order (root->left);
        pre_order (root->right);
    }
}

void in_order (NODE root)
{
    if (root!=NULL)
    {
        in_order (root->left);
        printf ("%d\t",root->data);
        in_order (root->right);
    }
}

void post_order (NODE root)
{
    if (root!=NULL)
    {
        post_order (root->left);
        post_order (root->right);
        printf ("%d\t",root->data);
    }
}

int main()
{
    NODE root=NULL;
    int item,ch;
    while (1)
    {
        printf ("\n1.Insert\n2.Pre order\n3.In order\n4.Post order\n5.Exit\nRead choice:");
        scanf ("%d",&ch);
        switch (ch)
        {
            case 1 : printf ("\nRead item to be inserted: ");
                     scanf ("%d",&item);
                     root=consBST (root,item);
                     break;
            case 2 : printf ("\nPre order traversal is \n");
                     pre_order (root);
                     break;
            case 3 : printf ("\nIn order traversal is \n");
                     in_order (root);
                     break;
            case 4 : printf ("\nPost order traversal is \n");
                     post_order (root);
                     break;
            default : exit (0);
        }
    }
    return 0;
}

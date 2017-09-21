#include <stdio.h>
struct node
{
    int info;
    struct node *next;
    struct node *back;
};

struct node *create(struct node **last)
{
    int n;
    struct node *prev,*newnode,*root;
    root=NULL;
    printf("ENTER VALUE\n");
    scanf("%d",&n);
    while(n!=-999)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->info=n;
        newnode->next=NULL;
        if(root==NULL)
        {
            root=newnode;
            newnode->back=NULL;
        }
        else
        {

            prev->next=newnode;
            newnode->back=prev;
        }
        prev=newnode;
        printf("ENTER VALUE\n");
        scanf("%d",&n);
    }
    if(root!=NULL)
    *last=newnode;
    return root;
}

void display(struct node *r,struct node *last)
{
 printf("---LINK LIST---\n");
 while(r!=NULL)
 {
 printf("%d\n",r->info);
 r=r->next;
 }
 while(last!=NULL)
 {
    printf("%d\n",last->info);
    last=last->back;
 }


}

struct node *insert(struct node *r,struct node *last,int n,int p)
{

    struct node *newnode,*root;
    root=r;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->info=n;
    newnode->next=NULL;
    newnode->back=NULL;
    if(p==1)
    {
        newnode->next=r;
        r->back=newnode;
        return newnode;
    }
    if(p==2)
    {
        last->next=newnode;
        newnode->back=last;
        return newnode;
    }
}

int length(struct node *r)
{
    int c=0;
    while(r!=NULL)
    {
        r=r->next;
        c++;
    }
    return c;
}

struct node *delete1(struct node *r,struct node *last,int p)
{
    struct node *root;
    root=r;
    int c=1;
    int l=length(r);
    if(p==0)
    {
        r=r->next;
        r->back=NULL;
        return r;
    }
    else if(p==-999)
    {
        last=last->back;
        last->next=NULL;
        return last;
    }
    else
    {
        while(c!=p)
        {
            r=r->next;
            c++;
        }
        r->next->next->back=r;
        r->next=r->next->next;
        return root;
    }

}


void main()
{
    int n=0,p;
    struct node *last,*start;
    start=create(&last);
    while(n!=6)
    {
    printf(" \n");
    scanf("%d",&n);
    switch(n)
    {
        case 1 :printf("Enter value\n");
                scanf("%d",&n);
                start=insert(start,last,n,1);
                break;

        case 2 :printf("Enter value\n");
                scanf("%d",&n);
                last=insert(start,last,n,2);
                break;

        case 3 :last=delete1(start,last,-999);
                break;

        case 4 :printf("ENTER POSITION");
                scanf("%d",&p);
                if(p==1)
                printf("INVALID");
                else{
                start=delete1(start,last,p-2);}
                break;

        case 5 :display(start,last);
                break;

        case 6 :break;
    }
    }
}

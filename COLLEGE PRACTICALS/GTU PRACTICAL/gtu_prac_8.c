#include <stdio.h>
struct node
{
int info;
struct node *next;
}st;
int size=0;
struct node *create()
{
struct node *newnode,*prev,*root;
int n;
printf("Enter The Number (-999 to stop)\n");
scanf("%d",&n);
root=NULL;
while(n!=-999)
{
newnode=(struct node *)malloc(sizeof(struct node));
newnode->info=n;
newnode->next=NULL;
if(root==NULL)
{
root=newnode;
}
else
{
prev->next=newnode;
}
prev=newnode;
size++;
    if(size==5)
{
    printf("QUEUE IS FULL\n");
    break;
}
printf("Enter The Number(-999 to stop)\n");
scanf("%d",&n);
}
return root;
}

void display(struct node *r)
{
    if(r==NULL)
        printf("QUEUE IS EMPTY\n");
while(r!=NULL)
{
printf("%d\n",r->info);
r=r->next;
}

}
struct node *insert(struct node *s)
{
struct node *temp;
int n;
printf("Enter the Value For Insert\n");
scanf("%d",&n);
while(s->next!=NULL)
{
    s=s->next;
}
temp=(struct node *)malloc(sizeof(struct node));
temp->info=n;
s->next=temp;
temp->next=NULL;
size++;
}

struct node *delete1(struct node *s)
{
    if(s==NULL)
        printf("QUEUE IS EMPTY\n");
    else{
struct node *root;
root=s;
root=s->next;
free(s);
return root;}
}

void main()
{
struct node *start,*start1;
int ch=1,x;
printf("Enter VALUE\n");
start=create();
while(ch!=0){
printf("1.Display\n2.Insert\n3.Delete\n0.EXIT\n");
scanf("%d",&ch);
switch(ch)
{
case 0:
        break;
case 1: display(start);
        break;
case 2: if(size==5)
        printf("QUEUE IS FULL\n");
        else{
        insert(start);}
        break;

case 3: start=delete1(start);
        break;

default:
printf("invalid input\n");
}
}
}

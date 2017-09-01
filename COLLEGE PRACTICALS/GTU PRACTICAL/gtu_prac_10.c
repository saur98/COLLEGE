#include<stdio.h>
struct node
{
int info;
struct node *next;
};
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
printf("Enter The Number(-999 to stop)\n");
scanf("%d",&n);
}
prev->next=root;
return root;
}

void display(struct node *r)
{
    struct node *root;
    root=r;
do
{
printf("%d\n",r->info);
r=r->next;
}while(r!=root);
printf("%d\n",r->info);
}
int length(struct node *r)
{
struct node *root;
root=r;
int l;
do
{
r=r->next;
l++;
}while(r!=root);
return l;
}

struct node *insert(struct node *r,int n,int p)
{
    struct node *root,*newnode;
root=r;
int d=0;
if(p==1)
{
newnode=(struct node *)malloc(sizeof(struct node));
newnode->info=n;
newnode->next=r;
do
{
    r=r->next;
}while(r->next!=root);
r->next=newnode;
return newnode;
}
else{
while(d!=p-1)
{
    r=r->next;
    d++;
}
newnode=(struct node *)malloc(sizeof(struct node));
newnode->info=n;
newnode->next=r->next;
r->next=newnode;
return root;
}}

struct node *delete(struct node *r,int p)
{
    struct node *root;
root=r;
int d=0;
 if(p==1)
 {
     do
     {
         r=r->next;
     }while(r->next!=root);
     r->next=root->next;
     return root->next;
 }
 else
 {
     while(d!=p-1)
     {
         r=r->next;
         d++;
     }
     r->next=r->next->next;
     return root;
 }
}

void main()
{
struct node *start,*start1;
int ch,x,l,p,n=0;
printf("Enter the info to create\n");
start=create();
display(start);
l=length(start);
while(n!=6){
printf("MENU\n1.INSERT AT END\n2.INSERT BEFORE SPECIFIED\n3.DELETE AT FIRST\n4.DELETE AFTER SPECIFIED\n5.DISPLAY\n");
scanf("%d",&n);
switch(n)
{
    case 1 :printf("Enter value to be inserted\n");
            scanf("%d",&x);
            p=l-1;
            start=insert(start,x,p);
            break;

    case 2 :printf("Enter value to be inserted\n");
            scanf("%d",&x);
            printf("Enter position to be inserted\n");
            scanf("%d",&p);
            start=insert(start,x,p);
            break;

    case 3 :p=1;
            printf("delete at first\n");
            start=delete(start,p);
            break;

    case 4 :printf("Enter position to be deleted\n");
            scanf("%d",&p);
            start=delete(start,p);
            break;

    case 5 :display(start);
            break;

    default:printf("ENTER RIGHT CHOICE");
            break;
}}
}

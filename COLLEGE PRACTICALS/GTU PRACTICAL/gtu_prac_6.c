#include<stdio.h>
struct node
{
int info;
struct node *next;
}st;
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
return root;
}
void display(struct node *r)
{
while(r!=NULL)
{
printf("%d\n",r->info);
r=r->next;
}
}
void display1(struct node *r)
{
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
temp=(struct node *)malloc(sizeof(struct node));
temp->info=n;
temp->next=s;
return temp;
}
struct node *insertend(struct node *s)
{
struct node *temp,*root,*end;
int n;
printf("Enter n To Insert at Last Node\n");
scanf("%d",&n);
root=s;
temp=(struct node *)malloc(sizeof(struct node));
temp->info=n;
while(s!=NULL)
{
end=s;
s=s->next;
}
end->next=temp;
temp->next=NULL;
return root;
}
struct node *insert_aesc(struct node *r,int x)
{
struct node *newnode,*root;
root=r;
printf("Enter the value to insert\n");
scanf("%d",&x);
if(r->info==0)
{
newnode=(struct node *)malloc(sizeof(struct node));
newnode->info=x;
newnode->next=NULL;
}else{
newnode=(struct node *)malloc(sizeof(struct node));
newnode->info=x;
newnode->next=NULL;
if(r->info>x)
{
newnode->next=r;
return newnode;
}
else
{
while(r!=NULL)
{
if(r->next==NULL)
break;
else if(r->next->info>x)
break;
else
r=r->next;
}
newnode->next=r->next;
r->next=newnode;
}
return root;
}}
struct node *deletefirst(struct node *s)
{
struct node *root;
root=s;
root=s->next;
free(s);
return root;
}
struct node *delete2(struct node *s)
{
struct node *root;
int n,i=1;
root=s;
printf("Enter the position\n");
scanf("%d",&n);
//if(n==1)
//{
// printf("Invalid Number\n");
//}
//else
{
while(i<=n-1)
{
s=s->next;
i++;
}
s->next=s->next->next;
}
return root;
}
int length(struct node *r)
{
int l=0;
while(r!=NULL)
{
l=l+1;
r=r->next;
}
return l;
}
struct node *delete1(struct node *s)
{
struct node *root;
int n,i=1,len;
root=s;
printf("Enter the position\n");
scanf("%d",&n);
len=length(s);
if(n==1||n>len)
{
printf("Invalid Number\n");
}
else
{
while(i<=n-3)
{
s=s->next;
i++;
}
s->next=s->next->next;
}
return root;
}
void main()
{
struct node *start,*start1;
int ch,x;
printf("Enter the info to create\n");
start=create();
// printf("Enter 1 Value for Ase. order");
//start1=create();
start1=(struct node *)malloc(sizeof(struct node));
start1->info=0;
start1->next=NULL;
c:
printf("Enter 1 for Display\nEnter 2 for Insert a node at the front of the linked list\nEnter 3 for Insert a node at the end of the linked list\nEnter 4 for insert a node such that linked list is in ascending order\n");
printf("Enter 5 for Delete a first node of the linked list\nEnter 6 for Delete a node before specified position\nEnter 7 for Delete a node after specified position\nEnter 8 for Display Sort\nEnter 0 for EXIT\n\n");
scanf("%d",&ch);
switch(ch)
{
case 0:
break;
case 1:
display(start);
goto c;
break;
case 2:
start=insert(start);
goto c;
break;
case 3:
start=insertend(start);
goto c;
break;
case 4:
start1=insert_aesc(start1,x);
goto c;
break;
case 5:
start=deletefirst(start);
goto c;
break;
case 6:
start=delete1(start);
goto c;
break;
case 7:
start=delete2(start);goto c;
break;
case 8:
display1(start1);
goto c;
break;
default:
printf("invalid input\n");
}
}

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
printf("\n%d\n",r->info);
r=r->next;
}
}
int max(struct node *r)
{
int m=r->info;
while(r!=NULL)
{
if(m<r->info)
{
m=r->info;
}
r=r->next;
}
return m;
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
int search(struct node *r,int len)
{
int m,i=0,temp=0;
printf("Enter Value to Search Position\n");
scanf("%d",&m);
while(r!=NULL)
{
i++;
if(m==r->info)
{
return i;
}
r=r->next;
}
if(i==len)
{
return -1;
}
}
void replace(struct node *r)
{
int m,n;
printf("Enter the old Value and New value for Replace\n");
scanf("%d%d",&m,&n);
while(r!=NULL)
{
if(m==r->info)
{
r->info=n;
}
r=r->next;
}
}
void sort(struct node *r)
{
struct node *s;
int temp=0;
s=r;
while(r!=NULL)
{
while(s!=NULL)
{
if(s->info<r->info)
{
temp=s->info;
s->info=r->info;
r->info=temp;
}
s=s->next;
}
r=r->next;
s=r;
}
}
struct node *reverse(struct node *r)
{
struct node *prev,*save;
struct node *current;
current=r;
prev=NULL;
while(current!=NULL)
{
save=current->next;
current->next=prev;
prev=current;
current=save;
}return prev;
}
void *merge(struct node *l1,struct node *l2,struct node *l3)
{
while(l1!=NULL)
{
l3->info=l1->info;
l1=l1->next;
l3->next=(struct node *)malloc(sizeof (struct node));
l3=l3->next;
}
while(l2!=NULL)
{
l3->info=l2->info;
l2=l2->next;
if(l2!=NULL)
{
l3->next=(struct node *)malloc(sizeof (struct node));
l3=l3->next;
}
}
}
void main()
{
struct node *start,*start1,*ans,*l3;
int ch,maximum,len,search1;
c:
printf("Enter 1 for Create\nEnter 2 for Display\nEnter 3 for Max Info\nEnter 4 for Length\nEnter 5 for Search\nEnter 6 for Replace\nEnter 7 for Sort\nEnter 8 for Reverse\nEnter 9 for Merge\nEnter 0 for Exit\n\n\n");
scanf("%d",&ch);
switch(ch)
{
case 0:
break;
case 1:
start=create();
goto c;
break;
case 2:
display(start);
goto c;
break;
case 3:
maximum=max(start);
printf("Max info is\t%d\n\n",maximum);
goto c;
break;
case 4:
len=length(start);
printf("Length of Linklist is\t%d\n\n",len);
goto c;
break;
case 5:
search1=search(start,length(start));
printf("\nPosition = %d\n",search1);
goto c;
break;
case 6:
replace(start);
goto c;
break;
case 7:
sort(start);
goto c;
break;
case 8:
start=reverse(start);
goto c;
break;
case 9:
printf("Enter Your First LINK LIST\n");
start=create();
printf("Enter Your Second LINK LIST\n");
start1=create();
l3=(struct node *)malloc(sizeof(struct node));
ans=merge(start,start1,l3);
printf("ANS\n");
display(l3);
goto c;
break;
default:
printf("Wrong Choice\n");
break;
}
}

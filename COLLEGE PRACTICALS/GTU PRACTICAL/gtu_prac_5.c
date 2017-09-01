#include <stdio.h>
#define size 50
struct queue
{
    int f;
    int r;
    int que[size];
}q;

void insert(int x)
{
    q.r++;
    q.que[q.r]=x;
}

int delete1()
{
    int x;
    x=q.que[q.f];
    q.f++;
    return x;
}

int isempty()
{
if(q.f>q.r)
return 1;
else
return 0;
}

int isfull()
{
if(q.r==size-1)
return 1;
else
return 0;
}

void display()
{
    int i;
    for(i=q.f;i<=q.r;i++)
    {
        printf("%d\n",q.que[i]);
    }
}

void main()
{
  q.f=0;
  q.r=-1;
  int n=0,x;
  while(n!=4){
  printf("MENU\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
  scanf("%d",&n);
  switch(n)
  {
      case 1: if(isfull==1)
                printf("QUEUE IS FULL\n");
                else
                {
                    printf("ENTER VALUE\n");
                    scanf("%d",&x);
                    insert(x);
                }
                break;

      case 2: if(isempty==1)
                printf("QUEUE IS EMPTY\n");
                else
                delete1();
                break;

      case 3: display();
                break;

      case 4:break;
  }
}
}

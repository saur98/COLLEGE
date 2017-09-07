#include<stdio.h>
#define size 5
struct queue
{
int f;
int r;
int que[size];
}cq;

void insert(int x)
{
    if(isfull())
        printf("Queue is full\n");
    else
        {
        if(cq.f==-1)
        cq.f=0;
        cq.r=(cq.r+1)%size;
        cq.que[cq.r]=x;
        }
}

int delete1()
{
    int x;
    if(isempty())
        printf("queue is empty\n");
    else
        {
        x=cq.que[cq.f];
        cq.f=(cq.f+1)%size;
        if(cq.f==cq.r)
            cq.f=cq.r=-1;
        return x;
        }
}

void display()
{
    int i;
    if(isempty())
        printf("queue is empty\n");
    else
    {
        printf("--QUEUE--\n");
        for(i=cq.f;i!=cq.r;i=(i+1)%size)
        {
        printf("%d\n",cq.que[i]);
        }
        printf("%d\n",cq.que[cq.r]);

    }
}

int isempty()
{
    if(cq.f==-1)
        return 1;
    else
        return 0;
}

int isfull()
{
    if(cq.f==(cq.r+1)%size)
        return 1;
    else
        return 0;
}

void main()
{
    cq.f=cq.r=-1;
    int n,x;
    while(n!=4)
    {
        printf("MENU\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&n);
        switch(n)
    {
        case 1:printf("Insert value to be inserted\n");
        scanf("%d",&x);
        insert(x);
        break;

        case 2:x=delete1();
                printf("Deleted value is %d\n",x);
                break;

        case 3:display();
        break;

        case 4:break;
    }}
}

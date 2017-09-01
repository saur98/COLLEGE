#include<stdio.h>
#define size 10
struct stack
{
    int top ;
    int s[size];
}st;
int isempty ()
{
    if(st.top ==-1)
        return 1;
    else
        return 0;
}
int isfull ()
{
    if(st.top == 9)
        return 1;
        else
            return 0;

}
void push(int i)
{
st.top++;
    st.s[st.top]=i;

}
int pop()
{int x;
    x=st.s[st.top];
    st.top--;
    return x;
}
int peep()
{int x;
    x=st.s[st.top];
    return x;
}
void change(int i)
{
    st.s[st.top]=i;
}
void display()
{int i;
    for(i=st.top;i>=0;i--)
    {
        printf("%d\n",st.s[i]);
    }
}
int main()
{int n,i;
    st.top=-1;
    read:
   printf("MENU\n1.PUSH ELEMENT INTO STACK\n2.POP ELEMENT\n3.SEE THE ELEMENT\n4.CHANGE THE ELEMENT\n5.DISPLAY STACK\n0.EXIT\n");
    scanf("%d",&n);
   switch(n)
   {
        case 1 : printf("enter element\n");
                 scanf("%d",&i);
                 if(isfull()==0)
                 push(i);
                 else
                 printf("STACK OVERFLOW\n");
                 goto read;
        case 2 : if(isempty()==0)
                    {i=pop();
                    printf("%d\n",i);}
                    else
                    printf("STACK EMPTY\n");
                    goto read;
        case 3 : if(isempty()==0)
        {        i=peep();
                 printf("%d\n",i);}
                 else
                    printf("STACK IS EMPTY\n");
                 goto read;
        case 4 :
                    if(isempty()==0){printf("ENTER THE ELEMENT\n");
                 scanf("%d",&i);
                 change(i);}
                 else
                    printf("STACK IS EMPTY\n");
                    goto read;
        case 5 :  if(isempty()==0)
                    display();
                    else
                   printf("STACK1 IS EMPTY\n");
                   goto read;
        case 0 : exit(0);break;


   }
}

#include<stdio.h>
struct stack
{
char s[100];
int top ;
}st;
void push(char x)
{
st.top++;
st.s[st.top] = x;
}

char pop()
{
if(st.top == -1)
return -1;
else
return st.s[st.top--];
}

int priority(char x)
{
if(x == '(')
return 0;
if(x == '+' || x == '-')
return 1;
if(x == '*' || x == '/')
return 2;
if(x == '^')
return 3;
}

main()
{
st.top=-1;
char exp[20];
char *e, x;
printf("Enter the expression :: ");
scanf("%s",exp);
e = exp;
while(*e != '\0')
{
if(isalnum(*e))
printf("%c",*e);
else if(*e == '(')
push(*e);
else if(*e == ')')
{
while((x = pop()) != '(')
printf("%c", x);
}
else
{
while(priority(st.s[st.top]) >= priority(*e))
printf("%c",pop());
push(*e);
}
e++;
}
while(st.top != -1)
{
printf("%c",pop());
}
}

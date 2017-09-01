#include<stdio.h>
#include<string.h>
#define size 20
struct stack
{
int top;
char s[size];
}st;
int isempty()
{
if(st.s[st.top]==-1)
return 1;
else
return 0;
}
int isfull()
{
if(st.top==size-1)
{
return 1;
}
else
return 0;
}
void push_string(char x)
{
st.top++;
st.s[st.top]=x;
}
void push(char x)
{
st.top++;
st.s[st.top]=x;
}
int pop()
{
int x;
x=st.s[st.top];
st.top--;
return x;
}
char pop_string()
{
char x;
x=st.s[st.top];
st.top--;
return x;
}
void display()
{
char i;
for(i=st.top;i>=0;i--)
{
printf("%c\n",st.s[i]);
}
}
int main()
{
int x,j,n,ch,i,p,m,len;
char string[20],s[20],str[20];
st.top=-1;
c:
printf("Enter 1 for convert Decimal to Binary\nEnter 2 for Reverse the String\nEnter 3 to Check string is palindrom or not\nEnter 4 for Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter the any Number\n");
scanf("%d",&n);
while(n!=0)
{
if(isfull())
{
printf("Enter small number\n");
}
else
{
x=n%2;
push(x);
n=n/2;
}
}
while(!isempty())
{
printf("%d",pop());
}
printf("\n");
goto c;
break;
case 2:
printf("Enter the String\n");
scanf("%s",string);
for(i=0;string[i]!='\0';i++)
{
push_string(string[i]);
}
i=0;
while(!isempty())
{
x=pop_string();
printf("%c",x);
}
printf("\n");
goto c;
break;
case 3:
p=0,m=0;
printf("Enter the String = \n");
scanf("%s",str);
len=strlen(str);
if(len%2!=0)
{
for(i=0;i<len;i++)
{
push_string(str[i]);
if(str[i]=='x')
p++;
}
if(p==1)
{
if(str[len/2]=='x')
{
for(i=0;i<len;i++)
{
if(str[i]==pop_string())
m++;
}
if(m==len)
printf(" your string is palindrome\n\n");
else
printf("your string is not palindrome\n\n");
}
else
printf("your string is not palindrome\n\n");
}
else
printf("your string is not palindrome\n\n");
}
else
printf("your string is not palindrome\n\n");
goto c;
break;
case 4:
break;
}
}

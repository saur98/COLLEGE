#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50

char *pop();
char postfix[MAX];
char stack[MAX][MAX];
void push(char *str);
int isempty();
int white_space(char operand);
void postfix_to_prefix();
int top;

int main()
{
	top = -1;
	printf("Enter postfix expression : ");
	scanf("%s",postfix);
	postfix_to_prefix();

	return 0;

}

void postfix_to_prefix()
{
	unsigned int i;
	char operand1[MAX], operand2[MAX];
	char operand;
	char temp[2];
	char strin[MAX];
	for(i=0;i<strlen(postfix);i++)
	{
		operand=postfix[i];
		temp[0]=operand;
		temp[1]='\0';

		if(!white_space(operand))
		{
			switch(operand)
			{
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
				strcpy(operand1,pop());
				strcpy(operand2,pop());
				strcpy(strin,temp);
				strcat(strin,operand2);
				strcat(strin,operand1);
				push(strin);
				break;
			default: /*if an operand comes*/
			     push(temp);
			}
		}
	}
	printf("\nPrefix Expression :: ");
	puts(stack[0]);
}

void push(char *str)
{
	if(top > MAX)
	{
		printf("\nStack overflow\n");
		exit(1);
	}
	else
	{
		top=top+1;
		strcpy( stack[top], str);
	}
}

char *pop()
{
	if(top == -1 )
	{
		printf("\nStack underflow \n");
		exit(2);
	}
	else
		return (stack[top--]);
}
int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int white_space(char operand)
{
	if( operand == ' ' || operand == '\0')
		return 1;
	else
		return 0;
}
